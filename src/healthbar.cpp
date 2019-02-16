#include "healthbar.h"
#include "main.h"

Healthbar::Healthbar(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);

    int n = 50;
    GLfloat g_vertex_buffer_data[508];

    int k = 0;
    for(int i = 0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f + 4.0*sin(2*M_PI/n*i);
        g_vertex_buffer_data[k++] = 0.0f + 4.0*cos(2*M_PI/n*i);
        g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f + 4.0*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 4.0*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
    }

    this->healthbar = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_LAVA);
}

void Healthbar::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->healthbar);
}
void Healthbar::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Healthbar::tick(){
    // this->position = (this->position)+(glm::vec3(0,-5,0))*(glm::vec3(0.01,0.01,0.01));
    
}