#pragma once


#include "../core/Types.h"

class HoldStack {
public:
    HoldStack();

    bool estaVacia() const { return vacia; }

    
    void push(PieceType tipo);

    
    PieceType pop();

    PieceType peek() const { return contenido; }

private:
    PieceType contenido;
    bool vacia;
};
