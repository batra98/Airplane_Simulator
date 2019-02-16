#include "main.h"
#include "indicator.h"


#ifndef PLANE_H
#define PLANE_H

class Plane {
public:
    Plane() {};
    Plane(float x,float y,float z);
    glm::vec3 position,velocity,acceleration,rotation;
    glm::mat4 local_rotation;
    void draw(glm::mat4 VP,camera_view_t camera_view);
    void draw2(glm::mat4 VP);
    float propeller_angle;
    float norm_speed;
    float height;
    float radius;
    float length_z;
    float length_y;
    float length_x;
    float angle_rotate;
    Indicator indicator;
    glm::vec3 translate_z;
    glm::vec3 translate_y;
    glm::vec3 translate_x;
    void set_position(float x,float y,float z);
    void tick(glm::vec3 direction);
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

    float length_fuel;
    float depth;
    glm::mat4 compass_axis;
    float angle;

    float length_altitude;
    

private:
    VAO *body;
    VAO *head;
    VAO *tail;
    VAO *back_fins;
    VAO *back_circle;
    VAO *propeller;
    VAO *pointer;

    VAO *fuelbar;
    VAO *fuel_boundary;

    VAO *compass_circle;
    VAO *compass_pointer;
    VAO *compass_tip;
    VAO *altitude_boundary;
    VAO *altitude;

    
};

#endif