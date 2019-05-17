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
    strncpy(orqLista[index].nombre, auxNombre, ORQ_LEN);
    strncpy(orqLista[index].lugar, auxLugar, ORQ_LEN);
    orqLista[index].tipo = auxTipo;
    strncpy(orqLista[index].desc, auxDesc, ORQ_LEN);
    orqLista[index].isEmpty = 1;

}

void mus_hardcode(sMusico* musLista, int MUS_CANT, int auxId, char* auxNombre, char* auxApellido, int auxEdad, int auxIdOrquesta, int auxIdInstrumento, int auxIsEmpty)
{

    int index = mus_getFreeSpot(musLista, MUS_CANT);

    musLista[index].id = auxId;
    strncpy(musLista[index].nombre, auxNombre, MUS_LEN);
    strncpy(musLista[index].apellido, auxApellido, MUS_LEN);
    musLista[index].edad = auxEdad;
    musLista[index].idOrquesta = auxIdOrquesta;
    musLista[index].idInstrumento = auxIdInstrumento;
    musLista[index].isEmpty = 1;

}

void ins_hardcode(sInstrumento* insLista, int INS_CANT, int auxId, char* auxNombre, int auxTipo, char* auxDesc, int auxIsEmpty){

    int index = ins_getFreeSpot(insLista, INS_CANT);

    insLista[index].id = auxId;
    strncpy(insLista[index].nombre, auxNombre, INS_LEN);
    insLista[index].tipo = auxTipo;
    strncpy(insLista[index].desc, auxDesc, INS_LEN);

}

/*void hardcodeActores(sActores* arrayActores, int capacidad, int id, char auxNombre[], char auxNacionalidad[], int datoOcupado)
{
    int index = buscarLibreActores(arrayActores, capacidad);
    arrayActores[index].id= id;
    strcpy(arrayActores[index].nombre, auxNombre);
    strcpy(arrayActores[index].nacionalidad, auxNacionalidad);
    arrayActores[index].datoOcupado = OCUPADO;

}*/
