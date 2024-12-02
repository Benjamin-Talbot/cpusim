#include "GraphicalElement.h"

/*
 * Return the x coordinate of the graphical element.
 */
int GraphicalElement::getX() { return this->x; }
/*
 * Set the x coordinate of the graphical element.
 * @param x: value to assign to x coordinate of the graphical element.
 */
void GraphicalElement::setX(int x) { this->x = x; }

/*
 * Return the y coordinate of the graphical element.
 */
int GraphicalElement::getY() { return this->y; }
/*
 * Set the y coordinate of the graphical element.
 * @param y: value to assign to y coordinate of the graphical element.
 */
void GraphicalElement::setY(int y) { this->y = y; }

/*
 * Return the z coordinate of the graphical element.
 */
int GraphicalElement::getZ() { return this->z; }
/*
 * Set the z coordinate of the graphical element.
 * @param z: value to assign to z coordinate of the graphical element.
 */
void GraphicalElement::setZ(int z) { this->z = z; }
/*
 * Increment the z coordinate of the graphical element.
 */
void GraphicalElement::bubble() { if (this->z < maxZ) this->z++; }
/*
 * Add an amount the z coordinate of the graphical element.
 * @param z: value to assign to z coordinate of the graphical element.
 */
void GraphicalElement::bubble(int z) { if (this->z + z <= maxZ) this->z += z; }
/*
 * Decrement the z coordinate of the graphical element.
 * @param z: value to assign to z coordinate of the graphical element.
 */
void GraphicalElement::sink() { if (this->z > minZ) this->z--; }
/*
 * Subtract an amount from the z coordinate of the graphical element.
 * @param z: value to assign to z coordinate of the graphical element.
 */
void GraphicalElement::sink(int z) { if (this->z - z >= minZ) this->z -= z; }

/*
 * Return the width of the graphical element.
 */
int GraphicalElement::getWidth() { return this->width; }
/*
 * Set the width of the graphical element.
 * @param width: the value to assign to the width of the graphical element.
 */
void GraphicalElement::setWidth(int width) { this->width = width; }

/*
 * Return the height of the graphical element.
 */
int GraphicalElement::getHeight() { return this->height; }
/*
 * Set the height of the graphical element.
 * @param height: the value to assign to the height of the graphical element.
 */
void GraphicalElement::setHeight(int height) { this->height = height; }

/*
 * Return the window of the graphical element.
 */
WINDOW* GraphicalElement::getWindow() { return this->window; }
/*
 * Set the window of the graphical element.
 */
// GraphicalElement::void setWindow(WINDOW* window) { this->window = window; }