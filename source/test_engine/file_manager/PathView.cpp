//
//  PathView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 13/03/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "PathView.hpp"
#include "FileManagerView.hpp"


void te::PathView::set_path(const cu::Path& path) {
    _label->set_text(path.file_name());
    _image->set_image(FileManagerView::image_for_extension(path.extension()));
}

const cu::Path& te::PathView::path() const {
    return _path;
}

void te::PathView::setup() {
    init_view(_label, { _frame.size });
    init_view(_image);
}

void te::PathView::layout_subviews() {

    static const float margin = 5;

    auto image_size = _frame.size.height - margin * 2;

    _image->edit_frame() =
            { margin,
              margin,
              image_size,
              image_size
            };

    _label->edit_frame().origin.x = _image->frame().max_x() + margin;

}