#pragma once
#include "raylib.h"
#include <cmath>
#include <thread>
#include <mutex>

class Player;
class Enemy;

class Ball {
private:
    Image img, img2, img3, img4, img5, img6, img7;
    Texture2D ball_sprite, ball_effect_right, ball_effect_top_corner_right, ball_effect_bottom_corner_right,
	      ball_effect_left, ball_effect_top_corner_left, ball_effect_bottom_left;
    Rectangle ball_hitbox;
    Vector2 Position;
    Vector2 Velocity;
    float speed = 17.0f;
    float angle = 0.0f;
    int width = 30, height = 30, scalar = 2;
    bool move_left = true, move_right = false;
    std::mutex position_mtx;
public:
    Ball();
    ~Ball();

    Rectangle GetBallHitBox() const;
    Vector2 GetBallPosition() const;
    Vector2 GetBallVelocity() const;
    float GetBallAngle() const;

    void Update(Player &player, Enemy &enemy);
    void Movement(Player &player, Enemy &enemy);
    void Effect();
    void Draw();
    
};

