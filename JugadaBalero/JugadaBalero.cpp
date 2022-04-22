#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"

#pragma warning(disable : 4996)

/*COPYRIGHT: Al3sKa 2022 Do not remove (or modify) this text.*/

/*This program can only be run in the IDE mentioned below:

Turbo C++
Borland C++
Dev C++
Netbeans 8.0.2*/

/*Update 1.1 Bug fixes, disabled a warning for Visual Studio so it can be compiled on it.*/

int main()
{

    int Punto1;
    int Punto2;
    int inst;
    int puntaje;
    int resultado;
    int Diferencia;

    int* PointsAc;
    int* PlayerPoints;


    char SN;

    char* PlayerSelect[20];

    char Player1[20], Player2[20];


    bool yn;


    classes clase;

Declaraciones:

    PointsAc = 0;
    PlayerPoints = 0;
    
    Punto1 = 0;
    Punto2 = 0;

    system("cls");

    printf("COPYRIGHT: Al3sKa 2022 Do not remove (or modify) this text.\n");
    printf("===========================================\n\nBIENVENIDOS AL TORNEO:\n\n");

    printf("Teclee el nombre del participante 1\n\n===========================================\n\n");
    scanf("%s", Player1);
    fflush(stdout);

    system("cls");
    printf("===========================================\n\nBIENVENIDOS AL TORNEO:\n\n");

    printf("Teclee el nombre del participante 2\n\n===========================================\n\n");
    scanf("%s", Player2);
    fflush(stdout);

Tabla_de_Puntos:

    system("cls");

    printf("JUGADORES: -------------------\n\n"
        "1. %s ..... Puntos: %d \n2. %s ..... Puntos: %d\n\n3. Editar Participantes\n4. Terminar Torneo", Player1, Punto1, Player2, Punto2);

    printf("\n\nEscoja un participante para comenzar! \n\n");
    scanf("%d", &inst);

    switch (inst)
    {
    case 1:
        *PlayerSelect = Player1;
        PlayerPoints = &Punto1;

        goto Eleccion;
        break;

    case 2:
        *PlayerSelect = Player2;
        PlayerPoints = &Punto2;

        goto Eleccion;
        break;

    case 3: goto Editor; break;

    case 4: goto Clausura; break;

    }

    if (inst < 1 || inst > 4) goto Tabla_de_Puntos;

Eleccion:

    system("cls");

    printf("OPCIONES DEL PARTICIPANTE: -------------------\n\n"
        "PARTICIPANTE ELEGIDO: %s", *PlayerSelect);

    printf("\n\n1. Realizar Accion!\n2. Eliminacion de Puntos!\n3. Cancelar operacion\n\n");
    printf("Escoja una operacion para continuar... ");
    scanf("%d", &inst);

    switch (inst) {
    case 1: goto Accion;
        break;

    case 2: goto Eliminacion;
        break;

    case 3: goto Tabla_de_Puntos;
        break;
    }

    if (inst < 1 || inst > 3) goto Eleccion;

Accion:

    system("cls");

    printf("PUFF! Se acaba de realizar una accion. Lo logro? S/N: ");
    scanf(" %c", &SN);

    if (SN == 'S') goto Accion_C;
    if (SN == 'N') goto Eleccion; else goto Accion;
Accion_C:

    yn = clase.acciones(inst, PlayerPoints, PlayerSelect);

    if (yn == false) goto Eleccion;

    goto Tabla_de_Puntos;

    goto Tabla_de_Puntos;

Eliminacion:
    system("cls");

    printf("ELIMINACION DE PUNTOS: %s\n\nCuantos puntos desea quitar? ", *PlayerSelect);
    scanf("%d", &puntaje);

    clase.eliminaciones(PlayerPoints, puntaje);

    goto Tabla_de_Puntos;

Editor:
    system("cls");

    printf("EDITOR: -------------------\n\n"
        "1. %s ..... Puntos: %d \n2. %s ..... Puntos: %d\n\n3. Terminar Operacion", Player1, Punto1, Player2, Punto2);

    printf("\n\nEscoja un participante para editar su nombre. \n\n");
    scanf("%d", &inst);

    switch (inst)
    {
    case 1:
        system("cls");
        printf("Teclee el nuevo nombre del integrante <<%s>>: ", Player1);
        scanf("%s", Player1);

        goto Editor;
        break;

    case 2:
        system("cls");
        printf("Teclee el nuevo nombre del integrante <<%s>>: ", Player2);
        scanf("%s", Player2);

        goto Editor;
        break;

    case 3:
        goto Tabla_de_Puntos; break;

    }


Clausura:

    resultado = clase.clausura(Punto1, Punto2);
    Diferencia = clase.Diferencia(Punto1, Punto2);

    switch (resultado)
    {
    case 1:
        *PlayerSelect = Player1;
        PointsAc = &Punto1;
        break;
    case 2:
        *PlayerSelect = Player2;
        PointsAc = &Punto2;
        break;

    case 3:
        printf("===========================================\n\nTREMENDO EMPATE!");
        printf("\n\nFELICITACIONES, %s & %s!!!!! Buena jugada con un total de %d puntos."
            "\n\nVolver a empezar? (S)\n\n===========================================\n\n", Player1, Player2, Punto1);

        scanf(" %c", &SN);

        if (SN == 'S') goto Declaraciones;
        return 0;

    }

    printf("===========================================\n\nHAY UN GANADOR!!!!\n\n%s\n\n", *PlayerSelect);
    printf("---------------------------------------\n\nCon un puntaje de: %d puntos\n\n"

        "Y una diferencia de: %d puntos\n\n"
        "Volver a empezar? (S)\n\n===========================================\n\n", *PointsAc, Diferencia);

    scanf(" %c", &SN);

    if (SN == 'S') goto Declaraciones;

    return 0;


}