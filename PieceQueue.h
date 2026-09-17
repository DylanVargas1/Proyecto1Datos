#pragma once

#include "../core/Types.h"
#include "../core/Random.h"

struct NodoPieza {
    PieceType tipo;
    NodoPieza* siguiente;
};

class PieceQueue {
public:
    PieceQueue();
    ~PieceQueue(); 

   
    void encolar(PieceType tipo);

    
    PieceType desencolar();

    
    PieceType consultar(int posicion) const;

    bool vacia() const { return frente == nullptr; }
    int cantidad() const { return contador; }

    void generarBolsa();

    void asegurarPiezasVisibles(int minimoVisible = 3);

private:
    NodoPieza* frente;
    NodoPieza* final;
    int contador;
    Random generadorAleatorio;
};
