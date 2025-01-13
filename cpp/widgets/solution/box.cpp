#include "box.hpp"
#include <algorithm>  // Для std::max
#include <numeric>

namespace widgets {

box::box(kind kind_) : kind_(kind_), width_(0), height_(0) {
}

int box::width() const {
    if (children.empty()) {
        return 0;
    }

    int result = 0;

    switch (kind_) {
        case kind::HORIZONTAL:
            result = std::accumulate(
                children.begin(), children.end(), 0,
                [](int sum, const std::unique_ptr<widget> &child) {
                    return sum + child->width();
                }
            );
            break;

        case kind::VERTICAL:
            for (const auto &child : children) {
                result = std::max(result, child->width());
            }
            break;
    }

    return result;
}

int box::height() const {
    if (children.empty()) {
        return 0;
    }

    int result = 0;

    switch (kind_) {
        case kind::HORIZONTAL:
            for (const auto &child : children) {
                result = std::max(result, child->height());
            }
            break;

        case kind::VERTICAL:
            result = std::accumulate(
                children.begin(), children.end(), 0,
                [](int sum, const std::unique_ptr<widget> &child) {
                    return sum + child->height();
                }
            );
            break;
    }

    return result;
}

// NOLINTBEGIN(misc-no-recursion)
widget *box::child_at(int x, int y) {
    int tmp = 0;

    for (const auto &child : children) {
        switch (kind_) {
            case kind::HORIZONTAL:
                if (x >= tmp && x < tmp + child->width() &&
                    y >= (height_ - child->height()) / 2 &&
                    y < (height_ + child->height()) / 2) {
                    if (auto *container = dynamic_cast<box *>(child.get())) {
                        return container->child_at(x - tmp, y);
                    }
                    return child.get();
                }
                tmp += child->width();
                break;

            case kind::VERTICAL:
                if (y >= tmp && y < tmp + child->height() &&
                    x >= (width_ - child->width()) / 2 &&
                    x < (width_ + child->width()) / 2) {
                    if (auto *container = dynamic_cast<box *>(child.get())) {
                        return container->child_at(x, y - tmp);
                    }
                    return child.get();
                }
                tmp += child->height();
                break;
        }
    }

    return nullptr;
}

// NOLINTEND(misc-no-recursion)

void box::update_layout() {
    int sum_size = 0;
    int max_size = 0;

    positions.clear();

    for (auto &child : children) {
        switch (kind_) {
            case kind::HORIZONTAL:
                positions.emplace_back(sum_size);
                sum_size += child->width();
                max_size = std::max(max_size, child->height());
                break;

            case kind::VERTICAL:
                positions.emplace_back(sum_size);
                sum_size += child->height();
                max_size = std::max(max_size, child->width());
                break;
        }
    }

    switch (kind_) {
        case kind::HORIZONTAL:
            width_ = sum_size;
            height_ = max_size;
            break;

        case kind::VERTICAL:
            width_ = max_size;
            height_ = sum_size;
            break;
    }
}

std::size_t box::size() const {
    return children.size();
}

widget *box::get(int index) const {
    return children[index].get();
}

[[maybe_unused]] widget *box::add(std::unique_ptr<widget> child) {
    if (!child) {
        return nullptr;
    }
    children.push_back(std::move(child));
    update_layout();
    return children.back().get();
}

[[maybe_unused]] std::unique_ptr<widget> box::remove(int index) {
    if (index < 0 || index >= static_cast<int>(children.size())) {
        return nullptr;
    }
    auto to_remove = std::move(children[index]);
    children.erase(children.begin() + index);
    update_layout();
    return to_remove;
}

[[nodiscard]] [[maybe_unused]] std::unique_ptr<box> make_box(box::kind kind_) {
    return std::make_unique<box>(kind_);
}

}  // namespace widgets
