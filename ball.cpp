#include "ball.h"
#include "player.h"
#include "enemy.h"
#include <iostream>

Ball::Ball() {
    img = LoadImage("images/Ball.png");
    img2 = LoadImage("images/Ball_Motion_Right.png");
    
    ImageResize(&img, width, height);
    ImageResize(&img2, width * 2.5, height * 2.5);
    
    ball_sprite = LoadTextureFromImage(img);
    ball_effect_right = LoadTextureFromImage(img2);
    
    UnloadImage(img);
    UnloadImage(img2);

    Position.x = 600;
    Position.y = 500;

    Velocity.x = -speed;
    Velocity.y = angle;

    ball_hitbox = { Position.x, Position.y, width, height };
}

Ball::~Ball() {
    UnloadTexture(ball_sprite);
    UnloadTexture(ball_effect_right);
}

Rectangle Ball::GetBallHitBox() const {
    return ball_hitbox;
}

Vector2 Ball::GetBallPosition() const {
    return Position;
}

Vector2 Ball::GetBallVelocity() const {
    return Velocity;
}

float Ball::GetBallAngle() const {
    return angle;
}

void Ball::Update(Player &player, Enemy &enemy) {
	std::thread move_ball([&]() {
			Movement(player, enemy);
	});
	move_ball.join();
	Draw();
}

void Ball::Movement(Player &player, Enemy &enemy) {
    std::lock_guard lock(position_mtx);
    
    ball_hitbox.x = Position.x;
    ball_hitbox.y = Position.y;

    Position.x += Velocity.x;
    Position.y += Velocity.y;

    if (Position.x <= 0) {
        Velocity.x = -Velocity.x;
        move_right = true;
	move_left = false;
	enemy.SetEnemyScore();
    }

    if (Position.x >= 1280) {
        Velocity.x = -Velocity.x;
        move_right = false;
        move_left = true;
	player.SetPlayerScore();
    }

    if (Position.y <= 80) {
        Velocity.y = -Velocity.y;
    }

    if (Position.y >= 720) {
        Velocity.y = -Velocity.y;
    }

    if (CheckCollisionRecs(GetBallHitBox(), player.GetPlayerHitBox()) && !move_right) {
        int player_paddle_hit_position = player.Calculate_Angle(Position);
        //std::cout << "Position Paddle Ball Hit: " << Position.y << std::endl;

        angle = player_paddle_hit_position * DEG2RAD;
        //std::cout << "Angle taken: " << angle << std::endl;

        Velocity.x = cos(angle) * speed;
        Velocity.y = sin(angle) * speed;

        move_right = true;
	move_left = false;
    }

    if (CheckCollisionRecs(GetBallHitBox(), enemy.GetEnemyHitBox()) && !move_left) {
        int enemy_paddle_hit_position = enemy.Calculate_Angle(Position);
	std::cout << "ENEMY HIT\n";
        angle = enemy_paddle_hit_position * DEG2RAD;
        std::cout << "Angle taken: " << angle << std::endl;

        Velocity.x = -cos(angle) * speed;
        Velocity.y = sin(angle) * speed;
	//Velocity.x = -Velocity.x;
        move_left = true;
	move_right = false;
    }
}

void Ball::Draw() {
    std::lock_guard lock(position_mtx);
    DrawTexture(ball_sprite, Position.x, Position.y, WHITE);
}

void Ball::Effect() {
    DrawTexture(ball_effect_right, Position.x - 68, Position.y - 20, WHITE);
}

