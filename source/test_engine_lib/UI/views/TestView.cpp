//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "TestView.hpp"

using namespace ui;

void TestView::_setup() {
    
    add_subview(left_stick = new AnalogStickView());
    left_stick->on_direction_change.subscribe([](auto point) {

    });
    
    add_subview(right_stick = new AnalogStickView());
    right_stick->on_direction_change.subscribe([](auto point) {
        TestView::on_stick_move(point);
    });
    
    button = new Button();
    add_subview(button);
    
    button->on_press.subscribe([]{
        Log("SOPOK");
    });
    
}

void TestView::_layout() {
    
    _frame = _superview->frame();
    
    View::_layout();
    
    right_stick->set_center(_frame.size.center());
    
    button->set_frame({
        0,
        _frame.size.height - 100,
        100,
        100
    });
    
    static const float margin = 20;
    
    left_stick->set_center({
        left_stick->frame().size.width / 2 + margin,
        _frame.size.height - left_stick->frame().size.height / 2 - margin,
    });
    
    right_stick->set_center({
        _frame.size.width - right_stick->frame().size.width / 2 - margin,
        _frame.size.height - right_stick->frame().size.height / 2 - margin,
    });
    
}
