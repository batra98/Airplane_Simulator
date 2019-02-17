#include "main.h"
#include "line.h"

#ifndef DIGIT_H
#define DIGIT_H




class Digit
{
public:
    Digit() {}
    
    void draw(glm::mat4 VP);
    Digit(char c, float x, float y);   
    glm::vec3 position;
    
    
private:
    Line lines[7];
};

#endif // DIGIT_H
