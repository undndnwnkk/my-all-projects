## **Bigint Project** — C++ Class for Large Integer Arithmetic

The **bigint** project is a C++ class designed to manage large integers. The class enables performing arithmetic operations with numbers significantly larger than those supported by standard data types such as `int` or `unsigned int`. The implementation is based on an integer vector that stores each part of the number as a separate "digit" in a defined number system.

---

### **Constructors**

The class provides several constructors for creating `bigint` objects:

- **Default constructor**: Initializes the `bigint` to zero.
- **String constructor**: Creates a `bigint` from a string containing a large integer.
- **Integer constructor**: Initializes a `bigint` object using a standard `int` value.

---

### **Comparison Operators**

The following comparison operators are implemented to compare two `bigint` objects:

- `==` and `!=` — Check equality and inequality.
- `<`, `>`, `<=`, and `>=` — Compare relative magnitude.

---

### **String Conversion**

To convert a `bigint` to a string, the `to_string()` method returns a string representation of the number. This allows easy printing and debugging of large numbers.

---

### **Explicit Conversion to `unsigned int`**

The `operator unsigned int()` explicitly converts a `bigint` to `unsigned int`, provided that the value fits within the range of `unsigned int`.

---

### **Arithmetic Operations**

The class supports the following arithmetic operations:

- **Addition**:
  - `operator+`: Adds two `bigint` objects and returns a new result.
  - `operator+=`: Adds another `bigint` to the calling object.
- **Subtraction**:
  - `operator-`: Subtracts one `bigint` from another and returns a new result.
  - `operator-=`: Subtracts another `bigint` from the calling object.

---

### **Increment and Decrement**

The prefix and postfix operators `++` and `--` are implemented:

- `++` — Increments the value by 1.
- `--` — Decrements the value by 1.

---

### **Input and Output Operators**

The input and output operators `>>` and `<<` provide convenient ways to read and write `bigint` values:

- `>>` — Reads a `bigint` from an input stream (entered as a string).
- `<<` — Outputs a `bigint` as a string representation to an output stream.
