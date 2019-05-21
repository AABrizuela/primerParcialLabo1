#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "hardcode.h"
#include "utn.h"

void orq_hardcode(sOrquesta* orqLista, int ORQ_CANT, int auxId, char* auxNombre, char* auxLugar, char* auxTipo, char* auxDesc, int auxIsEmpty)
{
    int index = orq_getFreeSpot(orqLista, ORQ_CANT);

    orqLista[index].id = auxId;
    strncpy(orqLista[index].nombre, auxNombre, ORQ_LEN);
    strncpy(orqLista[index].lugar, auxLugar, ORQ_LEN);
    strncpy(orqLista[index].tipo, auxTipo, 2);
    strncpy(orqLista[index].desc, auxDesc, ORQ_LEN);
    orqLista[index].isEmpty = 1;

}

void mus_hardcode(sMusico* musLista, int MUS_CANT, int auxId, char* auxNombre, char* auxApellido, char* auxEdad, char* auxIdOrquesta, char* auxDescOrq, char* auxIdInstrumento, char* auxDescIns, int auxIsEmpty)
{

    int index = mus_getFreeSpot(musLista, MUS_CANT);

    musLista[index].id = auxId;
    strncpy(musLista[index].nombre, auxNombre, MUS_LEN);
    strncpy(musLista[index].apellido, auxApellido, MUS_LEN);
    strncpy(musLista[index].descIns, auxDescIns, MUS_LEN);
    strncpy(musLista[index].descOrq, auxDescOrq, MUS_LEN);
    strncpy(musLista[index].edad, auxEdad, MUS_LEN);
    strncpy(musLista[index].idOrquesta, auxIdOrquesta, MUS_LEN);
    strncpy(musLista[index].idInstrumento, auxIdInstrumento, MUS_LEN);
    musLista[index].isEmpty = 1;

}

void ins_hardcode(sInstrumento* insLista, int INS_CANT, int auxId, char* auxNombre, char* auxTipo, char* auxDesc, int auxIsEmpty){

    int index = ins_getFreeSpot(insLista, INS_CANT);

    insLista[index].id = auxId;
    strncpy(insLista[index].nombre, auxNombre, INS_LEN);
    strncpy(insLista[index].tipo, auxTipo, INS_LEN);
    strncpy(insLista[index].desc, auxDesc, INS_LEN);
    insLista[index].isEmpty = 1;

}
