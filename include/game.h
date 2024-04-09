#pragma once

#include <vector>

#include "constants.h"
#include "background.h"
#include "paddle.h"
#include "ball.h"
#include "interactions.h"

class Game{
    sf::RenderWindow window;
    Background background;
    Ball ball;
    Paddle paddle;
    std::vector<Brick*> bricks;
    bool is_paused;

    void init();
    void win();
public:
    Game();
    void run();
    void reset();
};