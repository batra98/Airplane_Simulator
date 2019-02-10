#include "floor.h"
#include "main.h"

Floor::Floor(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
    if(rand()%4 == 0)
    {
        acc = glm::vec3(rand()%3,0,rand()%3);
    }
    else if(rand()%4 == 1)
    {
        acc = glm::vec3(-rand()%3,0,rand()%3);
    }
    else if(rand()%4 == 2)
    {
        acc = glm::vec3(rand()%3,0,-rand()%3);
    }
    else if(rand()%4 == 3)
    {
        acc = glm::vec3(-rand()%3,0,-rand()%3);
    }
    
    
    int n = 50;
    int k = 0;
    GLfloat g_vertex_buffer_data[455];
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f + 80*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f + 80*cos(2*M_PI/n*i);

		g_vertex_buffer_data[k++] = 0.0f + 80*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f + 80*cos(2*M_PI/n*(i+1));
    }

    GLfloat g_vertex_buffer_data1[1005];
    k=0;
    int rx = rand()%60;
    int rz = rand()%60;
    int ry = rand()%60+10;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = rx;
        g_vertex_buffer_data1[k++] = ry;
        g_vertex_buffer_data1[k++] = rz;

        g_vertex_buffer_data1[k++] = rx + 10*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f;
        g_vertex_buffer_data1[k++] = rz + 10*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = rx + 10*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data1[k++] = 0.0f;
		g_vertex_buffer_data1[k++] = rz + 10*cos(2*M_PI/n*(i+1));
    }

    this->object = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_CLOUDS);
    this->volcano = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data1,COLOR_GREEN);

}

void Floor::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->volcano);
}

void Floor::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Floor::tick(){
    this->position+= this->acc*glm::vec3(0.08,0.08,0.08);
    
    
}