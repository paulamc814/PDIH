# Seminario 4. Arduino.

**Realizado por:** Alejandro Sánchez Hens y Paula Molina Castillo

## 1. Breve introducción al seminario.

*Arduino* es una plataforma de electrónica abierta para la creación de prototipos basada en software y hardware flexibles y fáciles de usar.
La plataforma está formada por tres componentes principales que la hacen funcionar: hardware, entorno de programación y comunidad de usuarios.
El éxito y repercusión que ha tenido se debe sobre todo a varios factores: muy bajo coste del material a utilizar, facilidad de entendimiento y manejo para crear aplicaciones concretas.

## 2. Simulador UnoArduSim.

*UnoArduSim* es un programa que simula en la pantalla de nuestro ordenador una placa Arduino Uno. Nos permite utilizar LED, pulsadores, resistencias,
potenciómetros, servomotores, buses de comunicación, generador de ondas y altavoz piezoeléctrico, entre otros elementos.

## 3. Simulador TinkerCad.

*TinkerCad* Circuits permite diseñar circuitos electrónicos a través de un navegador en línea. Se pueden crear circuitos propios desde cero o modificar plantillas y otros proyectos compartidos públicamente.

## 4. Ejemplo con TinkerCad.

Vamos a hacer parpadear un LED usando una placa de prototipado. 

Así quedaría el montaje en el simulador:

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Arduino/images/EjTinkerCad.JPG" alt="update" width="500px">
</p>

Este es el código que hemos utilizado para hacerlo posibile:

~~~
// C++ code
void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Espera de 1000 milisegundos
  digitalWrite(13, LOW);
  delay(1000); // Espera de 1000 milisegundos
}
~~~


## 5. Cuestiones a resolver.

### 5.1 Primera

**Implementar en los simuladores el programa de parpadeo de LED, ampliándolo para para que encienda y apague alternativamente dos LED (uno rojo y otro verde), conectados a las salidas digitales 12 y 13 del Arduino, a un intervalo de 1.5 segundos.**

El código es el mismo para ambos simuladores:

~~~
// C++ code
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  
  delay(1500); //Esperar 1000 milisegundos
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  
  delay(1500);
}
~~~

*Simulador UnoArduSim*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Arduino/images/Ejer1(UnoArduSim).JPG" alt="update" width="500px">
</p>


*Simulador TinkerCad*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Arduino/images/Ejer1(TinkerCad).JPG" alt="update" width="500px">
</p>

*Placa de Arduino*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Arduino/images/Ejer1(Arduino).jpg" alt="update" width="500px">
</p>


### 5.2 Segunda

**Implementar en los simuladores el programa de parpadeo de LED, ampliándolo con las modificaciones necesarias para que se encienda el LED solo cuando se pulse un interruptor conectado a la entrada digital 7.**

El código es el mismo para ambos simuladores:

~~~
int interruptor = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  interruptor=digitalRead(7);
  if(interruptor==HIGH){
  	 digitalWrite(13, HIGH);
  }
  else{
  	digitalWrite(13, LOW);
  }
}
~~~
*Simulador UnoArduSim*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Arduino/images/Ejer2(UnoArduSim).JPG" alt="update" width="500px">
</p>


*Simulador TinkerCad*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Arduino/images/Ejer2(TinkerCad).JPG" alt="update" width="500px">
</p>

*Placa de Arduino*

<p align="center">
<img src="https://github.com/paulamc814/PDIH/blob/main/Seminario%20Arduino/images/Ejer2(Arduino).jpg" alt="update" width="500px">
</p>

