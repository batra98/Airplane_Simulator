#include "main.h"

#ifndef HEALTH_POWERUP_H
#define HEALTH_POWERUP_H

class Health_powerup {
public:
    Health_powerup() {};
    Health_powerup(float x,float y,float z);
    glm::vec3 position;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
    bounding_sphere_t bounding_sphere();

private:
    VAO *health_powerup;
};

#endif