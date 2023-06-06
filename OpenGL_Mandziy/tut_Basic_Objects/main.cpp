#include "GL/freeglut.h"
#include <time.h>
#include <iostream>
#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sstream>
//#include "draw_lib.h"

struct Fish {
    float x;
    float y;
    float speed;
    bool captured;
};

// Функция для генерации случайного числа в заданном диапазоне
float random(float min, float max) {
    return min +(float)(rand()) / ((float)(RAND_MAX / (max - min)));
}


struct Position
{
    GLfloat x, y, z;
};
std::string timeString = "";
Position dronPos;
float pos_x = 0.5, pos_y = 0.3;
const int numFish = 25;
Fish fishArray[numFish];
float areaXMin = -0.9f;
float areaXMax = 0.9f;
float areaYMin = -0.9f;
float areaYMax = 0.2f;
float droneSize = 0.1f;
int score = 0;
int timeRemaining = 60;
int timerDelay = 1000;
int prevTime = 0; // Предыдущее время в миллисекундах
int currentTime = 0; // Текущее время в миллисекундах


bool isRight = true;

void drawfish(int numFish, Fish* fishArray);
void backgroundScene();
void ship();
void dron(float x, float y);
void drawfish(int numFish, Fish* fish);


// блок объявлений функций
void renderScene(void);
void reshape(int width, int height);
void backgroundScene();
void ship();
void dron(float x, float y);
void ProcessKeys(unsigned char key, int x, int y);
void update(int value);
void timewatch();
void updateFish(int numFish, Fish* fishArray);
void initializeFish();
void updateScreen(int value);


std::vector<int> fishesToRemove;


int main(int argc, char* argv[])
{
    initializeFish();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Fish and Dron");
    glutTimerFunc(timerDelay, update, 0);
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(ProcessKeys);
    glutTimerFunc(0, updateScreen, 0);  // Запуск функции обновления экрана

    glutMainLoop();
    return 0;
}





void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    backgroundScene();


    ship();
    dron(pos_x, pos_y);
    updateFish(numFish, fishArray);
    drawfish(numFish, fishArray);


    // Настройки для отображения текста
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Позиция и цвет текста
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(10.0f, 10.0f);

    // Отображение оставшегося времени
    std::stringstream ss;
    ss << "Time: " << timeRemaining << " seconds";
    std::string timeString = ss.str();
    for (int i = 0; i < timeString.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, timeString[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();
}



void initializeFish() {
    srand(time(0)); 

    for (int i = 0; i < numFish; ++i) {
        fishArray[i].x = random(areaXMin, areaXMax);
        fishArray[i].y = random(areaYMin, areaYMax);
        fishArray[i].speed = random(0.01f, 0.03f);
        fishArray[i].captured = false;
    }
}

void updateScreen(int value)
{
    glutPostRedisplay();
    glutTimerFunc(100, updateScreen, 0);  // Обновление каждые 0.1 секунды
}

void updateFish(int numFish, Fish * fishArray) {
    fishesToRemove.clear();

    for (int i = 0; i < numFish; ++i) {
        if (!fishArray[i].captured) {
            fishArray[i].x += fishArray[i].speed;

            if (fishArray[i].x > areaXMax) {
                fishArray[i].speed *= -1.0f;
                fishArray[i].x = areaXMax;
            }
            else if (fishArray[i].x < areaXMin) {
                fishArray[i].speed *= -1.0f;
                fishArray[i].x = areaXMin;
            }

            float distance = std::sqrt(std::pow(fishArray[i].x - pos_x, 2) + std::pow(fishArray[i].y - pos_y, 2));
            if (distance < droneSize) {
                fishArray[i].captured = true;
                score--;
            }
        }
    }

    for (int i = numFish - 1; i >= 0; --i) {
        if (fishArray[i].captured) {
            fishArray[i].x = areaXMin - 1.0f;
            fishArray[i].y = areaYMin - 1.0f;
        }
    }
}
void generateNewFish(int numFish, Fish * fishArray) {
    for (int i = 0; i < numFish; ++i) {
        if (fishArray[i].captured) {
            fishArray[i].x = random(areaXMin, areaXMax);
            fishArray[i].y = random(areaYMin, areaYMax);
            fishArray[i].speed = random(0.01f, 0.05f);
            fishArray[i].captured = false;
        }
    }
}

void update(int value) {
    updateFish( numFish ,  fishArray);
    std::stringstream ss;
    ss << "Time: " << timeRemaining;
    timeString = ss.str();

    if (timeRemaining <= 0) {
        std::cout << "game end ; score: " << score << std::endl;
        return;
    }

    if (value % 10 == 0) {
        generateNewFish(numFish ,   fishArray);
    }

    timeRemaining += score;
    glutTimerFunc(timerDelay, update, value + 1);
}

void timewatch()
{
    // Настройки для отображения текста
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Позиция и цвет текста
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(10.0f, 10.0f);

    // Отображение оставшегося времени
    for (int i = 0; i < timeString.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, timeString[i]);
    }

}



void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}



void ProcessKeys(unsigned char key, int x, int y)
{
    if (key == 'w') {

        if (pos_y < 0.2)
        {
            pos_y += 0.01;
        }
        glutPostRedisplay();
        isRight = false;
    }
    if (key == 's') {


        if (pos_y > -0.8)
        {
            pos_y -= 0.01;
        }
        glutPostRedisplay();
        isRight = false;
    }
    if (key == 'd')
    {

        if (pos_x < 0.8)
        {
            pos_x += 0.01;
        }


        glutPostRedisplay();
        isRight = true;
    }



    if (key == 'a')
    {
        if (pos_x > -0.8)
        {
            pos_x -= 0.01;
        }
        glutPostRedisplay();

        isRight = false;

    }
}

void drawfish(int numFish, Fish* fishArray) {
    for (int i = 0; i < numFish; ++i)
        if (!fishArray[i].captured && fishArray[i].x < numFish) {
            glPushMatrix();
            glTranslatef(fishArray[i].x, fishArray[i].y, 0.0f);
            glScalef(0.06, 0.06, 0);
            glBegin(GL_TRIANGLES);
            glColor3ub(140, 70, 50);
            glVertex2f(-0.4, 0.2);
            glVertex2f(0, 0.2);
            glVertex2f(0, 0);

            glVertex2f(-0.4, 0.2);
            glVertex2f(0, 0);
            glVertex2f(-0.4, -0.2);

            glVertex2f(0, 0);
            glVertex2f(-0.4, -0.2);
            glVertex2f(0, -0.2);

            glVertex2f(0, 0.2);
            glVertex2f(0, -0.2);
            glVertex2f(0.3, 0);

            glVertex2f(0.25, 0);
            glVertex2f(0.45, 0.2);
            glVertex2f(0.45, -0.2);

            glColor3ub(150, 0, 0);
            glVertex2f(-0.1, 0.33);
            glVertex2f(-0.1, 0.2);
            glVertex2f(-0.3, 0.2);

            glVertex2f(-0.4, 0.2);
            glVertex2f(-0.4, -0.2);
            glVertex2f(-0.55, 0);

            glColor3ub(255, 255, 255);
            glVertex2f(-0.45, 0.);
            glVertex2f(-0.43, 0.07);
            glVertex2f(-0.48, 0.07);


            glEnd();
            glPopMatrix();
        }
}

void ship() {
    glPushMatrix();
    glTranslatef(0.6, 0.4, 0);
    glScalef(0.4, 0.4, 0);
    glBegin(GL_TRIANGLES);
    glColor3ub(155, 45, 48);
    glVertex2f(-0.7, 0.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.7, -0.3);

    glVertex2f(-0.7, -0.3);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.2, 0.2);

    glVertex2f(0.1, 0.1);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, 0.1);

    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);

    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.5, 0.1);

    glVertex2f(0.5, 0.1);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.2, 0.3);

    glVertex2f(0.3, 0.8);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.4, 0.3);

    glVertex2f(0.3, 0.8);
    glVertex2f(0.4, 0.8);
    glVertex2f(0.4, 0.3);

    glVertex2f(0.6, 0.1);
    glVertex2f(0.7, 0.2);
    glVertex2f(0.85, 0.1);

    glVertex2f(0.85, 0.1);
    glVertex2f(0.9, 0.2);
    glVertex2f(0.7, 0.2);

    glVertex2f(0.5, -0.5);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.85, 0.1);
    glEnd();

    glPopMatrix();

}

void dron(float x, float y) {

    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(0.2, 0.2, 0);
    if (isRight)
        glRotatef(180, 0, 1, 0);
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);
    glVertex2f(-0.7, 0);
    glVertex2f(-0.7, 0.02);
    glVertex2f(-0.7, 0.04);
    glVertex2f(-0.7, 0.06);
    glVertex2f(-0.7, 0.08);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.6, 0.14);
    glVertex2f(-0.6, 0.18);
    glVertex2f(-0.6, 0.22);
    glVertex2f(-0.5, 0.25);
    glVertex2f(-0.5, 0.28);
    glVertex2f(-0.5, 0.31);
    glVertex2f(-0.4, 0.33);
    glVertex2f(-0.4, 0.35);
    glVertex2f(-0.3, 0.36);
    glVertex2f(-0.3, 0.37);
    glVertex2f(-0.2, 0.38);
    glVertex2f(-0.1, 0.39);
    glVertex2f(-0.08, 0.4);
    glVertex2f(-0.06, 0.4);
    glVertex2f(-0.04, 0.4);
    glVertex2f(-0.02, 0.4);
    glColor3ub(4, 67, 244);
    glVertex2f(0, 0.4);
    glVertex2f(0.7, 0);
    glVertex2f(0.7, 0.02);
    glVertex2f(0.7, 0.04);
    glVertex2f(0.7, 0.06);
    glVertex2f(0.7, 0.08);
    glVertex2f(0.6, 0.1);
    glVertex2f(0.6, 0.14);
    glVertex2f(0.6, 0.18);
    glVertex2f(0.6, 0.22);
    glVertex2f(0.5, 0.25);
    glVertex2f(0.5, 0.28);
    glVertex2f(0.5, 0.31);
    glVertex2f(0.4, 0.33);
    glVertex2f(0.4, 0.35);
    glVertex2f(0.3, 0.36);
    glVertex2f(0.3, 0.37);
    glVertex2f(0.2, 0.38);
    glVertex2f(0.1, 0.39);
    glVertex2f(0.08, 0.394);
    glVertex2f(0.06, 0.396);
    glVertex2f(0.04, 0.398);
    glVertex2f(0.02, 0.4);
    glColor3ub(180, 180, 180);
    glVertex2f(-0.7, 0);
    glVertex2f(-0.7, -0.02);
    glVertex2f(-0.7, -0.04);
    glVertex2f(-0.7, -0.06);
    glVertex2f(-0.7, -0.08);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.6, -0.14);
    glVertex2f(-0.6, -0.18);
    glVertex2f(-0.6, -0.22);
    glVertex2f(-0.5, -0.25);
    glVertex2f(-0.5, -0.28);
    glVertex2f(-0.5, -0.31);
    glVertex2f(-0.4, -0.33);
    glVertex2f(-0.4, -0.35);
    glVertex2f(-0.3, -0.36);
    glVertex2f(-0.3, -0.37);
    glVertex2f(-0.2, -0.38);
    glVertex2f(-0.1, -0.39);
    glVertex2f(-0.08, -0.4);
    glVertex2f(-0.06, -0.4);
    glVertex2f(-0.04, -0.4);
    glVertex2f(-0.02, -0.4);
    glColor3ub(4, 67, 244);
    glVertex2f(0, -0.4);
    glVertex2f(0.7, -0);
    glVertex2f(0.7, -0.02);
    glVertex2f(0.7, -0.04);
    glVertex2f(0.7, -0.06);
    glVertex2f(0.7, -0.08);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.6, -0.14);
    glVertex2f(0.6, -0.18);
    glVertex2f(0.6, -0.22);
    glVertex2f(0.5, -0.25);
    glVertex2f(0.5, -0.28);
    glVertex2f(0.5, -0.31);
    glVertex2f(0.4, -0.33);
    glVertex2f(0.4, -0.35);
    glVertex2f(0.3, -0.36);
    glVertex2f(0.3, -0.37);
    glVertex2f(0.2, -0.38);
    glVertex2f(0.1, -0.39);
    glVertex2f(0.08, -0.394);
    glVertex2f(0.06, -0.396);
    glVertex2f(0.04, -0.398);
    glVertex2f(0.02, -0.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(164, 232, 237);
    glVertex2f(-0.2, 0.48);
    glVertex2f(-0.1, 0.49);
    glVertex2f(-0.08, 0.5);
    glVertex2f(-0.06, 0.5);
    glVertex2f(-0.04, 0.5);
    glVertex2f(-0.02, 0.5);
    glVertex2f(0, 0.5);
    glVertex2f(0.02, 0.5);
    glVertex2f(0.04, 0.5);
    glVertex2f(0.06, 0.5);
    glVertex2f(0.08, 0.5);
    glVertex2f(0.1, 0.49);
    glVertex2f(0.2, 0.48);
    glColor3f(0, 0.4, 0.9);
    glVertex2f(0.23, 0.35);
    glVertex2f(0.24, 0.34);
    glVertex2f(-0.24, 0.34);
    glVertex2f(-0.23, 0.35);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 79, 0);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.8, -0.4);
    glVertex2f(0.8, 0.4);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 215, 0);
    glVertex2f(-0.65, -0.09);
    glVertex2f(-0.6, -0.2);
    glVertex2f(-0.62, -0.25);
    glVertex2f(-0.71, -0.07);
    glEnd();


    glLineWidth(10);
    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.5, -0.25);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.9, -0.33);
    glEnd();


    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.5, -0.25);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.8, -0.6);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.6, -0.45);
    glVertex2f(-0.45, -0.6);
    glEnd();


    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.6, -0.45);
    glVertex2f(-0.7, -0.6);
    glEnd();
    glPopMatrix();
}

void backgroundScene() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(127, 199, 255);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.3);
    glVertex2f(-1, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(28, 169, 201);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0.3);
    glVertex2f(-1, 0.3);
    glEnd();

    glPopMatrix();

}
