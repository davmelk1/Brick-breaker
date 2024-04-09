#include "../include/background.h"

sf::Texture Background::texture;

Background::Background(float x, float y) {
    bool success = texture.loadFromFile("images.jpeg");

    if (!success) {
        std::cerr << "No background image\n";
        std::terminate();
    }

    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Background::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

int Background::update() { return 0; }

void Background::setScale(float scaleX, float scaleY) {
    sprite.setScale(scaleX, scaleY);
}

sf::Vector2<unsigned int> Background::getSize() {return texture.getSize();}
