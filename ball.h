#pragma once
#include "raylib.h"
#include "player.h"

class Ball {
	private:
		Image img;
		Texture2D ball_sprite;
		Rectangle ball_hitbox;
		Vector2 Position;
		float speed = 3.0f;
		int width = 70, height = 70, scalar = 2;
		bool init = true, player_hit = false, bot_hit = false;
	public:
		Ball() {
			img = LoadImage("images/ball_sprite.png");
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
			//init
			if (init) {
				Position.x -= speed;
			}
			if (player_hit and !bot_hit) {
				Position.x -= speed * scalar;
			}
			if (bot_hit and !player_hit) {
				Position.x += speed;
			}
			ball_hitbox.x = Position.x;
			ball_hitbox.y = Position.y;

			if (Position.x <= 400) {
				init = false;
				std::cout << "WALL: \n";
				Position.x += speed;
			}

			if (CheckCollisionRecs(GetBallHitBox(), player.GetPlayerHitBox())) { 
					std::cout << "RETURN TO PLAYER\n"; 
					init = false;
					player_hit = false;
					bot_hit = true;
					//position.y *= -2;	
			}
		}

		void Draw() {
			DrawTexture(ball_sprite, Position.x, Position.y, WHITE);
		}
};
