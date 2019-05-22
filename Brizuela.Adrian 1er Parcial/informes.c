#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "hardcode.h"
#include "utn.h"
#include "informes.h"

void inf_subMenu(sOrquesta* orqLista, int ORQ_CANT, sMusico* musLista, int MUS_CANT, sInstrumento* insLista, int INS_CANT)
{
    int optionSubMenu = 0;

    do
    {
        system("clear");
        printf("*** BIENVENIDO ***\n\n");

        printf("\t1.- Listar las orquestas de un lugar en particular ingresado por el usuario.\n");
        printf("\t2.- Listar los musicos de menos de 25 anios.\n");
        printf("\t3.- Listar las orquestas con menos de 6 musicos.\n");
        printf("\t4.- Listar todos los instrumentos de una orquesta determinada (por ID).\n");
        printf("\t5.- Listar orquestas completas.\n");
        printf("\t6.- Listar la orquesta con menos musicos.\n");
        printf("\t7.- Listar el promedio de instrumentos por orquesta.\n");
        printf("\t8.- Listar musicos que NO toquen instrumentos de viento.\n");
        printf("\t9.- Volver.\n\n");


        printf("Ingrese opcion: ");
        scanf("%d", &optionSubMenu);
        printf("\n");

        switch(optionSubMenu)
        {

        case 1:
            inf_puntoA(orqLista, ORQ_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 2:
            inf_puntoB(orqLista, ORQ_CANT, insLista, INS_CANT, musLista, MUS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 3:
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
            inf_puntoH(musLista, MUS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 9:
            break;

        default:
            printf("Las opciones correctas van del 1 al 9. Reingrese.");
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        }
    }
    while(optionSubMenu != 9);
}

void inf_puntoA(sOrquesta* orqLista, int ORQ_CANT)
{

    char lugarAux[ORQ_LEN];
    int i;
    int isValid;
    //int value;

    printf("Ingrese lugar de la orquesta: ");
    __fpurge(stdin);
    fgets(lugarAux, ORQ_LEN, stdin);
    quitarSaltoDeLinea(lugarAux);
    corregirNombreCompuesto(lugarAux);
    isValid = areCharacters(lugarAux);

    if(isValid == 1)
    {
        for(i = 0; i < ORQ_CANT; i++)
        {

            if(strncmp(orqLista[i].lugar, lugarAux, ORQ_LEN) == 0 && orqLista[i].isEmpty == 1)
            {

                printf("| %2i | %25s | %15s | %15s |\n", orqLista[i].id, orqLista[i].nombre, orqLista[i].desc, orqLista[i].lugar);

            }
        }
    }
}

void inf_puntoB(sOrquesta* orqLista, int ORQ_CANT, sInstrumento* insLista, int INS_CANT, sMusico* musLista, int MUS_CANT)
{
    int i;

    for(i = 0; i < MUS_CANT; i++)
    {

        if(atoi(musLista[i].edad) <= 25 && musLista[i].isEmpty == 1)
        {

            printf("| %2i | %10s | %10s | %3s | %10s | %25s |\n", musLista[i].id, musLista[i].nombre, musLista[i].apellido, musLista[i].edad, musLista[i].descIns, musLista[i].descOrq);

        }
    }



}

void inf_puntoH(sMusico* musLista, int MUS_CANT){

    int i;

    for(i = 0; i < MUS_CANT; i++)
        {

            if(strncmp(musLista[i].descIns, "Viento", MUS_LEN) != 0 && musLista[i].isEmpty == 1)
            {

                printf("| %10s | %10s | %2s | %10s |\n", musLista[i].nombre, musLista[i].apellido, musLista[i].edad, musLista[i].descIns);

            }
        }

}
