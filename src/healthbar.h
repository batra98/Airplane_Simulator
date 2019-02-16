#include "main.h"

#ifndef HEALTHBAR_H
#define HEALTHBAR_H

class Healthbar {
public:
    Healthbar() {}
    Healthbar(float x,float y,float z);
    glm::vec3 position;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();

private:
    VAO *healthbar;
};

#endif