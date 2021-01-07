#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "window.h"

Window *Window_new(int width, int height)
{
    Window *window = NULL;
    Renderer *renderer = NULL;
    int exitStatus;

    window = (Window *)calloc(1, sizeof(Window));
    if (!window) goto ERROR_LABEL;

    renderer = (Renderer *)calloc(1, sizeof(Renderer));
    if (!renderer) goto ERROR_LABEL;

    window->m_renderer = renderer;
    renderer->m_width = width;
    renderer->m_height = height;

    window->m_windowSDL = SDL_CreateWindow(
        "PhysiX Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_OPENGL);

    if (!window->m_windowSDL)
    {
        printf("ERROR - SDL_CreateWindow\n");
        printf("      - SDL : %s\n", SDL_GetError());
        goto ERROR_LABEL;
    }

    renderer->m_rendererSDL = SDL_CreateRenderer(
        window->m_windowSDL, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer->m_rendererSDL)
    {
        printf("ERROR - SDL_CreateRenderer\n");
        printf("      - SDL : %s\n", SDL_GetError());
        goto ERROR_LABEL;
    }

    exitStatus = SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    if (exitStatus == SDL_FALSE)
    {
        exitStatus = SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    }
    SDL_SetRenderDrawColor(renderer->m_rendererSDL, 0, 0, 0, 255);

    return window;

ERROR_LABEL:
    printf("ERROR - Window_new()\n");
    free(window);
    return NULL;
}

void Window_free(Window * window)
{
    if (!window) return;

    if (window->m_windowSDL)
    {
        SDL_DestroyWindow(window->m_windowSDL);
    }
    if (window->m_renderer)
    {
        Renderer *renderer = window->m_renderer;
        if (renderer->m_rendererSDL)
            SDL_DestroyRenderer(renderer->m_rendererSDL);

        free(renderer);
    }
    free(window);
}

Renderer *Window_getRenderer(Window *window)
{
    return window->m_renderer;
}

int SDL_init()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("ERROR - SDL_Init()\n");
        printf("      - SDL : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void SDL_quit()
{
    SDL_Quit();
}
