#include <iostream>
#include "morseur.hpp"

int main() {

    auto encoded = morseur::encode("Hello World");
    auto decoded = morseur::decode(encoded);

    std::cout << "Encoded: " << encoded << std::endl;
    std::cout << "Decoded: " << decoded << std::endl;
    
    return 0;
}