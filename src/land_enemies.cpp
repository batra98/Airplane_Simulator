#include "land_enemies.h"
#include "main.h"
#include "enemy_cannon.h"

Land_enemies::Land_enemies(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);

    GLfloat g_vertex_buffer_data[] = {
        5.0f,5.0f,5.0f, // triangle 1 : begin
        5.0f,5.0f,-5.0f, // triangle 1 : begin
        -5.0f,5.0f,-5.0f, // triangle 1 : begin

        -5.0f,5.0f,-5.0f, // triangle 1 : begin
        5.0f,5.0f,-5.0f, // triangle 1 : begin
        5.0f,5.0f,5.0f, // triangle 1 : begin

        5.0f,5.0f,5.0f, // triangle 1 : begin
        5.0f,5.0f,-5.0f, // triangle 1 : begin
        0.0f,10.0f,0.0f, // triangle 1 : begin

        5.0f,5.0f,5.0f, // triangle 1 : begin
        -5.0f,5.0f,5.0f, // triangle 1 : begin
        0.0f,10.0f,0.0f, // triangle 1 : begin

        -5.0f,5.0f,5.0f, // triangle 1 : begin
        -5.0f,5.0f,-5.0f, // triangle 1 : begin
        0.0f,10.0f,0.0f, // triangle 1 : begin

        5.0f,5.0f,-5.0f, // triangle 1 : begin
        -5.0f,5.0f,-5.0f, // triangle 1 : begin
        0.0f,10.0f,0.0f, // triangle 1 : begin
        
    };

    this->body = create3DObject(GL_TRIANGLES,18,g_vertex_buffer_data,COLOR_BLACK);

    enemy_cannon = Enemy_cannon(this->position.x,this->position.y,this->position.z);
}

void Land_enemies::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->body);
    enemy_cannon.draw(VP);

}

void Land_enemies::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Land_enemies::tick(glm::vec3 position,glm::vec3 direction){
    this->position = position+glm::vec3(0,0,0);

    enemy_cannon.tick(position+glm::vec3(0,9,0),direction);
    
}