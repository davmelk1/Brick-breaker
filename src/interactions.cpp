#include "interactions.h"

bool is_interacting(const Entity& e1, const Entity& e2) {
    auto b1 = e1.get_bounding_rectangle();
    auto b2 = e2.get_bounding_rectangle();
    return b1.intersects(b2);
}

void handle_interaction(Ball& ball, const Paddle& paddle) {
    if (is_interacting(ball, paddle)) {
        ball.move_up();
        if (ball.get_center().x < paddle.get_center().x)
            ball.move_left();
        else
            ball.move_right();
    }
}

void handle_interaction(const Paddle& paddle, Ball& ball) {
    handle_interaction(ball, paddle);
}

void handle_interaction(Ball& ball, Brick& brick) {
    if (is_interacting(ball, brick)) {
        brick.destroy();
        float left_overlap = ball.get_brx() - brick.get_tlx();
        float right_overlap = brick.get_brx() - ball.get_tlx();
        float top_overlap = ball.get_bry() - brick.get_tly();
        float bottom_overlap = brick.get_bry() - ball.get_tly();

        bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
        bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

        float min_x_overlap = from_left ? left_overlap : right_overlap;
        float min_y_overlap = from_top ? top_overlap : bottom_overlap;

        if (std::abs(min_x_overlap) < std::abs(min_y_overlap)) {
            if (from_left)
                ball.move_left();
            else
                ball.move_right();
        } else {
            if (from_top)
                ball.move_up();
            else
                ball.move_down();
        }
    }
}

void handle_interaction(Brick& brick, Ball& ball) {
    handle_interaction(ball, brick);
}