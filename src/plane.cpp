#include "plane.h"
#include "main.h"

Plane::Plane(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
    this->velocity = glm::vec3(0,0,0);
    this->acceleration = glm::vec3(0,0,0);
    this->rotation = glm::vec3(0,0,0);
    this->norm_speed = 1.5;
    this->propeller_angle = 0;

    int n = 100;
    GLfloat g_vertex_buffer_data[3805];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -7.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -2.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -2.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -2.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -7.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -7.0f;
    }

    //k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = -7.5f;

        g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -7.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -7.0f;
    }

    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = -2.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -2.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -2.0f;
    }

    GLfloat g_vertex_buffer_data1[]=
    {
        0.0f,0.0f,-2.0f,
        0.0f,0.0f,-4.0f,
        0.0f,1.0f,-1.0f,
                            //up
        0.0f,0.0f,-4.0f,
        0.0f,1.0f,-1.0f,
        0.0f,1.0f,-3.0f,

        0.0f,0.0f,-2.0f,
        0.0f,0.0f,-4.0f,
        1.0f,-0.15f,-1.0f,
                        //right
        0.0f,0.0f,-4.0f,
        1.0f,-0.15f,-1.0f,
        1.0f,-0.15f,-3.0f,

        0.0f,0.0f,-2.0f,
        0.0f,0.0f,-4.0f,
        -1.0f,-0.15f,-1.0f,
                            //left
        0.0f,0.0f,-4.0f,
        -1.0f,-0.15f,-1.0f,
        -1.0f,-0.15f,-3.0f,

        0.0f,0.0f,-5.0f,
        3.0f,-0.15f,-4.5f,
        0.0f,0.0f,-6.0f,
                            //right wing
        3.0f,-0.15f,-4.5f,
        0.0f,0.0f,-6.0f,
        2.5f,-0.15f,-5.5f,

        0.0f,0.0f,-5.0f,
        -3.0f,-0.15f,-4.5f,
        0.0f,0.0f,-6.0f,
                            //right wing
        -3.0f,-0.15f,-4.5f,
        0.0f,0.0f,-6.0f,
        -2.5f,-0.15f,-5.5f,
    };

    GLfloat g_vertex_buffer_data2[]=
    {
        1.0f,1.0f,-1.0f,
        1.0f,1.0f,-3.0f,
        -1.0f,1.0f,-1.0f,

        1.0f,1.0f,-3.0f,
        -1.0f,1.0f,-1.0f,
        -1.0f,1.0f,-3.0f,

    };

    GLfloat g_vertex_buffer_data3[] = {
        0.0f,0.0f,-7.5f,
        2.0f,-0.3f,-7.5f,
        2.0f,0.3f,-7.5f,

        -0.3f,2.0f,-7.5f,
        0.3f,2.0f,-7.5f,
        0.0f,0.0f,-7.5f,

        -2.0f,0.3f,-7.5f,
        -2.0f,-0.3f,-7.5f,
        0.0f,0.0f,-7.5f,

        -0.3f,-2.0f,-7.5f,
        0.3f,-2.0f,-7.5f,
        0.0f,0.0f,-7.5f,
    };

    this->body = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data,PLANE_BODY);
    this->head = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data+18*n,COLOR_RED);
    this->back_circle = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data+27*n,PLANE_BODY);
    this->tail = create3DObject(GL_TRIANGLES,30,g_vertex_buffer_data1,COLOR_GREEN);
    this->back_fins = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data2,COLOR_GREEN);
    this->propeller = create3DObject(GL_TRIANGLES,12,g_vertex_buffer_data3,COLOR_GREEN);
}
void Plane::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);
    glm::mat4 rotate_x = glm::rotate((float)(this->rotation.x*M_PI/180.0f),glm::vec3(1,0,0));
    glm::mat4 rotate_y = glm::rotate((float)(this->rotation.y*M_PI/180.0f),glm::vec3(0,1,0));
    glm::mat4 rotate_z = glm::rotate((float)(this->rotation.z*M_PI/180.0f),glm::vec3(0,0,1));
    Matrices.model *= (translate*rotate_x*rotate_y*rotate_z);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
    draw3DObject(this->body);
    draw3DObject(this->head);
    draw3DObject(this->tail);
    draw3DObject(this->back_circle);
    draw3DObject(this->back_fins);

    glm::mat4 rotate = glm::rotate((float)(this->propeller_angle*M_PI/180.0f),glm::vec3(0,0,1));
    Matrices.model *= (rotate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
    draw3DObject(this->propeller);
    //draw3DObject(this->propeller);
}
void Plane::draw2(glm::mat4 VP)
{
//     Matrices.model = glm::mat4(1.0f);
//     glm::mat4 translate = glm::translate(this->position);
//     glm::mat4 rotate = glm::rotate((float)(this->propeller_angle*M_PI/180.0f),glm::vec3(0,0,1));
//     Matrices.model *= (translate*rotate);
//     glm::mat4 MVP = VP * Matrices.model;
//     glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
//     draw3DObject(this->propeller);
}

void Plane::set_position(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Plane::set_speed(float a)
{
    this->norm_speed = a;
}

void Plane::tick()
{
    this->propeller_angle -= 25;

    if(this->velocity.z * this->acceleration.z < 0)
        this->velocity += this->acceleration;
    else
        this->velocity = glm::vec3(0,0,0);
    
    this->position += this->velocity;
}

void Plane::right()
{
    this->rotation.y -= this->norm_speed;
}

void Plane::left()
{
    this->rotation.y += this->norm_speed;
}

void Plane::forward()
{
    if(this->rotation.x > -20)
    this->rotation.x -= 0.3;
    // this->acceleration = glm::vec3((this->norm_speed/20)*sin(this->rotation.y*M_PI/180.0),0,(this->norm_speed/20)*cos(this->rotation.y*M_PI/180.0));
    // this->velocity = glm::vec3(-(this->norm_speed/4)*sin(this->rotation.y*M_PI/180.0),(this->norm_speed/8)*sin(this->rotation.x*M_PI/180.0),-(this->norm_speed/4)*cos(this->rotation.y*M_PI/180.0));
}

void Plane::backward()
{
    if(this->rotation.x < 20)
    this->rotation.x += 0.3;
    // this->acceleration = glm::vec3((this->norm_speed/20)*sin(this->rotation.y*M_PI/180.0),0,(this->norm_speed/20)*cos(this->rotation.y*M_PI/180.0));
    // this->velocity = glm::vec3(-(this->norm_speed/4)*sin(this->rotation.y*M_PI/180.0),(this->norm_speed/8)*sin(this->rotation.x*M_PI/180.0),-(this->norm_speed/4)*cos(this->rotation.y*M_PI/180.0));

}

void Plane::right_tilt()
{
    this->rotation.z -= this->norm_speed;
}

void Plane::left_tilt()
{
    this->rotation.z += this->norm_speed;
}



