#include "raylib.h"
#include "field.h"
#include "ball.h"
#include "player.h"
const int SCREEN_WIDTH = 1480;
const int SCREEN_HEIGHT = 720;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Soccer Pong");
    SetTargetFPS(60);
    Field field;
    Ball ball;
    Player player;
    while (!WindowShouldClose())
    {
        // Update
        // Draw
        BeginDrawing();
        ClearBackground(DARKGREEN);
        //DrawText("Soccer Pong", 20, 20, 40, WHITE);
	field.Draw();
        ball.Update(player);
	player.Update();
	EndDrawing();
    }

    CloseWindow();

    return 0;
}
