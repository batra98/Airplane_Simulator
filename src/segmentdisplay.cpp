#include "segmentdisplay.h"
#include "main.h"
#include <cstring>

void Segmentdisplay::set_position(float x, float y,float z){
    this->position = glm::vec3(x, y, z);
}
void Segmentdisplay::draw(glm::mat4 VP) 
{
    int i = 0;
    
    while(i<digslen)
    {
        digs[i].draw(VP);
        i++;
    }
}


void Segmentdisplay::update(int score) {
    
    char scorestr[50];
    sprintf(scorestr, "%d", score);
    this->score = score;
    digslen = strlen(scorestr);
    int i = digslen - 1;
    while(i >= 0)
    {
        digs[i] = Digit(scorestr[i], 4 - 0.3*(digslen - i) + position.x, position.y);
        i--;
    }
}