#!/bin/bash
mediana() {
    for r in 1 2 3; do "$@"; done > /tmp/m.txt
    for c in 1 2 3; do
    awk -v c=$c '{print $c}' /tmp/m.txt | sort -n | sed -n 2p
    done | tr '\n' ' '
    echo
}
q=20000
for n in 1000 2000 4000 8000 16000; do
    echo "== n=$n  (columnas: insertar consultar eliminar)"
    echo -n "lista            "; mediana ./medir_lista $n 1 $q 0
    echo -n "tabla m=11       "; mediana ./medir_tabla $n 11 $q 0
    echo -n "tabla m=$n    "; mediana ./medir_tabla $n $n $q 0
    echo -n "tabla m=100003   "; mediana ./medir_tabla $n 100003 $q 0
    echo -n "tabla 1 cubeta   "; mediana ./medir_tabla $n 1009 $q 1
    echo -n "map              "; mediana ./medir_map $n 1 $q 0
done