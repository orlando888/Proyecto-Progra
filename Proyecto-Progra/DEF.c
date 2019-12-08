#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define MAX 100
struct fichero
{
	int numero;
	char cliente[30];
	char gerente[30];
	char operador[30];
};
struct mensaje
{
	char texto[160];
	int numdestino;
	int empleado;
	time_t t;
	char fechayhora[100];
	int msjre;
};

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
	printf( "\n   Alta de Cliente");
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
void componer()
{
	FILE *archivo;
	archivo = fopen("facmensaje.dat", "a");
 	if(archivo == NULL)
 	{
 		printf("Error al abrir el archivo\n");
 		exit(1);
 	}
	struct mensaje comsaje;
	printf( "\n   Introduce texto ");
    scanf(" %[^\n]", &comsaje.texto );
    fflush(stdin);
    printf( "\n   Número del abonado: ");
    scanf( "%d", &comsaje.numdestino);
    printf( "\n   Número del empleado: ");
    scanf( "%d", &comsaje.empleado);
    fflush(stdin);
    if (strlen(&comsaje.texto)<160 && strlen(&comsaje.empleado)<16)
    {
    	printf( " Mensaje listo para el envio ");
    	fwrite(&comsaje, sizeof(struct mensaje), 1, archivo);
    	printf("%s %d ", comsaje.texto, comsaje.empleado) ;
    	fclose(archivo);
	}
	else{
		printf ("no");
		exit(1);
	}
}

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

//https://stackoverflow.com/questions/58244300/getting-the-error-undefined-reference-to-strsep-with-clang-and-mingw
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

void comprobar()
{
	FILE *arch;
    FILE *pf;
   int cont=0;
	int numaux;
	struct fichero N;
	struct mensaje M;
	arch=fopen("facliente.dat","r");
    pf=fopen("facmensaje.dat","r+");
	system("cls");
	printf("\t\t\t__________________________________\n");
	printf("\t\t\tIngrese número Destino:");
	fflush(stdin);
	scanf("%d",&numaux);
	fread(&N,sizeof(N),1,arch);
	fread(&M,sizeof(M),1,pf);
	struct tm *tm;
	M.t=time(NULL);
    tm=localtime(&M.t);
	strftime(M.fechayhora, 100, "%d/%m/%Y", tm);
	while(!feof(arch)&&(N.numero!=numaux))
	{
	  fread(&N,sizeof(N),1,arch);
    }
	  if(N.numero==numaux)
	 {
		 	while(!feof(pf)&&(M.numdestino!=numaux))
	       {
	        fread(&M,sizeof(M),1,pf);
           }
	      	if(M.numdestino==numaux)
	     	{ 
	         printf("\t\t\t ________________________________________________\n");
	         printf("\t\t\t| Empleado |  Destino   |     Fecha   | Enviado  |\n");
	         printf("\t\t\t ________________________________________________\n");
             printf("\t\t\t|     %d   |     %d     |      %s     |    Si    |\n",M.empleado,M.numdestino,M.fechayhora);
             printf("\t\t\t _______________________________________________\n");
    
            }
     }

   
    if(feof(arch)&&(M.numdestino!=N.numero))
     {
     	printf("\t\t\t _________________________________________________\n");
	    printf("\t\t\t| Empleado |  Destino   |     Fecha     | Enviado |\n");
	    printf("\t\t\t _________________________________________________\n");
	    printf("\t\t\t|     %d   |     %d     |    %s    |     NO       |\n",M.empleado,numaux,M.fechayhora);
	    printf("\t\t\t ________________________________________________\n");
	    printf("\t\t\tnúmero de empleado:");
	    fflush(stdin);
	    scanf("%d",&M.empleado);
	    cont++;
	    M.msjre=cont;
	    fwrite(&M,sizeof(M),1,pf);
    }
 
	fclose(arch);
	fclose(pf);
}
void salir()
{    

     FILE *pf;
	 pf=fopen("facmensaje.dat","r");
	 struct mensaje M;
	 int totalmsj=0;
	fread(&M,sizeof(M),1,pf);
	printf("\t\t\t _______________________\n");
    printf("\t\t\t| Empleado |  Mensajes  |\n");
	 while(!feof(pf))
	 {
	    printf("\t\t\t_______________________\n");
	    printf("\t\t\t|     %d   |     %d     |\n",M.empleado,M.msjre);
	    printf("\t\t\t|_______________________|\n");
	    totalmsj=totalmsj+M.msjre;
	    fread(&M,sizeof(M),1,pf);
	  
	 } 
	 if(feof(pf))
	 {
	 	printf("\t\t\tTotal mensajes rechazados:%d",M.msjre);
	 }

}

int main(void)
{
	setlocale(LC_ALL, "");
    int opcion;
	char key[20];
	int exito=0;
	
    do
    {   printf( "\n\t\t\tAPLICACIÓN DE MENSAJES MÓVILES \n  " );
        printf( "\n\t\t\t1)Rellenar fichero de clientes" );
        printf( "\n\t\t\t2)Componer mensaje de texto");
        printf( "\n\t\t\t3)Formatear mensaje(premium)");
        printf( "\n\t\t\t4)Introducir la clave" );
        printf( "\n\t\t\t5)Codificar mensaje" );
        printf( "\n\t\t\t6)Comprobar numero de envio" );
        printf( "\n\t\t\t7)Salir" );
        printf( "\n\t\t\tOpción: ");

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1:alta();
			       break;

            case 2:componer();
                   break;

            case 3:
            	printf("\n\t\t\tNo eres usuario premium\n");
				   break;

            case 4:clave(key);
            	   printf("\n\t\t\tLa clave es:%s",key);
            	   break;

			case 5:codificar(key);
                    break;

            case 6:	comprobar();
		        	break;
            
            
            case 7:	salir();
            
					break;
			default:
				 printf("\n\t\t\tOpción no valida¡¡¡\n");
				 break;
         }

    } while ( opcion != 7 );

    return 0;
}
