#include "main.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor {
public:
    Floor() {}
    Floor(float x,float y,float z);
    glm::vec3 position;
    float acc;
    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
private:
    VAO *object;
};

#endif 