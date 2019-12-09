#include "Funcion1.h" 

void alta()
{
	FILE *archivo;
	archivo = fopen("facliente.dat", "a");
 	if(archivo == NULL)
 	{
 		printf("Error al abrir el archivo\n");
 		exit(1);
 	}
	struct fichero registro;
	printf( "\n   Alta de factura");
    printf( "\n Nombre Cliente:");
	scanf(" %[^\n]", &registro.cliente);
    fflush(stdin);
    printf( "\n   Gerente:");
	scanf(" %[^\n]", &registro.gerente);
    fflush(stdin);
    printf( "\n   Número del abonado:");
    scanf( "%d", &registro.numero);
    fflush(stdin);
    printf( "\n   Operador:");
	scanf(" %[^\n]", &registro.operador);
    fflush(stdin);
	fwrite(&registro, sizeof(struct fichero), 1, archivo);
	printf("%d %s %s %s ", registro.numero, registro.cliente,registro.gerente, registro.operador ) ;
	fclose(archivo);
}
