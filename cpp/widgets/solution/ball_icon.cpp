#include "ball_icon.hpp"

namespace widgets {

ball_icon::ball_icon(int radius_) : radius_(radius_){};

int ball_icon::width() const {
    return 2 * radius_ + 1;
}

int ball_icon::height() const {
    return 2 * radius_ + 1;
}

int ball_icon::radius() const {
    return radius_;
}

void ball_icon::radius(int new_radius) {
    radius_ = new_radius;
}

widget *ball_icon::child_at(int x, int y) {
    const int center = radius_;
    const int a = x - center;
    const int b = y - center;

    if (a * a + b * b <= radius_ * radius_) {
        return this;
    } else {
        return nullptr;
    }
}

std::unique_ptr<ball_icon> make_ball_icon(int radius) {
    return std::make_unique<ball_icon>(radius);
}
}  // namespace widgets