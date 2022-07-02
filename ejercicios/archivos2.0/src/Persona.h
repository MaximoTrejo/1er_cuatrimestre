#ifndef PERSON_H
#define PERSON_H


typedef struct
{
    unsigned int id;
    char name[50];
    char lastName[50];
    char isEmpty;
}Persona;


#endif // PERSON_H

Persona* persona_new();
void persona_delete(Persona* this);
int persona_setId(Persona* this, unsigned int id);
int persona_getId(Persona* this);
int persona_setName(Persona* this, char* name);
char* persona_getName(Persona* this);
int persona_setLastName(Persona* this, char* lastName);
char* persona_getLastName(Persona* this);
int persona_setIsEmpty(Persona* this, unsigned int isEmpty);
int persona_getIsEmpty(Persona* this);
