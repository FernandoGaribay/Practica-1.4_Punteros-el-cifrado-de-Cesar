#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

#define LONGITUD_ALFABETO 26
#define INICIO_ALFABETO_MAYUSCULAS 65
#define INICIO_ALFABETO_MINUSCULAS 97
#define MAXIMA_LONGITUD_CADENA 5000
#define MOD(i, n) (i % n + n) % n

class CifradoCesar {
private:
    const char* alfabetoMinusculas = "abcdefghijklmnopqrstuvwxyz";
    const char* alfabetoMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    CifradoCesar();
    ~CifradoCesar();

    char* cifrar(char*, int);
    char* descifrar(char*, int);
    char** fuerzaBruta(char*);
    int enteroACaracter(char);
};

CifradoCesar::CifradoCesar() {

}

CifradoCesar::~CifradoCesar() {}

char* CifradoCesar::cifrar(char* mensaje, int rotaciones) {
    char* destino = new char[strlen(mensaje)];

    int i = 0;
    while (mensaje[i]) {
        char caracterActual = mensaje[i];
        int posicionOriginal = enteroACaracter(caracterActual);

        if (!isalpha(caracterActual)) {
            destino[i] = caracterActual;

            i++;
            continue;
        }
        if (isupper(caracterActual)) {
            destino[i] = alfabetoMayusculas[(posicionOriginal - INICIO_ALFABETO_MAYUSCULAS + rotaciones) % LONGITUD_ALFABETO];
        }
        else {
            destino[i] = alfabetoMinusculas[(posicionOriginal - INICIO_ALFABETO_MINUSCULAS + rotaciones) % LONGITUD_ALFABETO];
        }
        i++;
    }
    destino[strlen(mensaje)] = '\0';
    return destino;
}

char* CifradoCesar::descifrar(char* mensaje, int rotaciones) {
    char* destino = new char[strlen(mensaje)];

    int i = 0;
    while (mensaje[i]) {
        char caracterActual = mensaje[i];
        int posicionOriginal = enteroACaracter(caracterActual);
        if (!isalpha(caracterActual)) {
            destino[i] = caracterActual;
            i++;
            continue; // Ir a la siguiente iteración; por eso arriba aumentamos a i
        }
        if (isupper(caracterActual)) {
            destino[i] = alfabetoMayusculas[MOD(
                posicionOriginal - INICIO_ALFABETO_MAYUSCULAS - rotaciones,
                LONGITUD_ALFABETO)];
        }
        else {
            destino[i] = alfabetoMinusculas[MOD(
                posicionOriginal - INICIO_ALFABETO_MINUSCULAS - rotaciones,
                LONGITUD_ALFABETO)];
        }
        i++;
    }
    destino[strlen(mensaje)] = '\0';
    return destino;
}

char** CifradoCesar::fuerzaBruta(char* mensaje) {
    char* destino[27];

    for (int i = 1; i < 27; i++) {
        destino[i] = descifrar(mensaje, i);
    }

    return destino;
}

int CifradoCesar::enteroACaracter(char c) {
    return (int)c;
}


int main()
{
    char mensaje[MAXIMA_LONGITUD_CADENA];
    char* mensajeCifrado;
    char* mensajeDesifrado;

    CifradoCesar objCifrado = CifradoCesar();

    cin.getline(mensaje, MAXIMA_LONGITUD_CADENA);

    mensajeCifrado = objCifrado.cifrar(mensaje, 3);
    mensajeDesifrado = objCifrado.descifrar(mensajeCifrado, 3);

    cout << mensajeCifrado << endl;
    cout << mensajeDesifrado << endl;

    char** destino;
    destino = objCifrado.fuerzaBruta(mensajeCifrado);

    cout << destino[0][0] << endl;

    return 0;
}