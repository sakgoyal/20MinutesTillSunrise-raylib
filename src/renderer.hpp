#pragma once

#include "raylib.h"
#include "utils.hpp"

constexpr const int screenWidth = 800;
constexpr const int screenHeight = 450;
constexpr const auto WINDOW_TITLE = "20 Minutes till Sunrise";

void drawBackground(const Texture2D& backTex) {
	for (int i = 0; i < GetScreenWidth(); i += backTex.width) {
		for (int j = 0; j < GetScreenHeight(); j += backTex.height)
			DrawTextureV(backTex, {float(i), float(j)}, WHITE);
	}
}

void drawVignette(const Texture2D& vigTex) {
	DrawTexturePro(vigTex, {0, 0, float(vigTex.width), float(vigTex.height)}, {0, 0, float(GetScreenWidth()), float(GetScreenHeight())}, {0, 0}, 0, WHITE);
}

void drawPlayer(const Texture2D& playerTexture) {
	static Vector2 playerPosition = {(float)(screenWidth / 2 - playerTexture.width / 2), (float)(screenHeight / 2 - playerTexture.height / 2)};
	playerPosition += direction();

	DrawTextureV(playerTexture, playerPosition, WHITE);
}
