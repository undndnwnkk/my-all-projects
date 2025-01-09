This program is a virtual navigation simulator where the user controls a character traveling across a grid using various commands. The program supports recording macros, displaying a map of visited cells, showing statistics, and even displaying thematic quotes. Below is a detailed overview of the program's functionality.

---

## **1. Character Movement Control**
The user can issue the following movement commands:
- **`forward` / `fwd`** — moves the character one step forward in the current direction.
- **`backward` / `bwd`** — moves the character one step backward.
- **`right` / `turn-right`** — turns the character 90 degrees to the right.
- **`left` / `turn-left`** — turns the character 90 degrees to the left.

The character's position is tracked on a coordinate grid.

---

## **2. Displaying Statistics (`stats`)**
The `stats` command outputs the following information:
- The current facing direction of the character (`^` for up, `>` for right, `v` for down, `<` for left).
- The distance from the origin `(0, 0)` along the X and Y axes.
- The total number of unique cells visited by the character.

---

## **3. Map Display (`show-map`)**
The `show-map` command renders a visual map showing visited cells:
- **`o`** represents visited cells.
- **`0`** marks the origin point.
- The character's current position is displayed with the appropriate direction symbol (`^`, `>`, `v`, `<`).

This allows the user to visualize the character's journey and current position.

---

## **4. Command Macros**
The program supports recording sequences of commands (macros):
- **`start-macro`** — starts recording a macro.
- **`end-macro`** — stops recording and saves the macro.
- **`run-macro`** — runs the recorded macro.

Macros make it easy to automate repetitive sequences of steps and turns. After recording ends, the program displays how many commands have been saved.

---

## **5. Thematic Quotes**
The program includes thematic quotes for added entertainment:
- **`sherlock` / `sherlock-holmes`** — displays a quote from a Sherlock Holmes story.
- **`cat` / `cat-jeoffry`** — displays a quote from a poem about Jeoffry the cat.

These commands make the interaction more engaging.

---

## **6. Exiting the Program**
- **`exit` / `quit`** — terminates the program.

Entering any of these commands will close the program.

---

## **Sample Usage Scenario:**
```plaintext
> start-macro
> forward
> forward
> right
> forward
> end-macro
New macro of 3 command(s)
> run-macro
> stats
Player > stands 3 away from OY, 2 away from OX. 4 cell(s) has been visited.
> show-map
```
