#ifndef ESTRUCTURAS_H

#define ESTRUCTURAS_H
   
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
};

#endif

