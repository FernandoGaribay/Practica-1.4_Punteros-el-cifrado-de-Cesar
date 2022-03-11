#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

#define LONGITUD_ALFABETO 26
#define INICIO_ALFABETO_MAYUSCULAS 65
#define INICIO_ALFABETO_MINUSCULAS 97
#define MAXIMA_LONGITUD_CADENA 255
#define MOD(i, n) (i % n + n) % n // Calcular modulo positivo

class CifradoCesar {
private:
    const char* alfabetoMinusculas = "abcdefghijklmnopqrstuvwxyz";
    const char* alfabetoMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    CifradoCesar(); // Constructor por defecto
    ~CifradoCesar(); // Destructor

    char* cifrar(char*, int); // Funcion cifrar
    char* descifrar(char*, int); // Funcion desifrar
    char* fuerzaBruta(char*, int); // Funcion fuerza bruta
    int enteroACaracter(char);
};

CifradoCesar::CifradoCesar() {}

CifradoCesar::~CifradoCesar() {}

char* CifradoCesar::cifrar(char* mensaje, int des) {
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
            destino[i] = alfabetoMayusculas[(posicionOriginal - INICIO_ALFABETO_MAYUSCULAS + des) % LONGITUD_ALFABETO];
        }
        else {
            destino[i] = alfabetoMinusculas[(posicionOriginal - INICIO_ALFABETO_MINUSCULAS + des) % LONGITUD_ALFABETO];
        }
        i++;
    }
    destino[strlen(mensaje)] = '\0';
    return destino;
}

char* CifradoCesar::descifrar(char* mensaje, int des) {
    char* destino = new char[strlen(mensaje)];

    int i = 0;
    while (mensaje[i]) {
        char caracterActual = mensaje[i];
        int posicionOriginal = enteroACaracter(caracterActual);
        if (!isalpha(caracterActual)) {
            destino[i] = caracterActual;
            i++;
            continue; // Ir a la siguiente iteracion
        }
        if (isupper(caracterActual)) {
            destino[i] = alfabetoMayusculas[MOD(posicionOriginal - INICIO_ALFABETO_MAYUSCULAS - des, LONGITUD_ALFABETO)];
        }
        else {
            destino[i] = alfabetoMinusculas[MOD(posicionOriginal - INICIO_ALFABETO_MINUSCULAS - des, LONGITUD_ALFABETO)];
        }
        i++;
    }
    destino[strlen(mensaje)] = '\0';
    return destino;
}

char* CifradoCesar::fuerzaBruta(char* mensaje, int intervalo) {
    return descifrar(mensaje, intervalo);
}

int CifradoCesar::enteroACaracter(char c) {
    return (int)c;
}


int main()
{
    CifradoCesar objCifrado = CifradoCesar(); // Instancia de la clase "CifradoCesar"
    bool r = true;
    int opc;

    int rotaciones;
    char mensaje[MAXIMA_LONGITUD_CADENA]; // Mensaje original
    char* mensajeCifrado; // Mensaje cifrado
    char* mensajeDesifrado; // Mensaje desifrado

    // Entrada del mensaje
    cout << "Ingrese un mensaje a crifrar: ";
    cin.getline(mensaje, MAXIMA_LONGITUD_CADENA);

    // Entrada de las rotaciones
    cout << "Ingrese una cantidad de rotaciones: ";
    cin >> rotaciones;

    system("pause");
    system("cls");

    mensajeCifrado = objCifrado.cifrar(mensaje, rotaciones);
    mensajeDesifrado = objCifrado.descifrar(mensajeCifrado, rotaciones);

    // Menu--------
    do {
        cout << "Cifrado Cesar - Rotaciones: " << rotaciones << " - Mensaje: \"" << mensaje << "\"\n" << endl;
        cout << "1) Cifrar un mensaje" << endl;
        cout << "2) Desifrar un mensaje" << endl;
        cout << "3) Fuerza bruta" << endl;
        cout << "4) Salir" << endl;

        cout << "\nDijite una opcion: ";
        cin >> opc;

        switch (opc) {
        case 1:
            cout << "\nMensaje cifrado: " << mensajeCifrado << endl;
            break;
        case 2:
            cout << "Mensaje desifrado: " << mensajeDesifrado << endl;
            break;
        case 3:
            cout << "\nMetodo de fuerza bruta -------" << endl;
            for (int i = 1; i <= LONGITUD_ALFABETO; i++) 
                cout << "Rotacion " << i << ": " << objCifrado.fuerzaBruta(mensajeCifrado, i) << endl;
            break;
        case 4:
            r = false;
            continue; // Ir a la siguiente iteracion
            break;
        }
        system("pause");
        system("cls");
    } while (r);

    return 0;
}