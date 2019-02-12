#include "main.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor {
public:
    Floor() {}
    Floor(float x,float y,float z);
    glm::vec3 position;
    glm::vec3 acc;
    glm::vec3 position_volcano;
    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
    bounding_sphere_t bounding_sphere();
    bounding_sphere_t bounding_sphere2();


private:
    VAO *object;
    VAO *volcano;
    VAO *flames;
    VAO *base;
};

#endif 