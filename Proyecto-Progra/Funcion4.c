#include "Funcion4.h"

void clave(char *clave)
{
    printf("  Introducción de la clave \n");
    printf("------------------------------------ \n\n");
    int conta=0;
    int i=0;
    printf("Clave : ");
    while(clave[i]!=13)
    {
        clave[i]=getch();
        if(clave[i]>32 && i<20)
        {
	        putchar('*');
	        i++;
        }
        else if(clave[i]==8 && i>0)
        {
            putchar(8);
            putchar(' ');
            putchar(8);
            i--;  
        }
    }

    clave[i]='\0';	
}

void codifica_palabra(char *palabra, char *clave)
{
	int i;

	printf("\nTexto a codificar: %s", palabra);
	printf("\n%-24s","Caracteres del texto:");
	for(i = 0; i<strlen(palabra); i++) 
		printf("%4c", palabra[i]);
	printf("\n%-24s","Codigos ASCII:");
	for(i = 0; i<strlen(palabra); i++) 
		printf("%4d", palabra[i]);
	printf("\n%-24s","Contraseña:");
	for(i = 0; i<strlen(palabra); i++)
		printf("%4c", clave[i%strlen(clave)]);
	printf("\n%-24s","Codigos ASCII:");
	for(i = 0; i<strlen(palabra); i++)
		printf("%4d", clave[i%strlen(clave)]);
	printf("\n%-24s","Suma de Codigos ASCII:");
	for(i = 0; i<strlen(palabra); i++)
		printf("%4d", palabra[i]+clave[i%strlen(clave)]);
	printf("\n%-24s","En caracteres:");
	for(i = 0; i<strlen(palabra); i++)
	{
		printf("%4c", palabra[i]+clave[i%strlen(clave)]);
		palabra[i]=palabra[i]+clave[i%strlen(clave)];
	}
}

char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}

void codificar(char *clave)
{	
	char *palabra, *nuevaPalabra, *string;
	fpos_t posicion, posicion2;
	int i, n, j;
	struct mensaje codigo;
	FILE *archivo;

	archivo = fopen("facmensaje.dat", "r+");
	if(archivo == NULL)
	{
 		printf("Error al abrir el archivo\n");
		exit(1);
	}

	printf( "\nNúmero del abonado:");
	scanf( "%d", &n);
	fgetpos(archivo, &posicion);
	
	while(fread(&codigo, sizeof(struct mensaje), 1, archivo))
	{
		if (n==codigo.empleado)
		{
			string = strdup(codigo.texto);
			codigo.texto[0]='\0';
  			while ((palabra = strsep(&string," ,.")) != NULL)
			{
				codifica_palabra(palabra, clave);
				strcat(codigo.texto, palabra);
			}
            posicion2=ftell(archivo);
   	        fsetpos(archivo, &posicion);
    	    printf("\nResultado:%d",fwrite(&codigo, sizeof(struct mensaje), 1, archivo));
			fsetpos(archivo, &posicion2);
        	j=1;
		}
		else fgetpos(archivo, &posicion);
	}
	if (j==0)
		printf("\nAbonado no registrado");

  	fclose(archivo);
}
