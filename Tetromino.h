#pragma once


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
    void celdasParaOrientacion(int orientacionCandidata, Celda salida[4]) const;

	
    void rotarSiguiente() { orientacion = (orientacion + 1) % 4; }
	

private:
    PieceType tipoPieza;

    
    static const int TABLA_FORMAS[7][4][4][2];
};
