

// See /opt/microchip/xc8/v<version>/docs/chips/16f886.html
// for details on #pragma config

#pragma config CPD = OFF, BOREN = OFF, IESO = OFF, DEBUG = OFF, FOSC = HS
#pragma config FCMEN = OFF, MCLRE = ON, WDTE = OFF, CP = OFF, LVP = OFF
#pragma config PWRTE = ON, BOR4V = BOR21V, WRT = OFF


#pragma intrinsic(_delay)
#define _XTAL_FREQ 20000000 // necessary for __delay_us

#include <xc.h>
#include <stdio.h>


int contador = 0;
int contador1 = 0;

int ciclo_trabajo = 0;

char ciclo = 0;

int salida_UART = 0;
char continuar = 0;


void putch(char c)
{ 
  while (!TXSTAbits.TRMT);
  TXREG = c;
} 


void init_puertos()
{
    //TRISCbits.TRISC1 = 1;    //puerto de CCP2
    TRISCbits.TRISC2 = 1;    //puerto de CCP1
    
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

void init_PWM()
{   
    CCP1CONbits.CCP1M = 0b1100;         //configurar el modo del CCP
    CCP1CONbits.P1M = 0b00;             //configurar los bits de salida PWM 
    CCP1CONbits.DC1B = 0b00;            //Poner los 2 bits de menor peso del Duty Cycle a 00
    CCPR1L = 0;                         //Poner los 8 bits de mayor peso dle Duty Cycle a 00
    
    
 
    while(PIR1bits.TMR2IF == 0);        //esperar a que salte el flag del TMR2
    PIE1bits.TMR2IE = 0;
    
    PIR1bits.TMR2IF = 0;                //Resetear el flag del TMR2
    
    TRISCbits.TRISC2 = 0;               //puerto de CCP1
    //TRISCbits.TRISC1 = 0;             //puerto de CCP2
    
}

void init_TMR2()
{
    PR2 = 0xA6;                     //Poner el registro PR2 a 166 para configurar el periodo
    PIR1bits.TMR2IF = 0;            //Limpiar el flag de interrupcion
    T2CONbits.T2CKPS = 0;           //Seleccionar preescalado 1
    
    T2CONbits.TMR2ON = 1;           //Encender el Timer 2
}

void init_Interrupts()
{
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    PIE1bits.TMR2IE = 1;
}


void init_TMR0(void){
    OPTION_REGbits.T0CS= 0b0;
    OPTION_REGbits.PSA = 0b0;
    OPTION_REGbits.PS = 0b110;
    TMR0 = 60;
    INTCONbits.T0IE = 1; 
}

void actualizar_PWM(int ciclo_trabajo)
{   
    //if ( 0 <= ciclo && ciclo <= 100 )
    //{
        ciclo = (ciclo_trabajo * 166) / 100;
        CCPR1L = ciclo;
        salida_UART = ciclo;
        printf("%d\r\n", salida_UART); 
    //}


    
}


void __interrupt() treat_int(void){
    
    if(INTCONbits.T0IF == 1){
        TMR0 = 60;
        contador += 1;
        

        if(contador >= 1000){
            
            //actualizar_PWM(0);
            CCPR1L = 0x00;
            //ciclo_trabajo == 100 ? ciclo_trabajo=0 : (ciclo_trabajo += 20);
            
            
        }
        
        if(contador >= 2000)
            {
                //actualizar_PWM(0);
                CCPR1L = 0x00;
                contador = 0;
            }
        INTCONbits.T0IF = 0; 
    } 
}




void main(void)
{ 

  OSCCONbits.OSTS = 1; // External cristal
  
  init_puertos();
  init_Interrupts();
  init_TMR0();
  init_TMR2();
  init_PWM();
  init_uart();
  actualizar_PWM(0);
  
  
  //continuar = 0;
  while(1)
  {
    
  } 
}
