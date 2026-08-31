#pragma once
#include "raylib.h"
#include "player.h"
#include <cmath>

class Ball {
	private:
		Image img;
		Texture2D ball_sprite;
		Rectangle ball_hitbox;
		Vector2 Position;
		Vector2 Velocity;
		float speed = 5.0f;
		float angle = 0.0f;
		int width = 25, height = 25, scalar = 2;
		bool move_left = true, move_right = false;
		
	public:
		Ball() {
			img = LoadImage("images/Ball.png");
			ImageResize(&img, width, height);
			ball_sprite = LoadTextureFromImage(img); 
			UnloadImage(img);
			Position.x = 600;
			Position.y = 500;
			Velocity.x = -speed;
			Velocity.y = angle;
			ball_hitbox = { Position.x, Position.y, width, height };
		}	
		
		~Ball() {
			UnloadTexture(ball_sprite);
		}
		
		Rectangle GetBallHitBox() const {
			return ball_hitbox;
		}

		Vector2 GetBallPosition() const {
			return Position;
		}

		void Update(Player &player) {
			Movement(player);
			Draw();
		}

		void Movement(Player &player) {
			std::cout << Position.x << std::endl;
			ball_hitbox.x = Position.x;
			ball_hitbox.y = Position.y;
			//init
			Position.x += Velocity.x;
			Position.y += Velocity.y;
			
			if (Position.x <= 0) {
				std::cout << "WALL BOUNCE BACK:\n";
			 	Velocity.x = -Velocity.x;	
			}
			if (Position.x >= 1280) {
				Velocity.x = -Velocity.x;
				move_right = false;
			}
		        if (Position.y <= 0) {
				std::cout << "Richocet top\n";
				Velocity.x = cos(-angle) * speed;
				Velocity.y = sin(-angle) * speed;
				move_right = false;
			}
			if (Position.y >= 720) {
				std::cout << "Richocet Bottom\n";
				Velocity.x = cos(angle) * speed;
				Velocity.y = sin(angle) * speed;

			}	
			if (CheckCollisionRecs(GetBallHitBox(), player.GetPlayerHitBox()) and !move_right) { 
				//std::cout << "RETURN TO PLAYER\n"; 
				int player_paddle_hit_position = player.Calculate_Angle(Position);
				std::cout << "Position Paddle Hit: " << player_paddle_hit_position << std::endl;
				angle = player_paddle_hit_position * DEG2RAD;
				std::cout << "Angle taken: " << angle << std::endl;
				Velocity.x = cos(angle) * speed;
				Velocity.y = sin(angle) * speed;
				move_right = true;
			}

		}

		void Draw() {
			DrawTexture(ball_sprite, Position.x, Position.y, WHITE);
		}
};
