CC = gcc
CFLAGS = -Wall -Wextra -O2 -D__USE_MINGW_ANSI_STDIO=1

all: inventario

inventario: principal.c lista.c inventario.h
	$(CC) $(CFLAGS) -o inventario principal.c lista.c

pruebas: inventario
	@fallos=0; \
	for f in ../datos/*.in; do \
	esperado=$${f%.in}.out; \
	./inventario < $$f > salida_tmp.txt; \
	if diff -q --strip-trailing-cr salida_tmp.txt $$esperado > /dev/null; then \
	echo "OK     $$f"; \
	else \
	echo "FALLA  $$f"; fallos=1; \
	fi; \
	done; \
	rm -f salida_tmp.txt; \
	exit $$fallos

clean:
	rm -f inventario inventario.exe salida_tmp.txt

.PHONY: all pruebas clean