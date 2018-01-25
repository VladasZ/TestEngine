//
//  TestEngineMain.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//


#include "TestEngineMain.h"
#include "GL/GL.hpp"
#include "Window.hpp"

void testEngineMain() {
    
#if MEMORY_TEST
    memoryTest();
    MemoryManager::printDump();
    return;
#endif
    
	Window::initialize(1200, 800);

	do {
		glfwPollEvents();

		Window::update();

		glfwSwapBuffers(Window::window);
	} while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0);
    
    MemoryManager::printDump();
}