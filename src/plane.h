#include "main.h"

#ifndef PLANE_H
#define PLANE_H

class Plane {
public:
    Plane() {};
    Plane(float x,float y,float z);
    glm::vec3 position,velocity,acceleration,rotation;
    glm::mat4 local_rotation;
    void draw(glm::mat4 VP);
    void draw2(glm::mat4 VP);
    float propeller_angle;
    float norm_speed;
    float height;
    float radius;
    float length_z;
    float length_y;
    float length_x;
    float angle_rotate;
    glm::vec3 translate_z;
    glm::vec3 translate_y;
    glm::vec3 translate_x;
    void set_position(float x,float y,float z);
    void tick();
    void left();
    void right();
    void jump();
    void forward();
    void backward();
    void right_tilt();
    void left_tilt();
    void nose_down();
    void nose_up();
    void set_speed(float a);
    bounding_sphere_t bounding_sphere();

private:
    VAO *body;
    VAO *head;
    VAO *tail;
    VAO *back_fins;
    VAO *back_circle;
    VAO *propeller;
};

#endif