#pragma once

#include "ball.h"
#include "paddle.h"
#include "brick.h"

bool is_interacting(const Entity& e1, const Entity& e2);

void handle_interaction(Ball& ball, const Paddle& paddle);

void handle_interaction(const Paddle& paddle, Ball& ball);

void handle_interaction(Ball& ball, Brick& brick);

void handle_interaction(Brick& brick, Ball& ball);