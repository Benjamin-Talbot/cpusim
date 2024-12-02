#ifndef GRAPHICALRAM_H
#define GRAPHICALRAM_H

#include "GraphicalElement.h"
#include "RAM.h"

class GraphicalRAM : public GraphicalElement {
private:
    RAM ram;

public:
    RAM getRam();

    void draw();
};

#endif