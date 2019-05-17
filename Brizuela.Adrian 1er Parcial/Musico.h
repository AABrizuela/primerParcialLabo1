#ifndef MUSICO_H
#define MUSICO_H

#include "Instrumento.h"

#define MUS_LEN 51

typedef struct{

    int id;
    char nombre[51];
    char apellido[51];
    int edad;
    int idOrquesta;
    int idInstrumento;
    int isEmpty;
    char desc[51];
    char descOrq[51];

}sMusico;

int mus_init(sMusico* musLista, int MUS_CAN);
int mus_alta(sMusico* musLista, int MUS_CANT, sOrquesta* orqLista, int ORQ_CANT, sInstrumento* insLista, int INS_CANT);
int mus_getFreeSpot(sMusico* musLista, int MUS_CAN);
int mus_baja(sMusico* musLista, int MUS_CAN);
int mus_findById(sMusico* musLista, int MUS_CAN, int id);
void mus_mostrarUno(sMusico musico);
void mus_listarTodos(sMusico* musLista, int MUS_CAN);
int mus_modificacion(sMusico* musLista, int MUS_CAN);

#endif // MUSICO_H
