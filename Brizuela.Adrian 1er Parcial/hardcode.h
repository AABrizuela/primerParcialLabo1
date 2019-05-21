#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"

void orq_hardcode(sOrquesta* orqLista, int ORQ_CANT, int auxId, char* auxNombre, char* auxLugar, char* auxTipo, char* auxDesc, int auxIsEmpty);
void mus_hardcode(sMusico* musLista, int MUS_CANT, int auxId, char* auxNombre, char* auxApellido, char* auxEdad, char* auxIdOrquesta, char* auxDescOrq, char* auxIdInstrumento, char* auxDescIns, int auxIsEmpty);
void ins_hardcode(sInstrumento* insLista, int INS_CANT, int auxId, char* auxNombre, char* auxTipo, char* auxDesc, int auxIsEmpty);
/*void hardcodeActores(sActores* arrayActores, int capacidad, int id, char auxNombre[], char auxNacionalidad[], int datoOcupado);*/
