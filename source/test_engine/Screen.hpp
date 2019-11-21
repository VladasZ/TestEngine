//
//  Window.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Debug.hpp"
#include "Level.hpp"
#include "Scene.hpp"
#include "RootView.hpp"

#ifdef DEBUG_VIEW
class DebugInfoView;
#endif

namespace te {

	class Screen {

	private:

		void _initialize_ui();

		scene::Scene*   _scene = nullptr;
#ifndef NO_BOX2D
        sprites::Level* _level = nullptr;
#endif
        ui::View*       _view  = nullptr;

        te::RootView* _root_view = nullptr;

	public:

		unsigned FPS = 0;
		unsigned frames_drawn = 0;

		static inline gm::Size size;

		static inline gm::Color clear_color;

#ifdef DEBUG_VIEW
		static inline DebugInfoView* debug_view = nullptr;
#endif

	public:

		Screen(const gm::Size&);
#ifdef DESKTOP_BUILD
		void start_main_loop();
#endif

		void update();

		void setup_input();

		void set_size(const gm::Size&);

	public:

		void set_scene(scene::Scene*);
		scene::Scene* scene() const;

#ifndef NO_BOX2D
		void set_level(sprites::Level*);
		sprites::Level* level() const;
#endif
        
        void set_view(ui::View*);
        ui::View* view() const;

		te::RootView* root_view() const;

	};

}