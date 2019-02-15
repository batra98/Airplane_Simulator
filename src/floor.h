#include "main.h"
#include "land_enemies.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor {
public:
    Floor() {}
    Floor(float x,float y,float z);
    glm::vec3 position;
    glm::vec3 acc;
    glm::vec3 position_volcano;
    Land_enemies land_enemies;
    int hit;
    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick(glm::vec3 direction);
    void tick2(glm::vec3 direction);
    void draw2(glm::mat4 VP);

    bounding_sphere_t bounding_sphere();
    bounding_sphere_t bounding_sphere2();


private:
    VAO *object;
    VAO *volcano;
    VAO *flames;
    VAO *base;
};

#endif 