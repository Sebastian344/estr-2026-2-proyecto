CC = gcc
CFLAGS = -Wall -Wextra -O2 -D__USE_MINGW_ANSI_STDIO=1

all: inventario_lista inventario_tabla

inventario_lista: principal.c lista.c inventario_lista.c lista.h inventario.h
	$(CC) $(CFLAGS) -o inventario_lista principal.c lista.c inventario_lista.c

inventario_tabla: principal.c lista.c tabla.c lista.h inventario.h
	$(CC) $(CFLAGS) -o inventario_tabla principal.c lista.c tabla.c

medir_lista: medir.c lista.c inventario_lista.c lista.h inventario.h
	$(CC) $(CFLAGS) -o medir_lista medir.c lista.c inventario_lista.c

medir_tabla: medir.c lista.c tabla.c lista.h inventario.h
	$(CC) $(CFLAGS) -o medir_tabla medir.c lista.c tabla.c

medir_map: medir_map.cpp
	g++ -Wall -Wextra -O2 -o medir_map medir_map.cpp

medir: medir_lista medir_tabla medir_map

pruebas: all
	@fallo=0; \
	for exe in inventario_lista inventario_tabla; do \
	for f in ../datos/*.in; do \
	    esperado=$${f%.in}.out; \
	    ./$$exe < $$f > salida_tmp.txt; \
	    if diff -q --strip-trailing-cr salida_tmp.txt $$esperado > /dev/null; \
	    then echo "OK    $$exe $$f"; \
	    else echo "FALLA $$exe $$f"; fallo=1; fi; \
	done; \
	done; \
	rm -f salida_tmp.txt; \
	exit $$fallo

limpiar:
	rm -f inventario_lista inventario_tabla medir_lista medir_tabla medir_map *.exe salida_tmp.txt

.PHONY: all pruebas limpiar medir