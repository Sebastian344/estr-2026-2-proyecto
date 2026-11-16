// Autores: Sebastian Pulgarin 9035866
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct Inventario{
    Nodo **cubetas;
    int m;
};

static int indice(const Inventario *inv, long long codigo){
    int resultado;
    resultado = (int)(codigo % inv->m);
    if (resultado < 0)resultado += inv->m;
    return resultado;
}

Inventario *inv_crear(int m){
    Inventario *inv = (Inventario *)malloc(sizeof(Inventario));
    if (inv != NULL){
        inv->m = m;
        inv ->cubetas = (Nodo **)calloc ((size_t)m, sizeof(Nodo *));
        if (inv->cubetas == NULL){
            free(inv);
            inv = NULL;
        }
    }
    return inv;
}

void inv_destruir(Inventario *inv){
    if (inv != NULL){
        for (int i = 0; i < inv->m;i++){
            lista_destruir(&inv->cubetas[i]);
        }
        free(inv->cubetas);
    }
    free(inv);
}

int inv_agregar(Inventario *inv, long long codigo, const char *nombre, int cantidad) {
    return lista_agregar(&inv->cubetas[indice(inv,codigo)],codigo,nombre,cantidad);
}

int inv_eliminar(Inventario *inv, long long codigo){
    return lista_eliminar(&inv->cubetas[indice(inv,codigo)],codigo);
}


int inv_consultar(const Inventario *inv,long long codigo,char *nombre,int *cantidad){
    int resultado;
    Nodo *n = lista_buscar(inv->cubetas[indice(inv,codigo)],codigo);
    if (n == NULL)resultado = INV_NO_EXISTE;
    else{
        strncpy(nombre, n->nombre, Largo_nombre -1);
        nombre[Largo_nombre -1] = '\0';
        *cantidad = n->cantidad;
        resultado = INV_OK;
    }
    return resultado;
}



int inv_reponer(Inventario *inv, long long codigo,int cantidad){
    int resultado;
    Nodo *n = lista_buscar(inv->cubetas[indice(inv,codigo)],codigo);
    if (n == NULL)resultado = INV_NO_EXISTE;
    else {
        n->cantidad += cantidad;
        resultado = INV_OK;

    }
    return resultado;
}

void inv_listar(const Inventario *inv, FILE *salida){
    for (int i = 0; i < inv->m; i++){
        lista_imprimir(inv->cubetas[i],salida);
    }
}

