#include "parachute.h"
#include "main.h"

Parachute::Parachute(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);

    // GLfloat g_vertex_buffer_data[] = {
    //     2.0f,2.0f,2.0f, // triangle 1 : begin
    //     2.0f,2.0f,-2.0f, // triangle 1 : begin
    //     -2.0f,2.0f,-2.0f, // triangle 1 : begin

    //     -2.0f,2.0f,-2.0f, // triangle 1 : begin
    //     2.0f,2.0f,-2.0f, // triangle 1 : begin
    //     2.0f,2.0f,2.0f, // triangle 1 : begin

    //     2.0f,2.0f,2.0f, // triangle 1 : begin
    //     2.0f,2.0f,-2.0f, // triangle 1 : begin
    //     0.0f,4.0f,0.0f, // triangle 1 : begin

    //     2.0f,2.0f,2.0f, // triangle 1 : begin
    //     -2.0f,2.0f,2.0f, // triangle 1 : begin
    //     0.0f,4.0f,0.0f, // triangle 1 : begin

    //     -2.0f,2.0f,2.0f, // triangle 1 : begin
    //     -2.0f,2.0f,-2.0f, // triangle 1 : begin
    //     0.0f,4.0f,0.0f, // triangle 1 : begin

    //     2.0f,2.0f,-2.0f, // triangle 1 : begin
    //     -2.0f,2.0f,-2.0f, // triangle 1 : begin
    //     0.0f,4.0f,0.0f, // triangle 1 : begin
    // };

    int n = 6;
    GLfloat g_vertex_buffer_data[60];

    int k = 0;
    for(int i = 0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f + 4.0*sin(2*M_PI/n*i);
        g_vertex_buffer_data[k++] = 0.0f;
        g_vertex_buffer_data[k++] = 0.0f + 4.0*cos(2*M_PI/n*i);

        g_vertex_buffer_data[k++] = 0.0f + 4.0*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f + 4.0*cos(2*M_PI/n*(i+1));

        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 2.0f;
		g_vertex_buffer_data[k++] = 0.0f;
    }

    // GLfloat g_vertex_buffer_data1[] = {
    //     2.0f,2.0f,2.0f,
    //     0.0f,-0.6f,0.0f,
    // };

    GLfloat g_vertex_buffer_data1[100];

    k=0;
    for(int i = 0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = 0.0f + 4.0*sin(2*M_PI/n*i);
        g_vertex_buffer_data1[k++] = 0.0f;
        g_vertex_buffer_data1[k++] = 0.0f + 4.0*cos(2*M_PI/n*i);

        g_vertex_buffer_data1[k++] = 0.0f;
        g_vertex_buffer_data1[k++] = -4.0f;
        g_vertex_buffer_data1[k++] = 0.0f;
    }

    GLfloat g_vertex_buffer_data2[]={
        -0.5f,-4.5f,-0.5f, // triangle 1 : begin
        -0.5f,-4.5f, 0.5f,
        -0.5f, -3.5f, 0.5f, // triangle 1 : end
        0.5f, -3.5f,-0.5f, // triangle 2 : begin
        -0.5f,-4.5f,-0.5f,
        -0.5f, -3.5f,-0.5f, // triangle 2 : end
        0.5f,-4.5f, 0.5f,
        -0.5f,-4.5f,-0.5f,
        0.5f,-4.5f,-0.5f,
        0.5f, -3.5f,-0.5f,
        0.5f,-4.5f,-0.5f,
        -0.5f,-4.5f,-0.5f,
        -0.5f,-4.5f,-0.5f,
        -0.5f, -3.5f, 0.5f,
        -0.5f, -3.5f,-0.5f,
        0.5f,-4.5f, 0.5f,
        -0.5f,-4.5f, 0.5f,
        -0.5f,-4.5f,-0.5f,
        -0.5f, -3.5f, 0.5f,
        -0.5f,-4.5f, 0.5f,
        0.5f,-4.5f, 0.5f,
        0.5f, -3.5f, 0.5f,
        0.5f,-4.5f,-0.5f,
        0.5f, -3.5f,-0.5f,
        0.5f,-4.5f,-0.5f,
        0.5f, -3.5f, 0.5f,
        0.5f,-4.5f, 0.5f,
        0.5f, -3.5f, 0.5f,
        0.5f, -3.5f,-0.5f,
        -0.5f, -3.5f,-0.5f,
        0.5f, -3.5f, 0.5f,
        -0.5f, -3.5f,-0.5f,
        -0.5f, -3.5f, 0.5f,
        0.5f, -3.5f, 0.5f,
        -0.5f, -3.5f, 0.5f,
        0.5f,-4.5f, 0.5f
    };

    this->top = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_PARACHUTE_TOP);
    this->lines = create3DObject(GL_LINES,2*n,g_vertex_buffer_data1,COLOR_GRASS);
    this->gift = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data2,COLOR_PARACHUTE_GIFT);

}

void Parachute::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    Matrices.model *=  glm::translate(position);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->top);
    draw3DObject(this->lines);
    draw3DObject(this->gift);
    

}

void Parachute::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Parachute::tick(){
    this->position = (this->position)+(glm::vec3(0,-5,0))*(glm::vec3(0.01,0.01,0.01));
    
}

bounding_sphere_t Parachute::bounding_sphere()
{
    float x,y,z,radius;

    x = this->position.x;
    y = this->position.y;
    z = this->position.z;

    radius = 4.0f;

    bounding_sphere_t bsphere = {x,y,z,radius};

    return bsphere;
    
}

