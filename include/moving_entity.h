#pragma once

#include "entity.h"

class MovingEntity : public Entity{
protected:
    sf::Vector2f velocity;
public:
    virtual void move_up() = 0;
    virtual void move_down() = 0;
    virtual void move_right() = 0;
    virtual void move_left() = 0;
};