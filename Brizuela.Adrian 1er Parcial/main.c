#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "hardcode.h"

#define ORQ_CANT 50
#define INS_CANT 20
#define MUS_CANT 1000

int main()
{
    sOrquesta orqLista[ORQ_CANT];
    sMusico musLista[MUS_CANT];
    sInstrumento insLista[INS_CANT];

    int optionMainMenu = 0;

    orq_init(orqLista, ORQ_CANT);

    orq_hardcode(orqLista, ORQ_CANT, 1, "Filarmonica de Gerli", "Gerli", "2", "Filarmonica", 1);
    orq_hardcode(orqLista, ORQ_CANT, 2, "Sinfonica de Lanus", "Lanus", "1", "Sinfonica", 1);
    orq_hardcode(orqLista, ORQ_CANT, 3, "Camara de Banfield", "Banfield", "3", "Camara", 1);
    mus_hardcode(musLista, MUS_CANT, 1, "Carlos", "Cardozo", "50", "1", "Filarmonica de Gerli", "1", "Piano", 1);
    mus_hardcode(musLista, MUS_CANT, 2, "Jorge", "Perez", "35", "2", "Sinfonica de Lanus", "2", "Flauta", 1);
    mus_hardcode(musLista, MUS_CANT, 3, "Martin", "Martinez", "28", "3", "Camara de Banfield", "3", "Tuba", 1);
    ins_hardcode(insLista, INS_CANT, 1, "Piano", "1", "Cuerdas", 1);
    ins_hardcode(insLista, INS_CANT, 2, "Flauta", "2", "Viento-madera", 1);
    ins_hardcode(insLista, INS_CANT, 3, "Tuba", "3", "Viento-metal", 1);
    ins_hardcode(insLista, INS_CANT, 4, "Bateria", "4", "Percusion", 1);

    do{

        system("cls");
        printf("*** BIENVENIDO ***\n\n");

        printf("ORQUESTA\n");
        printf("\t1.- Agregar Orquesta.\n");
        printf("\t2.- Eliminar Orquesta.\n");
        printf("\t3.- Imprimir Orquestas.\n");
        printf("MUSICO\n");
        printf("\t4.- Agregar Musico.\n");
        printf("\t5.- Modificar Musico.\n");
        printf("\t6.- Eliminar Musico.\n");
        printf("\t7.- Imprimir Musicos.\n");
        printf("INSTRUMENTO\n");
        printf("\t8.- Agregar Instrumento.\n");
        printf("\t9.- Imprimir Instrumentos.\n\n");
        printf("10.- Salir.\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &optionMainMenu);
        printf("\n");

        switch(optionMainMenu){

            case 1:
                orq_alta(orqLista, ORQ_CANT);
                break;

            case 2:
                orq_baja(orqLista, ORQ_CANT);
                break;

            case 3:
                orq_listarTodos(orqLista, ORQ_CANT);
                system("pause");
                break;

            case 4:
                mus_alta(musLista, MUS_CANT, orqLista, ORQ_CANT, insLista, INS_CANT);
                break;

            case 5:
                mus_modificacion(musLista, MUS_CANT, orqLista, ORQ_CANT);
                break;

            case 6:
                mus_baja(musLista, MUS_CANT);
                break;

            case 7:
                mus_listarTodos(musLista, MUS_CANT);
                system("pause");
                break;

            case 8:
                ins_alta(insLista, INS_CANT);
                break;

            case 9:
                ins_listarTodos(insLista, MUS_CANT);
                system("pause");
                break;

            case 10:
                printf("Hasta luego!\n");
                break;

            default:
                printf("Error. Las opciones correctas van del 1 al 10. ");
                fflush(stdin);
                system("pause");
                break;
        }

    }while(optionMainMenu!=10);

    return 0;
}
