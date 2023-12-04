// juego.cpp

#include <iostream>
#include "dados.h"

using namespace std;

void jugarUnJugador()
{
    string nombre;

    cout << "=== Modo de un jugador ===" << endl;
    cout << "Ingresa tu nombre: ";
    cin >> nombre;

    int puntajeTotal = 0;
    int numRondas = 0;

    do
    {
        numRondas++;

        int valoresDados[6];
        int puntajeRonda = 0;

        cout << endl;
        cout << "=== Ronda N° " << numRondas << " ===" << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << "=== Lanzamiento " << i + 1 << " ===" << endl;

            for (int j = 0; j < 6; j++)
            {
                valoresDados[j] = lanzarDado();
                cout << "Dado " << j + 1 << ": " << valoresDados[j] << endl;
            }

            int puntajeLanzamiento = calcularPuntaje(valoresDados, 6);
            cout << "Combinación ganadora: " << puntajeLanzamiento << " puntos" << endl;
            puntajeRonda = max(puntajeRonda, puntajeLanzamiento);
        }

        puntajeTotal += puntajeRonda;

        cout << endl;
        cout << "=== Resultados de la Ronda N° " << numRondas << " ===" << endl;
        cout << "Jugador: " << nombre << endl;
        cout << "Puntaje de la ronda: " << puntajeRonda << " puntos" << endl;
        cout << "Puntaje total: " << puntajeTotal << " puntos" << endl;

        cout << endl;
        cout << "Presiona Enter para continuar a la siguiente ronda...";
        cin.ignore();
        cin.get();

    } while (puntajeTotal < 500);

    cout << endl;
    cout << "¡Felicidades, " << nombre << "! Has alcanzado los " << puntajeTotal << " puntos en " << numRondas << " rondas." << endl;
}

void jugarDosJugadores()
{
    string nombreJugador1, nombreJugador2;

    cout << "=== Modo de dos jugadores ===" << endl;
    cout << "Ingresa el nombre del Jugador 1: ";
    cin >> nombreJugador1;
    cout << "Ingresa el nombre del Jugador 2: ";
    cin >> nombreJugador2;

    jugadorUno = nombreJugador1;
    jugadorDos = nombreJugador2;

    while (nombreJugador2 == nombreJugador1)
    {
        cout << endl;
        cout << "El nombre ingresado es igual al del jugador 1. Por favor, selecciona otro nombre." << endl;
        cout << "Ingresa el nombre del jugador 2: ";
        cin >> nombreJugador2;
    }

    int puntajeJugador1 = 0;
    int puntajeJugador2 = 0;
    int numRondas = 0;

    do
    {
        numRondas++;

        int valoresDados[6];
        int puntajeRonda1 = 0;
        int puntajeRonda2 = 0;

        cout << endl;
        cout << "=== Ronda N° " << numRondas << " ===" << endl;

        // Turno del Jugador 1
        cout << "Turno de " << nombreJugador1 << ":" << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << "=== Lanzamiento " << i + 1 << " ===" << endl;

            for (int j = 0; j < 6; j++)
            {
                valoresDados[j] = lanzarDado();
                cout << "Dado " << j + 1 << ": " << valoresDados[j] << endl;
            }

            int puntajeLanzamiento = calcularPuntaje(valoresDados, 6);
            cout << "Combinacion ganadora: " << puntajeLanzamiento << " puntos" << endl;
            puntajeRonda1 = max(puntajeRonda1, puntajeLanzamiento);
        }

        puntajeJugador1 += puntajeRonda1;

        if (puntajeJugador1 > puntuacionMasAltaUno)
        {
            puntuacionMasAltaUno = puntajeJugador1;
        }

        cout << endl;
        cout << "=== Resultados de la Ronda N° " << numRondas << " ===" << endl;
        cout << "Jugador 1 (" << nombreJugador1 << ")" << endl;
        cout << "Puntaje de la ronda: " << puntajeRonda1 << " puntos" << endl;
        cout << "Puntaje total: " << puntajeJugador1 << " puntos" << endl;

        // Turno del Jugador 2
        cout << endl;
        cout << "Turno de " << nombreJugador2 << ":" << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << "=== Lanzamiento " << i + 1 << " ===" << endl;

            for (int j = 0; j < 6; j++)
            {
                valoresDados[j] = lanzarDado();
                cout << "Dado " << j + 1 << ": " << valoresDados[j] << endl;
            }

            int puntajeLanzamiento = calcularPuntaje(valoresDados, 6);
            cout << "Combinacion ganadora: " << puntajeLanzamiento << " puntos" << endl;
            puntajeRonda2 = max(puntajeRonda2, puntajeLanzamiento);
        }

        puntajeJugador2 += puntajeRonda2;

        if (puntajeJugador2 > puntuacionMasAltaDos)
        {
            puntuacionMasAltaDos = puntajeJugador2;
        }

        cout << endl;
        cout << "=== Resultados de la Ronda N° " << numRondas << " ===" << endl;
        cout << "Jugador 1 (" << nombreJugador1 << ")" << endl;
        cout << "Puntaje de la ronda: " << puntajeRonda1 << " puntos" << endl;
        cout << "Puntaje total: " << puntajeJugador1 << " puntos" << endl;
        cout << endl;
        cout << "Jugador 2 (" << nombreJugador2 << ")" << endl;
        cout << "Puntaje de la ronda: " << puntajeRonda2 << " puntos" << endl;
        cout << "Puntaje total: " << puntajeJugador2 << " puntos" << endl;

        cout << endl;
        cout << "Presiona Enter para continuar a la siguiente ronda...";
        cin.ignore();
        cin.get();

    } while (puntajeJugador1 < 500 && puntajeJugador2 < 500);

    if (puntajeJugador1 >= 500 && puntajeJugador2 < 500)
    {
        cout << endl;
        cout << "¡Felicidades, " << nombreJugador1 << "! Has alcanzado los: " << puntajeJugador1 << " puntos en: " << numRondas << " rondas." << endl;
    }

    if (puntajeJugador1 < 500 && puntajeJugador2 >= 500)
    {
        cout << endl;
        cout << "¡Felicidades, " << nombreJugador2 << "! Has alcanzado los: " << puntajeJugador2 << " puntos en: " << numRondas << " rondas." << endl;
    }

    if (puntajeJugador1 >= 500 && puntajeJugador2 >= 500)
    {
        if (puntajeJugador1 > puntajeJugador2)
        {
            cout << endl;
            cout << "¡Felicidades, " << nombreJugador1 << "! Has alcanzado los: " << puntajeJugador1 << " puntos en: " << numRondas << " rondas." << endl;
        }
        else if (puntajeJugador1 == puntajeJugador2)
        {
            cout << endl;
            cout << "¡Es un empate! Ambos jugadores han alcanzado los: " << puntajeJugador1 << " puntos en: " << numRondas << " rondas." << endl;
        }
        else
        {
            cout << endl;
            cout << "¡Felicidades, " << nombreJugador2 << "! Has alcanzado los: " << puntajeJugador2 << " puntos en: " << numRondas << " rondas." << endl;
        }
    }
}