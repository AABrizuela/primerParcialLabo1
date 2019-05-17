#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "utn.h"

int mus_init(sMusico* musLista, int MUS_CANT)
{

    int i = 0;

    for(i = 0; i < MUS_CANT; i++)
    {

        musLista[i].isEmpty = 0;

    }

    return 0;
}
int mus_alta(sMusico* musLista, int MUS_CANT)
{

    sMusico musNuevo;
    int indice;
    int ret = -1;
    int isValid = -1;
    char isIntAux[50];

    indice = mus_getFreeSpot(musLista, MUS_CANT);

    if(indice == -1)
    {
        printf("No hay lugar.\n");
        return ret;
    }
    else
    {

        do
        {
            printf("Ingrese nombre de musico: ");
            fflush(stdin);
            fgets(musNuevo.nombre, MUS_LEN, stdin);
            quitarSaltoDeLinea(musNuevo.nombre);
            corregirNombreCompuesto(musNuevo.nombre);
            isValid = areCharacters(musNuevo.nombre);
            if(isValid == 1)
            {

                strncpy(musLista[indice].nombre, musNuevo.nombre, MUS_LEN);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese apellido de musico: ");
            fflush(stdin);
            fgets(musNuevo.apellido, MUS_LEN, stdin);
            quitarSaltoDeLinea(musNuevo.apellido);
            corregirNombreCompuesto(musNuevo.apellido);
            isValid = areCharacters(musNuevo.apellido);
            if(isValid == 1)
            {

                strncpy(musLista[indice].apellido, musNuevo.apellido, MUS_LEN);

            }
        }
        while(isValid != 1);



        do
        {
            printf("Ingrese codigo de instrumento: ");
            fflush(stdin);
            scanf("%d", &musNuevo.idInstrumento);
            quitarSaltoDeLinea(itoa(musNuevo.idInstrumento, isIntAux, 10));
            isValid = isInteger(isIntAux);
            //el codigo de autor debe existir
            if(isValid == 1)
            {

                musLista[indice].idInstrumento = musNuevo.idInstrumento;
            }
        }
        while(isValid != 1);

        //Asignacion de tipo
        if(musLista[indice].idInstrumento == 1)
        {

            strncpy(musLista[indice].desc, "Cuerdas", MUS_LEN);

        }
        else if(musLista[indice].idInstrumento == 2)
        {

            strncpy(musLista[indice].desc, "Viento-madera", MUS_LEN);
        }
        else if(musLista[indice].idInstrumento == 3)
        {

            strncpy(musLista[indice].desc, "Viento-metal", MUS_LEN);
        }
        else if(musLista[indice].idInstrumento == 4)
        {

            strncpy(musLista[indice].desc, "Percusion", MUS_LEN);
        }

        //Asignacion de Orquesta
        if(musLista[indice].idInstrumento == 1)
        {

            strncpy(musLista[indice].desc, "Cuerdas", MUS_LEN);

        }
        else if(musLista[indice].idInstrumento == 2)
        {

            strncpy(musLista[indice].desc, "Viento-madera", MUS_LEN);
        }
        else if(musLista[indice].idInstrumento == 3)
        {

            strncpy(musLista[indice].desc, "Viento-metal", MUS_LEN);
        }
        else if(musLista[indice].idInstrumento == 4)
        {

            strncpy(musLista[indice].desc, "Percusion", MUS_LEN);
        }
            if(isValid == 1)
            {
                musLista[indice].id = indice + 1;
                musLista[indice].isEmpty = 1;
                printf("Instrumento cargado exitosamente!\n");
                system("pause");
            }
            ret = 0;
        }

        return ret;
    }

int mus_getFreeSpot(sMusico* musLista, int MUS_CANT)
{

    int index = -1, i=0;

    for(i=0; i<MUS_CANT; i++)
    {

        if( musLista[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int mus_baja(sMusico* musLista, int MUS_CANT){

    int id;
    int indice;
    int ret = -1;
    char autorBorrar;
    sMusico musico;

    printf("Ingrese codigo: ");
    scanf("%d", &id);

    indice = mus_findById(musLista, MUS_CANT, id);

    if(indice == -1)
    {

        printf("No hay ningun musico con el id %d\n", id);

    }
    else
    {

        musico = musLista[indice];
        mus_mostrarUno(musico);

        printf("\nConfirma borrado? S/N ");
        fflush(stdin);
        scanf("%c", &autorBorrar);
        if(autorBorrar != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {

            musLista[indice].isEmpty = 0;
            printf("Se ha eliminado el musico.\n\n");
            ret = 0;
        }
        system("pause");
    }

    return ret;
}

int mus_findById(sMusico* musLista, int MUS_CANT, int id){
    int index = -1;
    int i = 0;

    for(i=0; i < MUS_CANT; i++)
    {
        if( musLista[i].id == id && musLista[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mus_mostrarUno(sMusico musico){

    printf("| %4i | %15s | %15s | %2i | %15s |", musico.id, musico.nombre, musico.apellido, musico.idInstrumento, musico.desc);
}

void mus_listarTodos(sMusico* musLista, int MUS_CANT){
    int i;

    /*printf("=====================================================================\n"
           "||                        Listado de Orquestas                     ||\n"
           "=====================================================================\n");*/
    for(i = 0; i < MUS_CANT; i++)
    {

        if(musLista[i].isEmpty == 1)
        {

            mus_mostrarUno(musLista[i]);

        }

    }
    /*printf("=====================================================================\n");*/

}

int mus_modificacion(sMusico* musLista, int MUS_CANT){

    int index;
    int idAux;
    int isValid;
    //char isIntAux[50];
    int ret = -1;
    int optionEdit = 0;
    char idAuxChar[10];
    sMusico musico;

    do
    {
        mus_listarTodos(musLista, MUS_LEN);
        printf("Ingrese id a modificar: ");
        scanf("%d", &idAux);
        isValid = isInteger(itoa(idAux, idAuxChar, 10));
    }
    while(isValid != 1);

    index = mus_findById(musLista, MUS_LEN, idAux);

    if(index == -1)
    {

        printf("No hay ningun musico con el id %d\n", idAux);
    }
    else
    {
        do
        {
            musico = musLista[index];

            system("cls");
            printf("Musico a modificar: \n");
            mus_mostrarUno(musico);

            printf("1.- Nombre.\n");
            printf("2.- Apellido.\n");
            printf("3.- Sexo.\n");
            printf("4.- Telefono.\n");
            printf("5.- E-Mail.\n");
            printf("6.- Fecha de asociado.\n");
            printf("7.- Salir.");

            printf("\nQue desea modificar?\n\n");
            fflush(stdin);
            scanf("%d", &optionEdit);

            switch(optionEdit)
            {

            case 1:
                do
                {
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    fgets(musico.nombre, MUS_LEN, stdin);
                    quitarSaltoDeLinea(musico.nombre);
                    corregirNombreCompuesto(musico.nombre);
                    isValid = areCharacters(musico.nombre);
                    if(isValid == 1)
                    {

                        strncpy(musLista[index].nombre, musico.nombre, MUS_LEN);

                    }
                }
                while(isValid != 1);
                break;

            case 2:
                do
                {
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    fgets(musico.apellido, MUS_LEN, stdin);
                    quitarSaltoDeLinea(musico.apellido);
                    corregirNombreCompuesto(musico.apellido);
                    isValid = areCharacters(musico.apellido);
                    if(isValid == 1)
                    {

                        strncpy(musLista[index].apellido, musico.apellido, MUS_LEN);

                    }
                }
                while(isValid != 1);
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

            default:
                printf("Error. Las opciones van del 1 al 6.");

            }

        }
        while(optionEdit != 6);
    }

    return ret;

}
