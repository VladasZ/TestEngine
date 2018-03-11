//
//  Button.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"

class Button : public View _MEMORY_MANAGED(Button) {
    
    friend Input;
        
    function<void()> action;
    
    ImageView *imageView = nullptr;
    Label *label = nullptr;
    
public:
    
    using View::View;
    
    void setText(const String &text);
    void setImage(Image *image);
    
    void onTouch(function<void()> action);    
};