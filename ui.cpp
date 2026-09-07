#include "ui.h"
#include "raylib.h"

namespace UI {

void DrawScoreboard(Player& player, Enemy& enemy)
{
    const int screenWidth = GetScreenWidth();
    const int height = 80;

    DrawRectangle(
        0,
        0,
        screenWidth,
        height,
        PINK
    );

    int playerScore = player.GetPlayerScore();
    int enemyScore = enemy.GetEnemyScore();

    const char* playerText = TextFormat("%d", playerScore);
    const char* enemyText = TextFormat("%d", enemyScore);

    DrawText(
        playerText,
        screenWidth / 4 - MeasureText(playerText, 40) / 2,
        20,
        40,
        WHITE
    );

    DrawText(
        enemyText,
        (screenWidth * 3) / 4 - MeasureText(enemyText, 40) / 2,
        20,
        40,
        WHITE
    );
}

}
