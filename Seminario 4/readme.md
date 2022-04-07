# Seminario 4. Módulos cargables del kernel(LKM)

**Realizado por:** Alejandro Sánchez Hens y Paula Molina Castillo

## 1. Breve introducción al seminario.

En este seminario nos encargaremos de realizar una serie de cambios en un módulo cargable de nuestro kernel, cuyo código nos será facilitado previamente.

Los módulos cargables del kernel nos permitirán añadir o eliminar código del kernel en tiempo de ejecución, esto nos puede servir para dar soporte a nuevos periféricos o sistemas de archivos.

Dichos módulos se cargan en tiempo de ejecución y no se cargan en el espacio del usuario, sino en el espacio del kernel, ya que forman parte del mismo.

El código que usaremos para añadir un nuevo módulo al kernel es muy sencillo y no realiza ninguna configuración específica ni operaciones complejas. Simplemente nos muestra un mensaje por pantalla para verificarnos que el módulo se ha cargado y cuando terminemos nos mostrará otro mensaje informándonos de que la ejecución ha terminado.

## 2. Pasos para preparar el sistema.

Para desarrollar módulos cargables del kernel nuestro sistema operativo tiene que estar preparado. Para ello seguiremos los siguientes pasos:

~~~
sudo apt-get update
sudo apt-cache search linux-headers-$(uname -r)
sudo apt-get install linux-headores-$(uname -r)
~~~

<p align="center">
<img src="https://github.com/AlexHens/PDIH/blob/main/seminario%204/images/update-s4.jpg" alt="update" width="500px">
</p>

<p align="center">
<img src="https://github.com/AlexHens/PDIH/blob/main/seminario%204/images/search-install-s4.jpg" alt="search and install" width="500px">
</p>

Con estas órdenes del terminal lo que hacemos es buscar e instalar las cabeceras del kernel que necesitaremos para empezar a trabajar con los LKM's.

Se recomienda realizar todo este procedimiento, además de las pruebas, en una máquina virtual y no en nuestra máquina Linux, ya que es relativamente sencillo bloquear o dañar el núcleo del sistema.

## 3. Explicación del código.

En esta sección procederemos a explicar el código detalladamente.

Comenzaremos con la inclusión de las librerías necesarias para empezar a construir el módulo cargable del kernel y poder hacer uso de sus funciones.

~~~
#include <linux/init.h>             
#include <linux/module.h>           
#include <linux/kernel.h>           
~~~

A continuación, configuraremos una serie de variables del módulo que nos ayudarán a identificarlo correctamente, tales como el autor del mismo, el tipo de licencia, una breve descripción del módulo, la versión y el nombre del mismo.

~~~
MODULE_LICENSE("GPL");              
MODULE_AUTHOR("Alejandro Sánchez Hens y Paula Molina Castillo");      
MODULE_DESCRIPTION("Un simple controlador de Linux para la BBB.");  
MODULE_VERSION("0.1");          

static char *name = "mundo";      
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log"); 
~~~

Después de esta configuración, tenemos dos funciones que son obligatorias para el uso de nuestro LKM. Dichas funciones son las funciones de inicio y de salida.

Comenzaremos con la función de inicio del módulo. Dicha función, en este caso, mostrará un mensaje por pantalla en los registros del núcleo cuando se ejecute. Cuando se conecte el dispositivo correspondiente se ejecutará dicha función y podremos ver el mensaje por pantalla al acceder a los registros del núcleo.

~~~
static int __init helloBBB_init(void){
   printk(KERN_INFO "EBB: Hola %s desde las BBB LKM!\n", name);
   return 0;
}
~~~

Después, tenemos la función de salida de salida del módulo, la cual, en este caso, actúa de una forma similar a la función anterior, es decir, nos mostrará en los registros del núcleo un mensaje determinado. La diferencia es que está función se ejecutará para finalizar el uso de dicho módulo, es decir, se ejecutará cuando se desconecte el dispositivo determinado y podremos ver el mensaje de despedida en los registros del núcleo.

~~~
static void __exit helloBBB_exit(void){
   printk(KERN_INFO "EBB: Adiós %s desde las BBB LKM!\n", name);
}
~~~

Por último, tenemos las llamadas a las funciones anteriores para que se ejecuten cuando se llame al módulo que hemos creado.

Cabe destacar que a la hora de programar un LKM, como es este caso, no podemos depurarlo, es decir, programamos a ciegas.

~~~
module_init(helloBBB_init);
module_exit(helloBBB_exit);
~~~

## 4. Instrucciones para compilación 

Para compilar el módulo anterior haremos uso del Makefile siguiente.

~~~
obj-m+=hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
~~~
<p align="center">
<img src="https://github.com/AlexHens/PDIH/blob/main/seminario%204/images/makefile-s4.jpg" alt="makefile" width="500px">
</p>

Como resultado del Makefile obtenemos un archivo con extensión .ko.

<p align="center">
<img src="https://github.com/AlexHens/PDIH/blob/main/seminario%204/images/lista-makefile-s4.jpg" alt="lista makefile" width="500px">
</p>

## 5. Prueba del módulo LKM

Una vez compilado, procedemos a probar nuestro módulo LKM. Para ello, primero debemos insertar dicho módulo en el kernel usando el siguiente comando.

~~~
sudo ismod hello.ko
~~~

Para comprobar que está cargado procedemos a listar los módulos cargados del kernel con el siguiente comando.

~~~
lsmod
~~~

Como resultado obtenemos lo siguiente.

<p align="center">
<img src="https://github.com/AlexHens/PDIH/blob/main/seminario%204/images/cargar-listar-modulos-s4.jpg" alt="cargar y listar modulos" width="500px">
</p>

Como podemos ver, nos aparece al principio nuestro módulo.

A continuación, solicitamos información de dicho módulo con el siguiente comando.

~~~
modinfo hello.ko
~~~

Y vemos que su información coincide con la que introducimos en el código, en concreto en los parámetros que configuramos al principio.

<p align="center">
<img src="https://github.com/AlexHens/PDIH/blob/main/seminario%204/images/modinfo-s4.jpg" alt="modinfo" width="500px">
</p>

Para finalizar, eliminamos el módulo del kernel con el siguiente comando.

~~~
sudo rmmod hello.ko
~~~

Y procedemos a listar los 10 últimos mensajes del registro del kernel para asegurarnos que se ha ejecutado correctamente nuestro módulo.

<p align="center">
<img src="https://github.com/AlexHens/PDIH/blob/main/seminario%204/images/logs-s4.jpg" alt="logs" width="500px">
</p>
