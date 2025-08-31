#include <genesis.h>
#include <resources.h>

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

// Variables globales
EstadoJuego estadoActual = ESTADO_MENU;
int opcionMenu = 0;
int opcionJugador = 0;
int opcionIA = 0;
int mostrandoResultado = 0;
int contadorResultado = 0;

// Función para mostrar el menú principal
void mostrarMenu() {
    VDP_clearPlane(BG_A, TRUE);
    
    VDP_drawText("PIEDRA, PAPEL O TIJERA", 8, 4);
    VDP_drawText("=====================", 8, 5);
    VDP_drawText("", 0, 7);
    
    if (opcionMenu == 0) {
        VDP_drawText("> JUGAR", 15, 9);
        VDP_drawText("  CREDITOS", 15, 11);
        VDP_drawText("  SALIR", 15, 13);
    } else if (opcionMenu == 1) {
        VDP_drawText("  JUGAR", 15, 9);
        VDP_drawText("> CREDITOS", 15, 11);
        VDP_drawText("  SALIR", 15, 13);
    } else {
        VDP_drawText("  JUGAR", 15, 9);
        VDP_drawText("  CREDITOS", 15, 11);
        VDP_drawText("> SALIR", 15, 13);
    }
    
    VDP_drawText("Usa las flechas y BUTTON A", 6, 16);
}

// Función para mostrar la pantalla de créditos
void mostrarCreditos() {
    VDP_clearPlane(BG_A, TRUE);
    
    VDP_drawText("CREDITOS", 16, 6);
    VDP_drawText("========", 16, 7);
    VDP_drawText("", 0, 9);
    VDP_drawText("Desarrollado por:", 12, 11);
    VDP_drawText("Tu Nombre Aqui", 13, 12);
    VDP_drawText("", 0, 14);
    VDP_drawText("Para Sega Mega Drive", 10, 15);
    VDP_drawText("Usando SGDK", 14, 16);
    VDP_drawText("", 0, 18);
    VDP_drawText("Presiona BUTTON B para volver", 5, 20);
}

// Función para mostrar la pantalla del juego
void mostrarJuego() {
    VDP_clearPlane(BG_A, TRUE);
    
    VDP_drawText("ELIGE TU OPCION:", 12, 4);
    VDP_drawText("================", 12, 5);
    VDP_drawText("", 0, 7);
    
    if (opcionJugador == 0) {
        VDP_drawText("> PIEDRA", 16, 9);
        VDP_drawText("  PAPEL", 16, 11);
        VDP_drawText("  TIJERA", 16, 13);
    } else if (opcionJugador == 1) {
        VDP_drawText("  PIEDRA", 16, 9);
        VDP_drawText("> PAPEL", 16, 11);
        VDP_drawText("  TIJERA", 16, 13);
    } else {
        VDP_drawText("  PIEDRA", 16, 9);
        VDP_drawText("  PAPEL", 16, 11);
        VDP_drawText("> TIJERA", 16, 13);
    }
    
    VDP_drawText("BUTTON A para jugar", 10, 16);
    VDP_drawText("BUTTON B para menu", 11, 17);
}

// Función para obtener nombre de la opción
const char* getNombreOpcion(OpcionJuego opcion) {
    switch(opcion) {
        case PIEDRA: return "PIEDRA";
        case PAPEL: return "PAPEL";
        case TIJERA: return "TIJERA";
        default: return "ERROR";
    }
}

// Función para determinar el ganador
int determinarGanador(OpcionJuego jugador, OpcionJuego ia) {
    if (jugador == ia) return 0; // Empate
    
    if ((jugador == PIEDRA && ia == TIJERA) ||
        (jugador == PAPEL && ia == PIEDRA) ||
        (jugador == TIJERA && ia == PAPEL)) {
        return 1; // Jugador gana
    }
    
    return -1; // IA gana
}

// Función para mostrar el resultado
void mostrarResultado(int resultado) {
    VDP_clearPlane(BG_A, TRUE);
    
    VDP_drawText("RESULTADO DEL JUEGO", 10, 4);
    VDP_drawText("===================", 10, 5);
    VDP_drawText("", 0, 7);
    
    char textoJugador[32];
    char textoIA[32];
    sprintf(textoJugador, "Tu eleccion: %s", getNombreOpcion(opcionJugador));
    sprintf(textoIA, "IA eligio: %s", getNombreOpcion(opcionIA));
    
    VDP_drawText(textoJugador, 40 - strlen(textoJugador), 9);
    VDP_drawText(textoIA, 40 - strlen(textoIA), 11);
    VDP_drawText("", 0, 13);
    
    if (resultado == 0) {
        VDP_drawText("EMPATE!", 16, 15);
    } else if (resultado == 1) {
        VDP_drawText("GANASTE!", 15, 15);
    } else {
        VDP_drawText("PERDISTE!", 15, 15);
    }
    
    VDP_drawText("", 0, 17);
    VDP_drawText("Presiona cualquier boton", 8, 19);
    VDP_drawText("para continuar", 13, 20);
}

// Función para generar selección aleatoria de la IA
OpcionJuego seleccionIA() {
    // Usar el timer del sistema para generar aleatoriedad
    u32 seed = getTick();
    return (OpcionJuego)(seed % 3);
}

// Función para manejar input del menú
void manejarInputMenu(u16 joy) {
    if (joy & BUTTON_UP) {
        if (opcionMenu > 0) opcionMenu--;
        mostrarMenu();
    }
    
    if (joy & BUTTON_DOWN) {
        if (opcionMenu < 2) opcionMenu++;
        mostrarMenu();
    }
    
    if (joy & BUTTON_A) {
        if (opcionMenu == 0) {
            estadoActual = ESTADO_JUEGO;
            opcionJugador = 0;
            mostrarJuego();
        } else if (opcionMenu == 1) {
            estadoActual = ESTADO_CREDITOS;
            mostrarCreditos();
        } else {
            // Salir del juego (en una consola real esto podría mostrar un mensaje)
            VDP_clearPlane(BG_A, TRUE);
            VDP_drawText("GRACIAS POR JUGAR!", 11, 12);
            VDP_drawText("", 0, 14);
            VDP_drawText("Apaga la consola", 12, 15);
        }
    }
}

// Función para manejar input del juego
void manejarInputJuego(u16 joy) {
    if (!mostrandoResultado) {
        if (joy & BUTTON_UP) {
            if (opcionJugador > 0) opcionJugador--;
            mostrarJuego();
        }
        
        if (joy & BUTTON_DOWN) {
            if (opcionJugador < 2) opcionJugador++;
            mostrarJuego();
        }
        
        if (joy & BUTTON_A) {
            // Jugar
            opcionIA = seleccionIA();
            int resultado = determinarGanador(opcionJugador, opcionIA);
            mostrarResultado(resultado);
            mostrandoResultado = 1;
            contadorResultado = 0;
        }
        
        if (joy & BUTTON_B) {
            // Volver al menú
            estadoActual = ESTADO_MENU;
            opcionMenu = 0;
            mostrarMenu();
        }
    } else {
        // Mostrar resultado por unos frames
        if (contadorResultado > 120) { // Aprox 2 segundos a 60 FPS
            if (joy != 0) { // Cualquier botón presionado
                mostrandoResultado = 0;
                opcionJugador = 0;
                mostrarJuego();
            }
        }
        contadorResultado++;
    }
}

// Función para manejar input de créditos
void manejarInputCreditos(u16 joy) {
    if (joy & BUTTON_B) {
        estadoActual = ESTADO_MENU;
        opcionMenu = 0;
        mostrarMenu();
    }
}

int main() {
    // Inicializar SGDK
    VDP_setScreenWidth320();
    VDP_setScreenHeight224();
    
    // Mostrar pantalla inicial
    mostrarMenu();
    
    u16 joyPrev = 0;
    
    while(1) {
        u16 joy = JOY_readJoypad(JOY_1);
        u16 joyPressed = joy & ~joyPrev;
        
        // Manejar input según el estado actual
        switch(estadoActual) {
            case ESTADO_MENU:
                if (joyPressed) manejarInputMenu(joyPressed);
                break;
            case ESTADO_JUEGO:
                if (joyPressed || mostrandoResultado) manejarInputJuego(joyPressed);
                break;
            case ESTADO_CREDITOS:
                if (joyPressed) manejarInputCreditos(joyPressed);
                break;
        }
        
        joyPrev = joy;
        SYS_doVBlankProcess();
    }
    
    return 0;
}