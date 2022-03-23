Práctica realaizada por Alejandro Sánchez Hens y Paula Molina Castillo

# PRÁCTICA 1: Entrada/Salida utilizando interrupciones con lenguaje c

En esta práctica se va a acceder a las rutinas de servicio a interrupción de la BIOS para teclado y vídeo desde el
sistema operativo **MS-DOS**. Se va a utilizar el lenguaje de programación C para realizar interrupciones software a
través de la función no estándar *int86()*, que viene definida en el fichero dos.h de varios compiladores de C.

### Requisitos de esta práctica
* gotoxy(): coloca el cursor en una posición determinada
* setcursortype(): fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
* setvideomode(): fija el modo de video deseado
* getvideomode(): obtiene el modo de video actual
*  textcolor(): modifica el color de primer plano con que se mostrarán los caracteres
*  textbackground(): modifica el color de fondo con que se mostrarán los caracteres
*  clrscr(): borra toda la pantalla
*  cputchar(): escribe un carácter en pantalla con el color indicado actualmente
*  getche(): obtiene un carácter de teclado y lo muestra en pantalla
* Implementar una función que permita dibujar un recuadro en la pantalla en modo texto. Recibirá como parámetros las coordenadas superior izquierda e inferior derecha del recuadro, el color de primer plano y el color de fondo.
* Implementar en lenguaje C un programa que establezca modo gráfico CGA (modo=4) para crear dibujos sencillos en pantalla.

## Función *mi_pausa()*

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/mi_pausa.JPG)

Función que vamos a utilizar durante todo el código que pasa el control al teclado para leer una pulsación y poder realizar
una pausa para mostrar con claridad todas las implementaciones del las funciones explicadas a continuación. Llama a la **interrupción 21**
y la *función 8*.


## Función *gotoxy()*

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/gotoxy1.JPG)

Esta función nos permite colocar el cursor en una posición determinada de la pantalla. El número de interrupción utilizada como podemos observar es la **interrupción 10**, y la *función número 2*. El registro AH = 2, DH = y, DL = x, BH = 0 y salida no tiene. 

Para comprobar su funcionamiento hemos cologado el cursor en la posición *gotoxy(15,7);* y hemos escrito Hola, por pantalla *printf("Hola");*

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/gotoxy2.JPG)

## Función *setcursortype()*

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setcursortype1.JPG)

Esta función nos permite fijar el aspecto del cursor. Hemos utilizado la **interrupción 10** junto con la *función 1*.
Para conseguir el cursor invisible, normal y grueso hemos cambiado los valores de los registros CH y CL. Como podemos observar no tiene salida. 

Para comprobar su funcionamiento hemos llamado a la función mostrando los diferentes tipos de cursores. 

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setcursortype2.JPG)

## Función *setvideomode()*

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setvideomode1.JPG)

Esta función fija el modo de vídeo deseado, el cual le pasamos por argumento. Volvemos a utilizar la **interrupción 10** y la *función 0*.
El modo de video se le asigna al registro AL. Y tampoco tiene salida. 

Para comprobar su funcionamiento hemos realizado un cambio a modo 1 (letras grandes) y vuelta a modo de vídeo 3 (modo normal).

![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setvideomode2.JPG)
![imagen](https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setvideomode3.JPG)


