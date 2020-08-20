//CONFIGURATION BITS
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = ON
#pragma config FCMEN = ON
#pragma config LVP = OFF
#pragma config BOR4V = BOR40V
#pragma config WRT = OFF 

//LIBRERIAS
#include <xc.h>
#include "lcdlibrary.h"

//ALIAS

//FUNCION PRINCIPAL
void main(void) {
    TRISA=0x03;
    TRISB=0;
    TRISC=0x03;
    ANSEL=0;
    OPTION_REG=0x02;
    while(1){
        //Timer Setup.
        if(T0IF==1)
        {
            TMR0=TMR0+131; /* ACORDARME DE AJUSTARLO A 5 SEGUNDOS!! */
            T0IF=0;
        }
    }
}