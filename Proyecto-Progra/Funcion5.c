#include "Funcion5.h"

void comprobar(int *msjre)
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
	    printf("%d", msjre);
		msjre + 1;
	    fwrite(&M,sizeof(M),1,pf);
    }
 
	fclose(arch);
	fclose(pf);
}
