
# install.packages('tuneR', dep=TRUE)
# install.packages('seewave', dep=TRUE)
# install.packages('soundgen', dep=TRUE)

library(tuneR)
library(seewave)
#library(soundgen)
library(audio)

#getwd() para saber la ruta en la que estás trabajando

# establecer el path concreto en cada caso a la carpeta de trabajo
setwd("C:/Users/paaul/OneDrive/Escritorio/Curso 21-22/2cuatrimestre/Periféricos y Dispositivos de Interfaz Humana/Seminarios/Sonido/S6-varios-sonidos")


# cargar archivos de sonido (wav/mp3):
perro <- readWave('perro.wav')
perro
oveja <- readWave('oveja.wav')
oveja
gato  <- readMP3('gato.mp3')
gato

# mostrar los campos del archivo de sonido
str(oveja)
str(gato)

# calcular la duración exacta del sonido (con tres decimales)
round(length(gato@left) / gato@samp.rate, 3)


f <- gato@samp.rate    #44100

# escuchar un sonido:
listen(gato,f=f)
listen(oveja)

# mostrar la onda del sonido:
plot( extractWave(gato, from = 1, to = 393984) )


# escuchar una porción del sonido original:
listen(gato, f=f, from=6.5, to=8.9)


# cortar segmentos de un objeto “wave”:
s2 <- cutw(gato, from=6.5,to=8.9, output="Wave")
s2
plot( extractWave(s2, from = 1, to = 105841) )
listen(s2)


# añadir segmentos:
s3 <- pastew(perro, s2, output="Wave")
s3
plot( extractWave(s3, from = 1, to=265573) )
listen(s3)


# eliminar segmentos de sonido:
s4 <- deletew(s3, output="Wave", from = duration(s2), to = duration(perro))
duration(s4)
s4
plot( extractWave(s4, from = 1, to=211681) )
listen(s4)


# escribir el sonido en un archivo WAV:
writeWave(s4, file.path("snd-gato-perro.wav") )


# extraer un canal y crear un sonido mono:
sndObjLeft <- mono(gato, "left")
str(sndObjLeft)
sndObjLeft


listen(sndObjLeft,f=f)

plot( extractWave(sndObjLeft, from = 1, to = 393984) )

writeWave(sndObjLeft, file.path("tmpSndLeft.wav") )

#Cambiar frecuencia

gato8000<-resamp(s2,f=44100,g=8000, output="Wave")
gato8000
s6 <- pastew(oveja, gato8000, output="Wave")
s6
plot( extractWave(s6, from = 1, to=38965) )
listen(s6)
writeWave(s6, file.path("snd-gato-oveja.wav") )

sndF1 <- afilter(gato,f=f,threshold=50,colwave="red")
listen(sndF1,f=f)

sndF3 <- bwfilter(gato,f=f, channel=1, n=1, from=10000,
                  to=22000, bandpass=TRUE, listen = FALSE, output = "Wave")
listen(sndF3,f=f)

# Para visualizar las funciones
plot( sndF1[1:393984] , type = "l")
plot( extractWave(sndF3, from = 1, to = 393984) )

#Para aplicar los efectos de eco

hola <- readWave('hola.wav')
str(hola)
holaECO <- echo(hola,f=22050,amp=c(0.8,0.4,0.2),delay=c(1,2,3),
                output="Wave")
holaECO@left <- 10000 * holaECO@left
listen(holaECO , f= 22050)
str(holaECO)
plot( extractWave(holaECO, from = 1, to = 77959) )

#Darle la vuelta al sonido

alreves <- revw(hola, output="Wave")
listen(alreves)

