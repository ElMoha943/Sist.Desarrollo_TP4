#Trabajo Práctico Display LCD

Objetivo: Poner en práctica los conocimientos adquiridos en cuanto al control y configuración de un display LCD de caracteres y generar una librería de utilidad para futuros proyectos.

El objetivo de hacer una librería consiste en resolver el acceso al display desde el microcontrolador, teniendo en cuenta todas especificaciones del fabricante y generando las señales de control que el mismo establece para realizar funciones básicas sobre el display. 

Más adelante, si un proyecto requiere el uso de un display LCD, podremos acudir a nuestra librería y utilizarla en cualquier aplicación, sin necesidad de resolver nuevamente las cuestiones estrictamente ligadas al control del display.

#Librería LCD.
La misma de contar con al menos 3 funciones, a saber:

void InicializarDisplay(void)

Un llamado a esta función raliza las acciones a nivel de hardware necesarias para inicializar el display en modo de 2 lineas, caracteres 5x8 pixeles, desplazameinto automático del cursor con cada caracter ingresado e inicialización del cursor en la parte superior izquierda.

void Mostrar(char *str, unsigned char pos, unsigned char linea)

Esta funcion genera los comandos necesarios en el display para setear la dirección de DDRAM adecuada que posiciona el cursor en la linea indicada por la variable ‘linea’ (1 ó 2) y en la posición indicada por ‘pos’ (1 a 16). Inmediatamente despues transmite los caracteres ascii pasados en el arreglo str hasta encontrar en el mismo un caracter nulo (/0)

void BorrarDisplay(void)

Esta función borra el display y devuelve el cursor a la posición inicial.

#Programa principal (main)

A los fines de testear esta libería y presentar el trabajo práctico, se deberá hacer un programa principal que muestre dos textos en forma alternada. Cada uno de los textos deberá permanecer visible por 5 segundos.

La primera pantalla a visualizar deberá decir


TRABAJO PRACTICO
DISPLAY LCD

Y luego de 5 segundos conmutar a la pantalla

TIEMPO
00:00:00

Donde deberá mostrar la cantidad de horas, minutos y segundos transcurridos desde que se inició el programa.

Ambas pantallas se alternan con ciclos de visualización de 5 segundos y durante el tiempo de exposición de la segunda pantalla el contador de tiempo debe transcurrir con normalidad.
