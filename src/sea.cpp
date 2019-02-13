#include "sea.h"
#include "main.h"

Sea::Sea(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);

    GLfloat g_vertex_buffer_data[]={
        -9000.0f,0.0f,9000.0f,
        9000.0f,0.0f,9000.0f,
        9000.0f,0.0f,-9000.0f,

        -9000.0f,0.0f,9000.0f,
        -9000.0f,0.0f,-9000.0f,
        9000.0f,0.0f,-9000.0f,
    };

    this->object = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data,COLOR_SEA);
}

void Sea::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Sea::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Sea::tick(){
    
}