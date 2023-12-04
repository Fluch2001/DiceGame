// main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dados.h"
#include "juego.h"

using namespace std;

void jugarUnJugador();
void jugarDosJugadores();

int main()
{
    srand(time(0));

    int opcion;

    do
    {
        cout << "=== Juego de Dados Quinientos ===" << endl;
        cout << "1. Juego nuevo para un jugador" << endl;
        cout << "2. Juego nuevo para dos jugadores" << endl;
        cout << "3. Mostrar puntuación más alta" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            jugarUnJugador();
            break;
        case 2:
            jugarDosJugadores();
            break;
        case 3:
            mostrarPuntuacionMasAlta();
            break;
        case 4:
            cout << std::endl;
            cout << "Mati aprobame <3" << std::endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida (1-4)." << std::endl;
            break;
        }

        cout << std::endl;

    } while (opcion != 4);

    return 0;
}