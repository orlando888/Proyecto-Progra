#include "Funcion2.h"

void actualizaContador(char str[])
{
	COORD coord;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		exit(-1);

    coord.X = 39;
    coord.Y = csbi.dwCursorPosition.Y-2;

    if (!SetConsoleCursorPosition(hConsole, coord))
		exit(-1);

	int longitud = strlen(str);
	printf("%3d", 160-longitud);

    coord.X = csbi.dwCursorPosition.X;
    coord.Y = csbi.dwCursorPosition.Y;

    if (!SetConsoleCursorPosition(hConsole, coord))
		exit(-1);
}

void strInput(char str[], int nchars) {
  int i = 0;
  char ch;
  while((ch = getch()) != EOF ) 
  {
	if(ch == '\b')
    {
    	str[--i] = 0;
        if(i<0) {
            i++;
            //str={'\0'}
		}
        else {
            printf("\b \b");
		}
		actualizaContador(str);	    	
  	}
	else if (ch == '\r')
	{
		break;
	}
	else 
	{
	    if (i < nchars) 
		{
	    	str[i++] = ch;
	    	printf("%c", ch);
	    }
		actualizaContador(str);	
	}
  }
  str[i] = '\0';
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
	char c,mensaje[161]={'\0'};
    int i;
     
	printf("\n\tMáximo caracteres: 160 Quedan: 160");
	printf("\n---------------------------------------------------");
	printf("\n\tTexto: ");

	strInput(comsaje.texto, 160);
    fflush(stdin);
    printf( "\n   Número del abonado: ");
    scanf( "%d", &comsaje.numdestino);
    printf( "\n   Número del empleado: ");
    scanf( "%d", &comsaje.empleado);
    fflush(stdin);
    if (strlen(comsaje.texto)<160) //&&	strlen(comsaje.empleado)<16)
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
