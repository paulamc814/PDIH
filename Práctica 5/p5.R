# install.packages('tuneR', dep=TRUE)
# install.packages('seewave', dep=TRUE)
# install.packages('soundgen', dep=TRUE)

library(tuneR)
library(seewave)
#library(soundgen)
library(audio)

#getwd() para saber la ruta en la que estás trabajando

# establecer el path concreto en cada caso a la carpeta de trabajo
setwd("C:/Users/paaul/OneDrive/Escritorio/Curso 21-22/2cuatrimestre/Periféricos y Dispositivos de Interfaz Humana/Prácticas/P5")


# cargar archivos de sonido (wav/mp3):
nombreA <- readWave('nombreA.wav')
nombreA
nombreP <- readWave('nombreP.wav')
nombreP
apellidoA <- readWave('apellidoA.wav')
apellidoA
apellidoP <- readWave('apellidoP.wav')
apellidoP

#mostrar los campos del archivo de sonido y su cabecera
str(nombreA)
str(nombreP)
str(apellidoA)
str(apellidoP)

#mostrar la onda del sonido:
plot( extractWave(nombreA, from = 1, to = 393984) )
plot( extractWave(nombreP, from = 1, to = 393984) )
plot( extractWave(apellidoA, from = 1, to = 393984) )
plot( extractWave(apellidoP, from = 1, to = 393984) )


# calcular la duración exacta del sonido (con tres decimales)
round(length(nombreA@left) / nombreA@samp.rate, 3)
round(length(nombreP@left) / nombreP@samp.rate, 3)


f <- nombreA@samp.rate 
f <- nombreP@samp.rate

# escuchar un sonido:
listen(nombreA,f=f)
listen(nombreP,f=f)

# añadir segmentos:
s1 <- pastew(apellidoA, nombreA, output="Wave")
s1
plot( extractWave(s1, from = 1, to=265573) )
listen(s1)

s2 <- pastew(apellidoP, nombreP, output="Wave")
s2
plot( extractWave(s2, from = 1, to=265573) )
listen(s2)

# eliminar frecuencia
  
f1 <- bwfilter(s1, f=f, channel=1, n=1, from=5000, to=10000, bandpass = TRUE, listen = FALSE, output = "Wave")
listen(f1, f=f)

f2 <- bwfilter(s2, f=f, channel=1, n=1, from=5000, to=10000, bandpass = TRUE, listen = FALSE, output = "Wave")
listen(f2, f=f)

# escribir el sonido en un archivo WAV:
writeWave(s1, file.path("mezcla1.wav") )
writeWave(s2, file.path("mezcla2.wav") )

# aplicar efectos de eco
nombreAECO <- echo(nombreA,f=22050, amp=c(0.8, 0.4, 0.2), delay = c(1,2,3), output="Wave" )
nombreAECO@left <- 10000 * nombreAECO@left
listen(nombreAECO, f=22050)

writeWave(nombreAECO, file.path("alejandroECO.wav") )

nombrePECO <- echo(nombreP,f=22050, amp=c(0.8, 0.4, 0.2), delay = c(1,2,3), output="Wave" )
nombrePECO@left <- 10000 * nombrePECO@left
listen(nombrePECO, f=22050)

writeWave(nombrePECO, file.path("paulaECO.wav") )

# poner el sonido del revés

alrevesA <- revw(nombreAECO, output="Wave")
listen(alrevesA)
writeWave(alrevesA, file.path("alejandroECOalreves.wav") )

alrevesB <- revw(nombrePECO, output="Wave")
listen(alrevesB)
writeWave(alrevesB, file.path("paulaECOalreves.wav") )