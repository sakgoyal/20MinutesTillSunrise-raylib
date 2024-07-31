#include "pch.h"

#include "utils.hpp"

constexpr const int screenWidth = 800;
constexpr const int screenHeight = 450;
constexpr const auto WINDOW_TITLE = "20 Minutes till Sunrise";

void drawBackground(Texture2D& backTex) {
	for (int i = 0; i < GetScreenWidth(); i += backTex.width) {
		for (int j = 0; j < GetScreenHeight(); j += backTex.height)
			DrawTextureV(backTex, {float(i), float(j)}, WHITE);
	}
}

void drawVignette(Texture2D& vigTex) {
	DrawTexturePro(vigTex, {0, 0, float(vigTex.width), float(vigTex.height)}, {0, 0, float(GetScreenWidth()), float(GetScreenHeight())}, {0, 0}, 0, WHITE);
}


int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN | FLAG_WINDOW_HIGHDPI);
	InitWindow(screenWidth, screenHeight, WINDOW_TITLE);

	SetTargetFPS(120);

	Texture2D playerTexture = LoadTexture("assets/Player.png");
	Texture2D backgroundTexture = LoadTexture("assets/GroundPurple.png");
	Texture2D vigTexture = LoadTexture("assets/vignette.png");

	Vector2 playerPosition = {(float)(screenWidth / 2 - playerTexture.width / 2), (float)(screenHeight / 2 - playerTexture.height / 2)};

	while (!WindowShouldClose()) {
		// Move player around
		playerPosition += direction();

		// Draw
		BeginDrawing();

		ClearBackground(BLACK);
		drawBackground(backgroundTexture);
		DrawTextureV(playerTexture, playerPosition, WHITE);
		drawVignette(vigTexture);

		EndDrawing();
	}

	UnloadTexture(playerTexture);
	UnloadTexture(backgroundTexture);
	UnloadTexture(vigTexture);
	CloseWindow();
}
