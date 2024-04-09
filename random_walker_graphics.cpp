#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <chrono>

#include "include/constants.h"

class Creature{
    const static std::vector<float> steps;
    static std::mt19937 mt;
    static std::uniform_int_distribution<int> direction_generator;
    float stepX{15.0f};
    float stepY{15.0f};
    float currX;
    float currY;
    sf::Vector2f velocity;

    sf::RectangleShape rec;
public:
    Creature(float x, float y) {
        x = (x > 0) ? x : 0;
        x = (x < constants::WINDOW_WIDTH) ? x : constants::WINDOW_WIDTH;
        y = (y > 0) ? y : 0;
        y = (y < constants::WINDOW_WIDTH) ? y : constants::WINDOW_WIDTH;
        currX = x;
        currY = y;
        velocity = {stepX, stepY};
        rec.setPosition(x, y);
        rec.setFillColor(sf::Color::Red);
        rec.setSize({15.0f, 15.0f});
    }

    void draw(sf::RenderWindow& window) {
        rec.setFillColor(sf::Color::Blue);
        window.draw(rec);
        rec.move(velocity);
        rec.setFillColor(sf::Color::Red);
        window.draw(rec);
    }

    void update() {
        auto x = steps[direction_generator(mt)] * stepX;
        x = (currX + x > 0) ? x : -x;
        x = (currX + 3 * x <= constants::WINDOW_WIDTH) ? x : -x;
        auto y = steps[direction_generator(mt)] * stepY;
        y = (currY + 3 * y <= constants::WINDOW_HEIGHT) ? y : -y;
        y = (currY + y > 0) ? y : -y;

        currX += x;
        currY += y;
        velocity = {x, y};

    }
};

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 Creature::mt(seed);
const std::vector<float> Creature::steps{-1.0f, 0.0f, 1.0f};
std::uniform_int_distribution<int> Creature::direction_generator{0, static_cast<int>(Creature::steps.size() - 1)};

int main() {
    sf::RenderWindow window{{constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT}, "Random walker"};
    Creature req_object{constants::WINDOW_WIDTH / 2.0, constants::WINDOW_HEIGHT / 2.0};

    window.setFramerateLimit(100);

    window.clear(sf::Color::Black);


    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();

        req_object.update();
        req_object.draw(window);
        window.display();

    }
}