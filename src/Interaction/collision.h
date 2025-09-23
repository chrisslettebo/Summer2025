#ifndef collision
#define collision

#include "../Player/player.h"
#include "../Enemy/enemies.h"
#include "raylib.h"  // raylib header for graphics and input handling
#include "resource_dir.h"  // utility header for SearchAndSetResourceDir

void handleCollisions(Player *player, Enemy enemies[], int enemyCount);

#endif // collision