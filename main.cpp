#include "raylib.h"
#include "field.h"
#include "ball.h"
#include "player.h"
#include "enemy.h"
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Soccer Pong");
    SetTargetFPS(60);
    Field field;
    Ball ball;
    Player player;
    Enemy enemy; 
    while (!WindowShouldClose())
    {
        // Update
        // Draw
        BeginDrawing();
        ClearBackground(WHITE);
       // DrawText("Soccer Pong", 20, 20, 40, BLACK);
	field.Draw();
        enemy.Draw();
	ball.Update(player);
	player.Update();
	EndDrawing();
    }

    CloseWindow();

    return 0;
}
