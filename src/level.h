#ifndef LEVEL_H
#define LEVEL_H

#include <SDL3/SDL_events.h>

typedef struct SDL_Renderer SDL_Renderer;

typedef struct Level Level;

Level *level_create(void);
void level_destroy(Level *level);
void level_update(Level *level, const SDL_Event *event, float delta_time);
void level_draw(Level *level, SDL_Renderer *renderer);

#endif // LEVEL_H
