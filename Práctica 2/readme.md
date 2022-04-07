
Práctica realizada por Alejandro Sánchez Hens y Paula Molina Castillo.

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

Lo primero que tenemos que hacer es inicializar la pantalla con la función **initscr()**. 
Lo segundo es desarrollar el programa con todas las entradas y las salidas, la línea **printw("Holita")** imprime la cadena *Holita* con las coordenadas actuales. 
Con la función **refresh()** se pasa el contenido de la memoria intermedia a la pantalla real. 
La función **getch()** espera la pulsación de una tecla y por último debemos liberar todos los recursos y devolver el terminal a su modo normal haciendo uso de la función **endwin()**.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/holita.JPG" " width= "700" >
</p>

## Programa *ventana.c*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/ventana.JPG" width= "700" >
</p>

En este nuevo programa creamos una ventana y nos ayudamos de las siguientes funciones en orden de aparción.

* **init_pair()** : crea nuevos pares de colores de fondo y de caracteres y le asigna un número al nuevo par, de forma que luego se pueda usar en otras funciones.
* **clear()** : limpia el contenido de la ventana.
* **getmaxyx()** : calcula el tamaño en caracteres del terminal en este momento.
* **newwin()** : crea una nueva ventana del tamaño que indiquemos.
* **wbkgd()** : establece el color de fondo y de caracteres en la ventana recién creada.
* **box()** : dibuja los marcos de la ventana recién creada.
* **mvwprintw()** : muestra contenido (cadenas, números, etc) en la ventana actual.
* **wrefresh()** : refresca el contenido para mostrar en la ventana los últimos cambios realizados en ella.
 
<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/ventana1.JPG" width= "700" >
</p>

## Programa *pelotita.c*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/pelotita.JPG" width= "700" >
</p>

Lo único que realiza este programa es mover de derecha a izquierda "un caracter o" a lo largo de la pantalla. 
Usamos la función **noecho()** sólo se encarga de configurar la ventana para que no haya eco.
La función **curs_set()** establece la apariencia del cursor en función del valor de visibilidad.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/pelotita1.JPG" width= "700" >
</p>

## Programa *pong.c*

Nuestro programa se trata de un juego que consta de dos jugadores y golpear con una pala una pelota para mandársela al otro jugador y evitar que te metan gol. El primero que en el marcador llegue a 5 puntos gana y se acaba la partida. 

Los controles principales son; 
* *Jugador1* **W**: Moverse hacia arriba, **S**: Moverse hacia abajo.
* *Jugador2* **Flecha hacia arriba**: Moverse hacia arriba, **Flecha hacia abajo**: Moverse hacia abajo.
* La partida se puede pausar con la tecla **p**.
* La partida finaliza con el *escape*. 

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/1.jpg" width= "700" >
</p>

Comenzamos con las declaraciones, inicializaciones y las tareas principales del ncurses.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/pong1.JPG" width= "700" >
</p>

La siguiente parte del código es el menú de los controles que tiene nuestro juego. 
Establece los controles indicados anteriormente.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/pong2.JPG" width= "700" >
</p>

Lo primero que hacemos es un **nodelay()** que habilitar o deshabilitar el bloqueo durante la lectura y establecemos los valores iniciales de las raquetas y la pelota.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/pong3.JPG" width= "700" >
</p>

El bucle se encarga de dibujar todo el rato las dos palas en la posición en la que se encuentren, desde la posición inicial hasta 7 posiciones más abajo, tiene una altura de 8 píxeles. 
También se encarga de dibujar la red , una línea trazada de arriba abajo , la pelota en la posición en la que esté, por defecto está comienza en medio de la pantalla y los marcadores.

El *if* se encarga de calcular el movimiento de la pelota y estudiar los diferentes casos de movimiento de esta, si choca con una pala, si no choca...

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/pong4.JPG" width= "700" >
</p>

Por último entra en el *swtich*, evalua en cada iteración del bucle while qué tecla se ha pulsado, y respecto a ello se realiza la acción correspondiente, se mueve una de las dos palas, pone el juego en pausa...
El bucle se repite hasta que se pulse el escape, o hasta que uno de los dos jugadores gane la partida.

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/pong5.JPG" width= "700" >
</p>

Todo esto daría como resultado la siguiente pantalla de juego:

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%202/images/2.jpg" width= "700" >
</p>

