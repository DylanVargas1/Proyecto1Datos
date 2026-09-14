#pragma once

// ---- Piezas ----
enum class PieceType {
    I, O, T, S, Z, J, L,
    NINGUNA   
};

const int NUM_TIPOS_PIEZA = 7; 

// ---- Tablero ----
const int TABLERO_FILAS = 20;
const int TABLERO_COLUMNAS = 10;


enum class TipoAccion {
    MOVER_IZQUIERDA,
    MOVER_DERECHA,
    ROTAR,
    BAJAR_SUAVE,     
    BAJAR_FORZADO,   
    COLOCAR,         
    HOLD             
};

enum class TipoEvento {
    AUMENTAR_VELOCIDAD,
    PIEZA_ESPECIAL_LIMPIADORA,
    REDUCIR_VISIBILIDAD_COLA
};


enum class GameState {
    MENU_INICIO,
    JUGANDO,
    PAUSA,
    INGRESANDO_NOMBRE,  
    GAME_OVER,
    REPRODUCIENDO_REPLAY
};
