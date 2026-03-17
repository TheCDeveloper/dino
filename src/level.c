#include "level.h"
#include "log.h"

#include <stdlib.h>

#include <SDL3/SDL_render.h>


// TODO: finish struct
struct Level {
    
};


Level *level_create(void) {
    Level *self = calloc(1, sizeof(Level));

    if (!self) {
        LOG_ERROR("failed to allocate Level *!");
        return NULL;
    }

    LOG_DEBUG("allocated Level * %p", self);

    return self;
}


void level_destroy(Level *level) {
    LOG_DEBUG("freeing Level * %p", level);
    free(level);
}


// TODO: implement
void level_update(Level *level, const SDL_Event *event, float delta_time) {

}


// TODO: implement
void level_draw(Level *level, SDL_Renderer *renderer) {

}
