#include "entity.h"

sf::FloatRect Entity::get_bounding_rectangle() const noexcept {
    return sprite.getGlobalBounds();
}

sf::Vector2f Entity::get_center() const noexcept {
    auto box = get_bounding_rectangle();
    auto pos = sprite.getPosition();
    return {pos.x + box.width / 2, pos.y + box.height / 2};
}

float Entity::get_width() const noexcept {
    auto box = get_bounding_rectangle();
    return box.width;
}

float Entity::get_height() const noexcept {
    auto box = get_bounding_rectangle();
    return box.height;
}


float Entity::get_tlx() const noexcept {
    return sprite.getPosition().x;
}

float Entity::get_tly() const noexcept {
    return sprite.getPosition().y;
}

float Entity::get_brx() const noexcept {
    return sprite.getPosition().x + get_width();
}

float Entity::get_bry() const noexcept {
    return sprite.getPosition().y + get_height();
}
