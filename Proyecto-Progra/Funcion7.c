#include "Funcion7.h"

void salir(int *msjre)
{    

     FILE *pf;
	 pf=fopen("facmensaje.dat","r");
	 struct mensaje resu;
	 int totalmsj=0;
	fread(&resu,sizeof(resu),1,pf);
	printf("\t\t\t _______________________\n");
    printf("\t\t\t| Empleado |  Mensajes  |\n");
	 while(!feof(pf))
	 {
	    printf("\t\t\t_______________________\n");
	    printf("\t\t\t|     %d   |     %d     |\n",resu.empleado,msjre);
	    printf("\t\t\t|_______________________|\n");
	    totalmsj=totalmsj+*msjre;  //Cambio msjre por *msjre
	    fread(&resu,sizeof(resu),1,pf);
	  
	 } 
	 if(feof(pf))
	 {
	 	printf("\t\t\tTotal mensajes rechazados:%d",msjre);
	 }

}
