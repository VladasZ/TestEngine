//
//  SliderView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Input.hpp"
#include "ImageView.hpp"
#include "SliderView.hpp"

void SliderView::setup() {
    
    _color = C::gray;
    
    _topArrow = (new ImageView({ _frame.size.width, _frame.size.width }))
                    ->setImage(I::up);
    
    _bottomArrow = (new ImageView({ _frame.size.width, _frame.size.width }))
                    ->setImage(I::down);
    
    _slider = (new View({ _frame.size.width, _frame.size.height / 10 }));
    
    _slider->setColor(C::green);
    
    _slider_content_view = new View();
    _slider_content_view->setColor(C::blue);
    
    _slider_content_view->addSubview(_slider);
    
    addSubview(_topArrow);
    addSubview(_bottomArrow);
    addSubview(_slider_content_view);
}

void SliderView::layout() {
    
    View::layout();
    
    auto slider_content_view_height = _frame.size.height - _frame.size.width / 2;
    auto slider_height = _frame.size.height / 10;
    
    _slider_content_view->setFrame({
        0,
        _frame.size.width,
        _frame.size.width,
        slider_content_view_height
    });
    
    _slider->setFrame({
        0,
        (slider_content_view_height - slider_height) * value / 1,
        _frame.size.width,
        slider_height
    });
    
    _bottomArrow->setY(_frame.size.width + slider_content_view_height);
}

