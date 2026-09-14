#pragma once
// Random.h
// Generador de numeros aleatorios propio, usado unicamente como utilidad
// auxiliar (no sustituye ninguna de las 6 estructuras evaluadas).
// Se apoya en <random> de la biblioteca estandar, que esta permitido
// para entrada/salida y utilidades generales segun el enunciado.

#include <random>

class Random {
public:
    // Constructor: siembra el generador con una semilla basada en tiempo.
    Random();

    // Devuelve un entero en el rango [minimo, maximo] (ambos incluidos).
    int entero(int minimo, int maximo);

    // Mezcla un arreglo de PieceType de tamano n usando Fisher-Yates.
    // Este algoritmo de mezcla se implementa a mano (no std::shuffle)
    // para que el estudiante pueda explicarlo en la defensa.
    template <typename T>
    void mezclarArreglo(T* arreglo, int n) {
        for (int i = n - 1; i > 0; --i) {
            int j = entero(0, i);
            T temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
        }
    }

private:
    std::mt19937 motor;
};
