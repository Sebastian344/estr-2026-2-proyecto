// Autores: Sebastian Pulgarin 9035866
#include <stdio.h>
#include <string.h>
#include "inventario.h"


int main(void) {
  int n;
  Inventario *inv;

  scanf("%d",&n);
  inv = inv_crear();


  if (inv != NULL){
    for (int i = 0;i<n; i++){
      char orden[16];
      long long codigo;
      char nombre[Largo_nombre];
      int cantidad;
      int r;
      scanf("%15s",orden);

      

      if (strcmp(orden,"AGREGAR")==0){
        scanf("%lld %15s %d",&codigo,nombre, &cantidad);
        r = inv_agregar(inv,codigo,nombre,cantidad);
        if(r==INV_OK)printf("ok\n");
        else if (r== INV_REPETIDO)printf("repetido\n");
        else printf("sin memoria\n");
      } else if (strcmp(orden,"ELIMINAR")==0){
        scanf("%lld", &codigo);
        r = inv_eliminar(inv, codigo);
        printf("%s\n", r == INV_OK ? "ok" : "no existe");
      }else if(strcmp(orden,"CONSULTAR")==0){
        scanf("%lld",&codigo);
        r = inv_consultar(inv,codigo,nombre,&cantidad);
        if (r == INV_OK) printf("%lld %s %d\n", codigo, nombre, cantidad);
        else printf("no existe\n");
      }else if (strcmp(orden,"REPONER")==0){
        scanf("%lld %d",&codigo,&cantidad);
        r = inv_reponer(inv,codigo,cantidad);
        printf("%s\n",r == INV_OK ? "ok" : "no existe");
      }else if (strcmp(orden,"LISTAR")==0){
        inv_listar(inv,stdout);
      }
    }
    inv_destruir(inv);
  }
  return 0;
}
