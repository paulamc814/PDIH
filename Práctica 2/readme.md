
Práctica realaizada por Alejandro Sánchez Hens y Paula Molina Castillo.

# PRÁCTICA 2: Uso de bibliotecas de programación de interfaces de usuario en modo texto

*"ncurses"* es una biblioteca de programación que provee una API que permite al programador escribir interfaces basadas en texto. *ncurses* crea una capa sobre las capacidades del terminal y proporciona un marco de trabajo robusto para crear interfaces de usuario en modo texto. Permite crear fácilmente aplicaciones basadas en ventanas, menús, paneles y formularios.

**INSTALACIÓN**

<pre><code>sudo apt-get install libncurses5-dev libncursesw5-dev
</code></pre>

**COMPILACIÓN**

<pre><code>gcc hello.c -o hello -lncurses
</code></pre>

### Cuestiones a resolver
* Instalar la librería ncurses, crear los programas de ejemplo ofrecidos más arriba, y comprobar su funcionamiento.

* Crear un juego sencillo tipo “pong” partiendo del ejemplo del movimiento de la pelotita. Al iniciar el juego debe mostrarse un recuadro en una pantalla de bienvenida explicando los controles de juego. Tras una pausa se iniciará el juego en sí mismo.

## Instala la libreería ncurses

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/instalacion.JPG " width= "700" >
</p>

## Programa *hello.c*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/hello.JPG" width= "700" >
</p>

Lo primero que tenemos que hacer es inicializar la pantalla con la función **initscr()**. Lo segundo es desarrollar el programa con todas las entradas y las salidas, la línea **printw("Holita")** imprime la cadena *Holita* con las coordenadas actuales. 
Con la función **refresh()** se pasa el contenido de la memoria intermedia a la pantalla real. La función **getch()** espera la pulsación de una tecla y por último debemos liberar todos los recursos y devolver el terminal a su modo normal haciendo uso de la función **endwin()**.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/holita.JPG" " width= "700" >
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

Esta función se encarga únicamente de limpiar la pantalla completa. Usamos la **interrupción 10** y la *función 15* y *función 0*.

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
