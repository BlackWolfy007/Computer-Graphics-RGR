#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL\glut.h>

#define part1
#ifdef part1
//===================================================================
//  ��������-����������� ������ �� ������������ �������
//  
//  ������ ��-021 ������ �.�.
//===================================================================

// ----------------------------------------------------------
// ���������� �������
// ----------------------------------------------------------
void display_octahedron();
void display_trapezoid();
void display();
void specialKeys(int key, int x, int y);
void keyboard_ascii(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

// ----------------------------------------------------------
// ���������� ����������
// ----------------------------------------------------------
double rotate_y = 0;
double rotate_x = 0;
double k = 1.5;
double r = 0.00;
double g = 0.00;
double b = 0.00;
double bg = 0;
int figure = 0;

// ----------------------------------------------------------
// ����� ����
// ----------------------------------------------------------
#define BG_BLACK      glClearColor(0, 0, 0, 1)
#define BG_GREEN      glClearColor(0, 0, 1, 1)
#define BG_BLUE       glClearColor(0, 1, 0, 1)
#define BG_LIGTH_BLUE glClearColor(0, 1, 1, 1)
#define BG_RED        glClearColor(1, 0 ,0, 1)
#define BG_PURPLE     glClearColor(1, 0, 1, 1)
#define BG_YELLOW     glClearColor(1, 1, 0, 1)
#define BG_WHITE      glClearColor(1, 1, 1, 1)
#define BG_DEFAULT    glClearColor(0.13, 0, 0.38, 1)

// ----------------------------------------------------------
// ����� ��������
// ----------------------------------------------------------
void display_octahedron() {

    //  ����� ����
    glBegin(GL_POLYGON);
    glColor3f(0.25 + r, 0.25 + g, 0.25 + b);
    glVertex3f(0.25 * k, 0 * k, -0.25 * k);
    glVertex3f(0 * k, 0.5 * k, 0 * k);
    glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
    glEnd();

    //  ������ ����� ����
    glBegin(GL_POLYGON);
    glColor3f(1.0 + r, 0.5 + g, 0 + b);
    glVertex3f(0.25 * k, 0 * k, 0.25 * k);
    glVertex3f(0 * k, 0.5 * k, 0 * k);
    glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
    glEnd();

    //  ������ ������� ����
    glBegin(GL_POLYGON);
    glColor3f(1.0 + r, 0.0 + g, 1.0 + b);
    glVertex3f(0.25 * k, 0 * k, -0.25 * k);
    glVertex3f(0 * k, 0.5 * k, 0 * k);
    glVertex3f(0.25 * k, 0 * k, 0.25 * k);
    glEnd();

    //  ����� ������� ����
    glBegin(GL_POLYGON);
    glColor3f(0.0 + r, 0.65 + g, 1 + b);
    glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
    glVertex3f(0 * k, 0.5 * k, 0 * k);
    glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
    glEnd();

    //  ����� ���
    glBegin(GL_POLYGON);
    glColor3f(0.65 + r, 1 + g, 0 + b);
    glVertex3f(0.25 * k, 0 * k, -0.25 * k);
    glVertex3f(0 * k, -0.5 * k, 0 * k);
    glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
    glEnd();

    //  ������ ����� ���
    glBegin(GL_POLYGON);
    glColor3f(0.55 + r, 0 + g, 1.0 + b);
    glVertex3f(0.25 * k, 0 * k, 0.25 * k);
    glVertex3f(0 * k, -0.5 * k, 0 * k);
    glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
    glEnd();

    //  ������ ������� ���
    glBegin(GL_POLYGON);
    glColor3f(1.0 + r, 0.0 + g, 0.68 + b);
    glVertex3f(0.25 * k, 0 * k, -0.25 * k);
    glVertex3f(0 * k, -0.5 * k, 0 * k);
    glVertex3f(0.25 * k, 0 * k, 0.25 * k);
    glEnd();

    //  ����� ������� ���
    glBegin(GL_POLYGON);
    glColor3f(0.0 + r, 1.0 + g, 0.82 + b);
    glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
    glVertex3f(0 * k, -0.5 * k, 0 * k);
    glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
    glEnd();

}

// ----------------------------------------------------------
// ����� ��������
// ----------------------------------------------------------
void display_trapezoid() {

    //  ������� �����
    glBegin(GL_POLYGON);
    glColor3f(0.25+r, 0.25+g, 0.25+b);

    glVertex3f(0.2 * k, 0.2 * k, 0.2 * k);
    glVertex3f(0.2 * k, 0.2 * k, -0.2 * k);
    glVertex3f(-0.2 * k, 0.2 * k, -0.2 * k);
    glVertex3f(-0.2 * k, 0.2 * k, 0.2 * k);
    
    glEnd();

    //  ����������� �����
    glBegin(GL_POLYGON);
    glColor3f(1.0 + r, 0.5 + g, 0 + b);

    glVertex3f(-0.4 * k, -0.2 * k, -0.2 * k);
    glVertex3f(0.4 * k, -0.2 * k, -0.2 * k);
    glVertex3f(0.2 * k, 0.2 * k, -0.2 * k);
    glVertex3f(-0.2 * k, 0.2 * k, -0.2 * k);

    
    glEnd();

    //  ������� ����� �����
    glBegin(GL_POLYGON);
    glColor3f(1.0 + r, 0.0 + g, 1.0 + b);

    glVertex3f(0.2 * k, 0.2 * k, 0.2 * k);
    glVertex3f(0.2 * k, 0.2 * k, -0.2 * k);
    glVertex3f(0.4 * k, -0.2 * k, -0.2 * k);
    glVertex3f(0.4 * k, -0.2 * k, 0.2 * k);
    
    glEnd();

    //  ������� ����� ����
    glBegin(GL_POLYGON);
    glColor3f(0.0 + r, 0.65 + g, 1 + b);

    glVertex3f(-0.4 * k, -0.2 * k, 0.2 * k);
    glVertex3f(-0.4 * k, -0.2 * k, -0.2 * k);
    glVertex3f(-0.2 * k, 0.2 * k, -0.2 * k);
    glVertex3f(-0.2 * k, 0.2 * k, 0.2 * k);

    glEnd();

    //  ������ �����
    glBegin(GL_POLYGON);
    glColor3f(0.65 + r, 1 + g, 0 + b);

    glVertex3f(-0.4 * k, -0.2 * k, 0.2 * k);
    glVertex3f(0.4 * k, -0.2 * k, 0.2 * k);
    glVertex3f(0.2 * k, 0.2 * k, 0.2 * k);
    glVertex3f(-0.2 * k, 0.2 * k, 0.2 * k);
    
    glEnd();

    //  ������ �����
    glBegin(GL_POLYGON);
    glColor3f(0.0 + r, 1.0 + g, 0.82 + b);

    glVertex3f(0.4 * k, -0.2 * k, 0.2 * k);
    glVertex3f(0.4 * k, -0.2 * k, -0.2 * k);
    glVertex3f(-0.4 * k, -0.2 * k, -0.2 * k);
    glVertex3f(-0.4 * k, -0.2 * k, 0.2 * k);

    glEnd();

}

// ----------------------------------------------------------
// ����� ����� �� ����� �� �����
// ----------------------------------------------------------

void display() {
    int _bg = round(bg);
    //  ������� ����� ����
    switch (_bg % 9) {
    case 0:
        BG_DEFAULT;
        break;
    case 1:
        BG_BLACK;
        break;
    case 2:
        BG_GREEN;
        break;
    case 3:
        BG_BLUE;
        break;
    case 4:
        BG_LIGTH_BLUE;
        break;
    case 5:
        BG_RED;
        break;
    case 6:
        BG_PURPLE;
        break;
    case 7:
        BG_YELLOW;
        break;
    case 8:
        BG_WHITE;
        break;

    }

    //  ������� ������ � ������
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //  ������� �������
    glLoadIdentity();

    //  ��������� ��������� � ������������ 
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    // ������� ������
    switch (figure%2) {
    case 0:
        display_octahedron();
        break;
    case 1:
        display_trapezoid();
        break;
    }


    //  ������� �������
    glFlush();
    glutSwapBuffers();
}

// ----------------------------------------------------------
//  ����� ������� ��� ������ �� ���������� ���������
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {

    switch (key) {
        //  ������� "Right" - ��������� �� 2 ������� ������
    case GLUT_KEY_RIGHT:
        rotate_y += 2;
        break;
        //  ������� "Left" - ��������� �� 2 ������� �����
    case GLUT_KEY_LEFT:
        rotate_y -= 2;
        break;
        //  ������� "Up" - ��������� �� 2 ������� �����
    case GLUT_KEY_UP:
        rotate_x += 2;
        break;
        //  ������� "Down" - ��������� �� 2 ������� ����
    case GLUT_KEY_DOWN:
        rotate_x -= 2;
        break;
        //  ������� "F1" - ��������� ������ �� 0.1
    case GLUT_KEY_F1:
        if (k<2) k += 0.1;
        break;
        //  ������� "F2" - ��������� ������ �� 0.1
    case GLUT_KEY_F2:
        if (k>0) k -= 0.1;
        break;
        //  ������� "F3" - ����������� �������� �������� ����� �� 0.01
    case GLUT_KEY_F3:
        r += 0.01;
        break;
        //  ������� "F4" - ����������� �������� �������� ����� �� 0.01
    case GLUT_KEY_F4:
        g += 0.01;
        break;
        //  ������� "F5" - ����������� �������� ������ ����� �� 0.01
    case GLUT_KEY_F5:
        b += 0.01;
        break;
        //  ������� "F6" - ��������� �������� ������ ����� �� 0.01
    case GLUT_KEY_F6:
        r -= 0.01;
        break;
        //  ������� "F7" - ��������� �������� ������ ����� �� 0.01
    case GLUT_KEY_F7:
        g -= 0.01;
        break;
        //  ������� "F8" - ��������� �������� ������ ����� �� 0.01
    case GLUT_KEY_F8:
        b -= 0.01;
        break;
        //  ������� "F9" - ������� ����� �� ���������
    case GLUT_KEY_F9:
        r = 0;
        g = 0;
        b = 0;
        break;
        //  ������� "F10" - �������� ������� ������� �� ��������� �� ���������
    case GLUT_KEY_F10:
        k = 1.5;
        break;
        //  ������� "F11" - �������� ���� �������� �������
    case GLUT_KEY_F11:
        rotate_x = 0;
        rotate_y = 0;
    }
    

    //  ���������� ��������� ����
    glutPostRedisplay();

}

// ----------------------------------------------------------
//  ����� ������� ��� ������ � ��������� �����������
// ----------------------------------------------------------

void keyboard_ascii(unsigned char key, int x, int y) {
    switch (key) {
        //  ������� "Tab" - ������� ������������ ������
    case 9:
        figure++;
        break;
        //  ������� "Esc" - ��������� ������ ���������
    case 27:
        exit(0);
        break;
    }
    
}

// ----------------------------------------------------------
//  ����� ������� ��� ������ � �����
// ----------------------------------------------------------
void mouse(int button, int state, int x, int y)
{

    switch (button) {
        //  ����� ������ ���� - ������� �� ��������� ����� ����� �� 5 ��������
    case GLUT_LEFT_BUTTON:
        rotate_x -= 3;
        rotate_y -= 3;
        break;
        //  ������ ������ ���� - ������� �� ��������� ������ ����� �� 5 ��������
    case GLUT_RIGHT_BUTTON:
        rotate_x -= 3;
        rotate_y += 3;
        break;
        // ������� ������ ���� - ����� ���� ����������
    case GLUT_MIDDLE_BUTTON:
        bg+=0.5;
        break;
    }

    //  ���������� ��������� ����
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {

    //  ������������� GlUT
    glutInit(&argc, argv);

    //  ������� ������� ����������� ����
    glutInitWindowSize(700, 700);

    //  ������������� ������� ������ � ���������� Z
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    //  ����� ���� � ����������� �����������
    glutCreateWindow("��������-����������� ������ �� ������������ �������. ��-021");

    //  ������������� ������� �����
    glEnable(GL_DEPTH_TEST);

    //  ����� ������� � ���������� ��������� ���������� � ����
    glutDisplayFunc(display);

    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard_ascii);
    glutMouseFunc(mouse);

    //  ������������ ������ ������
    glutMainLoop();

    //  ����� �� ���������
    return 0;

}
#endif


