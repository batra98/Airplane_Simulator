#include "main.h"

#ifndef PARACHUTE_H
#define PARACHUTE_H

class Parachute {
public:
    Parachute() {}
    Parachute(float x,float y,float z);
    glm::vec3 position;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
    bounding_sphere_t bounding_sphere();

private:
    VAO *top;
    VAO *lines;
    VAO *gift;
};

#endif