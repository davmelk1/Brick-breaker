#include "paddle.h"

sf::Texture Paddle::texture;

Paddle::Paddle(float x, float y) {
    texture.loadFromFile("paddle.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);

    sprite.setScale(constants::PADDLE_WIDTH / get_width(), constants::PADDLE_HEIGHT / get_height());
    velocity = {0.0f, 0.0f};
}

void Paddle::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

int Paddle::update() {
    handle_user_keypress();
    sprite.move(velocity);
    return 0;
}

void Paddle::handle_user_keypress() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        if (get_center().x <= constants::WINDOW_WIDTH - constants::PADDLE_SPEED)
            move_right();
        else
            velocity.x = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        if (get_center().x >= constants::PADDLE_SPEED)
            move_left();
        else
            velocity.x = 0;
    } else
        velocity.x = 0;

}

void Paddle::move_up() {  }
void Paddle::move_down() {  }

void Paddle::move_right() {
    velocity.x = constants::PADDLE_SPEED;
}

void Paddle::move_left() {
    velocity.x = -constants::PADDLE_SPEED;
}
