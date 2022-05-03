# Práctica 3. Experimentación con Arduino

**Realizada por:** Alejandro Sánchez Hens y Paula Molina Castillo

## 1. Parpadeo de 3 LEDs

El primer programa que vamos a implementar es un sencillo programa para controlar el encendido y apagado, de forma alternativa, de tres LEDs de distintos colores (rojo, amarillo y verde).

Para ello, hemos realizado primeramente el montaje del circuito en una placa de arduino.

<p align="center">
    <img src="https://github.com/AlexHens/PDIH/blob/main/practica3/images/parpadeo_3_leds_montaje.jpg" width= "400" >
</p>

Como podemos ver en la imágen anterior hemos conectado a la placa de montaje cada uno de los tres LEDs de colores distintos, cada uno de ellos con sus resistencias correspondientes y sus cables de conexión de los mismos con tierra y con su puerto correspondiente.

A continuación, vamos a ver el código fuente que hemos usado para programar el comportamiento de dicho circuito.

<pre><code>
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  
  delay(1500); 
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  
  delay(1500);
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  
  delay(1500);

}
</code></pre>

En el código anterior podemos ver como en la primera función **setup()** hemos declarado el puerto de cada uno de los puertos que hemos conectado a la placa de montaje. Mientras que en la función **loop()**, la cual es la que en realidad contiene el funcionamiento de nuestro circuito, hemos declarado una serie de pautas de encendidos y apagados de los LEDs junto con una serie de esperas para que así podamos ver como se van encendiendo y apagando cada uno de nuestros LEDs en el orden que hemos especificado.

Por último, a continuación mostramos un vídeo del correcto <a href="https://drive.google.com/file/d/1F9Hczb2fbOKzzxFIs60QOrALsla-qnca/view?usp=sharing" title="Funcionamiento Parpadeo 3 LEDs">funcionamiento</a> de dicho circuito.

## 2. Parpadeo de 3 LEDs con pulsador

El segundo programa que vamos a implementar realiza una funcionalidad similar al anterior. Su comportamiento varía en que en este caso se apagarán y encenderán alternativamente dos LEDs de distintos colores (amarillo y verde), mientras que habrá un LED rojo que siempre estará apagado, hasta que se pulse un determinado pulsador. Cuando el pulsador sea activado el LED rojo se encenderá y los otros dos LEDs se apagarán.

Para ello, hemos realizado primeramente el montaje del circuito en una placa de arduino.

<p align="center">
    <img src="https://github.com/AlexHens/PDIH/blob/main/practica3/images/parpadeo_pulsador_montaje.jpg" width= "400" >
</p>

Como podemos ver en la imágen anterior, el circuito montado es muy similar al anterior, solo que en este caso hemos añadido un pulsador conectado a la placa arduino, junto con su respectiva resistencia.

A continuación, vamos a ver el código fuente que hemos usado para programar el comportamiento de dicho circuito.

<pre><code>
int interruptor = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  interruptor=digitalRead(7);

  if (interruptor==HIGH) {
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   digitalWrite(11, LOW);
   delay(1500);
  }
  
  else if(interruptor==LOW){ 
  
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);
   digitalWrite(11, LOW);
  
   delay(1000);
  
   digitalWrite(13, LOW);
   digitalWrite(12, LOW);
   digitalWrite(11, HIGH);
  
   delay(1000);
  }
    
}
</code></pre>

Como podemos observar en el código anterior, comenzamos declarando en la función **setup()** los puertos en los que estarán conectados nuestros LEDs y nuestro pulsador. Seguidamente implementamos la función **loop()**, en la cual comenzamos leyendo el estado de nuestro pulsador. Si el pulsador está activo, se enciende el LED rojo (puerto 13) y se apagan los otros dos LEDS, y si el pulsador está desactivado, se apagará el LED rojo y se encenderán y apagarán alternativamente los otros dos LEDS (puertos 12 y 11).

Por último, a continuación mostramos un vídeo del correcto <a href="https://drive.google.com/file/d/1HEQI0gkzipFrmul8L6AAVjCe5Pc6dGAR/view?usp=sharing">funcionamiento</a> de dicho circuito.

## 3. Coche fantástico LEDs

El tercer programa tiene un funcionamiento idéntico al del primer programa, únicamente cambiamos que usaremos un LED más, es decir, usaremos 4 LEDs en esta ocasión, y todos los LEDs serán del mismo color. En resumen, nuestro programa encenderá y apagará 4 LEDs del mismo color alternativamente en un orden y en orden inverso, imitándo el juego de luces del coche fantástico.

Para ello, hemos realizado primeramente el montaje del circuito en una placa de arduino.

<p align="center">
    <img src="https://github.com/AlexHens/PDIH/blob/main/practica3/images/coche_fantastico_montaje.jpg" width= "400" >
</p>

Como podemos ver el circuito anterior es idéntico al del primer programa, solo que en este caso hemos añadido un LED más con su respectiva resistencia y además todos los LEDs son del mismo color.

A continuación, vamos a ver el código fuente que hemos usado para programar el comportamiento de dicho circuito.

<pre><code>
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  delay(500); 
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  delay(500);
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  
  delay(500);
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  
  delay(500);
    
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  
  delay(500);
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  delay(500);
}
</code></pre>

Como podemos ver en el código anterior, hemos declarado los 4 LEDs en la función **setup()** y luego hemos implementado el comportamiento de encendidos y apagados en la función **loop()**.

Por último, a continuación mostramos un vídeo del correcto <a href="https://drive.google.com/file/d/1IBF6ZwybsvYLfRg6qveaR-AGfbcxXoOK/view?usp=sharing">funcionamiento</a> de dicho circuito.

## 4. Detector de proximidad

En este último programa vamos a implementar un sensor de proximidad que nos encienda un LED cuando detecte una presencia a una cierta proximidad.

Para ello, hemos realizado primeramente el montaje del circuito en una placa de arduino.

<p align="center">
    <img src="https://github.com/AlexHens/PDIH/blob/main/practica3/images/detector_movimiento_montaje.jpg" width= "400" >
</p>

Como podemos ver en el circuito anterior, tenemos nuestro LED conectado con su respectiva resistencia a la placa de arduino. Seguidamente, podemos ver una fotoresistencia, junto con una resistencia, conectadas a la placa de arduino. Dicha fotoresistencia será la encargada de medir el nivel de luz que recibe e informarnos de que hay una presencia a cierta distancia. Esto ocurrirá gracias a que cuanta menos luz reciba la fotoresistencia significa que más cerca estará la presencia.

A continuación, vamos a ver el código fuente que hemos usado para programar el comportamiento de dicho circuito.

<pre><code>
void setup() { 
 
  pinMode(13, OUTPUT); 
  Serial.begin(9600); 
} 
 
void loop() { 
 
  int v = analogRead(A0); 
  
  if (v < 550) digitalWrite(13, HIGH);  
  else digitalWrite(13, LOW); 
  Serial.println(v); 
}
</code></pre>

Como podemos ver en el código anterior, declaramos en la función **setup()** nuestro LED, el cual nos avisará de la proximidad del objeto, y nuestra fotoresistencia. A continuación, implementamos el funcionamiento del programa en la función **loop()**, en la cual comenzamos poniendo a leer información a nuestra fotoresistencia y finalmente comprobamos si la información recibida sobre la luz captada es menor que un cierto valor, en ese caso encenderemos el LED, en otro caso el LED se apagará.

Por último, a continuación mostramos un vídeo del correcto <a href="https://drive.google.com/file/d/1yTCkouXW0Y8bEBNiZv9k78LW4QaQZZvO/view?usp=sharing">funcionamiento</a> de dicho circuito.