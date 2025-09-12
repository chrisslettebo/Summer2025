#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"  // raylib header for graphics and input handling
#include "resource_dir.h"  // utility header for SearchAndSetResourceDir

typedef struct Enemy
{
	Texture2D texture;
	int x;
	int y;
	int hp;
	char name;
	int alive;
} Enemy;

void draw_enemies(const Enemy* enemies, int MAX_ENEMIES);
void spawn_enemies(Enemy enemies[], int MAX_ENEMIES, int* enemy_count);
void update_enemies(Enemy enemies[], int MAX_ENEMIES);
void unload_enemies(Enemy* enemies, int MAX_ENEMIES);


#endif // Enemy