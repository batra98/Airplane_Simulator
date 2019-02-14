#include "main.h"
// #include "enemy_bullet.h"

#ifndef ENEMY_CANNON_H
#define ENEMY_CANNON_H

class Enemy_cannon {
public:
    Enemy_cannon() {}
    Enemy_cannon(float x,float y,float z);
    glm::vec3 position;
    glm::mat4 local_axis;
    // Enemy_bullet enemy_bullet;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick(glm::vec3 position,glm::vec3 direction);

private:
    VAO *pipe;
};

#endif