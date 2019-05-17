#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#define INS_CANT 20

typedef struct{

    int id;
    char nombre[51];
    int tipo;
    int isEmpty;
    char desc[51];

}sInstrumento;

int ins_init(sInstrumento* insLista, int MUS_CANT);
int ins_alta(sInstrumento* insLista, int MUS_CANT);
int ins_getFreeSpot(sInstrumento* insLista, int MUS_CANT);
int ins_findById(sInstrumento* insLista, int MUS_CANT, int id);
void ins_mostrarUno(sInstrumento instrumento);
void ins_listarTodos(sInstrumento* insLista, int MUS_CANT);

#endif // INSTRUMENTO_H
