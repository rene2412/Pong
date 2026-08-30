#include "raylib.h"

class Field {
	private:
		Image img;
		Texture2D field;	
	public:
		Field() {
			img = LoadImage("images/Board.png");
			ImageResize(&img, 1150, 700);
			field = LoadTextureFromImage(img);	
			UnloadImage(img);
		}

		~Field() {
			UnloadTexture(field);
		}

		void Draw() {
			DrawTexture(field, 200, 8, WHITE);
		}

};
