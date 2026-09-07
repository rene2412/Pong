#pragma once
#include "raylib.h"
#include <iostream>
#include <thread>
#include <mutex>

class Player {
private:
    Rectangle player_hitbox;
    Vector2 Position;
    float slider_speed;
    int width = 25, height = 130;
    int score = 0;
    std::mutex position_mtx;
public:
    Player();

    Rectangle GetPlayerHitBox() const;
    Vector2 GetPlayerPosition() const;
    
    int GetPlayerScore() const;
    
    void SetPlayerScore();
    void Update();
    void Draw();
    void Move();

    int Calculate_Angle(Vector2 &hit);
};
