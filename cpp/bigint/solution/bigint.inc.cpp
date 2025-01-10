#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace lab_bigint {
const int BASE = 10;

class bigint {
private:
    std::vector<unsigned int> numbers;

    void remove_leading_zeros() {
        while (numbers.size() > 1 && numbers.back() == 0) {
            numbers.pop_back();
        }
    }

public:
    bigint() {
        numbers.push_back(0);
    }

    bigint(const std::string &input_number) {
        numbers.clear();
        std::size_t start = input_number.size();

        const std::size_t base_size = std::to_string(BASE).size() - 1;

        while (start > 0) {
            const std::size_t end = (start > base_size) ? start - base_size : 0;
            const std::string chunk = input_number.substr(end, start - end);
            const unsigned int chunk_value = std::stoi(chunk);
            numbers.push_back(chunk_value);
            start = end;
        }

        remove_leading_zeros();
    }

    bigint(int input_value) {
        if (input_value != 0) {
            while (input_value != 0) {
                numbers.push_back(input_value % BASE);
                input_value /= BASE;
            }
        } else {
            numbers.push_back(0);
        }

        remove_leading_zeros();
    }

    // Equal and Unequal operator:
    friend bool
    operator==(const bigint &left_number, const bigint &right_number) {
        return left_number.numbers == right_number.numbers;
    }

    friend bool
    operator!=(const bigint &left_number, const bigint &right_number) {
        return !(left_number == right_number);
    }

    // Less/more operators:
    friend bool
    operator>(const bigint &left_number, const bigint &right_number) {
        if (left_number.numbers.size() != right_number.numbers.size()) {
            return left_number.numbers.size() > right_number.numbers.size();
        }
        for (auto i = left_number.numbers.rbegin(),
                  j = right_number.numbers.rbegin();
             i != left_number.numbers.rend(); i++, j++) {
            if (*i != *j) {
                return *i > *j;
            }
        }

        return false;
    }

    friend bool
    operator<(const bigint &left_number, const bigint &right_number) {
        if (left_number.numbers.size() != right_number.numbers.size()) {
            return left_number.numbers.size() < right_number.numbers.size();
        }

        for (auto i = left_number.numbers.rbegin(),
                  j = right_number.numbers.rbegin();
             i != left_number.numbers.rend(); ++i, ++j) {
            if (*i != *j) {
                return *i < *j;
            }
        }
        return false;
    }

    // Less-equal/More-equal operators:
    friend bool
    operator>=(const bigint &left_number, const bigint &right_number) {
        return !(left_number < right_number);
    }

    friend bool
    operator<=(const bigint &left_number, const bigint &right_number) {
        return !(left_number > right_number);
    }

    // From vector numbers ints -> string method
    std::string to_string() {
        std::string result;
        for (const auto &current_number :
             std::vector<unsigned int>(numbers.rbegin(), numbers.rend())) {
            result += std::to_string(current_number);
        }
        return result;
    }
};

}  // namespace lab_bigint
