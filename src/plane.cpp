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
    this->compass_axis = glm::mat4(1.0f);

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

    GLfloat g_vertex_buffer_data4[]={
        0.0f,0.1f,-6.0f,
        0.0f,0.3f,-6.0f,

        0.1f,0.0f,-6.0f,
        0.3f,0.0f,-6.0f,

        0.0f,-0.1f,-6.0f,
        0.0f,-0.3f,-6.0f,

        -0.1f,0.0f,-6.0f,
        -0.3f,0.0f,-6.0f,

    };

    this->length_fuel = 4.0f;
    this->depth = -30.0f;
    float xs = 9.0f;
    float ys = 10.0f;
    float zs = 5.0f;


    GLfloat g_vertex_buffer_data5[] = {
        4.0f+xs,0.5f-ys,this->depth,
        4.0f+xs,-0.5f-ys,this->depth,
        -this->length_fuel+xs,0.5f-ys,this->depth,

        -this->length_fuel+xs,-0.5f-ys,this->depth,
        4.0f+xs,-0.5f-ys,this->depth,
        -this->length_fuel+xs,0.5f-ys,this->depth,

        4.5f+xs,1.0f-ys,this->depth-0.01,
        4.5f+xs,-1.0f-ys,this->depth-0.01,
        -4.5f+xs,1.0f-ys,this->depth-0.01,

        -4.5f+xs,-1.0f-ys,this->depth-0.01,
        4.5f+xs,-1.0f-ys,this->depth-0.01,
        -4.5f+xs,1.0f-ys,this->depth-0.01,

    };

    
    GLfloat g_vertex_buffer_data6[3608];
    k = 0;

    xs = 0.0f;
    ys = 10.0f;
    zs = 0.0f;
    for(int i=0;i<n;i++)
    {
       g_vertex_buffer_data6[k++] = 0.0f + 3.5*sin(2*M_PI/n*i)+xs;
		g_vertex_buffer_data6[k++] = 0.0f + 3.5*cos(2*M_PI/n*i)+ys;
		g_vertex_buffer_data6[k++] = this->depth+zs;

		g_vertex_buffer_data6[k++] = 0.0f + 4*sin(2*M_PI/n*i)+xs;
		g_vertex_buffer_data6[k++] = 0.0f + 4*cos(2*M_PI/n*i)+ys;
		g_vertex_buffer_data6[k++] = this->depth+zs;

		g_vertex_buffer_data6[k++] = 0.0f + 4*sin(2*M_PI/n*(i+1))+xs;
		g_vertex_buffer_data6[k++] = 0.0f + 4*cos(2*M_PI/n*(i+1))+ys;
		g_vertex_buffer_data6[k++] = this->depth+zs;

        g_vertex_buffer_data6[k++] = 0.0f + 4*sin(2*M_PI/n*(i+1))+xs;
		g_vertex_buffer_data6[k++] = 0.0f + 4*cos(2*M_PI/n*(i+1))+ys;
		g_vertex_buffer_data6[k++] = this->depth+zs;

        g_vertex_buffer_data6[k++] = 0.0f + 3.5*sin(2*M_PI/n*i)+xs;
		g_vertex_buffer_data6[k++] = 0.0f + 3.5*cos(2*M_PI/n*i)+ys;
		g_vertex_buffer_data6[k++] = this->depth+zs;

		g_vertex_buffer_data6[k++] = 0.0f + 3.5*sin(2*M_PI/n*(i+1))+xs;
		g_vertex_buffer_data6[k++] = 0.0f + 3.5*cos(2*M_PI/n*(i+1))+ys;
		g_vertex_buffer_data6[k++] = this->depth+zs;
    }

    GLfloat g_vertex_buffer_data7[] = {
        0.5f+xs,0.0f+ys,this->depth+zs,
        -0.5f+xs,0.0f+ys,this->depth+zs,
        0.0f+xs,3.5f+ys,this->depth+zs,

        0.1f+xs,3.0f+ys,this->depth+zs,
        -0.1f+xs,3.0f+ys,this->depth+zs,
        0.0f+xs,3.5f+ys,this->depth+zs,
    };


    this->length_altitude = 4.0f;
    this->depth = -30.0f;
    xs = 9.0f;
    ys = 10.0f;
    zs = 5.0f;


    GLfloat g_vertex_buffer_data8[] = {
        4.0f-xs,0.5f-ys,this->depth,
        4.0f-xs,-0.5f-ys,this->depth,
        -this->length_fuel-xs,0.5f-ys,this->depth,

        -this->length_fuel-xs,-0.5f-ys,this->depth,
        4.0f-xs,-0.5f-ys,this->depth,
        -this->length_fuel-xs,0.5f-ys,this->depth,

        4.5f-xs,1.0f-ys,this->depth-0.01,
        4.5f-xs,-1.0f-ys,this->depth-0.01,
        -4.5f-xs,1.0f-ys,this->depth-0.01,

        -4.5f-xs,-1.0f-ys,this->depth-0.01,
        4.5f-xs,-1.0f-ys,this->depth-0.01,
        -4.5f-xs,1.0f-ys,this->depth-0.01,

    };

    this->body = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data,PLANE_BODY);
    this->head = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data+18*n,COLOR_RED);
    this->back_circle = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data+27*n,PLANE_BODY);
    this->tail = create3DObject(GL_TRIANGLES,30,g_vertex_buffer_data1,COLOR_GREEN);
    this->back_fins = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data2,COLOR_GREEN);
    this->propeller = create3DObject(GL_TRIANGLES,12,g_vertex_buffer_data3,COLOR_GREEN);
    this->pointer = create3DObject(GL_LINES,8,g_vertex_buffer_data4,COLOR_GREEN);


    this->fuelbar = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data5,COLOR_ARROW);
    this->fuel_boundary = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data5+18,COLOR_BLACK);

    this->compass_circle = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data6,COLOR_BLACK);
    this->compass_pointer =create3DObject(GL_TRIANGLES,3,g_vertex_buffer_data7,COLOR_RED);
    this->compass_tip = create3DObject(GL_TRIANGLES,3,g_vertex_buffer_data7+9,COLOR_ARROW);

    this->altitude = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data8,COLOR_ARROW);
    this->altitude_boundary = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data8+18,COLOR_BLACK);
    


    indicator = Indicator(x,y+30,z);
    
}
void Plane::draw(glm::mat4 VP,camera_view_t camera_view)
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
    draw3DObject(this->pointer);

    if(camera_view == CAMERA_DRIVER)
    {
        draw3DObject(this->fuelbar);
        draw3DObject(this->fuel_boundary);
        draw3DObject(this->altitude_boundary);
        draw3DObject(this->altitude);
        // draw3DObject(this->compass_circle);
    }
    // draw3DObject(this->compass_pointer);


    glm::mat4 rotate = glm::rotate((float)(this->propeller_angle*M_PI/180.0f),glm::vec3(0,0,1));
    Matrices.model *= (rotate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
    draw3DObject(this->propeller);



    

    if(camera_view != CAMERA_DRIVER)
        indicator.draw(VP);
    else
    {
        Matrices.model = glm::mat4(1.0f);
        // glm::mat4 translate2 = glm::translate(glm::vec3(-10,-10,-10)*this->translate_y);
        // glm::mat4 translate = glm::translate(this->position);
        Matrices.model *= (translate*this->local_rotation);
        glm::mat4 rotate2 = glm::rotate((float)(this->angle),glm::vec3(0,0,1));
        // Matrices.model *= (translate2);
        Matrices.model *= (rotate2);
        MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
        draw3DObject(this->compass_pointer);
        draw3DObject(this->compass_tip);
        // Matrices.model = glm::mat4(1.0f);
        // glm::mat4 translate2 = glm::translate(glm::vec3(0,-10,30)-this->position);
        // glm::mat4 translate3 = glm::translate(glm::vec3(0,+10,-30)+this->position);

        // Matrices.model *= (glm::rotate((float)(0*M_PI/180.0f),glm::vec3(0,0,1))*translate2*translate*this->local_rotation);
        // MVP = VP * Matrices.model;
        // glUniformMatrix4fv(Matrices.MatrixID,1,GL_FALSE,&MVP[0][0]);
    }
    

    
    
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

void Plane::tick(glm::vec3 direction)
{
    this->propeller_angle -= 25;

    indicator.tick(this->position,glm::vec3(0,0,0),glm::vec3(0,0,0));

    // direction = direction-(this->position+glm::vec3(0,10,-30));
    //    direction = direction-(this->position);

        direction = glm::vec3(0,0,1);
    // glm::vec3 new_z = glm::normalize(direction);
    // glm::vec3 new_x = glm::normalize(glm::cross(direction,glm::vec3(1,1,1)));
    // glm::vec3 new_y = glm::normalize(glm::cross(new_z,new_x));

    // for(int i = 0;i<3;i++)
    // {
    //     this->compass_axis[1][i] = new_z[i];
    //     this->compass_axis[2][i] = new_y[i];
    //     this->compass_axis[0][i] = new_x[i];

    // }

    glm::vec3 vec1 = glm::normalize(direction);
    glm::vec3 vec2 = glm::normalize(this->translate_z);

    this->angle = acos(glm::dot(vec1,vec2));
    // std::cout << this->angle << '\n';

    float orientation= glm::dot(glm::normalize(glm::cross(vec1,vec2)),glm::normalize(glm::vec3(0,1,0)));

    glm::vec3 temp = glm::cross(vec1,vec2);
    float  temp_2 = glm::dot(temp, glm::vec3(0,1,0));

    // std::cout << temp.x << " " << temp.y << " " << temp.z << "\n";
    std::cout << temp_2 << "\n";

    this->angle = atan2(temp_2, glm::dot(vec1,vec2));

    // std::cout << orientation << '\n';
    // glm::mat4 rotate_z = glm::rotate((float)(angle),glm::vec3(this->local_rotation[1][0],this->local_rotation[1][1],this->local_rotation[1][2]));
    // this->compass_axis = rotate_z*this->compass_axis;

    



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



