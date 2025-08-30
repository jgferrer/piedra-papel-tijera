# Piedra, Papel o Tijera - Sega Mega Drive

Un juego clásico de Piedra, Papel o Tijera desarrollado para la consola Sega Mega Drive usando SGDK (Sega Genesis Development Kit).

## Características

- **Menú Principal** con navegación por joystick
  - Jugar: Inicia una partida contra la IA
  - Créditos: Muestra información del desarrollador
  - Salir: Finaliza el juego

- **Juego Principal**
  - Tres opciones: Piedra, Papel, Tijera
  - IA con selección aleatoria
  - Resultados en español: "¡Ganaste!", "¡Perdiste!", "¡Empate!"
  - Control total con joystick de Mega Drive

- **Interfaz en Español**
  - Todos los textos y mensajes en español
  - Navegación intuitiva con flechas direccionales

## Estructura del Proyecto

```
piedra-papel-tijera/
├── res/                    # Recursos (sprites, música, etc.)
│   └── resources.res       # Definición de recursos SGDK
├── src/                    # Código fuente en C
│   └── main.c             # Código principal del juego
├── inc/                    # Archivos de cabecera
│   └── game.h             # Definiciones del juego
└── README.md              # Este archivo
```

## Requisitos

Para compilar este proyecto necesitas:

1. **SGDK (Sega Genesis Development Kit)**
   - Descargar desde: https://github.com/Stephane-D/SGDK
   - Versión recomendada: 1.80 o superior

2. **Java Runtime Environment (JRE)**
   - Para ejecutar las herramientas de SGDK
   - Java 8 o superior

## Instalación y Compilación

### 1. Configurar SGDK

1. Descarga SGDK desde el repositorio oficial
2. Extrae el archivo en una carpeta (ej: `C:\sgdk` en Windows)
3. Configura la variable de entorno `GDK` que apunte a la carpeta de SGDK
   
   **Windows:**
   ```bash
   set GDK=C:\sgdk
   set PATH=%GDK%\bin;%PATH%
   ```
   
   **Linux/Mac:**
   ```bash
   export GDK=/path/to/sgdk
   export PATH=$GDK/bin:$PATH
   ```

### 2. Compilar el Proyecto

1. Abre una terminal/consola de comandos
2. Navega hasta la carpeta del proyecto
3. Ejecuta el comando de compilación:

   **Windows:**
   ```bash
   %GDK%\bin\make -f %GDK%\makefile.gen
   ```
   
   **Linux/Mac:**
   ```bash
   make -f $GDK/makefile.gen
   ```

### 3. Resultado

Si la compilación es exitosa, se generará un archivo `rom.bin` que puedes:

- Cargar en un emulador de Mega Drive (Gens, Fusion, etc.)
- Grabar en un cartucho flash para consola real
- Ejecutar en Mega EverDrive u otros dispositivos similares

## Controles

- **Flechas Arriba/Abajo**: Navegar menús y opciones
- **Botón A**: Confirmar selección / Jugar
- **Botón B**: Volver al menú anterior

## Cómo Jugar

1. En el menú principal, selecciona "JUGAR"
2. Usa las flechas para elegir entre Piedra, Papel o Tijera
3. Presiona el botón A para confirmar tu elección
4. El juego mostrará tu elección, la de la IA y el resultado
5. Presiona cualquier botón para jugar otra ronda

### Reglas

- **Piedra** vence a **Tijera**
- **Papel** vence a **Piedra**  
- **Tijera** vence a **Papel**
- Si ambos eligen lo mismo, es **Empate**

## Desarrollo

Este proyecto está desarrollado en C usando las librerías de SGDK. El código está organizado de manera modular para facilitar futuras expansiones como:

- Sprites animados para las opciones
- Música de fondo
- Efectos de sonido
- Contador de puntuación
- Modo multijugador

## Licencia

Este proyecto es de código abierto. Siéntete libre de modificarlo y distribuirlo.

## Créditos

Desarrollado para la comunidad de Sega Mega Drive usando SGDK.