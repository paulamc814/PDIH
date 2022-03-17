//editar.bat ej
// ALT R despliega el menu
#include <stdio.h>  //en teoria no es necesario pero es para facilitar, como info de depuracion, printf...
#include <dos.h> //para poder llamar a las INT software


void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs); //llamar al nucleo del SO para que le pase el control al teclado y se pare INT 21
}

void mi_modo_video(unsigned char modo){
	union REGS inregs, outregs; 
	inregs.h.ah = 0x00; //Dar valores para cada uno de los registros, parte h = reg de tipo char (8 bits)
	inregs.h.al = modo; 
	int86(0x10,&inregs,&outregs); //INT 10 para cambiar el modo de video
	return;
}

int mi_getchar(){  //Leer de teclado
	 union REGS inregs, outregs;
	 int caracter;

	 inregs.h.ah = 1;
	 int86(0x21, &inregs, &outregs);

	 caracter = outregs.h.al;
	 return caracter;
}

void mi_putchar(char c){ //Escribir lo leido
	 union REGS inregs, outregs;

	 inregs.h.ah = 2;
	 inregs.h.dl = c;
	 int86(0x21, &inregs, &outregs);
}



/*
void gotoxy(){

}

*/
int main(){

	int tmp;
	
	printf("\nPulsa una tecla...  ");
	tmp = mi_getchar(); 

	printf("\nHas pulsado: ");
    mi_putchar((char)tmp); 
	
	mi_modo_video(1);  // modo 1 -> 40x25 (letras grandes)

	printf("\nEn C. Pulsa una tecla...  ");

   	mi_pausa(); //funcion que le pase el control al teclado para leer una pulsacion 
	
	mi_modo_video(3);  // modo 3 -> 80x25 (letras pequenas) este es el modo de video normal

	return 0;
}
