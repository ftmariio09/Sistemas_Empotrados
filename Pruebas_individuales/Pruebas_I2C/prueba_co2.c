/*
 * File:   sma_lamp.c
 * Author: ftmar
 *
 * Created on 30 de noviembre de 2022, 14:51
 */
//RELATIVE HUMIDITY :RH =(VOUT - zero offset)/slope
//RELATIVE HUMIDITY :RH = (Vout - - 0.826)/0.0315)          


//Temperatura : VOUT = 10 mv/Â°C Ã? T   --> T = Vout/0.01


#pragma config CPD = OFF, BOREN = OFF, IESO = OFF, DEBUG = OFF, FOSC = HS
#pragma config FCMEN = OFF, MCLRE = ON, WDTE = OFF, CP = OFF, LVP = OFF
#pragma config PWRTE = ON, BOR4V = BOR21V, WRT = OFF

#include <xc.h>
#include <stdio.h>
#include "i2c-v2.h"

#pragma intrinsic(_delay)
#define _XTAL_FREQ 20000000 // necessary for __delay_us

char salida_B = 0;
int salida_UART = 0;
char contador = 0;
char continuar = 0;



int leer_co2()
{
    uint8_t data[10];
    uint16_t prediccion;
    uint8_t status;
    int32_t resistencia;
    uint16_t Tvoc;

    i2c_start();

    if(i2c_write(0xB5))            //si devuelve ack
    {
        data[0] = i2c_read(1);
        data[1] = i2c_read(1);
        data[2] = i2c_read(1);
        data[3] = i2c_read(1);
        data[4] = i2c_read(1);
        data[5] = i2c_read(1);
        data[6] = i2c_read(0);
        data[7] = i2c_read(1);
        data[8] = i2c_read(0);

        i2c_stop();
    }
    

    prediccion = (data[0] * 256) + data[1];
    status = data[2];
    resistencia = (data[4] * 65536) + (data[5] * 256) + data[6];
    Tvoc = (data[7] * 256) + data[8];
    
    
    //printf("%d\r\n", prediccion);
    //printf("%d\r\n", status);
    //printf("%d\r\n", resistencia);
    printf("%d\r\n", Tvoc);
    
    return prediccion;
}

void __interrupt() treat_int(void)
{
    
    if(INTCONbits.T0IF)
    {
        TMR0 = 60;
        contador += 1;
        
        if(contador >= 200)
        {
            salida_UART = leer_co2();
            continuar = 1;
            contador = 0;
        }
        
        INTCONbits.T0IF = 0; 
    }
}

void init_TMR0(void)
{
    OPTION_REGbits.T0CS= 0b0;
    OPTION_REGbits.PSA = 0b0;
    OPTION_REGbits.PS = 0b110;
    TMR0 = 60;
    INTCONbits.T0IE = 1; 
}

void init_uart(void)
{  
  TXSTAbits.BRGH = 0;
  BAUDCTLbits.BRG16 = 0;

  // SPBRGH:SPBRG = 
  SPBRGH = 0;
  SPBRG = 32;  // 9600 baud rate with 20MHz Clock
  
  TXSTAbits.SYNC = 0; /* Asynchronous */
  TXSTAbits.TX9 = 0; /* TX 8 data bit */
  RCSTAbits.RX9 = 0; /* RX 8 data bit */

  PIE1bits.TXIE = 0; /* Disable TX interrupt */
  PIE1bits.RCIE = 0; /* Disable RX interrupt */

  RCSTAbits.SPEN = 1; /* Serial port enable */

  TXSTAbits.TXEN = 0; /* Reset transmitter */
  TXSTAbits.TXEN = 1; /* Enable transmitter */
 }




void init_Ports(void)
{
    TRISBbits.TRISB1 = 1;           //Configurar el pin 1 del puerto B como Input
    ANSELbits.ANS2 = 2;             //Configurar el pin 1 del puerto B como Input Analogico
    //TRISB = 0;                      //Configurar el puerto B como Output
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 1;
}

void putch(char c)
{ 
  while (!TXSTAbits.TRMT);
  TXREG = c;
} 






void main(void)
{ 
  OSCCONbits.OSTS = 1; // External cristal
  

  init_uart();
  
  init_TMR0();
  init_Ports();
  init_uart();
  
  INTCONbits.PEIE = 1;
  INTCONbits.GIE = 1;
  
  continuar = 0;
  while(1)
  {
    while(!continuar);
    
    continuar = 0;
    printf("%d\r\n", salida_UART); 
  } 
  
}