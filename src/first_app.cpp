//
// Created by etogood on 16.09.2023.
//

#include "first_app.hpp"

namespace si {
    void FirstApp::run() {
        while(!siWindow.shouldClose()){
            glfwPollEvents();
        }
    }
}