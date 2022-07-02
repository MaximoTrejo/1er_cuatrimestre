/*
 * arrayEmployees.c
 *
 *  Created on: 10 oct. 2021
 *      Author: maxim
 */
#include "arrayEmployees.h"
#include "utn_biblioteca.h"
//sino , no anda el NULL
#include <stdio.h>
#include <string.h>


static int dameUnIdNuevo(void);
static int obtenerApellido (char employeesLasName[]);
static int obtenerNombre (char employeesName[]);
static int obtenerSarario (float* pEmployeesSalario);
static int obtenerSector (int* pEmployeesSector);
static void mostrarItems (void);
static int selecCampoModificar (int* selectedField);

int initEmployees(Employee list[], int len)
{
	int indice;
	int flag=-1;
	//si no pasa el if , directamente devuelve error-1;
	if(list != NULL && len > 0)
		{
			flag=1;
			for(indice=0;indice < len ;indice++)
			{
				list[indice].isEmpty = VACIO;
			}
		}
	return flag;
}


int addEmployee(Employee* list)
{
	int retorno=-1;
	float auxSalary;//salario
	int auxSector;//sector
	char auxName[EMPLOYEES_NAME_LASNAME];//nombre
	char auxLasName[EMPLOYEES_NAME_LASNAME];//apellido
	if(list)
		{
			if(pedirText(auxName, 51, "\nIngrese se nombre:","\nError", 10)==0)
			{
				if(pedirText(auxLasName,51,"Ingrese su apellido:","\nError",10)==0)
				{
					if(pedirFloat(&auxSalary, "Ingrese su salario:","Error.Ingresa un sueldo menor a 30000\n",1 , 30000, 10)==0)
					{
						if(pedirInt(&auxSector, "Ingrese su sector:","\nError.Solo hay 1000 sectores",1,1000, 10)==0)
						{

							list->salary = auxSalary;
							list->sector =auxSector;
							list->id=dameUnIdNuevo();
							strncpy(list->name,auxName,sizeof(list->name));
							strncpy(list->lasName,auxLasName,sizeof(list->lasName));
							list->isEmpty=0;
							retorno=0; // todo biennnn
						}
					}

				}

			}

		}
	return retorno;
}

/* \ brief dameUnIdNuevo genera un Id.
* \ return Devuelve un numero Id
*/

static int dameUnIdNuevo(void)//privada del arcivo
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}


int findEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;
		int i;
		if(list!=NULL && len>0 && id>0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].id==id && list[i].isEmpty==OCUPADO)
				{
					retorno=i;
					break;
				}
			}
		}
	return retorno;
}


void removeEmployee(Employee* list, int len)
{
	{
		int idModificar;
		int posicion;
		//1)Mostrar listado a modificar//imprimir lista
		imprimirPantalla(list,len);
		//2)Seleccionar id a modificar
		utn_getInt(&idModificar,"\nIngrese ID\n", "Error", 1, 9999, 5);
		//3)Buscar el id
		posicion = findEmployeeById(list, len, idModificar);
		if(posicion >=  0 )
		{
			//4)
			list[posicion].isEmpty=VACIO;//baja logica//estados de baja para llevar un control
			imprimirPantalla(list,len);
		}
	}
}


void alta(Employee* list)
{
	int emptyPosicion;
	//1)en que posicion del array hay que buscar un lugar libre
	if(buscarLibreR(list , EMPLOYEES_LEN , &emptyPosicion)==1)
	{
		//2)alta (lo carga en el primer lugar donde este vacio)(en emptyPosicion se guarda el lugar vacio )
		if(addEmployee(&list[emptyPosicion])==0)
		{
			printf("Tu Id es %d\n" ,list[emptyPosicion].id);

		}
		else
		{
			printf("No se pudo crear\n");
		}
	}
	else
	{
		printf("No hay mas lugar");
	}
}


void modificarMenu(Employee* list , int len)
{
	imprimirPantalla(list,len);
	//----------------------------------------------------
	int idIngresado;
	int indexAModif;
	// 1) pedirle al usuario que ingrese un id
	if (utn_getInt(&idIngresado, "\nIngrese ID\n", "Error", 1, 9999, 5) == 0)
	{
		// 2) hacer funcion q busque por id (en donde ESTA ocupada la posicion)
		if(buscarPorId(list,len,idIngresado,&indexAModif)==1)
		{
			//3) llamar a funcion q modifica
			modificarOpciones(&list[indexAModif]);
			//4)Mostrar
			imprimirPantalla(list,len);
		}
		else
		{
			printf("No esta creado este ID \n");
		}
	}
}


int imprimirPantalla(Employee* list ,int len)
{
	int retorno=-1;
	if(list != NULL && len>=0)
	{
		for(int indice=0;indice < len ; indice++)
		{
			cli_imprimir(&list[indice]);
			retorno=0;
		}
	}
	return retorno;
}


int cli_imprimir(Employee* list)
{
	int retorno=-1;
	if(list!=NULL &&list->isEmpty==0)
	{
		retorno=0;
		printf("\nId: %d Sector: %d Nombre:%s Apellido:%s Salario: %f\n ",list->id,list->sector ,list->name, list->lasName,list->salary );
	}
	return retorno;
}


int buscarLibreR (Employee* list, int len,int *posicion)
{
	 int retorno=-1;//status
	 int i;//index
	 if(list != NULL && len>0 && posicion != NULL)
	 {
		 retorno=0;//por si el error es antes del for
		 for (i = 0;  i< len; ++i)
		 {
			if(list[i].isEmpty==VACIO)//vaacio es 1
			{
				*posicion=i;
				retorno=1;
				break;
			}
		 }
	 }
	 return retorno;
}


int buscarPorId (Employee list[], int len, int id, int* pFoundDisplayPosition)
{
	int i;
	int retorno = -1;
	if (list != NULL && len > 0 && id >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty != 1)
			{
				if (list[i].id == id)
				{
					*pFoundDisplayPosition = i;
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}


int modificarOpciones(Employee* list)
{
	int status = -1;
	int campoModificado;
	//------
	int auxSector;
	float auxSalary;
	char auxName[EMPLOYEES_NAME_LASNAME];
	char auxLasName[EMPLOYEES_NAME_LASNAME];

	if (list != NULL)
	{
		if (selecCampoModificar(&campoModificado) == 1)
		{
			status = 1;
			switch (campoModificado)
			{
				case 1:
					if (obtenerSector(&auxSector) == 1)
					{
						list->sector = auxSector;
					}
					break;
				case 2:
					if (obtenerSarario(&auxSalary) == 1)
					{
						list->salary = auxSalary;
					}
					break;
				case 3:
					if (obtenerNombre(auxName) == 1)
					{
						strncpy(list->name,auxName,EMPLOYEES_NAME_LASNAME);
					}
					break;
				case 4:
					if (obtenerApellido(auxLasName) == 1)
					{
						strncpy(list->lasName, auxLasName, EMPLOYEES_NAME_LASNAME);
					}
					break;
			}
		}
	}
	return status;
}

/*
  \ brief subMenu del menu , pide la opcion para modificar
* \ param *campoSeleccionado
* \ return status [-1]ERROR , status[1]EXITO
*/
static int selecCampoModificar (int* campoSeleccionado)
{
	int status = -1;
	int auxSelectedItem;

	mostrarItems();
	if (utn_getInt(&auxSelectedItem,"\nElegi una opcion para modificar\n","Error",1,4,2) == 0)
	{
		status = 1;
		*campoSeleccionado = auxSelectedItem;
	}
	return status;
}

/*
  \ brief Items , pide los itemspara modificar
*/
static void mostrarItems (void)
{
	printf("\n1. Sector");
	printf("\n2. Salario");
	printf("\n3. Nombre ");
	printf("\n4. Apellido");
}

/*
  \ brief obtiene el nuevo dato del sector
* \ param *pEmployeesSector
* \ return status [-1]ERROR , status[1]EXITO
*/
static int obtenerSector (int* pEmployeesSector)
{
	int status = -1;
	char mensaje[100];
	int auxSector;
	strncpy(mensaje, "\nIngrese Sector\n",sizeof(mensaje));
	if (pedirInt(&auxSector,mensaje,"Error",1,1000,2) == 0)
	{
		status = 1;
		*pEmployeesSector = auxSector;
	}
	return status;
}


/*
  \ brief obtiene el nuevo dato del salario
* \ param *pEmployeesSalario
* \ return status [-1]ERROR , status[1]EXITO
*/
static int obtenerSarario (float* pEmployeesSalario)
{
	int status = -1;
	char mensaje[100];
	float auxSalary;
	strncpy(mensaje, "\nIngresa el salary\n",sizeof(mensaje));
	if (pedirFloat(&auxSalary, mensaje, "Error", 0, 10000, 2)== 0)
	{
		status = 1;
		*pEmployeesSalario = auxSalary;
	}
	return status;
}
/*
  \ brief obtiene el nuevo dato del nombre
* \ param *pEmployeesNombre
* \ return status [-1]ERROR , status[1]EXITO
*/
static int obtenerNombre (char employeesName[])
{
	int status = -1;
	char mensaje[100];
	char auxName[51];
	strncpy(mensaje, "\nIngrese el nombre\n",sizeof(mensaje));
	if (pedirText(auxName, EMPLOYEES_NAME_LASNAME, mensaje, "Error",10) == 0)
	{
		status = 1;
		strncpy(employeesName,auxName, 51);
	}
	return status;
}
/*
  \ brief obtiene el nuevo dato del apellido
* \ param *pEmployeesApellido
* \ return status [-1]ERROR , status[1]EXITO
*/
static int obtenerApellido (char employeesLasName[])
{
	int status = -1;
	char mensaje[100];
	char auxLastName[51];
	strncpy(mensaje,"\nIngrese su apellido\n",sizeof(mensaje));
	if (pedirText(auxLastName, EMPLOYEES_NAME_LASNAME, mensaje, "Error",10) == 0)
	{
		status = 1;
		strncpy(employeesLasName, auxLastName,51);
	}
	return status;
}


void menuEmployee (Employee list[], int len)
{
	initEmployees(list,len);
	int opcion;
	do{
		if (utn_getInt(&opcion, "--------------\n1)Altas:\n2)Modificar:\n3)Baja:\n4)Informar:\nIngrese una opcion: ", "\nError opcion Invalida",  1, 4, 10)==0)
			{
			switch (opcion)
				{
					case 1:
						alta(list);
					break;
					case 2:
						modificarMenu(list , len);
					break;
					case 3:
						removeEmployee(list,len);
					break;
					case 4:
						cli_ordenarPorNormbre(list, len);
						imprimirPantalla(list,len);
						promedio(list,len);

					break;
				}
			}
	}while (opcion <= 4);
}


int cli_ordenarPorNormbre(Employee* array , int limite)
{
	int respuesta=-1;
	int flagSwap;//cambia
	int i;
	int auxiliarCmp;
	Employee buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				auxiliarCmp=strncmp(array[i].lasName,array[i+1].lasName,EMPLOYEES_NAME_LASNAME);
				if(auxiliarCmp > 0 || (auxiliarCmp == 0 && array[i].sector<array[i+1].sector))
				{
					flagSwap=1;
					buffer=array[i];
					array[i]=array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


int promedio(Employee* array , int len)
{
	int estado=-1;
	int i;
	int index;
	int cont=0;
	float acum=0;
	float promedio=0;
	int contMSueldoPromedio=0;
	if(array != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==OCUPADO)
			{
				cont++;
				acum=acum+array[i].salary;
				estado=0;
			}
		}
		promedio=acum/cont;

		for(index=0;index<len;index++)
		{
			if(array[index].salary > promedio && array[index].isEmpty==OCUPADO)
			{
				contMSueldoPromedio++;
			}
		}
		printf("\n\n1)La cantidad de empleados que tienen un salario que supera el promedio son %d" , contMSueldoPromedio);
		printf("\n2)El promedio es: %f", promedio);
		printf("\n3)El total es %f\n", acum);
	}
	return estado;
}



