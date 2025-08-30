#ifndef GAME_H
#define GAME_H

// Definiciones para el juego Piedra, Papel o Tijera

// Estados del juego
typedef enum {
    ESTADO_MENU,
    ESTADO_JUEGO,
    ESTADO_CREDITOS
} EstadoJuego;

// Opciones del juego
typedef enum {
    PIEDRA = 0,
    PAPEL = 1,
    TIJERA = 2
} OpcionJuego;

// Funciones del juego
void mostrarMenu();
void mostrarCreditos();
void mostrarJuego();
void mostrarResultado(int resultado);
OpcionJuego seleccionIA();
int determinarGanador(OpcionJuego jugador, OpcionJuego ia);
const char* getNombreOpcion(OpcionJuego opcion);

#endif // GAME_H