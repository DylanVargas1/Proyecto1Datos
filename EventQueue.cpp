#include "EventQueue.h"

EventQueue::EventQueue() : frente(nullptr), contador(0) {
}

EventQueue::~EventQueue() {
    NodoEvento* actual = frente;
    while (actual != nullptr) {
        NodoEvento* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void EventQueue::insertarOrdenado(const GameEvent& evento) {
    NodoEvento* nuevo = new NodoEvento{evento, nullptr};

    if (frente == nullptr || evento.momentoDisparo < frente->dato.momentoDisparo) {
        nuevo->siguiente = frente;
        frente = nuevo;
        contador++;
        return;
    }

    NodoEvento* actual = frente;
    while (actual->siguiente != nullptr &&
           actual->siguiente->dato.momentoDisparo <= evento.momentoDisparo) {
        actual = actual->siguiente;
    }
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    contador++;
}

GameEvent EventQueue::verFrente() const {
    return frente->dato;
}

GameEvent EventQueue::extraerFrente() {
    NodoEvento* viejo = frente;
    GameEvent resultado = viejo->dato;
    frente = frente->siguiente;
    delete viejo;
    contador--;
    return resultado;
}

bool EventQueue::hayEventoListo(float tiempoActualPartida) const {
    if (frente == nullptr) return false;
    return frente->dato.momentoDisparo <= tiempoActualPartida;
}
