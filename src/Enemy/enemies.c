#include "enemies.h"
#include <stdio.h>

/**
 * @brief Draws the player to the screen using raylib's function.
 */
void draw_enemies(const Enemy* enemies, int MAX_ENEMIES) {
    for(int i= 0; i<MAX_ENEMIES; i++){
        if (enemies[i].alive == 1) {
            // Use raylib's drawing function
            DrawTexture(enemies[i].texture, (int)enemies[i].x, (int)enemies[i].y, RED);  // gathers the player's position and draws the texture wihtth white color
            //note: not logges due to the nature of drawing functions in raylib. See debugging section in the main.c file for the logging of the drawing action
        }
    }
    
}

void spawn_enemies(Enemy enemies[], int MAX_ENEMIES, int* enemy_count){
    Texture2D bandit_texture = LoadTexture("wabbit_alpha.png");
    if (*enemy_count < MAX_ENEMIES) {
        int x = GetRandomValue(10, 1000);
        int y = GetRandomValue(10, 1000);
        enemies[*enemy_count] = (Enemy){bandit_texture, x, y, 100, (char) *enemy_count, 1}; // hp=100, pos=(10,20)
        (*enemy_count)++;
    }
}

void update_enemies(Enemy* enemies[], int MAX_ENEMIES){
    for(int i= 0; i<MAX_ENEMIES; i++){
        if(enemies[i]->hp==0 && enemies[i]->alive==1){
            enemies[i]->alive=0;
        }
    }
}