#include "brick.h"
#include <iostream>

Brick::Brick(float x, float y) {
    texture.loadFromFile("brick.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(constants::BRICK_WIDTH / get_width(), constants::BRICK_HEIGHT / get_height());
}

int Brick::update() { return 0; }

void Brick::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

void Brick::destroy() {
    destroyed = true;
}

bool Brick::is_destroyed() const noexcept {
    return destroyed;
}