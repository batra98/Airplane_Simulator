#include "main.h"

#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

class Enemy_bullet {
public:
    Enemy_bullet() {}
    Enemy_bullet(float x,float y,float z,glm::vec3 direction);
    glm::vec3 position;
    glm::vec3 initial_direction;
    glm::vec3 direction;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
    bounding_sphere_t bounding_sphere();

private:
    VAO *pipe;
};

#endif