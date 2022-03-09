#include <iostream>
#include <ctype.h>  // isalpha, isupper
#include <string.h> // strcspn

using namespace std;

#define LONGITUD_ALFABETO 26
#define INICIO_ALFABETO_MAYUSCULAS 65
#define INICIO_ALFABETO_MINUSCULAS 97
#define MAXIMA_LONGITUD_CADENA 5000
#define MOD(i, n) (i % n + n) % n

const char* alfabetoMinusculas = "abcdefghijklmnopqrstuvwxyz",
          * alfabetoMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void cifrar(char* mensaje, char* destino, int rotaciones);
int ord(char c);

int main()
{
    char mensaje[] = "retirada";
    char destino[200] = "";
    cifrar(mensaje, destino, 3);
    cout << destino << endl;


    return 0;
}

void cifrar(char* mensaje, char* destino, int rotaciones) {
    int i = 0;
    while (mensaje[i]) {
        char caracterActual = mensaje[i];
        int posicionOriginal = ord(caracterActual);
        if (!isalpha(caracterActual)) {
            destino[i] = caracterActual;
            i++;
            continue; // Ir a la siguiente iteración; por eso arriba aumentamos a i
        }
        if (isupper(caracterActual)) {
            destino[i] =
                alfabetoMayusculas[(posicionOriginal - INICIO_ALFABETO_MAYUSCULAS +
                    rotaciones) %
                LONGITUD_ALFABETO];
        }
        else {

            destino[i] =
                alfabetoMinusculas[(posicionOriginal - INICIO_ALFABETO_MINUSCULAS +
                    rotaciones) %
                LONGITUD_ALFABETO];
        }
        i++;
    }
}

int ord(char c) { return (int)c; }