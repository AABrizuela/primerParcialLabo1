#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "Orquesta.h"
#include "hardcode.h"

#define ORQ_CANT 50
#define MUS_CANT 1000

int main()
{
    sOrquesta orqLista[ORQ_CANT];

    int optionMainMenu = 0;

    orq_init(orqLista, ORQ_CANT);

    orq_hardcode(orqLista, ORQ_CANT, 1, "Filarmonica de Londres", "Londres", 2, "Filarmonica", 1);
    orq_hardcode(orqLista, ORQ_CANT, 2, "Sinfonica de Lanus", "Lanus", 1, "Sinfonica", 1);
    orq_hardcode(orqLista, ORQ_CANT, 3, "Camara de Banfield", "Banfield", 3, "Camara", 1);

    do{

        system("cls");
        printf("*** BIENVENIDO ***\n\n");

        printf("1.- Agregar Orquesta.\n");
        printf("2.- Eliminar Orquesta.\n");
        printf("3.- Imprimir Orquestas.\n");
        printf("4.- Agregar Musico.\n");
        printf("5.- Modificar Musico.\n");
        printf("6.- Eliminar Musico.\n");
        printf("7.- Imprimir Musicos.\n");
        printf("8.- Agregar Instrumento.\n");
        printf("9.- Imprimir Instrumentos.\n");
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

                break;

            case 5:

                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
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
