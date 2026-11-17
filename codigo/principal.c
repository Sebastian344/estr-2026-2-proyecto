// Autores: Sebastian Pulgarin 9035866
#include <stdio.h>
#include <string.h>
#include "inventario.h"

static void descartar_resto(const char *palabra){
  if (strlen(palabra) == Largo_nombre -1){
    int ch = getchar();
    while (ch != EOF && ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r') {
      ch = getchar();
    }
  }
}

int main(void) {
  int n = 0;
  int ok;
  Inventario *inv;

  ok = (scanf("%d", &n) == 1);
  inv = inv_crear(1009);

  if (inv != NULL) {
    for (int i = 0; ok && i < n; i++) {
      char orden[16];
      long long codigo = 0;
      char nombre[Largo_nombre];
      int cantidad = 0;
      int r;

      ok = (scanf("%15s", orden) == 1);
      if (ok && strcmp(orden, "AGREGAR") == 0) {
        ok = (scanf("%lld %63s", &codigo, nombre) == 2);
        if (ok) {
          descartar_resto(nombre);
          ok = (scanf("%d", &cantidad) == 1);
        }
        if (ok) {
          r = inv_agregar(inv, codigo, nombre, cantidad);
          if (r == INV_OK) printf("ok\n");
          else if (r == INV_REPETIDO) printf("repetido\n");
          else printf("sin memoria\n");
        }
      } else if (ok && strcmp(orden, "ELIMINAR") == 0) {
        ok = (scanf("%lld", &codigo) == 1);
        if (ok) {
          r = inv_eliminar(inv, codigo);
          printf("%s\n", r == INV_OK ? "ok" : "no existe");
        }
      } else if (ok && strcmp(orden, "CONSULTAR") == 0) {
        ok = (scanf("%lld", &codigo) == 1);
        if (ok) {
          r = inv_consultar(inv, codigo, nombre, &cantidad);
          if (r == INV_OK) printf("%lld %s %d\n", codigo, nombre, cantidad);
          else printf("no existe\n");
        }
      } else if (ok && strcmp(orden, "REPONER") == 0) {
        ok = (scanf("%lld %d", &codigo, &cantidad) == 2);
        if (ok) {
          r = inv_reponer(inv, codigo, cantidad);
          printf("%s\n", r == INV_OK ? "ok" : "no existe");
        }
      } else if (ok && strcmp(orden, "LISTAR") == 0) {
        inv_listar(inv, stdout);
      }
    }
    inv_destruir(inv);
  }
  return 0;
}