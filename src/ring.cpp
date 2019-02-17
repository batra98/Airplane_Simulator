#include "ring.h"
#include "main.h"

Ring::Ring(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
    this->position_arrow = glm::vec3(x,y,z);
    this->velocity = 0.1;

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

    n = 100;
    GLfloat g_vertex_buffer_data3[908];

    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data3[k++] = 0.0f;
        g_vertex_buffer_data3[k++] = 5.0f;
        g_vertex_buffer_data3[k++] = 0.0f;

        g_vertex_buffer_data3[k++] = 0.0f + 0.75*sin(2*M_PI/n*i);
        g_vertex_buffer_data3[k++] = 7.0f;
        g_vertex_buffer_data3[k++] = 0.0f + 0.75*cos(2*M_PI/n*i);

        g_vertex_buffer_data3[k++] = 0.0f + 0.75*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data3[k++] = 7.0f;
        g_vertex_buffer_data3[k++] = 0.0f + 0.75*cos(2*M_PI/n*(i+1));
    }


    GLfloat g_vertex_buffer_data1[1808];
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 7.0f;
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 10.0f;
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 10.0f;
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 10.0f;
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 7.0f;
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 7.0f;
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));

    }

    GLfloat g_vertex_buffer_data2[908];

    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data2[k++] = 0.0f;
        g_vertex_buffer_data2[k++] = 10.0f;
        g_vertex_buffer_data2[k++] = 0.0f;

        g_vertex_buffer_data2[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data2[k++] = 10.0f;
        g_vertex_buffer_data2[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);

        g_vertex_buffer_data2[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data2[k++] = 10.0f;
        g_vertex_buffer_data2[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
    }


    this->ring = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data,COLOR_RED);
    this->arrow_head = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data3,COLOR_ARROW);
    this->arrow_body = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data1,COLOR_ARROW_BODY);
    this->arrow_cover = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data2,COLOR_ARROW);
    


}

void Ring::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->ring);

    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position_arrow);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->arrow_head);
    draw3DObject(this->arrow_body);
    draw3DObject(this->arrow_cover);

}

void Ring::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->position_arrow = glm::vec3(x, y, z);

}

void Ring::tick(){

    // std::cout << this->position.y << " " << this->position_arrow.y << '\n';
    if(this->position_arrow.y > this->position.y+5)
    {
        velocity*=-1;
    }
    else if(this->position_arrow.y < this->position.y)
    {
        velocity*=-1;
    }
    
    this->position_arrow.y += velocity;
}