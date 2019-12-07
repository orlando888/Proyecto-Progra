#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <locale.h>
#include"funciones.h"
void alta()
{
	FILE *archivo;
 	archivo = fopen("facturas_telf.dat", "ab");
 
	struct factura registro;
	printf( "\n   Alta de factura");
    printf( "\n   Número del abonado:");
    scanf( "%d", &registro.num_abo );
    fflush(stdin);
    printf( "\n   Nombre:");
	scanf("%s", &registro.nombre);
    fflush(stdin);
    printf( "\n   valor de factura:");
    scanf( "%f", &registro.valor_fact );
    fflush(stdin);

	fwrite(&registro, sizeof(struct factura), 1, archivo);
    fclose(archivo);
}
