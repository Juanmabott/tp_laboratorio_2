/*
 Name        : TP 2
 Author      : Juan Manuel Bottaro
 Description :
 	 Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener m�s de 2000 pasajeros.
El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
n�mero de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o C�digo de vuelo
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
1-NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayPassenger� que
facilitar� el manejo de la lista de pasajeros y su modificaci�n. En la secci�n siguiente se
detallan las funciones que esta biblioteca debe tener.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int contador=0;
	int flag=1;
	int banderaInit=0;

	int id;

			ePassenger list[TAM];


			eStatusFlight estado[4]={
			{1,"en vuelo"},
			{2, "retrasado"},
			{3, "en hora"},
			{4,"por partir"}};
			eTypePassenger pasajero[3]={
			{1,"primera clase"},
			{2, "clase ejecutiva"},
			{3, "clase economica"}};

		do{
			printf("1. ALTAS\n");
			printf("2. MODIFICAR\n");
			printf("3. BAJA\n");
			printf("4. INFORMAR\n");
			printf("5. CARGA FORZADA\n");//por hacer sin punteros
			printf("6. Salir\n");
			fflush(stdin);
			scanf("%d",&opcion);

				switch(opcion)
				{
				case 1:
					if(banderaInit==0)
					{
						initPassengers(list,TAM);
						banderaInit=1;
					}

					contador=pasajeros(list,TAM,contador);
					flag=1;
					break;
				case 2:
					if(flag==1)
					{
						modificarPasajero(list, TAM);
					}
					break;
				case 3:
					if(flag==1)
					{
						 removePassenger(list,TAM);
					}
					break;
				case 4:
					//mostarListaPasajero(list,TAM);
					informar(list, TAM, pasajero,3, estado, 4);

					break;
				case 5:
					hardcodeo(list, TAM);
					break;
				case 6:
				printf("saliendo del programa...");
					break;
				default:
					printf("ingrese una opcion valida");
					break;
				}
		}while(opcion!=6);
		return 0;
}

