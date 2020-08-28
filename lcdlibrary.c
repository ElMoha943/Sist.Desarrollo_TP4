#include<xc.h>
#include"lcdlibrary.h"

void InicializarDisplay(void){
/*    __delay_ms(15);
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=1; D4=1;
    E=0;
    __delay_ms(5);
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=1; D4=1;
    E=0;
    __delay_ms(0.1);
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=1; D4=1;
    E=0; */
    //Function Set
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=1; D4=1;
    D3=1; D2=0;
    E=0;
    __delay_ms(1)
    //DISPLAY ON/OFF
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=0; D4=0;
    D3=1; D2=1; D1=0; D0=0;
    E=0;
    __delay_ms(1)
    //Display Clear
    BorrarDisplay();
    //Entry Mode Set
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=0; D4=0;
    D3=0; D2=1; D1=1; D0=1;
    E=0;
    __delay_ms(1)
}

void Mostrar(char *str, unsigned char pos, unsigned char linea){
    unsigned char cosa, i=0;
    if(linea<3 && linea>0){
        //seleccion de linea
        if(linea==1) cosa=0;
        else cosa=64;
    }
    else{
        return;
    }
    if(pos<17 && pos>0){
        //lectura de posicion
        pos=pos+cosa;
    }
    else{
        return;
    }
    //Seleccion de posicion
    RS=0; RW=0 ;E=1;
    PORTC=pos;
    E=0;
    __delay_ms(1)
    //escritura en el display
    while(str[i]!='\0'){
        RS=1; RW=0; E=1;
        PORTB=str[i];
        E=0;
        __delay_ms(1)
        i++;
    }
}

void BorrarDisplay(void){
    //Display Clear
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=0; D4=0;
    D3=0; D2=0; D1=0; D0=1;
    E=0;
    __delay_ms(10)
}

