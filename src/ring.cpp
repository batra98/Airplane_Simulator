#include "ring.h"
#include "main.h"

Ring::Ring(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);

    int n = 100;
    GLfloat g_vertex_buffer_data[3605];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f + 5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -0.5f;

		g_vertex_buffer_data[k++] = 0.0f + 5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = 0.0f + 5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f + 5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f + 5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -0.5f;

		g_vertex_buffer_data[k++] = 0.0f + 5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -0.5f;
    }

    this->ring = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data,COLOR_RED);


}

void Ring::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->ring);
}

void Ring::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Ring::tick(){
    
}