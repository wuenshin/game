#ifndef draw_lib_h
#define draw_lib_h

#include<array>

struct Fish {
    float x;
    float y;
    float speed;
    bool captured;
};
void backgroundScene();
void ship();
void dron(float x, float y) ;
void drawfish(int maxValue, Fish * fishArray);

#endif /* draw_lib_h */