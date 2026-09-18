#pragma once


#include "../core/Types.h"

struct GameEvent {
    TipoEvento tipo;
    float momentoDisparo; 

struct NodoEvento {
    GameEvent dato;
    NodoEvento* siguiente;
};

class EventQueue {
public:
    EventQueue();
    ~EventQueue();

    
    void insertarOrdenado(const GameEvent& evento);

    bool vacia() const { return frente == nullptr; }

    
    GameEvent verFrente() const;

    
    GameEvent extraerFrente();

    
    bool hayEventoListo(float tiempoActualPartida) const;

    int cantidad() const { return contador; }

private:
    NodoEvento* frente;
    int contador;
};
