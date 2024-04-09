#pragma once

namespace constants{
constexpr int WINDOW_WIDTH = 520;
constexpr int WINDOW_HEIGHT = 640;
constexpr float BALL_SPEED = 6.0f;
constexpr float BALL_DIAMETER = 30.0f;
constexpr float PADDLE_WIDTH = 120.0f;
constexpr float PADDLE_HEIGHT = 20.0f;
constexpr float PADDLE_SPEED = 6.0f;
constexpr int NUMBER_OF_COLUMNS = 8;
constexpr int NUMBER_OF_ROWS = 3;
constexpr float BRICK_WIDTH = WINDOW_WIDTH / (NUMBER_OF_COLUMNS + 2.0f);
constexpr float BRICK_HEIGHT = WINDOW_HEIGHT / 3.0f / NUMBER_OF_ROWS;
constexpr float BRICK_PADDING_TOP = 2 * BALL_DIAMETER;
constexpr float BRICK_PADDING_SIDE = BRICK_WIDTH;
}   // namespace