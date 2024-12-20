#ifdef _MSC_VER
#include <crtdbg.h>
#endif
#include <iostream>
#include <string>

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
    EndMacro
};

Operation get_operation(const std::string &operation_str) {
    if (operation_str == "exit" || operation_str == "quit") {
        return Operation::Exit;
    } else if (operation_str == "sherlock" || operation_str == "sherlock-holmes") {
        return Operation::Sherlock;
    } else if (operation_str == "cat" || operation_str == "cat-jeoffry") {
        return Operation::Cat;
    } else {
        return Operation::Exit;
    }
}

int main() {
#ifdef _MSC_VER
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
#endif

    while(true) {
        std::string operation_str;

        if(!(std::cin >> operation_str)) {
            break;
        }

        Operation operation = get_operation(operation_str);

        switch(operation) {
            case Operation::Exit:
                return 0;
                break;
            case Operation::Sherlock:
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
            case Operation::Cat:
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
        }
    }
}
