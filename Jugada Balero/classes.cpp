/* 
 * File:   classes.cpp
 * Author: Al3sKa
 * 
 * Created on 21 de abril de 2022, 16:55
 */

#include "classes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"

bool classes::acciones(int valor, int *Puntos, char *PlayerSelect[20]) {
    
    puntaje:
    
    int PUNTAJE[8] = {1, 5, 10, 10, 50, 100, 250, 500};
    
            system("cls");
            printf("Que accion pudo realizar el participante?\n\n"
                    
            "0. Cancelar operacion---------------------- 0 puntos\n\n"
                    
            "1. Sencillo ------------------------------- 1 punto\n"
            "2. Capirucho Sencillo --------------------- 5 puntos\n"
            "3. Clasico -------------------------------- 10 puntos\n"
            "4. Capirucho complicado ------------------- 10 puntos\n"
            "5. Cruzado -------------------------------- 50 puntos\n"
            "6. Reves ---------------------------------- 100 puntos\n"
            "7. Jalon ---------------------------------- 250 puntos\n"
            "8. Invertido ------------------------------ 500 puntos\n"
            
            "\n\n Elige una opcion para continuar: ");
    scanf("%d", &valor);
    
    if (valor == 0) return false;
    if (valor < 0 || valor > 8) goto puntaje;
    
    *Puntos = *Puntos + PUNTAJE[(valor - 1)];
    
    system("cls");
    printf("FELICITACIONES, %s!!! USTED HA RECIBIDO %d PUNTOS.\n\n", *PlayerSelect, PUNTAJE[(valor - 1)]);
    system("pause");
    
    return true;
}

void classes::eliminaciones(int *Puntos, int Puntaje)
{
    *Puntos = *Puntos - Puntaje;
}

int classes::clausura(int Valor1, int Valor2) {
    
    system("cls");
            
    if(Valor1 > Valor2) return 1;
    if(Valor1 < Valor2) return 2;
    if(Valor1 == Valor2) return 3;
    
}

int classes::Diferencia(int Valor1, int Valor2) {
    if(Valor1 > Valor2) return (Valor1 - Valor2);
    if(Valor1 < Valor2) return (Valor2 - Valor1);
    if(Valor1 == Valor2) return 0;
}

