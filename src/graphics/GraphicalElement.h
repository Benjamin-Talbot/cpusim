#ifndef GRAPHICALELEMENT_H
#define GRAPHICALELEMENT_H

#include <stdio.h>
#include <ncurses.h>

/*
 * Represents a graphical element on the screen.
 */
class GraphicalElement {
    const static int maxZ = 2;
    const static int minZ = -2;
    const static int alertZ = 3;
    // const static int oppositeOfAlertZ = -3;
private:
    int x;
    int y;
    int z;
    int width;
    int height;
    WINDOW* window;
public:
    int getX();
    void setX(int x);

    int getY();
    void setY(int y);

    int getZ();
    void setZ(int z);
    void bubble();
    void bubble(int z);
    void sink();
    void sink(int z);

    int getWidth();
    void setWidth(int width);

    int getHeight();
    void setHeight(int height);

    WINDOW* getWindow();
    // void setWindow(WINDOW* window);

    virtual void draw() = 0;

    virtual ~GraphicalElement() {}
};

#endif