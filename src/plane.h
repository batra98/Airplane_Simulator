#include "main.h"

#ifndef PLANE_H
#define PLANE_H

class Plane {
public:
    Plane() {};
    Plane(float x,float y,float z);
    glm::vec3 position,velocity,acceleration,rotation;
    void draw(glm::mat4 VP);
    void draw2(glm::mat4 VP);
    float propeller_angle;
    float norm_speed;
    float height;
    float radius;
    void set_position(float x,float y,float z);
    void tick();
    void left();
    void right();
    void jump();
    void forward();
    void backward();
    void right_tilt();
    void left_tilt();
    void set_speed(float a);
    bounding_box_t bounding_box();

private:
    VAO *body;
    VAO *head;
    VAO *tail;
    VAO *back_fins;
    VAO *back_circle;
    VAO *propeller;
};

#endif