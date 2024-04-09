#pragma once

#include "moving_entity.h"

class Paddle : public MovingEntity{
    static sf::Texture texture;
public:
    Paddle() = default;
    Paddle(float x, float y);
    int update() override;
    void draw(sf::RenderWindow &window) const override;
    void handle_user_keypress();
    void move_up() override;
    void move_down() override;
    void move_right() override;
    void move_left() override;
};