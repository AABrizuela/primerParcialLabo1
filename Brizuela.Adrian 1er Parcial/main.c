#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "hardcode.h"
#include "utn.h"
#include "informes.h"


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

    orq_hardcode(orqLista, ORQ_CANT, 1, "Orquesta1", "Lugar1", "1", "");
    orq_hardcode(orqLista, ORQ_CANT, 2, "Orquesta2", "Lugar1", "2", "");
    orq_hardcode(orqLista, ORQ_CANT, 3, "Orquesta3", "Lugar2", "3", "");
    orq_hardcode(orqLista, ORQ_CANT, 4, "Orquesta4", "Lugar3", "2", "");

    mus_hardcode(insLista, INS_CANT, orqLista, ORQ_CANT, musLista, MUS_CANT, 1, "Mus1", "AMus1", "30", "1", "", "2", "");
    mus_hardcode(insLista, INS_CANT, orqLista, ORQ_CANT, musLista, MUS_CANT, 2, "Mus2", "AMus2", "20", "2", "", "5", "");
    mus_hardcode(insLista, INS_CANT, orqLista, ORQ_CANT, musLista, MUS_CANT, 3, "Mus3", "AMus3", "25", "4", "", "2", "");
    mus_hardcode(insLista, INS_CANT, orqLista, ORQ_CANT, musLista, MUS_CANT, 4, "Mus4", "AMus4", "27", "4", "", "1", "");
    mus_hardcode(insLista, INS_CANT, orqLista, ORQ_CANT, musLista, MUS_CANT, 5, "Mus5", "AMus5", "22", "1", "", "3", "");
    mus_hardcode(insLista, INS_CANT, orqLista, ORQ_CANT, musLista, MUS_CANT, 6, "Mus6", "AMus6", "35", "3", "", "4", "");

    ins_hardcode(insLista, INS_CANT, 1, "Inst1", "1", "");
    ins_hardcode(insLista, INS_CANT, 2, "Inst2", "2", "");
    ins_hardcode(insLista, INS_CANT, 3, "Inst3", "2", "");
    ins_hardcode(insLista, INS_CANT, 4, "Inst4", "3", "");
    ins_hardcode(insLista, INS_CANT, 5, "Inst5", "4", "");

    do
    {

        system("clear");
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
        printf("10.- INFORMES\n");
        printf("11.- Salir.\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &optionMainMenu);
        printf("\n");

        switch(optionMainMenu)
        {

        case 1:
            orq_alta(orqLista, ORQ_CANT);
            break;

        case 2:
            orq_baja(orqLista, ORQ_CANT);
            break;

        case 3:
            orq_listarTodos(orqLista, ORQ_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
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
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 8:
            ins_alta(insLista, INS_CANT);
            break;

        case 9:
            ins_listarTodos(insLista, MUS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 10:
            inf_subMenu(orqLista, ORQ_CANT, musLista, MUS_CANT, insLista, INS_CANT);
            break;

        case 11:
            printf("Hasta luego!\n");
            break;

        default:
            printf("Error. Las opciones correctas van del 1 al 11. ");
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;
        }

    }
    while(optionMainMenu!=11);

    return 0;
}
