#define REINTENTOS 5
#define TAM 500


int controller_cargarArchivoDesdeTexto(char* path , LinkedList* pArrayList);

int controller_listar(LinkedList* pArrayList);

int controller_asignarPromedio(LinkedList* pArrayList);

LinkedList * controller_filtrar(LinkedList *pArrayList , LinkedList * pAuxArrayList );

int controller_guardarModoTexto(char* path , LinkedList* pArrayList);

int controller_sortPassenger(LinkedList* pArrayList);
