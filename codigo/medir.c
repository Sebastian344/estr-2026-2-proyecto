// Autores: Sebastian Pulgarin 9035866
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inventario.h"

static long long codigo_de(long long i, int modo, int m) {
    long long resultado = 0;
    if (modo == 0) {
        resultado = (long long)(((unsigned long long)i * 2654435761ULL) % 1000000007ULL) + 1;
    } else {
        resultado = (i + 1) * (long long)m;
    }
    return resultado;
}



int main(int argc, char **argv) {
    int estado = 0;
    if (argc != 5) {
    fprintf(stderr, "uso: medir n m q modo\n");
    estado = 1;
    } else {
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int q = atoi(argv[3]);
    int modo = atoi(argv[4]);
    Inventario *inv = inv_crear(m);
    if (n < 1 || m < 1 || q < 0 || inv == NULL) {
        fprintf(stderr, "argumentos invalidos o sin memoria\n");
        estado = 1;
    } else {
        long long control = 0;
        clock_t t0 = clock();
        for (int i = 0; i < n; i++) {
        inv_agregar(inv, codigo_de(i, modo, m), "x", 1);
        }
        clock_t t1 = clock();
        for (int j = 0; j < q; j++) {
        char nombre[Largo_nombre];
        int cantidad = 0;
        long long i = 0;
        if (j % 2 == 0) {
            i = (j / 2) % n;
        } else {
            i = n + (j / 2) % n;    
        }
        if (inv_consultar(inv, codigo_de(i, modo, m), nombre, &cantidad) == INV_OK) {
            control += cantidad;
        }
        }
        clock_t t2 = clock();
        for (int i = 0; i < n; i++) {
            inv_eliminar(inv, codigo_de(i, modo, m));
        }
        clock_t t3 = clock();
        printf("%.6f %.6f %.6f %lld\n",
                (double)(t1 - t0) / CLOCKS_PER_SEC,
                (double)(t2 - t1) / CLOCKS_PER_SEC,
                (double)(t3 - t2) / CLOCKS_PER_SEC, control);
    }
    inv_destruir(inv);
    }
    return estado;
}