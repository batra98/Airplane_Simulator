#include "main.h"

#ifndef INDICATOR_H
#define INDICATOR_H

class Indicator {
public:
    Indicator() {}
    Indicator(float x,float y,float z);
    glm::vec3 position;
    glm::mat4 local_axis;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick(glm::vec3 position,glm::vec3 vector_of_alignment,glm::vec3 z_axis);

    glm::vec3 cross_product(glm::vec3 a,glm::vec3 b);

private:
    VAO *cone;
    VAO *body;
    VAO *cover;
};

#endif