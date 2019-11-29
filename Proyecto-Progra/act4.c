#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
void main()
{

	setlocale (LC_ALL,"Spanish");

    char clave[20];
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
    
    if(!strcmp(clave, "Admin1234"))
        printf("\n\n\n\n\n\t\tACCESO PERMITIDO");
    else
        printf("\n\n\n\n\n\t\t**ACCESO DENEGADO**");


getch();
    return 0;
}
