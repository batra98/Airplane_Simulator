#include "main.h"

#ifndef BULLET_H
#define BULLET_H

class Bullet {
public:
    Bullet() {}
    Bullet(float x,float y,float z,glm::vec3 bullet_direction);
    glm::vec3 position;
    glm::vec3 bullet_direction;
    glm::vec3 initial_position;
    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
private:
    VAO *body;
    VAO *flame;
};

#endif

