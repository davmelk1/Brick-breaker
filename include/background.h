#pragma once

#include "entity.h"
#include <iostream>

class Background : Entity {
    static sf::Texture texture;
public:
    Background(float x, float y);

    void draw(sf::RenderWindow& window) const override;

    int update() override;

    void setScale(float scaleX, float scaleY);
    static sf::Vector2<unsigned int> getSize();
};