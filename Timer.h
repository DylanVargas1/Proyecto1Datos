#pragma once
// Se usará para: la caida automatica de piezas, el reloj de la cola de
// eventos, y la medicion de tiempos de los algoritmos de ordenamiento.

#include <chrono>

class Timer {
public:
    Timer();

    // Reinicia el cronometro a 0.
    void reiniciar();

    
	float segundosTranscurridos() const;

private:
    std::chrono::high_resolution_clock::time_point inicio;
};

// Utilidad estatica para medir bloques de codigo

template <typename Funcion>
double MedirTiempoMs(Funcion f) {
    auto t0 = std::chrono::high_resolution_clock::now();
    f();
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = t1 - t0;
    return duracion.count();
}
