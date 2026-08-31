#pragma once
#include "raylib.h"
#include <iostream>
#include "ball.h"

class Player { 
   private:
  	Rectangle player_hitbox;
	Vector2 Position;
	float slider_speed;
	int width = 25, height = 175;
	
   public:
	Player() {
		Position.x = 25;
		Position.y = 225;
		slider_speed = 5.0f;
		player_hitbox = { Position.x, Position.y, width, height };
	}
	
	Rectangle GetPlayerHitBox() const {
		return player_hitbox;
	}
	
	Vector2 GetPlayerPosition() const {
		return Position;
	}

	void Update() {
		Move();
		Draw();
	}

	void Draw() {
		DrawRectangle(Position.x, Position.y, width, height, BLUE); 
	}
	
	void Move() {
		player_hitbox.x = Position.x;
		player_hitbox.y = Position.y;
		
		if (IsKeyDown(KEY_UP)) {
			if (Position.y <= 160) {
				Position.y = 160;
			}
			Position.y -= slider_speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			if (Position.y >= 720) {
				Position.y = 720;
			}
			Position.y += slider_speed;
		}
	//	std::cout << Position.y << std::endl;	
     }

      int Calculate_Angle(Vector2 &hit) {
      		if (hit.y >= 140) {
			return -75;
		}
		else if (hit.y >= 105) {
			return -60;
		}   
		else if (hit.y >= 70) {
			return 0;
		}
		else if (hit.y >= 35) {
			return 60;
		}
		else if (hit.y >= 0) {
			return 75;
		}
		else return 90;
      }

};
