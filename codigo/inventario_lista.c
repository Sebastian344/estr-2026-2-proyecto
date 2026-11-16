//Autores: Sebastian Pulgarin 9035866

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "lista.h"



struct Inventario{
    Nodo *cabeza;
};


Inventario *inv_crear(int m){
    Inventario *inv = (Inventario *)malloc(sizeof(Inventario));
    (void)m;
    if (inv != NULL){
        inv->cabeza = NULL;
    }
    return inv;
}


int inv_consultar(const Inventario *inv,long long codigo, char *nombre, int *cantidad){
    int resultado;
    Nodo *n =lista_buscar(inv->cabeza,codigo);
    if (n==NULL)resultado=INV_NO_EXISTE;
    else{
        strncpy(nombre,n->nombre,Largo_nombre-1);
        nombre[Largo_nombre-1] = '\0';
        *cantidad = n->cantidad;
        resultado = INV_OK;
    }
    return resultado;
}

int inv_reponer(Inventario *inv, long long codigo,int cantidad){
    int resultado;
    Nodo *n =lista_buscar(inv->cabeza,codigo);
    if (n == NULL)resultado = INV_NO_EXISTE;
    else{
        n->cantidad += cantidad;
        resultado = INV_OK;
    }
    return resultado;
}

int inv_agregar(Inventario *inv, long long codigo, const char *nombre, int cantidad){
    return lista_agregar(&inv->cabeza,codigo,nombre,cantidad);
}

int inv_eliminar(Inventario *inv,long long codigo){
return lista_eliminar(&inv->cabeza,codigo);
}

void inv_listar(const Inventario *inv,FILE *salida){
    lista_imprimir(inv->cabeza, salida);
}

void inv_destruir(Inventario *inv){
    if (inv != NULL){
    lista_destruir(&inv->cabeza);
    }   
    free(inv);
}