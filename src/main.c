/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include <stdio.h>  // strandard input/output header for printf and sprintf functions
#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "../build/build_files/player.h"


typedef enum GameScreen {
    SCREEN_MENU = 0,
    SCREEN_SETTINGS,
    SCREEN_MAP,
	SCREEN_GAMEPLAY,
	SCREEN_PAUSE,
    SCREEN_EXIT
} GameScreen;

typedef struct Button {
	int x;
	int y;
	int width;
	int height;
	char *text;
	bool hovering;
	bool activated; 
} Button;


void drawButton(Button button, int fontsize, Color color);
//void drawButton(x, y, w, h)
int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Initialize a player structure
	Player my_player;
	// Call the modular function to initialize the player
	initialize_player(&my_player, "wabbit_alpha.png", 600.0f, 300.0f, 500.0f);
	// Set the target FPS to 60
	GameScreen currentScreen = SCREEN_MENU;

	
	Vector2 mousePoint = { 0.0f, 0.0f };
	// menu resources
	Button menuButtonStart = {550, 300, 200, 50, "START", false, false};
	Rectangle menuRec = {menuButtonStart.x, menuButtonStart.y, menuButtonStart.width, menuButtonStart.height};
	Button menuButtonSettings = {550, 380, 200, 50, "SETTINGS", false, false};
	Rectangle menuSRec = {menuButtonSettings.x, menuButtonSettings.y, menuButtonSettings.width, menuButtonSettings.height};

	//enemies
	int capacity = 10;
    int count = 0;
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{	
		// functions
		mousePoint = GetMousePosition();
		switch (currentScreen)
		{
			case SCREEN_MENU:
				// Update menu logic (e.g. check button presses)
				if (IsKeyPressed(KEY_ENTER)) currentScreen = SCREEN_GAMEPLAY;
				if (IsKeyPressed(KEY_S)) currentScreen = SCREEN_SETTINGS;
				menuButtonStart.activated = false;
				if (CheckCollisionPointRec(mousePoint, menuRec))
					{
						if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) menuButtonStart.activated = true;
						else menuButtonStart.hovering = true;
					}
					else {
						menuButtonStart.hovering = false;
					}

				if (menuButtonStart.activated == true) {
					currentScreen = SCREEN_GAMEPLAY;
				}
				menuButtonSettings.activated = false;
				if (CheckCollisionPointRec(mousePoint, menuSRec))
					{
						if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) menuButtonSettings.activated = true;
						else menuButtonSettings.hovering = true;
					}
					else {
						menuButtonSettings.hovering = false;
					}

				if (menuButtonSettings.activated == true) currentScreen = SCREEN_SETTINGS;
				break;
		
			case SCREEN_SETTINGS:
				// Update settings logic
				if (IsKeyPressed(KEY_BACKSPACE)) currentScreen = SCREEN_MENU;
				break;
		
			case SCREEN_GAMEPLAY:
				// Update gameplay logic
				if (IsKeyPressed(KEY_BACKSPACE)) currentScreen = SCREEN_MENU;
				// Update the game state
				float delta_time = GetFrameTime(); // Get the delta time from raylib and use it for consistency over different frame rates
				move_player(&my_player, delta_time); // Call the player movement function

				// end the frame and get ready for the next one  (display frame, poll input, etc...)
		
			default: break;
		}
		// Setup the back buffer for drawing (clear color and depth buffers)
		// draw our texture to the screen
		BeginDrawing();
		ClearBackground(RAYWHITE);
		switch (currentScreen)
		{
			case SCREEN_MENU:
				DrawText("MAIN MENU", 100, 100, 30, BLACK);
				DrawText("Press ENTER to Play", 100, 150, 20, DARKGRAY);
				DrawText("Press S for Settings", 100, 180, 20, DARKGRAY);
				DrawText("Press ESC to exit", 100, 210, 20, DARKGRAY);
				if(menuButtonStart.hovering) drawButton(menuButtonStart, 30, RED);
				else drawButton(menuButtonStart, 30, GRAY);
				if(menuButtonSettings.hovering) drawButton(menuButtonSettings, 30, RED);
				else drawButton(menuButtonSettings, 30, GRAY);
				break;

			case SCREEN_SETTINGS:
				DrawText("SETTINGS", 100, 100, 30, BLACK);
				DrawText("Press BACKSPACE to return", 100, 150, 20, DARKGRAY);
				break;

			case SCREEN_GAMEPLAY:
				DrawText("GAMEPLAY", 100, 100, 30, BLACK);
				DrawText("Press ESC to exit", 100, 150, 20, DARKGRAY);
				DrawText("Press BACKSPACE to return", 100, 180, 20, DARKGRAY);

				draw_player(&my_player); // Call the player drawing function

				// Display debug information directly on the screen
				char posText[64];
				sprintf(posText, "Position: (%.2f, %.2f)", my_player.x_pos, my_player.y_pos);
				DrawText(posText, 10, 40, 20, BLACK);
				DrawFPS(10, 10);

				break;
		
			default: break;
		}

		EndDrawing();
		
	}

	// cleanup
	// unload our texture so it can be cleaned up
	unload_player(&my_player); // Call the player unload function

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

void drawButton(Button button, int fontsize, Color color){
	Rectangle rec = {button.x, button.y, button.width, button.height};
	DrawRectangleRounded(rec,  0.15, 1, color);
	DrawText(button.text, button.x+10, button.y+10, fontsize, BLACK);
}


