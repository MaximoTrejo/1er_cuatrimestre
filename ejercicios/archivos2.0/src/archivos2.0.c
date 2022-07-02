/*
 ============================================================================
 Name        : 0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

#define CANTIDAD 300

int main()
{
    char name[500], lastName[500], id[500], isEmpty[500];
    int i; //,cantidad;

    Persona* array[CANTIDAD];
    FILE * pFile;

    /*
    0X001 0X100 hasta 0X204 0
    0X002 0X500 hasta 0X604 1
    0X003 0X780 2
    array == &array[0] == 0X001
    */

    pFile = fopen("data.txt", "w");

    i = 0;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

    while(!feof(pFile)){
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

        array[i] = persona_new();
        persona_setId(array[i], atoi(id));
        persona_setName(array[i],name);
        persona_setLastName(array[i],lastName);


        if(strcmp(isEmpty,"true") == 0){ //compara si isempty es true
            persona_setIsEmpty(array[i],1);
        }else{
            persona_setIsEmpty(array[i],0);
        }

        i++;
    }
/*
    printf("ID\tName\tLast\tName\n");
    for (i=0; i<CANTIDAD; i++)
    {
        if(persona_getIsEmpty(array[i]) == 0)
            printf("%4d\t%-15s\t%15s\n" ,
               persona_getId(array[i]),
               persona_getName(array[i]),
               persona_getLastName(array[i]));

    }
*/
    fclose(pFile);

    return 0;
}
