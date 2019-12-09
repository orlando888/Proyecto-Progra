#include "DEF.h"

#define MAX 160

int main(void)
{
	setlocale(LC_ALL, "");
    int opcion;
	char key[20];
	int *msjre;
	
    do
    {
        printf( "\n   1. Rellenar fichero de clientes" );
        printf( "\n   2. Componer mensaje de texto");
        printf( "\n   3. Formatear mensaje");
        printf( "\n   4. Introducir la clave" );
        printf( "\n   5. Codificar mensaje" );
        printf( "\n   6. Comprobar numero de envio" );
        printf( "\n   7. Salir" );
        printf( "\n\n   Opción (1-7): ");

         scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: 
				   alta();
			       break;

            case 2:componer();
                   break;

            case 3:
            	   printf("\n\t\t\tNo eres usuario premium\n");
				   break;

            case 4:
				   clave(key);
            	   printf("\n\t\t\tLa clave es:%s",key);
            	   break;

			case 5:codificar(key);
                   break;

            case 6:comprobar(msjre);
		           break;

            case 7:salir(msjre);
            	   break;

			default:
				   printf("\n\t\t\tOpción no valida¡¡¡\n");
				   break;
         }

    } while ( opcion != 7 );

    return 0;
}
