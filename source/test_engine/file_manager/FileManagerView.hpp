//
//  FileManagerView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 27/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Image.hpp"
#include "StackView.hpp"
#include "ScrollView.hpp"


namespace te {

    class FileManagerTopPanel;

    class FileManagerView : public ui::ScrollView {

    private:

        cu::Path _path;
        FileManagerTopPanel* _top_panel;
        ui::StackView* _stack_view;

    public:

        using ScrollView::ScrollView;

        float cell_height = 50.0f;

    protected:

        void set_path(const cu::Path& path);

        void setup() override;
        void layout_subviews() override;

    public:

        static Image* image_for_extension(const std::string& extension);

    };

}
