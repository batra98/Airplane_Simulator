#include "enemy_bullet.h"
#include "main.h"

Enemy_bullet::Enemy_bullet(float x,float y,float z,glm::vec3 direction)
{
    this->position = glm::vec3(x,y,z);
    this->direction = direction;
    this->initial_direction = glm::vec3(x,y,z);

    GLfloat g_vertex_buffer_data[]={
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    };

    this->pipe = create3DObject(GL_TRIANGLES,36,g_vertex_buffer_data,COLOR_LAVA); 
}

void Enemy_bullet::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);
    glm::mat4 rotate = glm::mat4(1.0f);
    Matrices.model *= (translate*rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
    draw3DObject(this->pipe);
    
}

void Enemy_bullet::set_position(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Enemy_bullet::tick()
{
    float length = glm::length(glm::vec3(direction.x,direction.y,direction.z));
    glm::vec3 translate = glm::vec3(direction.x/length,direction.y/length,direction.z/length);
    this->position += translate;
}

bounding_sphere_t Enemy_bullet::bounding_sphere()
{
    float x,y,z,radius;

    x = this->position.x;
    y = this->position.y;
    z = this->position.z;

    radius = 1.0f;

    bounding_sphere_t bsphere = {x,y,z,radius};
    return bsphere;
}