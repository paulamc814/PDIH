Práctica realaizada por Alejandro Sánchez Hens y Paula Molina Castillo

# PRÁCTICA 1: Entrada/Salida utilizando interrupciones con lenguaje c

En esta práctica se va a acceder a las rutinas de servicio a interrupción de la BIOS para teclado y vídeo desde el
sistema operativo **MS-DOS**. Se va a utilizar el lenguaje de programación C para realizar interrupciones software a
través de la función no estándar *int86()*, que viene definida en el fichero dos.h de varios compiladores de C.

### Requisitos de esta práctica
* gotoxy(): coloca el cursor en una posición determinada
* setcursortype(): fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
*  setvideomode(): fija el modo de video deseado
*  getvideomode(): obtiene el modo de video actual
*  textcolor(): modifica el color de primer plano con que se mostrarán los caracteres
*  textbackground(): modifica el color de fondo con que se mostrarán los caracteres
*  clrscr(): borra toda la pantalla
*  cputchar(): escribe un carácter en pantalla con el color indicado actualmente
*  getche(): obtiene un carácter de teclado y lo muestra en pantalla
* Implementar una función que permita dibujar un recuadro en la pantalla en modo texto. Recibirá como parámetros las coordenadas superior izquierda e inferior derecha del recuadro, el color de primer plano y el color de fondo.
* Implementar en lenguaje C un programa que establezca modo gráfico CGA (modo=4) para crear dibujos sencillos en pantalla.

## Función *gotoxy()*

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/gotoxy1.JPG)

Esta función nos permite colocar el cursor en una posición determinada de la pantalla. El número de interrupción utilizada como podemos observar es la número 10, y la función número 2. El registro AH = 2, DH = y, DL = x, BH = 0 y salida no tiene. 

Para comprobar su funcionamiento hemos cologado el cursor en la posición *gotoxy(15,7);* y hemos escrito Hola, por pantalla *printf("Hola");*

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/gotoxy2.JPG)
