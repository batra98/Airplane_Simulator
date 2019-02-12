#include "bullet.h"
#include "main.h"

Bullet::Bullet(float x,float y,float z,glm::vec3 bullet_direction)
{
    this->position = glm::vec3(x,y,z);
    this->initial_position = glm::vec3(x,y,z);
    this->bullet_direction = bullet_direction;

    int n = 100;
    GLfloat g_vertex_buffer_data[1805];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f + 0.3*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.3*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -2.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.3*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.3*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.3*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.3*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.3*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.3*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.3*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.3*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -2.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.3*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.3*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -2.0f;
    }

    GLfloat g_vertex_buffer_data1[905];
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = 0.0f;
        g_vertex_buffer_data1[k++] = 0.0f;
        g_vertex_buffer_data1[k++] = 0.0f;

        g_vertex_buffer_data1[k++] = 0.0f + 0.3*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f + 0.3*cos(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f;

        g_vertex_buffer_data1[k++] = 0.0f + 0.3*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data1[k++] = 0.0f + 0.3*cos(2*M_PI/n*(i+1));
        g_vertex_buffer_data1[k++] = 0.0f;
    }

    this->body = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data,COLOR_MISSILE_BODY);
    this->flame = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data1,COLOR_MISSILE_FLAME);

}

void Bullet::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);
    glm::mat4 rotate = glm::mat4(1.0f);
    rotate[2][0] = this->bullet_direction.x;
    rotate[2][1] = this->bullet_direction.y;
    rotate[2][2] = this->bullet_direction.z;

    Matrices.model *= (translate*rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
    draw3DObject(this->body);
    draw3DObject(this->flame);
}

void Bullet::set_position(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Bullet::tick()
{
    this->position -= this->bullet_direction*glm::vec3(1.5,1.5,1.5);
}