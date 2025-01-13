Widgets can be either simple (`button`, `ball_icon`, `placeholder`) or containers (`box`). Containers can hold other widgets and arrange them in different ways. All widgets have coordinates, dimensions, and methods to interact with their children.

---

## **Main Classes and Methods**

### 1. **`widget` (Base Class)**
This class defines the interface for all widgets and provides methods for working with dimensions and positions.
- **Method `child_at(int x, int y)`**: checks if the point \((x, y)\) is inside the widget and returns a pointer to the current widget if it is not a container. If the point is outside the widget bounds, it returns `nullptr`.

---

### 2. **`ball_icon` (Ball Icon)**
This widget represents a circular element with a radius `radius` and has computed width and height of \((2 \times \text{radius} + 1)\).
- **`width()` and `height()`**: return the widget’s dimensions in pixels.
- **`radius()`**: getter and setter for the radius.
- **`child_at(int x, int y)`**: calculates the distance from the center and returns the current widget if the point is inside the circle; otherwise, returns `nullptr`.

**Usage Example**: This widget is used for displaying a circular area, such as an icon in a user interface.

---

### 3. **`button` (Button with Text)**  
This widget contains a text label and has fixed paddings.
- **`width()`**: the button width depends on the length of the label: \(10 + 8 \times \text{label length}\).
- **`height()`**: the button height is fixed at `22 pixels`.
- **Constructor**: takes a string for the button label.
- **Factory Method `make_button()`**: creates a button with the specified label.

**Usage Example**: Adding buttons with text for user interface controls.

---

### 4. **`placeholder` (Placeholder)**
A simple widget with fixed dimensions that do not change after creation.
- **Constructor**: takes the width and height.
- **Factory Method `make_placeholder()`**: creates a placeholder widget with the specified dimensions.

---

### 5. **`box` (Container)**
A container widget that can be either vertical or horizontal, arranging its child widgets accordingly:
- **`kind`**: specifies the container type (`HORIZONTAL` or `VERTICAL`).
- **`width()` and `height()`**: calculate the dimensions of the container based on the dimensions of its child widgets.
- **`add(child)`**: adds a child widget.
- **`remove(index)`**: removes a child widget at the specified index and returns a unique pointer to it.
- **`update_layout()`**: updates the position of all child widgets and recalculates the container’s bounding box.
- **`child_at(int x, int y)`**: returns a pointer to the child widget containing the point \((x, y)\), or `nullptr` if no such widget is present.

**Usage Example**: Creating a layout with horizontal or vertical alignment of elements.

---

## **System Usage Examples**

1. **`ball_icon` Example:**
   ```cpp
   auto icon = make_ball_icon(5);
   assert(icon->width() == 11);  // width: 2 * 5 + 1
   ```

2. **`box` Container Example:**
   ```cpp
   auto horizontal_box = make_box(box::kind::HORIZONTAL);
   horizontal_box->add(make_button("Hello"));
   horizontal_box->add(make_placeholder(20, 20));
   horizontal_box->update_layout();
   ```
   - Here, a horizontal container is created with a button and a placeholder. The `update_layout` method recalculates the container’s dimensions.
