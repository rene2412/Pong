#include "enemy.h"
#include "ball.h" 

Enemy::Enemy() {
    Position.x = 1200;
    Position.y = 225;
    slider_speed = 10.0f;
    enemy_hitbox = { Position.x, Position.y, width, height };
}

Rectangle Enemy::GetEnemyHitBox() const {
    return enemy_hitbox;
}

int Enemy::GetEnemyScore() const {
	return score;
}

void Enemy::SetEnemyScore() {
	score ++;
}

void Enemy::Update(Ball &ball) {
    std::thread move_enemy([&]() { 
		    Move(ball);
    });
    move_enemy.join();
    Draw();
}

void Enemy::Draw() {
    std::lock_guard lock(position_mtx);
    DrawRectangle(Position.x, Position.y, width, height, ORANGE);
}

void Enemy::Move(Ball &ball) {
    std::lock_guard lock(position_mtx);
    enemy_hitbox.x = Position.x;
    enemy_hitbox.y = Position.y;
    if (player) {
        if (IsKeyDown(KEY_UP)) {
            if (Position.y <= 160) {
                Position.y = 160;
            }
            Position.y -= slider_speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            if (Position.y >= 385) {
                //Position.y = 385;
            }
            Position.y += slider_speed;
        }
    } 

    if (bot) {
        float trace_angle = ball.GetBallAngle();
        Vector2 ball_position = ball.GetBallPosition();
        
	if (Position.y + (enemy_hitbox.height - 10) < ball_position.y) {
            	if (Position.y >= 575) {
			Position.y = 575;
		}
		Position.y += slider_speed;
        }
       if (Position.y > ball_position.y) {
		if (Position.y <= 100) {
			Position.y = 100;
		}
                Position.y -= slider_speed;
        }
    }
}

int Enemy::Calculate_Angle(Vector2 &hit) {
    float paddleCenter = enemy_hitbox.y + enemy_hitbox.height / 2.0f;
    float relativeHit = hit.y - paddleCenter;

    if (relativeHit <= -50 ) {
        std::cout << "Returning -45 at: " << hit.y << std::endl;
        return -45;
    }
    if (relativeHit <= -20) {
        std::cout << "Returning -15 at: " << hit.y << std::endl;
        return -15;
    }
    else if (relativeHit <= 20) {
        std::cout << "Returning 20 at: " << hit.y << std::endl;
        return 0;
    }
    else if (relativeHit <= 50) {
        std::cout << "Returning 15 at: " << hit.y << std::endl;
        return 15;
    }
    else {
        std::cout << "Else: Return 45\n";
        return 45;
    }
}

