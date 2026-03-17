#include "game.h"
#include "level.h"
#include "log.h"

#include <stdbool.h>
#include <stdlib.h>

#include <SDL3/SDL.h>


struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool should_quit;

    Level *level;
};


static void handle_events(Game *game, const SDL_Event *event) {
    switch (event->type) {
        case SDL_EVENT_QUIT:
            LOG_DEBUG("window close requested");
            game->should_quit = true;
            break;

        default:
            break;
    }
}


Game *game_create(void) {
    LOG_DEBUG("initializing SDL");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        LOG_ERROR("SDL initialization failed! %s", SDL_GetError());
        return NULL;
    }


    LOG_DEBUG("initializing SDL objects");

    SDL_Window *window = SDL_CreateWindow("Dino", 800, 450, 0);

    if (!window) {
        LOG_ERROR("SDL window creation failed! %s", SDL_GetError());
        SDL_Quit();

        return NULL;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    if (!renderer) {
        LOG_ERROR("SDL renderer creation failed! %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();

        return NULL;
    }


    Game *self = calloc(1, sizeof(Game));

    if (!self) {
        LOG_ERROR("failed to allocate Game *!");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return NULL;
    }

    LOG_DEBUG("allocated Game * %p", self);

    self->window = window;
    self->renderer = renderer;


    LOG_DEBUG("initializing game objects");

    self->level = level_create();


    return self;
}


void game_destroy(Game *game) {
    LOG_DEBUG("deinitializing game objects");
    level_destroy(game->level);

    LOG_DEBUG("deinitializing SDL objects");
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    LOG_DEBUG("freeing Game * %p", game);
    free(game);

    LOG_DEBUG("deinitializing SDL");
    SDL_Quit();
}


void game_run(Game *game) {
    game->should_quit = false;
    
    while (!game->should_quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            handle_events(game, &event);
        }

        SDL_RenderClear(game->renderer);
        SDL_RenderPresent(game->renderer);
    }
}
