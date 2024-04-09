#include "game.h"

Game::Game() :
        window{{constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT}, "Random walker"},
        background{0, 0}
{
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);


    bricks.reserve(constants::NUMBER_OF_COLUMNS * constants::NUMBER_OF_ROWS);
    init();


    sf::Vector2u windowSize = window.getSize();

    auto textureSize = Background::getSize();

    float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y);

    // Use the smaller scale factor to maintain the aspect ratio
    float scaleFactor = std::max(scaleX, scaleY);

    // Set the scale of the sprite
    background.setScale(scaleFactor, scaleFactor);
}

void Game::init() {
    for (int i{0}; i < constants::NUMBER_OF_COLUMNS; ++i)
        for (int j{0}; j < constants::NUMBER_OF_ROWS; ++j) {
            float x = constants::BRICK_PADDING_SIDE + i * constants::BRICK_WIDTH;
            float y = constants::BRICK_PADDING_TOP + j * constants::BRICK_HEIGHT;
            bricks.push_back(new Brick{x, y});
        }

    paddle = {constants::WINDOW_WIDTH / 2.0, constants::WINDOW_HEIGHT - 1.5 * constants::PADDLE_HEIGHT};
    ball = {0, constants::WINDOW_HEIGHT / 2.0};

    is_paused = false;
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::P) {
                    std::cout << "The 'P' key is pressed!" << std::endl;
                    is_paused = !is_paused;
                }

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::R) {
                    std::cout << "The 'R' key is pressed!" << std::endl;
                    reset();
                }
        }

        if (is_paused)
            continue;

        handle_interaction(ball, paddle);

        background.update();
        if (ball.update() == -1)
            is_paused = true;
        paddle.update();
        for (auto& brick : bricks)
            brick->update();

        for (auto& brick : bricks)
            handle_interaction(ball, *brick);

        bricks.erase(std::remove_if(bricks.begin(), bricks.end(), [](const Brick* brick){
            return brick->is_destroyed();
        }), bricks.end());


        background.draw(window);
        for (const auto brick : bricks)
            brick->draw(window);
        ball.draw(window);
        paddle.draw(window);


        window.display();
        if (bricks.empty()) {
            win();
        }
    }
}

void Game::reset() {
    init();
}

void Game::win() {
    ball.freeze();
}