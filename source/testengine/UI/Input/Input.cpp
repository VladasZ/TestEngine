//
//  Input.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Input.hpp"
#include "Point.hpp"
#include "Window.hpp"
#include "DebugInfoView.hpp"
#include "GL.hpp"
#include "View.hpp"
#include "Log.hpp"
#include "GlobalEvents.hpp"
#include "Dictionary.hpp"


#if GLFW

Point Input::cursorPosition;
bool Input::mouseKeyIsPressed;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    
    if (button != GLFW_MOUSE_BUTTON_LEFT) return;
    
    if (action == GLFW_PRESS) {
        Input::mouseKeyIsPressed = true;
        Input::touchBegan(Input::cursorPosition.x, Input::cursorPosition.y, 1);
    }
    else {
        Input::mouseKeyIsPressed = false;
        Input::touchEnded(Input::cursorPosition.x, Input::cursorPosition.y, 1);
    }
}

void cursorPositionCallback(GLFWwindow* window, double x, double y) {
    Input::cursorPosition = Point((float)x, (float)y);
    if (Input::mouseKeyIsPressed) Input::touchMoved((float)x, (float)y, 1);
}

#endif

void Input::initialize() {
#if GLFW
    glfwSetCursorPosCallback(Window::window, cursorPositionCallback);
    glfwSetMouseButtonCallback(Window::window, mouseButtonCallback);
#endif
}

void Input::touchBegan(INPUT_PARAMETERS) {
	Point location{ x, y };
	Events::touch(location);

	for (auto view : _subscribedViews)
		if (view->containsGlobalPoint(location)) {
			view->_touchID = id;
			view->on_touch(Touch(view->localPointFrom(location), Touch::Event::Began));
			break;
		}
}

void Input::touchMoved(INPUT_PARAMETERS) {
	Point location{ x, y };
	Events::touch(location);
	
	for (auto view : _subscribedViews)
		if (id == view->_touchID) {
			view->on_touch(Touch(view->localPointFrom(location), Touch::Event::Moved));
			break;
		}
}

void Input::touchEnded(INPUT_PARAMETERS) {
	Point location{ x, y };
	Events::touch(location);

	for (auto view : _subscribedViews)
		if (id == view->_touchID) {
			view->on_touch(Touch(view->localPointFrom(location), Touch::Event::Ended));
			view->_touchID = -1;
			break;
		}
}

void Input::pressedKey(const char &key) {
    Log(key);
}

void Input::subscribeView(View* view) {
	_subscribedViews.push_back(view);
}

void Input::unsubscribeView(View* view) {
	_subscribedViews.remove(view);
}