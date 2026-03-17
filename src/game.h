#ifndef GAME_H
#define GAME_H

typedef struct Game Game;

Game *game_create(void);
void game_destroy(Game *game);
void game_run(Game *game);

#endif // GAME_H
