// dados.cpp

#include "dados.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int puntuacionMasAltaUno = 0;
int puntuacionMasAltaDos = 0;
string jugadorUno;
string jugadorDos;

int lanzarDado()
{
    return rand() % 6 + 1;
}

int calcularPuntaje(int valores[], int numDados)
{
    int puntaje = 0;

    // Comprobar escalera
    bool escalera = true;
    for (int i = 1; i <= 6; i++)
    {
        if (valores[i - 1] != i)
        {
            escalera = false;
            break;
        }
    }
    if (escalera)
    {
        return 500;
    }

    // Comprobar combinaciones ganadoras
    int contador[6] = {0};
    for (int i = 0; i < numDados; i++)
    {
        contador[valores[i] - 1]++;
    }

    // Comprobar combinaciones de 3 dados con el mismo valor
    for (int i = 0; i < 6; i++)
    {
        if (contador[i] >= 3)
        {
            puntaje += (i + 1) * 10;
            contador[i] -= 3;
        }
    }

    // Comprobar combinaciones de 6 dados iguales (excepto 6)
    if (contador[5] == 6)
    {
        puntaje = 0;
    }

    // Sumar puntaje de dados individuales
    for (int i = 0; i < 6; i++)
    {
        puntaje += (i + 1) * contador[i];
    }

    return puntaje;
}

void mostrarPuntuacionMasAlta()
{
    if (puntuacionMasAltaUno > puntuacionMasAltaDos)
    {
        cout << endl;
        cout << "=== Puntuaciones más altas ===" << endl;
        cout << "1. " << jugadorUno << ": " << puntuacionMasAltaUno << " puntos." << endl;
        cout << "2. " << jugadorDos << ": " << puntuacionMasAltaDos << " puntos." << endl;
        cout << "=============================" << endl;
    }
    else if (puntuacionMasAltaDos > puntuacionMasAltaUno)
    {
        cout << endl;
        cout << "=== Puntuaciones más altas ===" << endl;
        cout << "1. " << jugadorDos << ": " << puntuacionMasAltaDos << " puntos." << endl;
        cout << "2. " << jugadorUno << ": " << puntuacionMasAltaUno << " puntos." << endl;
        cout << "=============================" << endl;
    }
    else
    {
        cout << endl;
        cout << "No hay puntuaciones guardadas." << endl;
    }
}