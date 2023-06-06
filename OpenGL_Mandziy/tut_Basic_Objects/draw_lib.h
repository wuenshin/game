#ifndef draw_lib_h
#define draw_lib_h
#include "GL/freeglut.h"
#include<array>

struct Fish {
    float x;
    float y;
    float speed;
    bool captured;
};

bool isRight = true;

void drawfish(int numFish, Fish* fishArray);
void backgroundScene();
void ship();
void dron(float x, float y);
void drawfish(int numFish, Fish* fish);

#endif /* draw_lib_h */