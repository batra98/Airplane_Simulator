#include "line.h"
#include "main.h"


void Line::draw(glm::mat4 VP) {
    if (!this->object) return;
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 rotate = glm::rotate(this->rotation, glm::vec3(0,0,1));
    glm::mat4 translate = glm::translate (this->position);        // glTranslatef
    Matrices.model *= translate * rotate;
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

Line::Line(float fx, float fy, float tx, float ty)
{

    if(tx == fx)
    {
        if(ty > fy )
        this->rotation = M_PI/2;
        else
        {
            this->rotation = -M_PI/2;
        }
        
    }
    else if(ty == fy)
    {
         if(tx > fx)
         {
             this->rotation = 0;
         }
         else
         {
             this->rotation = M_PI;
         }
         
    }
    else
    {
        this->rotation = atan((ty-fy)/(tx-fx));
    }
    
    
    
    static const GLfloat vertex_buffer_data [] = 
    {
        0, 0, 0,
        0.2, 0, 0
    };

    this->position = glm::vec3(fx, fy, 0);
    
    this->object = create3DObject(GL_LINES, 2, vertex_buffer_data, COLOR_ARROW, GL_FILL);
}



