# Seminario. Manejo del sonido con R

**Realizado por :** Alejandro Sánchez Hens y Paula Molina Castillo

# 1. Reproducción y operaciones con sonido en R

En R disponemos de varias librerías que nos permitirán trabajar con archivos de sonido, tanto *WAV* como *MP3*.
Lo primero que necesitamos es instalar una serie de librerías, pueden instalarse tanto en el terminal como manualmente: 

<pre><code>
install.packages('tuneR', dep=TRUE)
install.packages('seewave', dep=TRUE)
install.packages('soundgen', dep=TRUE)
</code></pre>

Al inicio de nuestro código tenemos que cargar dichas librerías para poder utilizarlas, con la siguiente orden:

<pre><code>
library(tuneR)
library(seewave)
library(audio)
</code></pre>

## Cargar, reproducir y visualizar sonidos

Para poder indicar la ubicación de nuestros sonidos hemos tenido que incluir la siguiente orden:

<pre><code>
setwd("C:/Users/paaul/OneDrive/Escritorio/Curso 21-22/2cuatrimestre/Periféricos y Dispositivos de Interfaz Humana/Seminarios/Sonido/S6-varios-sonidos")
</code></pre>

Para encontrar la ubicación correcta he hecho uso de **getwd()** en la terminal de R. 

La forma correcta para cargar un sonido es la siguiente: 

<pre><code>
gato <- readWave('gato.wav')
</code></pre>

Una vez cargado, podemos observarlo en la pantalla superior derecha: 
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/cargaArchivo.JPG" width= "600" >
</p>

Si escribimos el nombre del sonido directamente *"gato"* podremos inspeccionar sus características:

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/caracteristicas.JPG" width= "600" >
</p>

Para calcular la dirección exacta del sonido (con 3 decimales) realizaremos las siguientes órdenes: 
<pre><code>
round(length(gato@left) / gato@samp.rate, 3)

f <- gato@samp.rate    #44100
</code></pre>

Para poder escuchar el sonido hay que utilizar la orden:
<pre><code>
listen(gato,f=f)
</code></pre>

Y la forma de onda: 
<pre><code>
plot( extractWave(gato, from = 1, to = 393984) )
</code></pre>

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/onda.JPG" width= "600" >
</p>

Si sólo deseamos escuchar una porción del sonido original, especificaremos desde qué segundo y hasta cuál:
<pre><code>
listen(gato, f=f, from=6.5, to=8.9)
</code></pre>

## Trocear, unir y guardar sonidos

Si lo que queremos es **cortar** un trozo de sonido debido a su longitud podemos utilizar: 
<pre><code>
s2 <- cutw(gato, from=6.5,to=8.9, output="Wave")
</code></pre>


<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/ondaCorte.JPG" width= "600" >
</p>

Si en cambio lo que queremos es **unir** dos sonidos se debe de hacer con:
<pre><code>
s3 <- pastew(perro, s2, output="Wave")
</code></pre>

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/ondaUnion.JPG" width= "600" >
</p>

Finalmente para eliminar alguna porción de sonido: 
<pre><code>
s4 <- deletew(s3, output="Wave", from = duration(s2), to = duration(perro))
duration(s4)
s5 <- addsilw(s4, at = "end", d = 1, output = "Wave")
duration(s5)
</code></pre>

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/ondaEliminar.JPG" width= "600" >
</p>

La función **addsilw** añade un silencio al sonido.

Una vez hemos terminado de trabajar con los sonidos, podemos guardarlos en disco en el formato deseado:
<pre><code>
writeWave(s4, file.path("snd-gato-perro.wav") )
</code></pre>

A continuación cambiaremos la frecuencia del sonido “gato” desde los 44100Hz hasta los 8000Hz:
<pre><code>
gato8000<-resamp(s2,f=44100,g=8000, output="Wave")
</code></pre>

## Otras formas de modificar sonido

La función **afilter()** nos permite aplicar un filtro de amplitud:
<pre><code>
sndF1 <- afilter(gato,f=f,threshold=50,colwave="red")
listen(sndF1,f=f)
</code></pre>

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/amplitud.JPG" width= "600" >
</p>

La función **bwfilter()** aplica un filtro de frecuencia, eliminando las muestras entre las frecuencias (en Hz) indicadas:
<pre><code>
sndF3 <- bwfilter(gato,f=f, channel=1, n=1, from=10000,
to=22000, bandpass=TRUE, listen = FALSE, output = "Wave")
listen(sndF3,f=f)
</code></pre>

Para aplicar los efectos de eco vamos a utilizar un nuevo audio llamado *"hola"*:
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/hola.JPG" width= "600" >
</p>

<pre><code>
hola <- readWave('hola.wav')
str(hola)
holaECO <- echo(hola,f=22050,amp=c(0.8,0.4,0.2),delay=c(1,2,3),
                output="Wave")
holaECO@left <- 10000 * holaECO@left
listen(holaECO , f= 22050)
str(holaECO)
plot( extractWave(holaECO, from = 1, to = 77959) )
writeWave(holaECO, file.path("tmpholaECO.wav") )
</code></pre>

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Sonido/images/ondaHolaEco.JPG" width= "600" >
</p>

La función **revw()** de la librería seewave le da la vuelta al sonido:
<pre><code>
alreves <- revw(hola, output="Wave")
listen(alreves)
</code></pre>

