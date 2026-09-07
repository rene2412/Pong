#include "player.h"

Player::Player() {
    Position.x = 25;
    Position.y = 225;
    slider_speed = 8.0f;
    player_hitbox = { Position.x, Position.y, width, height };
}

Rectangle Player::GetPlayerHitBox() const {
    return player_hitbox;
}

Vector2 Player::GetPlayerPosition() const {
    return Position;
}

int Player::GetPlayerScore() const { 
	return score;
}

void Player::SetPlayerScore() {
	score ++;
}

void Player::Update() {
    std::thread move_player([&]() { 
		  Move();
    });
    move_player.join();
    Draw();
}

void Player::Draw() {
    std::lock_guard lock(position_mtx);
    DrawRectangle(Position.x, Position.y, width, height, BLUE);
}

void Player::Move() {
    std::lock_guard lock(position_mtx);
    player_hitbox.x = Position.x;
    player_hitbox.y = Position.y;

    if (IsKeyDown(KEY_UP)) {
        if (Position.y <= 90) {
            Position.y = 90;
        }
        Position.y -= slider_speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
        if (Position.y >= 575) {
            Position.y = 575;
        }
        Position.y += slider_speed;
    }
}

int Player::Calculate_Angle(Vector2 &hit) {
    float paddleCenter = player_hitbox.y + player_hitbox.height / 2.0f;
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
