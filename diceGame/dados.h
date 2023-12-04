// dados.h

#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <string>

using namespace std;

int lanzarDado();
int calcularPuntaje(int valores[], int numDados);
void mostrarPuntuacionMasAlta();

extern int puntuacionMasAltaUno;
extern int puntuacionMasAltaDos;
extern string jugadorUno;
extern string jugadorDos;

#endif