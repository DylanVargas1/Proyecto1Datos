#pragma once
// Tetromino.h
// Representa una pieza (tetromino) con sus 4 orientaciones PRECALCULADAS.
// No hay sistema de wall kick: si la orientacion siguiente no cabe
// (colision o fuera del tablero), la pieza simplemente no rota.
//
// Cada pieza vive dentro de una caja imaginaria de 4x4 celdas. Cada
// orientacion se representa como 4 pares (fila, columna) dentro de esa
// caja. Esto hace que rotar sea trivial: solo se cambia el indice de
// orientacion (0..3) y se reconsulta la tabla precalculada; nunca se
// recalculan coordenadas con formulas de rotacion en tiempo real.

#include "../core/Types.h"

struct Celda { int fila; int columna; };

class Tetromino {
public:
    Tetromino(PieceType tipo);

    PieceType tipo() const { return tipoPieza; }

    // Posicion de la pieza: fila/columna de la esquina superior
    // izquierda de su caja 4x4 dentro del tablero.
    int filaBase, columnaBase;
    int orientacion; // 0..3

    // Devuelve las 4 celdas ocupadas (en coordenadas ABSOLUTAS del
    // tablero) para la orientacion actual.
    void celdasAbsolutas(Celda salida[4]) const;

    // Devuelve las 4 celdas para una orientacion dada (sin modificar
    // el estado de la pieza) -- usado para probar si una rotacion cabe.
    void celdasParaOrientacion(int orientacionCandidata, Celda salida[4]) const;

    void rotarSiguiente() { orientacion = (orientacion + 1) % 4; }

private:
    PieceType tipoPieza;

    // Tabla de formas: [orientacion][celda][fila,columna] dentro de
    // una caja 4x4. Definida en el .cpp para cada uno de los 7 tipos.
    static const int TABLA_FORMAS[7][4][4][2];
};
