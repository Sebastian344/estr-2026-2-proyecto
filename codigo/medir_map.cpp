// Autores: Sebastian Pulgarin 9035866
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>

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
    std::fprintf(stderr, "uso: medir_map n m q modo\n");
    estado = 1;
} else {
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int q = std::atoi(argv[3]);
    int modo = std::atoi(argv[4]);
    if (n < 1 || m < 1 || q < 0) {
    std::fprintf(stderr, "argumentos invalidos\n");
    estado = 1;
    }else {
    std::map<long long, int> mapa;
    long long control = 0;
    std::clock_t t0 = std::clock();
    for (int i = 0; i < n; i++) {
        mapa.insert(std::make_pair(codigo_de(i, modo, m), 1));
    }
    std::clock_t t1 = std::clock();
    for (int j = 0; j < q; j++) {
        long long i = 0;
        if (j % 2 == 0) {
            i = (j / 2) % n;
        } else {
            i = n + (j / 2) % n;    
        }
        std::map<long long, int>::const_iterator it = mapa.find(codigo_de(i, modo, m));
        if (it != mapa.end()) {
        control += it->second;
        }
    }
    std::clock_t t2 = std::clock();
    for (int i = 0; i < n; i++) {
        mapa.erase(codigo_de(i, modo, m));
    }
    std::clock_t t3 = std::clock();
    std::printf("%.6f %.6f %.6f %lld\n",
                (double)(t1 - t0) / CLOCKS_PER_SEC,
                (double)(t2 - t1) / CLOCKS_PER_SEC,
                (double)(t3 - t2) / CLOCKS_PER_SEC, control);
        }
    }
return estado;
}