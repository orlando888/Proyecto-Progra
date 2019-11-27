void alta()
{
	FILE *archivo;
 	archivo = fopen("facturas_telf.dat", "a");
 	if(archivo == NULL)
 	{
 		printf("Error al abrir el archivo\n");
 		exit(1);
 	}
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
