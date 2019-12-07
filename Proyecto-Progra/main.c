#include <stdio.h>
#include "funciones.h"
int main()
{   
    int opcion;
	pritntf("1) Rellenar fichero de clientes \n");
	pritntf("2) Componer el mensaje de texto \n");
    pritntf("3) Formatear mensaje \n");
	pritntf("4) Introducir clave\n");
	pritntf("5) Codificar mensaje de un envío\n");
	pritntf("6) Comprobar número del envío\n");
	pritntf("7) Salir\n");
	printf ("Opción :");
	scanf("%d",&opcion);
	switch(opcion)
	{
		case(1):alta();
		        break;
		case(2):mensaje();
		        break;
		case(3):Formatear();
                break;		
		case(4):clave();
		        break;
		case(5):codificar();
	            break;		
		case(6):comprobar();
		        break;
		case(7):salir();
		        break;
	
	}
}
