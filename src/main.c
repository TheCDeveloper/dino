#include "game.h"
#include "log.h"


int main(int argc, char *argv[]) {
    LOG_PRINT("version: 0.1.0");

    Game *game = game_create();

    if (!game) {
        LOG_ERROR("exiting...");
        return 1;
    }

    game_run(game);

    LOG_PRINT("quitting");
    game_destroy(game);
    return 0;
}
