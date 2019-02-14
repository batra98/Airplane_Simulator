#include "floor.h"
#include "land_enemies.h"
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

    GLfloat g_vertex_buffer_data1[905];
    k=0;
    int rx = rand()%60;
    int rz = rand()%60;
    int ry = rand()%40+10;

    this->position_volcano = glm::vec3(rx,ry,rz);
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = rx + 3*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = ry;
        g_vertex_buffer_data1[k++] = rz + 3*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = rx + 10*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f;
        g_vertex_buffer_data1[k++] = rz + 10*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = rx + 10*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data1[k++] = 0.0f;
		g_vertex_buffer_data1[k++] = rz + 10*cos(2*M_PI/n*(i+1));


        g_vertex_buffer_data1[k++] = rx + 10*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data1[k++] = 0.0f;
		g_vertex_buffer_data1[k++] = rz + 10*cos(2*M_PI/n*(i+1));


        g_vertex_buffer_data1[k++] = rx + 3*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = ry;
        g_vertex_buffer_data1[k++] = rz + 3*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = rx + 3*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data1[k++] = ry;
		g_vertex_buffer_data1[k++] = rz + 3*cos(2*M_PI/n*(i+1));
    }
    GLfloat g_vertex_buffer_data2[905];
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data2[k++] = rx + 2*sin(2*M_PI/n*i);
        g_vertex_buffer_data2[k++] = ry+5;
        g_vertex_buffer_data2[k++] = rz + 2*cos(2*M_PI/n*i);

        g_vertex_buffer_data2[k++] = rx + 3*sin(2*M_PI/n*i);
        g_vertex_buffer_data2[k++] = ry;
        g_vertex_buffer_data2[k++] = rz + 3*cos(2*M_PI/n*i);

        g_vertex_buffer_data2[k++] = rx + 3*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data2[k++] = ry;
		g_vertex_buffer_data2[k++] = rz + 3*cos(2*M_PI/n*(i+1));


        g_vertex_buffer_data2[k++] = rx + 3*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data2[k++] = ry;
		g_vertex_buffer_data2[k++] = rz + 3*cos(2*M_PI/n*(i+1));


        g_vertex_buffer_data2[k++] = rx + 2*sin(2*M_PI/n*i);
        g_vertex_buffer_data2[k++] = ry+5;
        g_vertex_buffer_data2[k++] = rz + 2*cos(2*M_PI/n*i);

        g_vertex_buffer_data2[k++] = rx + 2*sin(2*M_PI/n*(i+1));
        g_vertex_buffer_data2[k++] = ry+5;
		g_vertex_buffer_data2[k++] = rz + 2*cos(2*M_PI/n*(i+1));
    }

    GLfloat g_vertex_buffer_data3[455];
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data3[k++] = rx;
		g_vertex_buffer_data3[k++] = 0.1f;
		g_vertex_buffer_data3[k++] = rz;

        g_vertex_buffer_data3[k++] = rx + 12*sin(2*M_PI/n*i);
		g_vertex_buffer_data3[k++] = 0.1f;
		g_vertex_buffer_data3[k++] = rz + 12*cos(2*M_PI/n*i);

		g_vertex_buffer_data3[k++] = rx + 12*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data3[k++] = 0.1f;
		g_vertex_buffer_data3[k++] = rz + 12*cos(2*M_PI/n*(i+1));
    }


    this->object = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_CLOUDS);
    this->volcano = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data1,COLOR_VOLCANO);
    this->flames = create3DObject(GL_TRIANGLES,6*n,g_vertex_buffer_data2,COLOR_LAVA);
    this->base = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data3,COLOR_GRASS);

    land_enemies = Land_enemies(x+rand()%60,y+5,z+rand()%30);
}

void Floor::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->volcano);
    draw3DObject(this->flames);
    draw3DObject(this->base);

    land_enemies.draw(VP);
}

void Floor::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Floor::tick(glm::vec3 direction){
    this->position+= this->acc*glm::vec3(0.08,0.08,0.08);
    land_enemies.tick(this->position,direction);
    
    
}

bounding_sphere_t Floor::bounding_sphere(){
    float x,y,z,radius;
    
    x = this->position.x+this->position_volcano.x;
    y = this->position.y;
    z = this->position.z+this->position_volcano.z;

    radius = this->position_volcano.y/4;

    bounding_sphere_t bsphere = {x,y,z,radius};
    return bsphere;

}

bounding_sphere_t Floor::bounding_sphere2(){
    float x,y,z,radius;
    
    x = this->position.x+this->position_volcano.x;
    y = this->position.y+this->position_volcano.y*3/4;
    z = this->position.z+this->position_volcano.z;

    radius = this->position_volcano.y/8;

    bounding_sphere_t bsphere = {x,y,z,radius};
    return bsphere;

}