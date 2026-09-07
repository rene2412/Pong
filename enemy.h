#pragma once
#include "raylib.h"
#include <iostream>
#include <thread>
#include <mutex>
class Ball;

class Enemy {
private:
    Rectangle enemy_hitbox;
    Vector2 Position;
    float slider_speed;
    int width = 25, height = 130;
    int score = 0;
    bool player = false, bot = true;
    bool should_move = false;
    std::mutex position_mtx;
public:
    Enemy();

    Rectangle GetEnemyHitBox() const;
    
    [[nodiscard]]    
    int GetEnemyScore() const;
    
    void SetEnemyScore();
    void Update(Ball &ball);
    void Draw();
    void Move(Ball &ball);

    int Calculate_Angle(Vector2 &hit);
};

