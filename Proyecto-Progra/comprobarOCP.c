void comprobar()
{
	FILE *arch;
    FILE *pf;
	int num;
	int numaux;
	struct fichero N;
	struct mensaje M;
	arch=fopen("facliente.dat","r");
    pf=fopen("facmensaje.dat","r");
	system("cls");
	printf("\t\t\t__________________________________\n");
	printf("\t\t\tIngrese número cliente:");
	fflush(stdin);
	scanf("%d",&num);
	printf("\t\t\tIngrese número Destino:");
	fflush(stdin);
	scanf("%d",&numaux);
	fread(&N,sizeof(N),1,arch);
	fread(&M,sizeof(M),1,pf);
	while(!feof(arch)&&(N.numero!=num))
	{
	  fread(&N,sizeof(N),1,arch);
	} 
	 if(N.numero==num)
	{
		 	while(!feof(pf)&&(M.numdestino!=num))
	       {
	        fread(&M,sizeof(M),1,pf);
           } 
	      	if(M.numdestino==num)
	     	{ 
	         printf("\t\t\t ____________________________________________\n");
	         printf("\t\t\t| Empleado |  Destino   | Fecha   | Enviado  |\n");
	         printf("\t\t\t ____________________________________________\n");
             printf("\t\t\t|     %d   |     %d     |   % s   |    Si    |\n",M.empleado,M.numdestino,M.fecha);
             printf("\t\t\t ____________________________________________\n");
            }
     }
    if(feof(arch)&&(N.numero!=M.numdestino))
     {
     	printf("\t\t\t ____________________________________________\n");
	    printf("\t\t\t| Empleado |  Destino   | Fecha   | Enviado  |\n");
	    printf("\t\t\t ____________________________________________\n");
	    printf("\t\t\t|     %d   |     %d     |   % s   |   NO     |\n",M.empleado,M.numdestino,M.fecha);
	    printf("\t\t\t ____________________________________________\n");
    }
     	
	fclose(arch);
	fclose(pf);
}
