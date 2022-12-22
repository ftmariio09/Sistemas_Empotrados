/*
 * File:   sma_lamp.c
 * Author: ftmar
 *
 * Created on 30 de noviembre de 2022, 14:51
 */
//RELATIVE HUMIDITY :RH =(VOUT - zero offset)/slope
//RELATIVE HUMIDITY :RH = (Vout - - 0.826)/0.0315)          


//Temperatura : VOUT = 10 mv/°C × T   --> T = Vout/0.01


#pragma config CPD = OFF, BOREN = OFF, IESO = OFF, DEBUG = OFF, FOSC = HS
#pragma config FCMEN = OFF, MCLRE = ON, WDTE = OFF, CP = OFF, LVP = OFF
#pragma config PWRTE = ON, BOR4V = BOR21V, WRT = OFF

#include <xc.h>
#include <stdio.h>

#pragma intrinsic(_delay)
#define _XTAL_FREQ 20000000 // necessary for __delay_us

char salida_B = 0;
int salida_UART = 0;
char contador = 0;
char continuar = 0;
int lectura_ruido = 0;
int lectura_aux = 0;
int contador1 = 0;



int leerRuido()
{
    int ruido; 
    
    //ADCON0bits.CHS = 0b1100;         //Elegir el channel 12  del ADC
    //ESPERAR el Acquisition Time  Page 389
    ADCON0bits.GO = 1;              //Iniciar conversion
    while(ADCON0bits.GO == 1);
    
    ruido = (int)ADRESH << 8 | (int)ADRESL;

    return ruido;
}

void __interrupt() treat_int(void)
{
    
    if(INTCONbits.T0IF)
    {
        TMR0 = 60;
        contador += 1;
        contador1 += 1;
        
        if(contador >= 20)
        {
            lectura_aux = leerRuido();
            
            if(lectura_aux > lectura_ruido)
            {
                lectura_ruido = lectura_aux;
            }
            
            
            contador = 0;
        }
        
        if(contador1 >= 200)
        {
            salida_UART = lectura_ruido;
            continuar = 1;
            contador1 = 0;
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


void init_ADC(void)
{
    ADCON0bits.CHS = 0b1100;         //Elegir el channel 12 del ADC
    ADCON1bits.VCFG0 = 0;           //Elegir voltage de alimendacion del equipo VDD
    ADCON1bits.VCFG1 = 0;           //Elegir voltage negativo o conectado a tierra VSS
    
    ADCON0bits.ADCS = 0b10;         //Configurar TAD.  Ver TABLE 9-1 del data sheet
    ADCON1bits.ADFM = 1;            //Elegir justificacion a la derecha
    
    ADCON0bits.ADON = 1;            //Encender el ADC
}

void init_Ports(void)
{
    TRISBbits.TRISB0 = 1;           //Configurar el pin 0 del puerto B como Input
    ANSELHbits.ANS12 = 1;             //Configurar el pin 0 del puerto B como Input Analogico
    //TRISB = 0;                      //Configurar el puerto B como Output
}

void putch(char c)
{ 
  while (!TXSTAbits.TRMT);
  TXREG = c;
} 






void main(void)
{ 
  OSCCON = 0b00001000; // External cristal
  

  init_uart();
  init_ADC();
  init_TMR0();
  init_Ports();
  
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