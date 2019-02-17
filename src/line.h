#ifndef LINE_H
#define LINE_H

#include "main.h"

class Line
{
public:
    Line() {}
    Line(float fx, float fy, float tx, float ty);
    void draw(glm::mat4 VP);
    float rotation;
    glm::vec3 position;
    
private:
    VAO* object = NULL;
};

#endif // LINE_H
