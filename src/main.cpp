//
// Created by etogood on 16.09.2023.
//

#include "first_app.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main(){
    si::FirstApp app{};
    try {
        app.run();

    } catch (const std::exception &e){
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}