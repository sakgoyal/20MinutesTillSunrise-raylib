// #pragma once

// #include "pch.h"

// constexpr const float normSpeed = 3;
// constexpr const float runSpeed = 5;

// Vector2 norm(Vector2 vel) {
// 	auto det = (vel.x * vel.x) + (vel.y * vel.y);
// 	auto scale = sqrt(det);
// 	vel.x /= scale;
// 	vel.y /= scale;

// 	return vel;
// }

// Vector2 direction() {
// 	const auto speed = (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) ? runSpeed : normSpeed;
// 	Vector2 dir = {
// 		float((IsKeyDown(KEY_RIGHT) | IsKeyDown(KEY_D)) - (IsKeyDown(KEY_LEFT) | IsKeyDown(KEY_A))) * speed,
// 		float((IsKeyDown(KEY_DOWN) | IsKeyDown(KEY_S)) - (IsKeyDown(KEY_UP) | IsKeyDown(KEY_W))) * speed
// 	};

// 	return norm(dir);
// }
