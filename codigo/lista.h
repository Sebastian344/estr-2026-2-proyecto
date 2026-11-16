// Autores: Sebastian Pulgarin 9035866
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include "inventario.h"

typedef struct Nodo
{
    long long codigo;
    char nombre[Largo_nombre];
    int cantidad;
    struct Nodo *siguiente;

}Nodo;


void lista_destruir(Nodo **cabeza);
int lista_agregar(Nodo **cabeza, long long codigo, const char *nombre, int cantidad);
int lista_eliminar(Nodo **cabeza, long long codigo);
Nodo *lista_buscar(Nodo *cabeza, long long codigo);
void lista_imprimir(const Nodo *cabeza, FILE *salida);

#endif