#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"

class Entity{
protected:
    sf::Sprite sprite;
    bool destroyed{false};
public:
//    Entity() {sprite.setScale({WINDOW_WIDTH, WINDOW_HEIGHT});}
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual int update() = 0;

    sf::FloatRect get_bounding_rectangle() const noexcept;
    sf::Vector2f get_center() const noexcept;
    float get_tlx() const noexcept;
    float get_tly() const noexcept;
    float get_brx() const noexcept;
    float get_bry() const noexcept;
    float get_width() const noexcept;
    float get_height() const noexcept;


    virtual ~Entity() {}
};