#include "collision.h"
#include <stdio.h>

void handleCollisions(Player *player, Enemy enemies[], int enemyCount) {
    for (int i = 0; i < enemyCount; i++) {
        Vector2 vec_P = {player->x_pos, player->y_pos};
        Vector2 vec_E = {enemies[i].x, enemies[i].y};
        if (CheckCollisionCircles(vec_P, player->texture.width, vec_E, enemies[i].texture.width)) {
            enemies[i].alive=0;
        }
    }
}
