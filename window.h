#ifndef _WINDOW_H_
#define _WINDOW_H_

/// @file window.h
/// @defgroup Window
/// @{

#include "renderer.h"

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 720

/// @brief Structure représentant une fenêtre SDL avec son moteur de rendu.
typedef struct Window_s
{
    /// @brief La fenêtre SDL.
    SDL_Window  *m_windowSDL;

    /// @brief Le moteur de rendu associé à la fenêtre.
    Renderer *m_renderer;
} Window;

/// @brief Crée une nouvelle fenêtre.
/// @param[in] width la largeur (en pixels) de la fenêtre.
/// @param[in] height la hauteur (en pixels) de la fenêtre. 
/// @return La fenêtre créée.
Window *Window_new(int width, int height);

/// @brief Détruit une fenêtre préalablement allouée avec Window_new();
/// @param[in,out] window la fenêtre à détruire. 
void Window_free(Window * window);

/// @brief Renvoie le moteur de rendu associé à la fenêtre.
/// @param[in] window la fenêtre.
/// @return Le moteur de rendu de la fenêtre.
Renderer *Window_getRenderer(Window *window);

/// @brief Initialise la SDL.
/// @return EXIT_SUCCESS ou EXIT_FAILURE.
int SDL_init();

/// @brief Quitte la SDL.
void SDL_quit();

#endif
