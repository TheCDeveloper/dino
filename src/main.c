#include "game.h"


int main(int argc, char *argv[]) {
    Game *game = game_create();

    if (!game) {
        return 1;
    }

    game_run(game);
    game_destroy(game);
    return 0;
}
