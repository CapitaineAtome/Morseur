#ifndef MORSEUR_HPP
#define MORSEUR_HPP

#include <string.h>
#include <string>
#include <array>

static constexpr unsigned int MorseArraySize{39UL};

static constexpr std::array<const char * const, MorseArraySize> morse_table_ = {
        ".-",    "-...",  "-.-.",   "-..",   ".",     "..-.",   "--.",    "....",
        "..",    ".---",  "-.-",    ".-..",  "--",    "-.",     "---",    ".--.", 
        "--.-",  ".-.",   "...",    "-",     "..-",   "...-",   ".--",    "-..-", 
        "-.--",  "--..",  "-----", ".----", "..---",  "...--",  "....-",
        ".....", "-....", "--...",  "---..", "----.", "--..--", "..--..", 
};

static constexpr std::array<char, MorseArraySize> ascii_table_ = {

        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z', '0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9', ',', '?', 
};

static constexpr char is_upper_(const char c) {

        return c >= 'A' && c <= 'Z';
}

static constexpr char is_lower_(const char c) {

        return c >= 'a' && c <= 'z';
}

static constexpr char is_alphabet_(const char c) {

        return is_lower_(c) || is_upper_(c);
}


static constexpr char to_lower_(const char c) {

        if(is_upper_(c)) {

                return 'a' + (c - 'A');
        }

    return c;
}

static constexpr int find_index_of_(const char * const car, const std::array<const char * const, MorseArraySize> &array) {

        int idx{0UL};

        for(const auto elem: array) {

                if(strlen(car) == strlen(elem) && strcmp(car, elem) == 0) {
                        
                        return idx;
                }

                ++idx;
        }

        return -1;
}

static constexpr int find_index_of_(const char car, const std::array<char, MorseArraySize> &array) {

        int idx{0};

        for(const auto elem: array) {

                if(car == array[idx]) {
                        
                        return idx;
                }

                ++idx;
        }

        return -1;
}

namespace morseur {

    std::string encode(const std::string &message, char separator=' ') {

        std::string encoded{};

        for(const auto elem: message) {

                auto ret = find_index_of_(to_lower_(elem), ascii_table_);
                if(ret == -1) {
                        continue;
                }
                
                encoded += std::string(morse_table_[ret]) + ' ';

        }

        return encoded;
    }

    std::string decode(const std::string &message, char separator=' ') {

        std::string decoded{};
        std::string tmp;

        for(const auto elem: message) {

                if(elem == ' ' || elem == '\0') {

                        auto ret = find_index_of_(tmp.c_str(), morse_table_);
                        tmp = {};

                        if(ret == -1) {
                                continue;
                        }
                
                        decoded += ascii_table_[ret];

                } else {

                        tmp += elem;
                }
                
        }

        return decoded;
    }

}



#endif // MORSEUR_HPP
