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
		std::cout << "POS Y: " << Position.y << std::endl;
		DrawRectangle(Position.x, Position.y, width, height, BLUE); 
	}
	
	void Move() {
		player_hitbox.x = Position.x;
		player_hitbox.y = Position.y;
		
		if (IsKeyDown(KEY_UP)) {
			if (Position.y <= 20) {
				Position.y = 20;
			}
			Position.y -= slider_speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			if (Position.y >= 525) {
				Position.y = 525;
			}
			Position.y += slider_speed;
		}
	//	std::cout << Position.y << std::endl;	
     }

      int Calculate_Angle(Vector2 &hit) {
	      /*
      		int relativePos = 
		if ( >= ) {
			std::cout << "Returning -45 at: " << hit.y << std::endl;
			return -45;
		}
	      */
		if (hit.y >= 105) {
			std::cout << "Returning -15 at: " << hit.y << std::endl;
			return -15;
		}   
		else if (hit.y >= 70) {
			std::cout << "Returning 0 at: " << hit.y << std::endl;
			return 0;
		}
		else if (hit.y >= 15) {
			std::cout << "Returning 15 at: " << hit.y << std::endl;
			return 15;
		}
		else if (hit.y >= 0) {
			std::cout << "Returning 45 at: " << hit.y << std::endl;
			return 45;
		}
		else return 90;
      }

};
