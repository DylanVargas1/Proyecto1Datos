#pragma once
// Timer.h
// Cronometro simple basado en <chrono> (estandar de C++, portable entre
// Visual Studio y ZinjaI, no depende de SFML).
// Se usa para: la caida automatica de piezas, el reloj de la cola de
// eventos, y la medicion de tiempos de los algoritmos de ordenamiento.

#include <chrono>

class Timer {
public:
    Timer();

    // Reinicia el cronometro a 0.
    void reiniciar();

    // Segundos transcurridos desde la ultima llamada a reiniciar().
    float segundosTranscurridos() const;

private:
    std::chrono::high_resolution_clock::time_point inicio;
};

// Utilidad estatica para medir bloques de codigo (usada en el benchmark
// de los algoritmos de ordenamiento). Uso:
//   double ms = MedirTiempoMs([&](){ miFuncion(); });
template <typename Funcion>
double MedirTiempoMs(Funcion f) {
    auto t0 = std::chrono::high_resolution_clock::now();
    f();
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = t1 - t0;
    return duracion.count();
}
