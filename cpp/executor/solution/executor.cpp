#ifdef _MSC_VER
#include <crtdbg.h>
#endif
#include <iostream>
#include <string>
#include <set>
#include <vector>

struct Position{
    int x = 0;
    int y = 0;
};

enum class Operation { 
    Exit,
    Sherlock,
    Cat,
    MoveForward,
    MoveBackward,
    TurnRight,
    TurnLeft,
    Stats,
    StartMacro,
    EndMacro,
    RunMacro
};

enum class Direction {
    Up,
    Right,
    Down,
    Left
};

Operation get_operation(const std::string &operation_str) {
    if (operation_str == "exit" || operation_str == "quit") {
        return Operation::Exit;
    } else if (operation_str == "sherlock" || operation_str == "sherlock-holmes") {
        return Operation::Sherlock;
    } else if (operation_str == "cat" || operation_str == "cat-jeoffry") {
        return Operation::Cat;
    } else if(operation_str == "fwd" || operation_str == "forward") {
        return Operation::MoveForward;
    } else if(operation_str == "bwd" || operation_str == "backward") {
        return Operation::MoveBackward;
    } else if(operation_str == "turn-right" || operation_str == "right") {
        return Operation::TurnRight;
    } else if(operation_str == "turn-left" || operation_str == "left") {
        return Operation::TurnLeft;
    } else if(operation_str == "fwd" || operation_str == "forward") {
        return Operation::MoveForward;
    } else if(operation_str == "print-statistics" || operation_str == "stats") {
        return Operation::Stats;
    } else if (operation_str == "start-macro") {
        return Operation::StartMacro;
    } else if(operation_str == "end-macro") {
        return Operation::EndMacro;
    } else if(operation_str == "run-macro") {
        return Operation::RunMacro;
    } else {
        return Operation::Exit;
    }
}

void move_forward(Position &pos ,Direction dir) {
    switch(dir) {
        case Direction::Up: pos.y++; break;
        case Direction::Right: pos.x++; break;
        case Direction::Down: pos.y--; break;
        case Direction::Left: pos.x--; break;
    }
}

void move_backward(Position &pos ,Direction dir) {
    switch(dir) {
        case Direction::Up: pos.y--; break;
        case Direction::Right: pos.x--; break;
        case Direction::Down: pos.y++; break;
        case Direction::Left: pos.x++; break;
    }
}

Direction turn_left(Direction dir) {
    switch (dir) {
        case Direction::Up: return Direction::Left; break;
        case Direction::Right: return Direction::Up; break;
        case Direction::Down: return Direction::Right; break;
        case Direction::Left: return Direction::Down; break;
    }
    return dir;
}

Direction turn_right(Direction dir) {
    switch (dir) {
        case Direction::Up: return Direction::Right; break;
        case Direction::Right: return Direction::Down; break;
        case Direction::Down: return Direction::Left; break;
        case Direction::Left: return Direction::Up; break;
    }
    return dir;
}

void stats (const Position &pos,const Direction dir,const std::set<std::pair<int, int>> &visited_cells){
    switch (dir) {
        case Direction::Up:
            std::cout << "Player ^ stands " << abs(pos.x) << " away from OY, " << abs(pos.y) << " away from OX. " << visited_cells.size() << " cell(s) has been visited." << std::endl;
            break;
        case Direction::Right:
            std::cout << "Player > stands " << abs(pos.x) << " away from OY, " << abs(pos.y) << " away from OX. " << visited_cells.size() << " cell(s) has been visited." << std::endl;
            break;
        case Direction::Down:
            std::cout << "Player v stands " << abs(pos.x) << " away from OY, " << abs(pos.y) << " away from OX. " << visited_cells.size() << " cell(s) has been visited." << std::endl;
            break;
        case Direction::Left:
            std::cout << "Player < stands " << abs(pos.x) << " away from OY, " << abs(pos.y) << " away from OX. " << visited_cells.size() << " cell(s) has been visited." << std::endl;
            break;
    }
}

void run_macro(std::set<std::pair<int, int>> &visited_cells, Position &pos, Direction &dir, const std::vector <Operation> macros_commands) {
    if(macros_commands.size() != 0) {
        for(const Operation current_command : macros_commands) {
            switch (current_command) {
                case Operation::MoveForward:
                    move_forward(pos, dir);
                    visited_cells.insert({pos.x, pos.y});
                    break;
                case Operation::MoveBackward:
                    move_backward(pos, dir);
                    visited_cells.insert({pos.x, pos.y});
                    break;
                case Operation::TurnRight:
                    dir = turn_right(dir);
                    break;
                case Operation::TurnLeft:
                    dir = turn_left(dir);
                    break;
                case Operation::Stats:
                    stats(pos, dir, visited_cells);
                    break;
                default:
                    break;
            }
        }
    }
}

int main() {
#ifdef _MSC_VER
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
#endif
    Position pos;
    Direction dir = Direction::Up;
    std::set<std::pair<int, int>> visited_cells;
    visited_cells.insert({pos.x, pos.y});
    std::vector<Operation> macros_commands{};
    bool isRecording = false;

    while(true) {
        std::string operation_str;

        if(!(std::cin >> operation_str)) {
            break;
        }

        Operation operation = get_operation(operation_str);
        if (isRecording && (operation == Operation::MoveForward || operation == Operation::MoveBackward ||
                                operation == Operation::TurnRight || operation == Operation::TurnLeft ||
                                operation == Operation::Stats)) {
            macros_commands.push_back(operation);
            std::cout << "Recorded" << std::endl;
            continue;
        }


        switch(operation) {
            case Operation::Exit:
            {
                return 0;
                break;
            }

            case Operation::Sherlock:
            {
                std::cout << "I had had so many reasons to believe in my friend's subtle powers of\n";
                std::cout << "reasoning and extraordinary energy in action that I felt that he must\n";
                std::cout << "have some solid grounds for the assured and easy demeanour with which\n";
                std::cout << "he treated the singular mystery which he had been called upon to\n";
                std::cout << "fathom. Once only had I known him to fail, in the case of the King of\n";
                std::cout << "Bohemia and of the Irene Adler photograph; but when I looked back to\n";
                std::cout << "the weird business of the Sign of Four, and the extraordinary\n";
                std::cout << "circumstances connected with the Study in Scarlet, I felt that it would\n";
                std::cout << "be a strange tangle indeed which he could not unravel.\n";
                break;
            }
            case Operation::Cat:
            {
                const std::string cats_quote =
                    R"(For he is of the tribe of Tiger.
For the Cherub Cat is a term of the Angel Tiger.
For he has the subtlety and hissing of a serpent, which in goodness he suppresses.
For he will not do destruction, if he is well-fed, neither will he spit without provocation.
For he purrs in thankfulness, when God tells him he's a good Cat.
For he is an instrument for the children to learn benevolence upon.
For every house is incomplete without him and a blessing is lacking in the spirit.
For the Lord commanded Moses concerning the cats at the departure of the Children of Israel from Egypt.
For every family had one cat at least in the bag.
For the English Cats are the best in Europe.)";
                std::cout << cats_quote << std::endl;
                break;
            }
            case Operation::MoveForward:
            {
                move_forward(pos, dir);
                visited_cells.insert({pos.x, pos.y});
                break;
            }
            case Operation::MoveBackward:
                move_backward(pos, dir);
                visited_cells.insert({pos.x, pos.y});
                break;
            case Operation::TurnRight:
                dir = turn_right(dir);
                break;
            case Operation::TurnLeft:
                dir = turn_left(dir);
                break;
            case Operation::Stats:
                stats(pos, dir, visited_cells);
                break;
            case Operation::StartMacro:
                macros_commands.clear();
                isRecording = true;
                break;
            case Operation::EndMacro:
                isRecording = false;
                std::cout << "New macro of " << macros_commands.size() << " command(s)" << std::endl;
                break;
            case Operation::RunMacro:
                run_macro(visited_cells, pos, dir, macros_commands);
        }
    }
}
