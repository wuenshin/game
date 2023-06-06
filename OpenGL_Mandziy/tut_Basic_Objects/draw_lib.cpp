#include "draw_lib.h"


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
