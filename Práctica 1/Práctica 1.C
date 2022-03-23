//editar.bat ej
// ALT R despliega el menu
#include <stdio.h>  //en teoria no es necesario pero es para facilitar, como info de depuracion, printf...
#include <dos.h> //para poder llamar a las INT software

#define BYTE unsigned char

BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;
BYTE MODOTEXTOGRANDE =1;
BYTE COLORTEXTO =0;
BYTE COLORFONDO =7;

//Función que le pase el control al teclado para leer una pulsacion 
void mi_pausa(){
   union REGS inregs, outregs;

	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs); //llamar al nucleo del SO para que le pase el control al teclado y se pare INT 21
}

//Fija el modo de video deseado
void setvideomode(BYTE modo){
	union REGS inregs, outregs; 

	inregs.h.ah = 0x00; //Dar valores para cada uno de los registros, parte h = reg de tipo char (8 bits)
	inregs.h.al = modo; 
	int86(0x10,&inregs,&outregs); //INT 10 para cambiar el modo de video
	return;
}

//Obtiene el modo de video actual

int getvideomode(){
	int modo;
	union REGS inregs, outregs;

	inregs.h.ah = 0x0F;
	int86(0x10,&inregs,&outregs);
	modo = outregs.h.al;

	return modo;
}

//Leer de teclado
int getche(){  
	 int caracter;
	union REGS inregs, outregs;

	 inregs.h.ah = 1;
	 int86(0x21, &inregs, &outregs);

	 caracter = outregs.h.al;
	 return caracter;
}

//Escribir lo leido
void mi_putchar(char c){ 
	 union REGS inregs, outregs;

	 inregs.h.ah = 2;
	 inregs.h.dl = c;
	 int86(0x21, &inregs, &outregs);
}

// Función que coloca el cursor en una posición determinada
void gotoxy(int x, int y){
	union REGS inregs, outregs;

	inregs.h.ah = 0x02;
	inregs.h.bh = 0x00;
	inregs.h.dh = y;
	inregs.h.dl = x;

	int86(0x10,&inregs,&outregs);
}

//Función que fija el aspecto del cursor
void setcursortype(int tipo_cursor){
	union REGS inregs, outregs;

	inregs.h.ah = 0x01;
	switch(tipo_cursor){
		case 0: //invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;
		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);
}

//Modifica el color con el que se mostrarán los caracteres
void textcolor(BYTE color){
	COLORTEXTO = color;
}

//Modifica el color de fondo con el que se mostrarán los caracteres
void textbackground(BYTE fondo){
	COLORFONDO = fondo;
}

//Escribe un caracter en pantalla con el color indicado actualmente
void cputchar(unsigned char letra){
	union REGS inregs, outregs;

	inregs.h.ah = 0x09;
	inregs.h.al = letra;
	inregs.h.bl = (COLORFONDO << 4) | COLORTEXTO;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
	return;
}

//Borra toda la pantalla
void clrsc(){
	union REGS regs;

	regs.h.ah = 15; 
	int86( 0x10, &regs, &regs );
	regs.h.ah = 0; 
	int86( 0x10, &regs, &regs );
}

//Función que crea un recuadro en la posición y colores indicados
void createbox(int izq_x, int izq_y, int dcha_x, int dcha_y, BYTE color, BYTE fondo){
	int i,j;

	for(i=izq_x; i<dcha_x; i++){
		for(j=izq_y; j<dcha_y;j++){
			gotoxy(i,j);
			textcolor(color);
			textbackground(fondo);
			cputchar('*');
			printf("$");
		}
	}
}

//Función que activa el modo gráfico
void modo_grafico(){
	setvideomode(4);
}

// pone un pixel en la coordenada X,Y de color C
void pixel(int x, int y, BYTE C){
   union REGS inregs, outregs;

   inregs.x.cx = x;
   inregs.x.dx = y;
   inregs.h.al = C;
   inregs.h.ah = 0x0C;
   int86(0x10, &inregs, &outregs);
}

//Función que dibuja la pantalla utilizando la función pixel
void screendrawn(){
	int i,j;
	
	modo_grafico();
	for(i=0; i<1000; i++){
		for(j=0; j<1000; j++){
    		pixel(i,j, i%4 );
		}
	}

}

int main(){

	int tmp;
	int modo;

	printf("\nPulsa una tecla...  ");
	tmp = getche(); 

	mi_pausa();

	printf("\nHas pulsado: ");
	mi_putchar((char)tmp); 
	mi_pausa();
	
	setvideomode(MODOTEXTOGRANDE);  // modo 1 -> 40x25 (letras grandes)
	printf("\nCambio a letras grandes...  ");
	mi_pausa();  
	
 	setvideomode(MODOTEXTO);  // modo 3 -> 80x25 (letras pequenas) este es el modo de video normal
	printf("\nCambio a letras pequenias...  ");
	mi_pausa();

	clrsc();

	modo = getvideomode();
	printf("\nEl modo de video es %i\n", modo);
	mi_pausa();
	
	clrsc();

	printf("\nCursor invisible: ");
   	setcursortype(0);
   	mi_pausa();
   	printf("\nCursor grueso: ");
   	setcursortype(2);
   	mi_pausa();
   	printf("\nCursor normal: ");
   	setcursortype(1);
   	mi_pausa();

	clrsc();
	printf("\nColocar el cursor en una posicion determinada:  ");
	gotoxy(15,7);
	printf("Hola");
	mi_pausa();

	clrsc();
	mi_pausa();

	printf("\nEscribir la letra 'A' con en color magenta sobre fondo verde.\n");

	textcolor(5);
	textbackground(2);

	cputchar('A');
	mi_pausa();

	printf("\nCrea un recuadro de colores:  ");
	clrsc();

	createbox(2,3,25,15,2,5);
            
	mi_pausa();

	clrsc();

	printf("\nPor último lo vamos a pasar a modo gráfico.\n");

//	modo_grafico();

	screendrawn();

	mi_pausa();

	printf("\nPulsa cualquier tecla para terminar....");

	mi_pausa();

	return 0;
}
