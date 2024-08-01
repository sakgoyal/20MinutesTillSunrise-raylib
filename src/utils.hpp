#pragma once

constexpr Vector2& operator+=(Vector2& lhs, const Vector2& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

// constexpr Vector2& operator-=(Vector2& lhs, const Vector2& rhs) {
// 	lhs.x -= rhs.x;
// 	lhs.y -= rhs.y;
// 	return lhs;
// }

// constexpr Vector2& operator*=(Vector2& lhs, const float scale) {
// 	lhs.x *= scale;
// 	lhs.y *= scale;
// 	return lhs;
// }

[[nodiscard]] constexpr Vector2 operator*(const Vector2& vec, float scale) noexcept {
    return { vec.x * scale, vec.y * scale };
}

[[nodiscard]] Vector2 norm(Vector2 vel) noexcept {
	auto det = (vel.x * vel.x) + (vel.y * vel.y);
	auto scale = sqrt(det);
	if (scale != 0.0) {
		vel.x /= scale;
		vel.y /= scale;
	}
	return vel;
}

[[nodiscard]] Vector2 direction() noexcept {
	constexpr const float normSpeed = 3;
	constexpr const float runSpeed = 5;

	const auto speed = (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) ? runSpeed : normSpeed;
	auto right = float(IsKeyDown(KEY_RIGHT) | IsKeyDown(KEY_D)) - float(IsKeyDown(KEY_LEFT) | IsKeyDown(KEY_A));
	auto left = float(IsKeyDown(KEY_DOWN) | IsKeyDown(KEY_S)) - float(IsKeyDown(KEY_UP) | IsKeyDown(KEY_W));

	return norm({ right, left }) * speed;
}
