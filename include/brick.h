#pragma once

#include "entity.h"

class Brick : public Entity{
    sf::Texture texture;
public:
    Brick() = default;
    Brick(float x, float y);
    void draw(sf::RenderWindow &window) const override;
    int update() override;
    void destroy();
    bool is_destroyed() const noexcept;
};