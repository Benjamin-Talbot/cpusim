#ifndef GRAPHICALGENERALPURPOSEREGISTER_H
#define GRAPHICALGENERALPURPOSEREGISTER_H

#include "GraphicalElement.h"
#include "GeneralPurposeRegister.h"

class GraphicalGeneralPurposeRegister : public GraphicalElement {
private:
    GeneralPurposeRegister reg;

public:
    GeneralPurposeRegister getRegister();

    void draw();
};

#endif