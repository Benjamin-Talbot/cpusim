#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "GraphicalElement.h"
#include <iostream>
#include <ncurses.h>
#include <forward_list>

/*
 * The GraphicsEngine class is responsible for drawing all GraphicalElements
 * that are added to its buffer. It uses the ncurses library to draw to the
 * terminal.
 * The engine should ensure that elements with z values that put them behind 
 * others are not included in the buffer. --> think about this one for a bit 
 * and how it could work, cause it may not be necessary (less performant than
 * if left without these checks) --> still must ensure that ordering is kept
 * so z values are drawn in order
*/

class GraphicsEngine {
private:
    std::forward_list<GraphicalElement*> buffer;
public:
    void draw();
};

#endif