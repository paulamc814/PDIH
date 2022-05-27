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
perro <- readWave('perro.wav')
</code></pre>

Una vez cargado, podemos observarlo en la pantalla superior derecha: 
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%204/micasita.jpg" width= "600" >
</p>