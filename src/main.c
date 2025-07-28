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
	int pos_x = start_x;
	int pos_y = start_y;
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		
		ClearBackground(RED);

		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);

		// draw our texture to the screen
		
		DrawTexture(wabbit, pos_x, pos_y, WHITE);
		
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
		
		
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
