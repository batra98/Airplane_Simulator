#include "main.h"

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class ScoreBoard {
public:
    ScoreBoard() {};
    ScoreBoard(float x,float y,float z);
    glm::vec3 position;
    float rotation;
    int digit;
    void draw(glm::mat4 VP);
    void set_position(float x,float y,float z);
    void update(int digit);

private:
    VAO *object0;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;
    VAO *object9;
    VAO *objectneg;
    VAO *objectm;

};

#endif