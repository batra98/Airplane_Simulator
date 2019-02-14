#include "enemy_cannon.h"
// #include "enemy_bullet.h"
#include "main.h"

Enemy_cannon::Enemy_cannon(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
    this->local_axis = glm::mat4(1.0f);

    int n = 100;
    GLfloat g_vertex_buffer_data[1805];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f + 1*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f + 1.0*cos(2*M_PI/n*i);

		g_vertex_buffer_data[k++] = 0.0f + 1.0*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 5.0f;
		g_vertex_buffer_data[k++] = 0.0f + 1.0*cos(2*M_PI/n*i);

		g_vertex_buffer_data[k++] = 0.0f + 1.0*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 5.0f;
		g_vertex_buffer_data[k++] = 0.0f + 1.0*cos(2*M_PI/n*(i+1));

        g_vertex_buffer_data[k++] = 0.0f + 1.0*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 5.0f;
		g_vertex_buffer_data[k++] = 0.0f + 1.0*cos(2*M_PI/n*(i+1));

        g_vertex_buffer_data[k++] = 0.0f + 1.0*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f + 1.0*cos(2*M_PI/n*i);

		g_vertex_buffer_data[k++] = 0.0f + 1.0*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f + 1.0*cos(2*M_PI/n*(i+1));
    }

    this->pipe = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data,COLOR_CANNON);
    
    // enemy_bullet = Enemy_bullet(this->position.x,this->position.y,this->position.z);
}

void Enemy_cannon::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);

    Matrices.model *= (translate*this->local_axis);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
    draw3DObject(this->pipe);
    // enemy_bullet.draw(VP);
}

void Enemy_cannon::set_position(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Enemy_cannon::tick(glm::vec3 position,glm::vec3 direction)
{
    this->position = position;

    // std::cout << position.x << " " << direction.x << '\n';

    direction = direction-this->position;

    float length = glm::length(direction);

    this->local_axis[1][0] = direction.x/length;
    this->local_axis[1][1] = direction.y/length;
    this->local_axis[1][2] = direction.z/length;

    // enemy_bullet.tick(direction);



}