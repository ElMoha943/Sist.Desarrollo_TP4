#include<xc.h>
#include"lcdlibrary.h"

void InicializarDisplay(void){
    //Function Set
    RS=0;
    RW=0;
    D7=0;
    D6=0;
    D5=1;
    D4=1;
    D3=1;
    D2=0;
    //DISPLAY ON/OFF
    RS=0;
    RW=0;
    D7=0;
    D6=0;
    D5=0;
    D4=0;
    D3=1;
    D2=1;
    D1=0;
    D0=0;
    //Display Clear
    BorrarDisplay();
    //Entry Mode Set
    RS=0;
    RW=0;
    D7=0;
    D6=0;
    D5=0;
    D4=0;
    D3=0;
    D2=1;
    D1=1;
    D0=1;   
}

void Mostrar(char *str, unsigned char pos, unsigned char linea){
    if(linea<3 && linea>0){
        //seleccion de linea
    }
    else{
        return;
    }
    if(pos<17 && pos>0){
        //seleccion de posicion
    }
    else{
        return;
    }
    //Write Data to RAM
    RS=1;
    RW=0;
    
    //
}

void BorrarDisplay(void){
    //Display Clear
    RS=0;
    RW=0;
    D7=0;
    D6=0;
    D5=0;
    D4=0;
    D3=0;
    D2=0;
    D1=0;
    D0=1;
}

