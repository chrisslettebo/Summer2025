#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"  // raylib header for graphics and input handling
#include "resource_dir.h"  // utility header for SearchAndSetResourceDir


typedef struct Player {
    Texture2D texture;  // Raylib's texture type
	float x_pos;  // Player's x position
	float y_pos;  // Player's y position
	float speed;  // Player's movement speed
} Player;


// Function declarations (prototypes)
void initialize_player(Player* player, const char* texture_path, float start_x, float start_y, float speed);
void move_player(Player* player, float delta_time);
void draw_player(const Player* player);
void unload_player(Player* player);

#endif // PLAYER_H

