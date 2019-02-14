#include "plane.h"
#include "main.h"
#include "indicator.h"

Plane::Plane(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
    this->velocity = glm::vec3(0,0,0);
    this->acceleration = glm::vec3(0,0,0);
    this->rotation = glm::vec3(0,0,0);
    this->norm_speed = 0.5;
    this->angle_rotate = 0.5;
    this->propeller_angle = 0;
    this->local_rotation = glm::mat4(1.0f);

    int n = 100;
    GLfloat g_vertex_buffer_data[3605];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -3.5f;

		g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 1.5f;

		g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 1.5f;

        g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 1.5f;

        g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -3.5f;

		g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -3.5f;
    }

    //k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = -4.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -3.5f;

		g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.25*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -3.5f;
    }

    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 1.5f;

        g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 1.5f;

		g_vertex_buffer_data[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 1.5f;
    }

    GLfloat g_vertex_buffer_data1[]=
    {
        0.0f,0.0f,1.5f,
        0.0f,0.0f,-0.5f,
        0.0f,1.0f,2.5f,
                            //up
        0.0f,0.0f,-0.5f,
        0.0f,1.0f,2.5f,
        0.0f,1.0f,0.5f,

        0.0f,0.0f,1.5f,
        0.0f,0.0f,-0.5f,
        1.0f,-0.15f,2.5f,
                        //right
        0.0f,0.0f,-0.5f,
        1.0f,-0.15f,2.5f,
        1.0f,-0.15f,0.5f,

        0.0f,0.0f,1.5f,
        0.0f,0.0f,-0.5f,
        -1.0f,-0.15f,2.5f,
                            //left
        0.0f,0.0f,-0.5f,
        -1.0f,-0.15f,2.5f,
        -1.0f,-0.15f,0.5f,

        0.0f,0.0f,-1.5f,
        3.0f,-0.15f,-1.0f,
        0.0f,0.0f,-2.5f,
                            //right wing
        3.0f,-0.15f,-1.0f,
        0.0f,0.0f,-2.5f,
        2.5f,-0.15f,-2.0f,

        0.0f,0.0f,-1.5f,
        -3.0f,-0.15f,-1.0f,
        0.0f,0.0f,-2.5f,
                            //right wing
        -3.0f,-0.15f,-1.0f,
        0.0f,0.0f,-2.5f,
        -2.5f,-0.15f,-2.0f,
    };

    GLfloat g_vertex_buffer_data2[]=
    {
        1.0f,1.0f,2.5f,
        1.0f,1.0f,0.5f,
        -1.0f,1.0f,2.5f,

        1.0f,1.0f,0.5f,
        -1.0f,1.0f,2.5f,
        -1.0f,1.0f,0.5f,

    };

    GLfloat g_vertex_buffer_data3[] = {
        0.0f,0.0f,-4.0f,
        2.0f,-0.3f,-4.0f,
        2.0f,0.3f,-4.0f,

        -0.3f,2.0f,-4.0f,
        0.3f,2.0f,-4.0f,
        0.0f,0.0f,-4.0f,

        -2.0f,0.3f,-4.0f,
        -2.0f,-0.3f,-4.0f,
        0.0f,0.0f,-4.0f,

        -0.3f,-2.0f,-4.0f,
        0.3f,-2.0f,-4.0f,
        0.0f,0.0f,-4.0f,
    };

    this->body = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data,PLANE_BODY);
    this->head = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data+18*n,COLOR_RED);
    this->back_circle = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data+27*n,PLANE_BODY);
    this->tail = create3DObject(GL_TRIANGLES,30,g_vertex_buffer_data1,COLOR_GREEN);
    this->back_fins = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data2,COLOR_GREEN);
    this->propeller = create3DObject(GL_TRIANGLES,12,g_vertex_buffer_data3,COLOR_GREEN);

    indicator = Indicator(x,y+30,z);
}
void Plane::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);
    // glm::mat4 translate_origin = glm::translate(glm::vec3(0,0,3.5f));
    // glm::mat4 rotate_x = glm::rotate((float)(this->rotation.x*M_PI/180.0f),glm::vec3(1,0,0));
    // glm::mat4 rotate_y = glm::rotate((float)(this->rotation.y*M_PI/180.0f),glm::vec3(0,1,0));
    // glm::mat4 rotate_z = glm::rotate((float)(this->rotation.z*M_PI/180.0f),glm::vec3(0,0,1));
    Matrices.model *= (translate*this->local_rotation);
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

    indicator.draw(VP);
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

    indicator.tick(this->position,glm::vec3(0,0,0),glm::vec3(0,0,0));

    // this->length_y = glm::length(glm::vec3(this->local_rotation[2][0],this->local_rotation[2][1],this->local_rotation[2][2]));
    // this->translate_y = glm::vec3(this->local_rotation[2][0]*this->norm_speed/this->length_z,this->local_rotation[2][1]*this->norm_speed/this->length_z,this->local_rotation[2][2]*this->norm_speed/this->length_z);
    
}

void Plane::right()
{
    glm::mat4 rotate_y = glm::rotate((float)(-this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[1][0],this->local_rotation[1][1],this->local_rotation[1][2]));
    //this->rotation.y -= this->norm_speed;
    this->local_rotation = rotate_y*this->local_rotation;

}

void Plane::left()
{
    glm::mat4 rotate_y = glm::rotate((float)(this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[1][0],this->local_rotation[1][1],this->local_rotation[1][2]));
    //this->rotation.y += this->norm_speed;
    this->local_rotation = rotate_y*this->local_rotation;
}

void Plane::forward()
{
    // if(this->rotation.x > -20)
    // this->rotation.x -= 0.3;
    // this->acceleration = glm::vec3((this->norm_speed/20)*sin(this->rotation.y*M_PI/180.0),0,(this->norm_speed/20)*cos(this->rotation.y*M_PI/180.0));
    // this->velocity = glm::vec3(-(this->norm_speed/4)*sin(this->rotation.y*M_PI/180.0),(this->norm_speed/8)*sin(this->rotation.x*M_PI/180.0),-(this->norm_speed/4)*cos(this->rotation.y*M_PI/180.0));
    //glm::mat4 rotate_x = glm::rotate((float)(-this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[0][0],this->local_rotation[0][1],this->local_rotation[0][2]));
    this->length_z = glm::length(glm::vec3(this->local_rotation[2][0],this->local_rotation[2][1],this->local_rotation[2][2]));
    this->translate_z = glm::vec3(this->local_rotation[2][0]*this->norm_speed/this->length_z,this->local_rotation[2][1]*this->norm_speed/this->length_z,this->local_rotation[2][2]*this->norm_speed/this->length_z);
    this->position -= this->translate_z;
    //std::cout << translate_z.length() << '\n'; 
    //this->local_rotation = rotate_x*this->local_rotation;
}

void Plane::nose_down()
{
    glm::mat4 rotate_x = glm::rotate((float)(-this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[0][0],this->local_rotation[0][1],this->local_rotation[0][2]));
    this->local_rotation = rotate_x*this->local_rotation;
}

void Plane::nose_up()
{
    glm::mat4 rotate_x = glm::rotate((float)(this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[0][0],this->local_rotation[0][1],this->local_rotation[0][2]));
    this->local_rotation = rotate_x*this->local_rotation;
}

void Plane::backward()
{
    // if(this->rotation.x < 20)
    // this->rotation.x += 0.3;
    // this->acceleration = glm::vec3((this->norm_speed/20)*sin(this->rotation.y*M_PI/180.0),0,(this->norm_speed/20)*cos(this->rotation.y*M_PI/180.0));
    // this->velocity = glm::vec3(-(this->norm_speed/4)*sin(this->rotation.y*M_PI/180.0),(this->norm_speed/8)*sin(this->rotation.x*M_PI/180.0),-(this->norm_speed/4)*cos(this->rotation.y*M_PI/180.0));
    // glm::mat4 rotate_x = glm::rotate((float)(this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[0][0],this->local_rotation[0][1],this->local_rotation[0][2]));
    this->length_z = glm::length(glm::vec3(this->local_rotation[2][0],this->local_rotation[2][1],this->local_rotation[2][2]));
    this->translate_z = glm::vec3(this->local_rotation[2][0]*this->norm_speed/this->length_z,this->local_rotation[2][1]*this->norm_speed/this->length_z,this->local_rotation[2][2]*this->norm_speed/this->length_z);
    this->position += this->translate_z;
    // this->local_rotation = rotate_x*this->local_rotation;
}

void Plane::right_tilt()
{
    glm::mat4 rotate_z = glm::rotate((float)(this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[2][0],this->local_rotation[2][1],this->local_rotation[2][2]));
    this->local_rotation = rotate_z*this->local_rotation;
}

void Plane::left_tilt()
{
    glm::mat4 rotate_z = glm::rotate((float)(-this->angle_rotate*M_PI/180.0f),glm::vec3(this->local_rotation[2][0],this->local_rotation[2][1],this->local_rotation[2][2]));
    this->local_rotation = rotate_z*this->local_rotation;
}

bounding_sphere_t Plane::bounding_sphere(){
    float x,y,z,radius;

    x = this->position.x;
    y = this->position.y;
    z = this->position.z;

    radius = 4;

    bounding_sphere_t bsphere = {x,y,z,radius};
    return bsphere;

}



