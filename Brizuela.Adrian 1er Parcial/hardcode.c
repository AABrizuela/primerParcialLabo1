#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "hardcode.h"
#include "utn.h"

void orq_hardcode(sOrquesta* orqLista, int ORQ_CANT, int auxId, char* auxNombre, char* auxLugar, int auxTipo, char* auxDesc, int auxIsEmpty)
{
    int index = orq_getFreeSpot(orqLista, ORQ_CANT);
    orqLista[index].id = auxId;
    strcpy(orqLista[index].nombre, auxNombre);
    strcpy(orqLista[index].lugar, auxLugar);
    orqLista[index].tipo = auxTipo;
    strcpy(orqLista[index].desc, auxDesc);
    orqLista[index].isEmpty = 1;

}

void mus_hardcode(sMusico* musLista, int MUS_CANT, int auxId, char* auxNombre, char* auxApellido, int auxEdad, int auxIdOrquesta, int auxIdInstrumento, int auxIsEmpty){

    int index = mus_getFreeSpot(musLista, MUS_CANT);

}

/*void hardcodeActores(sActores* arrayActores, int capacidad, int id, char auxNombre[], char auxNacionalidad[], int datoOcupado)
{
    int index = buscarLibreActores(arrayActores, capacidad);
    arrayActores[index].id= id;
    strcpy(arrayActores[index].nombre, auxNombre);
    strcpy(arrayActores[index].nacionalidad, auxNacionalidad);
    arrayActores[index].datoOcupado = OCUPADO;

}*/
