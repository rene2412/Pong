#include "raylib.h"
#include "field.h"
#include "ball.h"
#include "player.h"
#include "enemy.h"
#include "ui.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Classic Pong");
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
        enemy.Update(ball);
	ball.Update(player, enemy);
	player.Update();
	UI::DrawScoreboard(player, enemy);
	EndDrawing();
    }
    	CloseWindow();

    return 0;
}
