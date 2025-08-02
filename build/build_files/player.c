#include "player.h"
#include <stdio.h>

// --- Function Definitions ---

/**
 * @brief Initializes the player's texture, position, and speed.
 */
void initialize_player(Player* player, const char* texture_path, float start_x, float start_y, float speed) {
    if (player != NULL) {
        player->texture = LoadTexture(texture_path); // Use raylib's function
        player->x_pos = start_x;
        player->y_pos = start_y;
        player->speed = speed;
		printf("Player initialized with texture '%s' at (%.2f, %.2f)\n", texture_path, start_x, start_y);  // Log the initialization action
    }
}

/**
 * @brief Updates the player's position based on raylib input.
 */
void move_player(Player* player, float delta_time) {
    if (player != NULL) {
        // Use raylib's input functions
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
            player->y_pos -= player->speed * delta_time;
        }
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
            player->y_pos += player->speed * delta_time;
        }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            player->x_pos -= player->speed * delta_time;
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            player->x_pos += player->speed * delta_time;
        }
    }
}

/**
 * @brief Draws the player to the screen using raylib's function.
 */
void draw_player(const Player* player) {
    if (player != NULL) {
        // Use raylib's drawing function
		DrawTexture(player->texture, (int)player->x_pos, (int)player->y_pos, WHITE);  // gathers the player's position and draws the texture wihtth white color
		//note: not logges due to the nature of drawing functions in raylib. See debugging section in the main.c file for the logging of the drawing action
    }
}

/**
 * @brief Unloads the player's texture from memory.
 */
void unload_player(Player* player) {
    if (player != NULL) {
        UnloadTexture(player->texture); // Use raylib's unload function
		printf("Player texture unloaded.\n");  // Log the unloading action
    }
}