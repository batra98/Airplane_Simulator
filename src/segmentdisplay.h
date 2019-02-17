#include "digit.h"

#ifndef SEGMENTDISPLAY_H
#define SEGMENTDISPLAY_H



class Segmentdisplay
{
public:
    void update(int score);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    
    
    void set_position(float a, float b,float z);

private:
    int score, digslen;
    Digit digs[50];
};

#endif // SCORE_H
