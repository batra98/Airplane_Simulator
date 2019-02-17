#include "main.h"

#ifndef FUEL_POWERUP_H
#define FUEL_POWERUP_H

class Fuel_powerup {
public:
    Fuel_powerup() {};
    Fuel_powerup(float x,float y,float z);
    glm::vec3 position;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick();
    bounding_sphere_t bounding_sphere();

private:
    VAO *fuel_powerup;
};

#endif