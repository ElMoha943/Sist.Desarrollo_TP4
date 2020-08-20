#ifndef lcdlibrary_h
#define lcdlibrary_h

void InicializarDisplay(void);
void Mostrar(char *str, unsigned char pos, unsigned char linea);
void BorrarDisplay(void);

#define D0 PORTBbits.RB7
#define D1 PORTBbits.RB6
#define D2 PORTBbits.RB5
#define D3 PORTBbits.RB4
#define D4 PORTBbits.RB3
#define D5 PORTBbits.RB2
#define D6 PORTBbits.RB1
#define D7 PORTBbits.RB0

#define RS PORTCbits.RC7
#define RW PORTCbits.RC6
#define E PORTCbits.RC5

#endif