#ifndef BALL_ICON_HPP_
#define BALL_ICON_HPP_

#include <memory>
#include "abstract_widgets.hpp"

namespace widgets {

struct ball_icon final : widget {
private:
    int radius_;

public:
    explicit ball_icon(int radius_);

    [[nodiscard]] int width() const override;
    [[nodiscard]] int height() const override;

    [[nodiscard]] int radius() const;
    void radius(int new_radius);

    widget *child_at(int x, int y) override;
};

[[nodiscard]] std::unique_ptr<ball_icon> make_ball_icon(int radius);
}  // namespace widgets

#endif  // BALL_ICON_HPP_