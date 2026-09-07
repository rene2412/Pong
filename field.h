#include "raylib.h"

class Field {
	private:
		Image img;
		Texture2D field;	
	public:
		Field() {
			img = LoadImage("images/Board.png");
			ImageResize(&img, 1300, 720);
			field = LoadTextureFromImage(img);	
			UnloadImage(img);
		}

		~Field() {
			UnloadTexture(field);
		}

		void Draw() {
			DrawTexture(field, 0, 8, WHITE);
		}

};
