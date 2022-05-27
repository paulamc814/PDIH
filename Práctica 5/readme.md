# Práctica 5. Experimentación con el sistema de salida de sonido

**Realizado por :** Alejandro Sánchez Hens y Paula Molina Castillo
*Práctica realizada con la ayuda del Seminario de Sonido*

### 1. Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno. En el primero debe escucharse el nombre de la persona que realiza la práctica. En el segundo debe escucharse el apellido

Lo primero para poder grabar los sonidos, hemos utilizado el anexo para utlizar la orden **espeak**.

<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/GrabarSonido.JPG" width= "600" >
</p>

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

<pre><code>
setwd("C:/Users/paaul/OneDrive/Escritorio/Curso 21-22/2cuatrimestre/Periféricos y Dispositivos de Interfaz Humana/Prácticas/P5")
</code></pre>

Para encontrar la ubicación correcta he hecho uso de **getwd()** en la terminal de R. 

Para cargar todos archivos con nuestros nombres y apellidos tenemos que realizar: 
<pre><code>
nombreA <- readWave('nombreA.wav')
nombreA #Alejandro
nombreP <- readWave('nombreP.wav')
nombreP #Paula
apellidoA <- readWave('apellidoA.wav')
apellidoA #Sánchez Hens
apellidoP <- readWave('apellidoP.wav')
apellidoP #Molina Castillo
</code></pre>

### 2. Dibujar la forma de onda de ambos sonidos.

<pre><code>
plot( extractWave(nombreA, from = 1, to = 393984) )
plot( extractWave(nombreP, from = 1, to = 393984) )
plot( extractWave(apellidoA, from = 1, to = 393984) )
plot( extractWave(apellidoP, from = 1, to = 393984) )
</code></pre>

**Alejandro**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/ondaA.JPG" width= "600" >
</p>

**Paula**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/ondaP.JPG" width= "600" >
</p>

**Sánchez Hens**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/ondaAA.JPG" width= "600" >
</p>

**Molina Castillo**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/ondaPA.JPG" width= "600" >
</p>

### 3. Obtener la información de las cabeceras de ambos sonidos

<pre><code>
str(nombreA)
str(nombreP)
str(apellidoA)
str(apellidoP)
</code></pre>

**Alejandro**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/infoA.JPG" width= "600" >
</p>

**Paula**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/infoP.JPG" width= "600" >
</p>

**Sánchez Hens**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/infoAA.JPG" width= "600" >
</p>

**Molina Castillo**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/infoPA.JPG" width= "600" >
</p>

### 4. Unir ambos sonidos en uno nuevo

<pre><code>
s1 <- pastew(apellidoA, nombreA, output="Wave")
s1
plot( extractWave(s1, from = 1, to=265573) )
listen(s1)

s2 <- pastew(apellidoP, nombreP, output="Wave")
s2
plot( extractWave(s2, from = 1, to=265573) )
listen(s2)
</code></pre>

### 5. Dibujar la forma de onda de la señal resultante

Este sería el resultado de la orden **plot** indicada anteriormente:

**Alejandro Sánchez Hens**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/ondaASH.JPG" width= "600" >
</p>

**Paula Molina Castillo**
<p align="center">
    <img src="https://github.com/paulamc814/PDIH/blob/main/Pr%C3%A1ctica%205/images/ondaPMC.JPG" width= "600" >
</p>

### 6. Pasarle un filtro de frecuencia para eliminar las frecuencias entre 10000Hz y 20000Hz

Finalmente tuvimos que eliminar frecuencias entre 5000Hz a 10000Hz.

<pre><code>
f1 <- bwfilter(s1, f=f, channel=1, n=1, from=5000, to=10000, bandpass = TRUE, listen = FALSE, output = "Wave")
listen(f1, f=f)

f2 <- bwfilter(s2, f=f, channel=1, n=1, from=5000, to=10000, bandpass = TRUE, listen = FALSE, output = "Wave")
listen(f2, f=f)
</code></pre>

### 7. Almacenar la señal obtenida como un fichero WAV denominado “mezcla.wav”

<pre><code>
writeWave(s1, file.path("mezcla1.wav") )
writeWave(s2, file.path("mezcla2.wav") )
</code></pre>

### 8. Cargar un nuevo archivo de sonido, aplicarle eco y a continuación darle la vuelta al sonido. Almacenar la señal obtenida como un fichero WAV denominado “alreves.wav”

<pre><code>
nombreAECO <- echo(nombreA,f=22050, amp=c(0.8, 0.4, 0.2), delay = c(1,2,3), output="Wave" )
nombreAECO@left <- 10000 * nombreAECO@left
listen(nombreAECO, f=22050)

nombrePECO <- echo(nombreP,f=22050, amp=c(0.8, 0.4, 0.2), delay = c(1,2,3), output="Wave" )
nombrePECO@left <- 10000 * nombrePECO@left
listen(nombrePECO, f=22050)
</code></pre>

Ambos archivos están subidos a la raíz de esta práctica, por último le damos la vuelta y los volvemos a almacenar: 

<pre><code>
alrevesA <- revw(nombreAECO, output="Wave")
listen(alrevesA)
writeWave(alrevesA, file.path("alejandroECOalreves.wav") )

alrevesB <- revw(nombrePECO, output="Wave")
listen(alrevesB)
writeWave(alrevesB, file.path("paulaECOalreves.wav") )
</code></pre>