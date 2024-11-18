#include "abstract_widgets.hpp"

namespace widgets {

widget *widget::child_at(int x, int y) {
    if (x < width() && y < height() && x >= 0 && y >= 0) {
        return this;
    } else {
        return nullptr;
    }
}

}  // namespace widgets