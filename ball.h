#pragma once
#include "raylib.h"
#include "player.h"

class Ball {
	private:
		Image img;
		Texture2D ball_sprite;
		Rectangle ball_hitbox;
		Vector2 Position;
		float speed = 4.0f;
		int width = 35, height = 35, scalar = 2;
		bool move_left = true, move_right = false;
	public:
		Ball() {
			img = LoadImage("images/Ball.png");
			ImageResize(&img, width, height);
			ball_sprite = LoadTextureFromImage(img); 
			UnloadImage(img);
			Position.x = 600;
			Position.y = 500;
			ball_hitbox = { Position.x, Position.y, width, height };
		}	
		
		~Ball() {
			UnloadTexture(ball_sprite);
		}
		
		Rectangle GetBallHitBox() const {
			return ball_hitbox;
		}

		void Update(const Player &player) {
			Movement(player);
			Draw();
		}

		void Movement(const Player &player) {
			std::cout << Position.x << std::endl;
			ball_hitbox.x = Position.x;
			ball_hitbox.y = Position.y;
			std::cout << "Move Right: " << move_right << std::endl;
			std::cout << "Move Left`: " << move_left << std::endl;
			//init
			if (move_left) {
				Position.x -= speed;
			}
			if (move_right) {
				Position.x += speed;
			}
			if (Position.x <= 200) {
				move_right = true;
				move_left = false;
				std::cout << "WALL BOUNCE BACK:\n";
			}
			if (Position.x >= 1000) {
				move_left = true;
				move_right = false;
			} 
			if (CheckCollisionRecs(GetBallHitBox(), player.GetPlayerHitBox())) { 
				std::cout << "RETURN TO PLAYER\n"; 
				move_right = true;
				move_left = false;
			}

		}

		void Draw() {
			DrawTexture(ball_sprite, Position.x, Position.y, WHITE);
		}
};
