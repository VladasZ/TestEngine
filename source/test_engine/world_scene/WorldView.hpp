//
//  WorldView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "TestView.hpp"
#include "XYZSlidersView.hpp"

namespace te {

    class WorldView : public ui::View {
    public:

        TestView* testView;
        XYZSlidersView* sliders;

        using View::View;

        void _setup() override;
        void _layout() override;

    };

}
