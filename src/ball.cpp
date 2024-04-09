#include "ball.h"

sf::Texture Ball::texture;

Ball::Ball(float x, float y) {
    texture.loadFromFile("ball.png");
    sprite.setTexture(texture);
    sprite.setScale(constants::BALL_DIAMETER / get_width(), constants::BALL_DIAMETER / get_height());

    sprite.setPosition(x, y);
    velocity = {constants::BALL_SPEED, constants::BALL_SPEED};
}

void Ball::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

int Ball::update() {
    if (frozen)
        return 0;
    if (get_tlx() < 0)
        move_right();
    if (get_tlx() + get_width() > constants::WINDOW_WIDTH)
        move_left();
    if (get_tly() < 0)
        move_down();
    if (get_tly() + get_height() > constants::WINDOW_HEIGHT)
        return -1;
    sprite.move(velocity);
    return 0;
}

void Ball::move_up() {
    velocity.y = -constants::BALL_SPEED;
}

void Ball::move_down() {
    velocity.y = constants::BALL_SPEED;
}

void Ball::move_right() {
    velocity.x = constants::BALL_SPEED;
}

void Ball::move_left() {
    velocity.x = -constants::BALL_SPEED;
}

void Ball::freeze() {
    frozen = true;
}