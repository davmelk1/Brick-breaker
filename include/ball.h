#pragma once

#include "moving_entity.h"
#include "constants.h"

class Ball : public MovingEntity{
    static sf::Texture texture;
    bool frozen{false};
public:
    Ball() = default;
    Ball(float x, float y);
    void draw(sf::RenderWindow &window) const override;
    int update() override;
    void move_up() override;
    void move_down() override;
    void move_right() override;
    void move_left() override;
    void freeze();
};