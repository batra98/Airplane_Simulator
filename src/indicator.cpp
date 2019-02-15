#include "indicator.h"
#include "main.h"

Indicator::Indicator(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
    this->local_axis = glm::mat4(1.0f);

    int n = 100;
    GLfloat g_vertex_buffer_data[908];

    int k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f;
        g_vertex_buffer_data[k++] = 0.0f;
        g_vertex_buffer_data[k++] = -2.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.75*sin(2*M_PI/n*i);
        g_vertex_buffer_data[k++] = 0.0f + 0.75*cos(2*M_PI/n*i);
        g_vertex_buffer_data[k++] = 0.0f;

        g_vertex_buffer_data[k++] = 0.0f + 0.75*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data[k++] = 0.0f + 0.75*cos(2*M_PI/n*(i+1));
        g_vertex_buffer_data[k++] = 0.0f;
    }

    GLfloat g_vertex_buffer_data1[1808];
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f;

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 3.0f;

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 3.0f;

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 3.0f;

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f;

        g_vertex_buffer_data1[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f;

    }

    GLfloat g_vertex_buffer_data2[908];

    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data2[k++] = 0.0f;
        g_vertex_buffer_data2[k++] = 0.0f;
        g_vertex_buffer_data2[k++] = 3.0f;

        g_vertex_buffer_data2[k++] = 0.0f + 0.5*sin(2*M_PI/n*i);
        g_vertex_buffer_data2[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
        g_vertex_buffer_data2[k++] = 3.0f;

        g_vertex_buffer_data2[k++] = 0.0f + 0.5*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data2[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
        g_vertex_buffer_data2[k++] = 3.0f;
    }

    this->cone = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_ARROW);
    this->body = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data1,COLOR_ARROW_BODY);
    this->cover = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data2,COLOR_ARROW_BODY);
}

void Indicator::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(position);
    Matrices.model *=  (translate*this->local_axis);
    // this->local_axis = glm::mat4(1.0f);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->cone);
    draw3DObject(this->body);
    draw3DObject(this->cover);
}

void Indicator::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}
float temp = 0;
void Indicator::tick(glm::vec3 position,glm::vec3 vector_of_alignment,glm::vec3 z_axis){
    float len1 = glm::length(vector_of_alignment);
    // float len2 = glm::length(z_axis);

    // std::cout << "z-axis of plane" << " " <<  z_axis.x << " " << z_axis.y << " " << z_axis.z << "\n"; 
    // std::cout << "ring-plane" << " " << vector_of_alignment.x << " " << vector_of_alignment.y << " " << vector_of_alignment.z << "\n";

    // if(len1 != 0)
    // {
        
    //     float dot_product = vector_of_alignment.x*z_axis.x + vector_of_alignment.y*z_axis.y + vector_of_alignment.z*z_axis.z;
    //     float angle = acos(-dot_product/(len1*len2));
    //     std::cout << "dot_product" << -dot_product << '\n';
    //     std::cout << angle*180.0f/M_PI << '\n';
        
    //     if(angle <10)
    //     {
    //         this->local_axis = glm::mat4(1.0f);
    //         glm::mat4 rotate_y;
    //         if(vector_of_alignment.x - z_axis.x >= 0)
    //         rotate_y = glm::rotate((float)(angle),glm::vec3(this->local_axis[1][0],this->local_axis[1][1],this->local_axis[1][2]));
    //         else if(vector_of_alignment.x - z_axis.x < 0)
    //         {
    //             //std::cout << "hello" << '\n';
    //             //rotate_y = glm::rotate((float)(-temp),glm::vec3(this->local_axis[1][0],this->local_axis[1][1],this->local_axis[1][2]));
    //             //this->local_axis = rotate_y*this->local_axis;
    //             rotate_y = glm::rotate((float)(angle),glm::vec3(this->local_axis[1][0],this->local_axis[1][1],this->local_axis[1][2]));
    //         }
    //     //this->rotation.y -= this->norm_speed;
    //         this->local_axis = rotate_y*this->local_axis;
    //     }
    //     temp = angle;
    // }

    // this->local_axis[2][0] = -vector_of_alignment.x/len1;
    // this->local_axis[2][1] = -vector_of_alignment.y/len1;
    // this->local_axis[2][2] = -vector_of_alignment.z/len1;

    glm::vec3 new_z = glm::normalize(-vector_of_alignment);
    glm::vec3 new_x = glm::normalize(glm::cross(-vector_of_alignment,glm::vec3(1,1,1)));
    glm::vec3 new_y = glm::normalize(glm::cross(new_z,new_x));

    for(int i = 0;i<3;i++)
    {
        this->local_axis[2][i] = new_z[i];
        this->local_axis[1][i] = new_y[i];
        this->local_axis[0][i] = new_x[i];

    }
    

    //glm::vec3 up = vector_of_alignment-glm::vec3()

this->position = position+glm::vec3(0,5,0);
}

glm::vec3 Indicator::cross_product(glm::vec3 a,glm::vec3 b)
{
    glm::vec3 result;
    result = glm::vec3(a.y*b.z-b.y*a.z,a.z*b.x-a.x*b.z,a.x*b.y-b.x*a.y);
    return result;
}