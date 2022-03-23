Práctica realaizada por Alejandro Sánchez Hens y Paula Molina Castillo

# PRÁCTICA 1: Entrada/Salida utilizando interrupciones con lenguaje C

En esta práctica se va a acceder a las rutinas de servicio a interrupción de la BIOS para teclado y vídeo desde el
sistema operativo **MS-DOS**. Se va a utilizar el lenguaje de programación C para realizar interrupciones software a
través de la función no estándar *int86()*, que viene definida en el fichero dos.h de varios compiladores de C.

### Requisitos de esta práctica
* gotoxy(): coloca el cursor en una posición determinada
* setcursortype(): fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
* setvideomode(): fija el modo de video deseado
* getvideomode(): obtiene el modo de video actual
* textcolor(): modifica el color de primer plano con que se mostrarán los caracteres
* textbackground(): modifica el color de fondo con que se mostrarán los caracteres
* clrscr(): borra toda la pantalla
* cputchar(): escribe un carácter en pantalla con el color indicado actualmente
* getche(): obtiene un carácter de teclado y lo muestra en pantalla
* Implementar una función que permita dibujar un recuadro en la pantalla en modo texto. Recibirá como parámetros las coordenadas superior izquierda e inferior derecha del recuadro, el color de primer plano y el color de fondo.
* Implementar en lenguaje C un programa que establezca modo gráfico CGA (modo=4) para crear dibujos sencillos en pantalla.

## Función *mi_pausa()*

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/mi_pausa.JPG " width= "700" >
</p>

Función que vamos a utilizar durante todo el código que pasa el control al teclado para leer una pulsación y poder realizar
una pausa para mostrar con claridad todas las implementaciones del las funciones explicadas a continuación. Llama a la **interrupción 21**
y la *función 8*.


## Función *gotoxy()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/gotoxy1.JPG " width= "700" >
</p>

Esta función nos permite colocar el cursor en una posición determinada de la pantalla. El número de interrupción utilizada como podemos observar es la **interrupción 10**, y la *función número 2*. El registro AH = 2, DH = y, DL = x, BH = 0 y salida no tiene. 

Para comprobar su funcionamiento hemos colocado el cursor en la posición *gotoxy(15,7);* y hemos escrito Hola, por pantalla *printf("Hola");*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/gotoxy2.JPG " width= "700" >
</p>

## Función *setcursortype()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setcursortype1.JPG " width= "700" >
</p>

Esta función nos permite fijar el aspecto del cursor. Hemos utilizado la **interrupción 10** junto con la *función 1*.
Para conseguir el cursor invisible, normal y grueso hemos cambiado los valores de los registros CH y CL. Como podemos observar no tiene salida. 

Para comprobar su funcionamiento hemos llamado a la función mostrando los diferentes tipos de cursores. 

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setcursortype2.JPG " width= "700" >
</p>

## Función *setvideomode()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setvideomode1.JPG " width= "700" >
</p>

Esta función fija el modo de vídeo deseado, el cual le pasamos por argumento. Volvemos a utilizar la **interrupción 10** y la *función 0*.
El modo de video se le asigna al registro AL. Y tampoco tiene salida. 

Para comprobar su funcionamiento hemos realizado un cambio a modo 1 (letras grandes) y vuelta a modo de vídeo 3 (modo normal).

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setvideomode2.JPG " width= "700" >
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/setvideomode3.JPG " width= "700" >
</p>

## Función *getvideomode()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/getvideomode1.JPG " width= "700" >
</p>

Esta función nos muestra el tipo de modo de vídeo que tenemos activo actualmente. Volvemos a utilizar la **interrupción 10** y la *función F*. En este caso si disponemos de una salida, la cual está en el registro AL.

Para comprobar su funcionamiento utilizamos un *printf("\nEl modo de video es %i\n", modo);* 
justo después de haber indicado el modo de video 3 de la función anterior. 

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/getvideomode2.JPG " width= "700" >
</p>

## Función *textcolor()* y *textbackground()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/textcolor1.JPG " width= "700" >
</p>

Estas funciones únicamente cambian el color de las letras y del fondo, y no hacen uso de ninguna interrupción sino de unas variables globales. 

## Función *clrscr()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/clrscr1.JPG " width= "700" >
</p>

Esta función se encarga únicamente de limpiar la pantalla completa. Usamos la *interrupción 10* y la *función 15* y *función 0*.

## Función *cputchar()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/cputchar1.JPG " width= "700" >
</p>

Esta función escribe un caracter en pantalla del color y fondo indicado actualmente.
Utilizamos la **interrupción 10** y la *función 9*. El registro AL contiene el carácter que se desea escribir y el registro BL contiene el color de fondo que se desea usar, en sus primeros 4 bits, y el color de texto que se desea usar, en los 4 siguientes.

Para su comprobación vamos a escribir una 'A' en color magenta sobre un fondo verde. 

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/cputchar2.JPG " width= "700" >
</p>

## Función *getche()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/getche1.JPG " width= "700" >
</p>

Graias a esta función podremos leer un carácter de la pantalla. **Interrupción 21** y *función 1*.
Hacemos uso de la función *mi_putchar* para poder escribir el carácter leído.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/getche2.JPG " width= "700" >
</p>

## Función *createbox()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/createbox1.JPG " width= "700" >
</p>

Es mi función creada para dibujar un cuadrado indicándole las coordenadas y colores en modo texto.  
No necesitamos hacer uso de ninguna interrupción únicamente creamos dos bucles for anidados y hacemos uso de las funciones
anteriorente comentadas. 

Vamos a crear un cuadrado de los colores anteriormente indicados anteriormente.
<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/createbox2.JPG " width= "700" >
</p>

## Función *screendrawn()*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/screendrawn1.JPG " width= "700" >
</p>

En esta función creo un dibujo en la pantalla en modo gráfico(CGA). 
Primero utilizo la función *modo_grafico()* para establecer el modo. A continuación itero dos bucles haciendo uso de la función *pixel()*
la cuál pone el pixel en la posición y en el color indicado. 

Hemos realizado el siguiente dibujo para mostrar su funcionamiento.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%201/images/screendrawn2.JPG " width= "700" >
</p>
