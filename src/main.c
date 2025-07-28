/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#define speed 2
#define start_x 400
#define start_y 200

typedef enum GameScreen {
    SCREEN_MENU = 0,
    SCREEN_SETTINGS,
    SCREEN_MAP,
	SCREEN_GAMEPLAY,
    SCREEN_EXIT
} GameScreen;

void updateMenu(GameScreen *currentScreen);
void drawMenu(GameScreen currentScreen);

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	GameScreen currentScreen = SCREEN_MENU;
	int pos_x = start_x;
	int pos_y = start_y;
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		updateMenu(&currentScreen);
		// drawing
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Setup the back buffer for drawing (clear color and depth buffers)
		// draw our texture to the screen
		
		drawMenu(currentScreen);
		if (currentScreen == SCREEN_GAMEPLAY)
		{
			DrawTexture(wabbit, pos_x, pos_y, WHITE);
		}

		EndDrawing();
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		if (IsKeyDown(KEY_W))
		{
			pos_y -= speed;
		}
		else if (IsKeyDown(KEY_S))
		{
			pos_y += speed;
		}
		if (IsKeyDown(KEY_A))
		{
			pos_x -= speed;
		}
		else if (IsKeyDown(KEY_D))
		{
			pos_x += speed;
		}
		
		
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

void updateMenu(GameScreen *currentScreen){
	switch (*currentScreen)
{
	case SCREEN_MENU:
		// Update menu logic (e.g. check button presses)
		if (IsKeyPressed(KEY_ENTER)) *currentScreen = SCREEN_GAMEPLAY;
		if (IsKeyPressed(KEY_S)) *currentScreen = SCREEN_SETTINGS;
		break;

	case SCREEN_SETTINGS:
		// Update settings logic
		if (IsKeyPressed(KEY_BACKSPACE)) *currentScreen = SCREEN_MENU;
		break;

	case SCREEN_GAMEPLAY:
		// Update gameplay logic
		if (IsKeyPressed(KEY_ESCAPE)) *currentScreen = SCREEN_MENU;
		break;

	default: break;
}
}

void drawMenu(GameScreen currentScreen){
	switch (currentScreen)
    {
        case SCREEN_MENU:
            DrawText("MAIN MENU", 100, 100, 30, BLACK);
            DrawText("Press ENTER to Play", 100, 150, 20, DARKGRAY);
            DrawText("Press S for Settings", 100, 180, 20, DARKGRAY);
            break;

        case SCREEN_SETTINGS:
            DrawText("SETTINGS", 100, 100, 30, BLACK);
            DrawText("Press BACKSPACE to return", 100, 150, 20, DARKGRAY);
            break;

        case SCREEN_GAMEPLAY:
            DrawText("GAMEPLAY", 100, 100, 30, BLACK);
            DrawText("Press ESC to exit", 100, 150, 20, DARKGRAY);
            break;

        default: break;
    }
}
