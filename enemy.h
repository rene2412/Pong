#pragma once
#include "raylib.h"
#include <iostream>
#include "ball.h"

class Enemy { 
   private:
  	Rectangle enemy_hitbox;
	Vector2 Position;
	float slider_speed;
	int width = 25, height = 170;
   public:
	Enemy() {
		Position.x = 1200;
		Position.y = 225;
		slider_speed = 5.0f;
		enemy_hitbox = { Position.x, Position.y, width, height };
	}
	Rectangle GetPlayerHitBox() const {
		return enemy_hitbox;
	}

	void Update() {
		Move();
		Draw();
	}

	void Draw() {
		DrawRectangle(Position.x, Position.y, width, height, ORANGE); 
	}
	
	void Move() {
		enemy_hitbox.x = Position.x;
		enemy_hitbox.y = Position.y;
		
		if (IsKeyDown(KEY_UP)) {
			if (Position.y <= 160) {
				Position.y = 160;
			}
			Position.y -= slider_speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			if (Position.y >= 385) {
				Position.y = 385;
			}
			Position.y += slider_speed;
		}
	//	std::cout << Position.y << std::endl;	
	}

};
