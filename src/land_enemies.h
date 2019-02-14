#include "main.h"
#include "enemy_cannon.h"

#ifndef LAND_ENEMIES
#define LAND_ENEMIES

class Land_enemies {
public:
    Land_enemies() {}
    Land_enemies(float x,float y,float z);
    glm::vec3 position;
    Enemy_cannon enemy_cannon;

    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void tick(glm::vec3 position,glm::vec3 direction);

private:
    VAO *body;
};

#endif