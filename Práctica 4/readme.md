# Práctica 4. El lenguaje Postscript

**Realizado por :** Alejandro Sánchez Hens y Paula Molina Castillo

## 1. Dibujo de casita

Para el primer problema a resolver debemos crear una página en la que se muestre un dibujo de una casa y un mensaje junto a la misma que ponga "mi casita".

Para ello necesitamos crear un triángulo a modo de tejado, un cuadrado para la estructura de la casa y una serie de rectángulos para las ventanas y la puerta.

Para realizar el tejado hemos usado el siguiente código:

<pre><code>
newpath
240 682 moveto
305 740 lineto
370 682 lineto
closepath
0.7 setgray
fill

newpath
0 0.5 1 setrgbcolor
240 682 moveto
305 740 lineto
370 682 lineto
closepath
stroke
</code></pre>

En el código anterior lo que hacemos básicamente es colocar nuestro cursor en un punto determinado de la pantalla gracias a la orden <code>moveto</code> y trazamos una línea hasta el punto deseado gracias a la orden <code>lineto</code>. Gracias a estas dos órdenes podemos colocar el cursor en las posiciones pertinentes y trazar una serie de líneas para formar un triángulo. Finalmente, establecemos el color gracias a <code>setgray</code> y a la orden <code>fill</code>.

La estructura de la casa la hemos creado gracias a estas líneas de código:

<pre><code>
newpath
250 600 moveto
360 600 lineto
360 690 lineto
250 690 lineto
closepath
0.7 setgray

fill

newpath
0 0.5 1 setrgbcolor
250 600 moveto
360 600 lineto
360 690 lineto
250 690 lineto
closepath
stroke
</code></pre>

Como podemos ver aplicamos la misma técnica como para el tejado, es decir, establecemos la posición del cursor en la página y trazamos una serie de líneas para crear el cuadrado que formará la estructura de la casa, para finalmente rellenarla con un determinado color.

Continuamos con la puerta, para la cual hemos usado este código y hemos seguido la misma técnica que para las partes anteriores:

<pre><code>
newpath
295 600 moveto
295 640 lineto
315 640 lineto
315 600 lineto
closepath
stroke
</code></pre>

En el siguiente código mostramos cómo hemos diseñado las ventanas:

<pre><code>
newpath
265 650 moveto
265 670 lineto
290 670 lineto
290 650 lineto
closepath
stroke

newpath
320 650 moveto
320 670 lineto
345 670 lineto
345 650 lineto
closepath
stroke
</code></pre>

Finalmente, hemos implementado el siguiente código para colocar el texto al lado de la casa:

<pre><code>
/Times-Roman findfont
12 scalefont
setfont
0 setgray

newpath
230 620 moveto
90 rotate
(mi casita) show
closepath
stroke
</code></pre>

Como podemos ver hemos definido la fuente que hemos usado, el tamaño de la misma, el texto y la rotación del mismo.

A continuación podemos ver una imágen que nos muestra el <a href="https://github.com/AlexHens/PDIH/blob/main/practica4/micasita.jpg">resultado final</a>.

## 2. Tarjeta de visita

Para el siguiente problema debemos diseñar una página en la que se muestre una tarjeta de visita con un texto determinado y un círculo.

Para establecer el rectángulo que hemos usado para la tarjeta hemos usado el siguiente código:

<pre><code>
newpath
150 550 moveto
150 750 lineto
450 750 lineto
450 550 lineto
closepath

0.95 setgray
fill
stroke

</code</pre>

Para establecer las distintas secciones de texto de nuestra tarjeta de visita usaremos el siguiente código:

<pre><code>
/Arial-bold findfont
9 scalefont
setfont
0 setgray

newpath
335 660 moveto
(Drago Kovacevic) show
closepath
stroke

/Arial findfont
8 scalefont
setfont
0.5 setgray

newpath
335 650 moveto
(Ejecutivo de cuentas) show
closepath
stroke

/Arial findfont
6 scalefont
setfont
0.5 setgray

newpath
345 620 moveto
(P. de la Castellana, 141) show
339 612 moveto
(Local 2 - Edificio Cuzco IV) show
372 604 moveto
(28046 Madrid) show
323 596 moveto
(Tels. 914 174 550 / 669 896 224) show
362 588 moveto
(drago@serotel.es) show
closepath
stroke

</code></pre>

Como en el ejercicio anterior, debemos establecer la fuente, el tamaño de la misma, el texto y la posición del mismo, así como el color y la opacidad del mismo.

Por último, hemos usado el siguiente código para crear el círculo en el que se nos mostrará la foto de perfil:

<pre><code>
newpath
220 660 35 0 360 arc
closepath

0.7 setgray
fill
newpath
0 setgray
220 660 35 0 360 arc
closepath
stroke
</code></pre>

Como podemos ver para crear un círuclo debemos establecer una serie de parámetros, como son las coordenadas x e y donde se dibujará, el radio de la circunferencia y hasta que ángulo quiere que se dibuje.

A continuación podemos ver una imágen que nos muestra el <a href="https://github.com/AlexHens/PDIH/blob/main/practica4/tarjeta_visita.jpg">resultado final</a>.

## 3. Dibujo de un corazón y texto

Para este último problema, debemos crear una página en la que podamos visualizar un corazón en color rojo y a su lado un determinado texto.

Para crear el corazón hemos usado dos círculos y un triángulo invertido.

Para crear los círculos hemos usado el siguiente código:

<pre><code>
newpath
225 660 35 0 360 arc
closepath

1 0 0 setrgbcolor
fill
stroke

newpath
285 660 35 0 360 arc
closepath

1 0 0 setrgbcolor
fill
stroke
</code></pre>

Para crear el triángulo invertido usaremos el siguiente código:

<pre><code>
newpath
192 650 moveto
253 580 lineto
318 650 lineto
closepath


1 0 0 setrgbcolor
fill

stroke

newpath
318 650 moveto
253 580 lineto
192 650 lineto
closepath

1 0 0 setrgbcolor
fill

stroke
</code></pre>

Por último, para crear el texto al lado de la figura del corazón usaremos el siguiente código:

<pre><code>
/Arial-bold findfont
8 scalefont
setfont

  newpath
  0.8 setgray
  324 625 moveto
  (La belleza no es nada, no permanece.) show
  stroke

  newpath
  0.6 setgray
  324 612 moveto
  (No sabes la suerte que tienes sin belleza.) show
  stroke

  newpath
  0.4 setgray
  324 599 moveto
  (Porque si le gustas a alguien,) show
  stroke

  newpath
  0.2 setgray
  324 586 moveto
  (sabes que es por otra cosa.) show
  stroke
</code></pre>

A continuación podemos ver una imágen que nos muestra el <a href="https://github.com/AlexHens/PDIH/blob/main/practica4/corazon.jpg">resultado final</a>.

