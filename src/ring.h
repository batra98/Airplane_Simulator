#include "main.h"

#ifndef RING_H
#define RING_H

class Ring {
public:
    Ring() {}
    Ring(float x,float y,float z);
    glm::vec3 position;
    glm::vec3 position_arrow;
    float velocity;
    
    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();

private:
    VAO *ring;
    VAO *arrow_head;
    VAO *arrow_body;
    VAO *arrow_cover;
};

#endif