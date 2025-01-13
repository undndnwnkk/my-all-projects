#ifndef BOX_HPP_
#define BOX_HPP_
#include <memory>
#include <vector>
#include "abstract_widgets.hpp"

namespace widgets {

struct box : container {
public:
    enum class kind { HORIZONTAL, VERTICAL };
    explicit box(kind kind_);

    [[nodiscard]] int width() const override;
    [[nodiscard]] int height() const override;

    widget *child_at(int x, int y) override;
    void update_layout() override;

    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] widget *get(int index) const;
    widget *add(std::unique_ptr<widget> child);
    std::unique_ptr<widget> remove(int index);

private:
    kind kind_;
    int width_;
    int height_;
    std::vector<std::unique_ptr<widget>> children;
    std::vector<int> positions;
};

std::unique_ptr<box> make_box(box::kind kind_);
}  // namespace widgets
#endif  // BOX_HPP_