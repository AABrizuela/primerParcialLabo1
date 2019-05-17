#ifndef ORQUESTA_H
#define ORQUESTA_H

#define ORQ_LEN 51

typedef struct{

    char nombre[51];
    char lugar[51];
    int tipo;
    int id;
    int isEmpty;
    char desc[51];

}sOrquesta;

int orq_init(sOrquesta* orqLista, int ORQ_CANT);
int orq_alta(sOrquesta* orqLista, int ORQ_CANT);
int orq_getFreeSpot(sOrquesta* orqLista, int ORQ_CANT);
int orq_baja(sOrquesta* orqLista, int ORQ_CANT);
int orq_findById(sOrquesta* orqLista, int ORQ_CANT, int id);
void orq_mostrarUno(sOrquesta orquesta);
void orq_listarTodos(sOrquesta* orqLista, int ORQ_CANT);
//int orq_modificacion(sOrquesta* orqLista, int ORQ_CANT);

#endif // ORQUESTA_H
