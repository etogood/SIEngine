//
// Created by etogood on 16.09.2023.
//

#ifndef SIENGINE_FIRST_APP_HPP
#define SIENGINE_FIRST_APP_HPP

#include "si_window.hpp"

namespace si {
    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
    private:
        SiWindow siWindow{WIDTH, HEIGHT, "Hello, World!"};
    };
}

#endif //SIENGINE_FIRST_APP_HPP
