#include "main.h"

#ifndef BOMB_H
#define BOMB_H

class Bomb {
public:
    Bomb() {}
    Bomb(float x,float y,float z);
    glm::vec3 position;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
    bounding_sphere_t bounding_sphere();

private:
    VAO *bomb;

};

#endif