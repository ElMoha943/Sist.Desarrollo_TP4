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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ALIAS

char IntToChar(int numero){
    return numero + '0';
}

//FUNCION PRINCIPAL
void main(void) {
    int contador=0, contador2=0, segs=0, mins=0, hours=0, d, u;
    char cosa[]= "TRABAJO PRACTICO", cosa2[]= "DISPLAY LCD", cosa3[]= "TIEMPO", cosa4[20];
    unsigned char mode=1;
    TRISA=0x03;
    TRISB=0;
    TRISC=0x03;
    ANSEL=0;
    OPTION_REG=0x02;
    InicializarDisplay();
    while(1){
        //Timer Setup.
        if(T0IF==1)
        {
            TMR0=TMR0+254;
            T0IF=0;
            contador++;
            if (contador==250){
                contador=0;
                if(segs!=60) segs++;
                else {
                    segs=0;
                    if(mins!=60) mins++;
                    else{
                        mins=0;
                        if(hours!=24)hours++;
                        else hours=0;
                    }
                }
                contador2++;
                if(contador2==5){
                    contador2=0;
                    
                    if(mode==1) mode=2;
                    else mode=1;
                }
            }
        }
        if(mode==1){ //LETRERO
            Mostrar(cosa,0,1);
            Mostrar(cosa2,0,2);
        } 
        else //reloj
        {
            Mostrar(cosa3,0,1);
            d=hours/10; u=hours%10;
            cosa4[0]=IntToChar(d);
            cosa4[1]=IntToChar(u);
            d=mins/10; u=mins%10;
            cosa4[2]=IntToChar(d);
            cosa4[3]=IntToChar(u);
            d=segs/10; u=segs%10;
            cosa4[4]=IntToChar(d);
            cosa4[5]=IntToChar(u);
            Mostrar(cosa4,0,2);
        }
    }
}