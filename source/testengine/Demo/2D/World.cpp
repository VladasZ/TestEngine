//
//  World.cpp
//  friskEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "World.hpp"
#include "Unit.hpp"
#include "Sprite.hpp"
#include "Image.hpp"
#include "GL.hpp"
#include "RootView.hpp"
#include "AnalogStickView.hpp"

World world;

static Unit* frisk;

World::World() { }

void World::addSprite(Sprite* sprite) {
    objects.push_back(sprite);
}

void World::update() {
    for (auto sprite  : objects) {
        if (Movable* movable = dynamic_cast<Movable*>(sprite)) movable->update();
        sprite->draw();
    }
}

void World::setup() {
    frisk = new Unit(Image::frisk);
    addSprite(frisk);
    
    frisk->setPosition(ui::Point(150, 150));
    frisk->setSize(ui::Size(34, 57));
    
    frisk->setSubsprites({
		ui::Rect( 6,   7, 33, 57),
		ui::Rect( 7,  65, 34, 56),
		ui::Rect(57, 131, 33, 57),
		ui::Rect(53, 190, 34, 56)
    });

}
