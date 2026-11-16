//Autores: Sebastian Pulgarin 9035866

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "lista.h"

Nodo *lista_buscar(Nodo *cabeza, long long codigo){
    Nodo *p = cabeza;
    while (p != NULL && p->codigo != codigo){
        p = p->siguiente;
    }
    return p;
}

int lista_agregar(Nodo **cabeza, long long codigo, const char *nombre, int cantidad){
    int resultado;
    Nodo **p = cabeza ;
    while (*p != NULL && (*p)->codigo != codigo){
        p = &(*p)->siguiente;
    }
    
    if (*p != NULL)resultado = INV_REPETIDO;
    else{
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevo == NULL)resultado=INV_SIN_MEMORIA;
        else{
        nuevo->codigo = codigo;
        strncpy(nuevo-> nombre,nombre,Largo_nombre - 1);
        nuevo->nombre[Largo_nombre -1]='\0';
        nuevo->cantidad = cantidad;
        nuevo->siguiente = NULL;
        *p = nuevo;
        resultado = INV_OK;}
    }
    return resultado;
}

int lista_eliminar(Nodo **cabeza, long long codigo){
    int resultado;
    Nodo **p = cabeza;
    while (*p != NULL && (*p)->codigo != codigo){
        p = &(*p)->siguiente;
    }
    if(*p ==NULL)resultado = INV_NO_EXISTE;
    else {
        Nodo *borrar = *p;
        *p = borrar->siguiente;
        free(borrar);
        resultado = INV_OK;
    }
    return resultado;
}


void lista_imprimir ( const Nodo *cabeza, FILE *salida){
    const Nodo *p = cabeza;
    while (p != NULL){
        fprintf(salida, "%lld %s %d\n", p->codigo, p->nombre, p->cantidad);
        p = p->siguiente;
    }
}

void lista_destruir(Nodo **cabeza){
    Nodo *p = *cabeza;
    while (p != NULL){
        Nodo *siguiente = p->siguiente;
        free(p);
        p = siguiente;
    }
    *cabeza = NULL;
}
