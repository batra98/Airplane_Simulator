#include "digit.h"
#include "main.h"

void Digit::draw(glm::mat4 VP)
{
    for (int i = 0; i < 7; i++)
        lines[i].draw(VP);
}

Digit::Digit(char c, float x, float y)
{
    this->position = glm::vec3(x, y, 0);
    const GLfloat vbl[][6] = {
        {0, 0.4, 0, 0.2, 0.4, 0},
        {0.2, 0.4, 0, 0.2, 0.2, 0},
        {0.2, 0.2, 0, 0.2, 0, 0},
        {0.2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0.2, 0},
        {0, 0.4, 0, 0, 0.2, 0},
        {0, 0.2, 0, 0.2, 0.2, 0},
    };
    bool l[8];
    for (int i = 0; i < 8; i++)
        l[i] = false;
    
    if(c == '0')
    {
        l[1] = l[2] = l[3] = l[4] = true;
        l[5] = l[6] = true;
    }
    else if (c == '1')
    {
        l[2] = true;
        l[3] = true;
    }
    else if(c == '2')
    {
        l[1] = l[2] = l[7] = true;
        l[5] = l[4] = true;
    }
    else if(c == '3')
    {
        l[1] = l[2] = l[7] = true;
        l[3] = l[4] = true;
    }
    else if(c == '4')
    {
        l[6] = l[7] = l[2] = true;
        l[3] = true;
    }
    else if(c == '5')
    {
        l[1] = l[6] = l[7] = true;
        l[3] = l[4] = true;
    }
    else if(c == '6')
    {
        l[1] = l[6] = l[7] = true;
        l[3] = l[4] = l[5] = true;
    }
    else if(c == '7')
    {
        l[1] = l[2] = l[3] = true;
    }
    else if(c == '8')
    {
        l[1] = l[2] = l[7] = true;
        l[5] = l[4] = l[3] = l[6] = true;
    }
    else if(c == '9')
    {
        l[1] = l[2] = l[7] = true;
        l[4] = l[3] = l[6] = true;
    }
    
    
    
        
    
    for (int i = 0; i < 7; i++) {
        if (l[i+1] == false)
            continue;
        lines[i] = Line(x+vbl[i][0], y+vbl[i][1], x+vbl[i][3], y+vbl[i][4]);
    }
}


