//
//  RootView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"

class RootView : public View {
    
    friend Window;
    
    Label *helloLabel;
    Button *button;
    Path *testPath;
    
    void setup() override;
    
public:
    
    using View::View;

    void draw() override;
};