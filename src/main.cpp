#include "pch.h"
#include "utils.hpp"
#include "renderer.hpp"

template<typename ... T>
void UnloadTextures(const T& ...texture) noexcept {
	(UnloadTexture(texture), ...);
}

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN | FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT);
	InitWindow(screenWidth, screenHeight, WINDOW_TITLE);

	SetTargetFPS(120);

	const Texture2D playerTexture = LoadTexture("assets/Player.png");
	const Texture2D backgroundTexture = LoadTexture("assets/GroundPurple.png");
	const Texture2D vigTexture = LoadTexture("assets/vignette.png");

	Vector2 playerPosition = {(float)(screenWidth / 2 - playerTexture.width / 2), (float)(screenHeight / 2 - playerTexture.height / 2)};

	while (!WindowShouldClose()) {
		// Move player around
		playerPosition += direction();

		BeginDrawing();
		{
			ClearBackground(BLACK);
			drawBackground(backgroundTexture);
			drawPlayer(playerTexture);
			drawVignette(vigTexture);
		}

		EndDrawing();
	}

	UnloadTextures(playerTexture, backgroundTexture, vigTexture);
	CloseWindow();
}
