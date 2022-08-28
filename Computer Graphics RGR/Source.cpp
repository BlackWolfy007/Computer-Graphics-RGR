#include <GL\glut.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

#define part1
#ifdef part1
//===================================================================
//  Расчетно-графическая работа по компьютерной графике
//
//  Группа АБ-021 Шуваев В.А.
//===================================================================

// ----------------------------------------------------------
// Объявление функций
// ----------------------------------------------------------
void display_octahedron();
void display_trapezoid();
void display();
void specialKeys(int key, int x, int y);
void keyboard_ascii(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

// ----------------------------------------------------------
// Глобальные переменные
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
// Цвета фона
// ----------------------------------------------------------
#define BG_BLACK glClearColor(0, 0, 0, 1)
#define BG_GREEN glClearColor(0, 0, 1, 1)
#define BG_BLUE glClearColor(0, 1, 0, 1)
#define BG_LIGTH_BLUE glClearColor(0, 1, 1, 1)
#define BG_RED glClearColor(1, 0, 0, 1)
#define BG_PURPLE glClearColor(1, 0, 1, 1)
#define BG_YELLOW glClearColor(1, 1, 0, 1)
#define BG_WHITE glClearColor(1, 1, 1, 1)
#define BG_DEFAULT glClearColor(0.13, 0, 0.38, 1)

// ----------------------------------------------------------
// Показ октаэдра
// ----------------------------------------------------------
void display_octahedron() {
  //  Перед верх
  glBegin(GL_POLYGON);
  glColor3f(0.25 + r, 0.25 + g, 0.25 + b);
  glVertex3f(0.25 * k, 0 * k, -0.25 * k);
  glVertex3f(0 * k, 0.5 * k, 0 * k);
  glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
  glEnd();

  //  Задняя часть верх
  glBegin(GL_POLYGON);
  glColor3f(1.0 + r, 0.5 + g, 0 + b);
  glVertex3f(0.25 * k, 0 * k, 0.25 * k);
  glVertex3f(0 * k, 0.5 * k, 0 * k);
  glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
  glEnd();

  //  Правая сторона верх
  glBegin(GL_POLYGON);
  glColor3f(1.0 + r, 0.0 + g, 1.0 + b);
  glVertex3f(0.25 * k, 0 * k, -0.25 * k);
  glVertex3f(0 * k, 0.5 * k, 0 * k);
  glVertex3f(0.25 * k, 0 * k, 0.25 * k);
  glEnd();

  //  Левая сторона верх
  glBegin(GL_POLYGON);
  glColor3f(0.0 + r, 0.65 + g, 1 + b);
  glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
  glVertex3f(0 * k, 0.5 * k, 0 * k);
  glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
  glEnd();

  //  Перед низ
  glBegin(GL_POLYGON);
  glColor3f(0.65 + r, 1 + g, 0 + b);
  glVertex3f(0.25 * k, 0 * k, -0.25 * k);
  glVertex3f(0 * k, -0.5 * k, 0 * k);
  glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
  glEnd();

  //  Задняя часть низ
  glBegin(GL_POLYGON);
  glColor3f(0.55 + r, 0 + g, 1.0 + b);
  glVertex3f(0.25 * k, 0 * k, 0.25 * k);
  glVertex3f(0 * k, -0.5 * k, 0 * k);
  glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
  glEnd();

  //  Правая сторона низ
  glBegin(GL_POLYGON);
  glColor3f(1.0 + r, 0.0 + g, 0.68 + b);
  glVertex3f(0.25 * k, 0 * k, -0.25 * k);
  glVertex3f(0 * k, -0.5 * k, 0 * k);
  glVertex3f(0.25 * k, 0 * k, 0.25 * k);
  glEnd();

  //  Левая сторона низ
  glBegin(GL_POLYGON);
  glColor3f(0.0 + r, 1.0 + g, 0.82 + b);
  glVertex3f(-0.25 * k, 0 * k, 0.25 * k);
  glVertex3f(0 * k, -0.5 * k, 0 * k);
  glVertex3f(-0.25 * k, 0 * k, -0.25 * k);
  glEnd();
}

// ----------------------------------------------------------
// Показ трапеции
// ----------------------------------------------------------
void display_trapezoid() {
  //  Верхняя грань
  glBegin(GL_POLYGON);
  glColor3f(0.25 + r, 0.25 + g, 0.25 + b);

  glVertex3f(0.2 * k, 0.2 * k, 0.2 * k);
  glVertex3f(0.2 * k, 0.2 * k, -0.2 * k);
  glVertex3f(-0.2 * k, 0.2 * k, -0.2 * k);
  glVertex3f(-0.2 * k, 0.2 * k, 0.2 * k);

  glEnd();

  //  Фронтальная грань
  glBegin(GL_POLYGON);
  glColor3f(1.0 + r, 0.5 + g, 0 + b);

  glVertex3f(-0.4 * k, -0.2 * k, -0.2 * k);
  glVertex3f(0.4 * k, -0.2 * k, -0.2 * k);
  glVertex3f(0.2 * k, 0.2 * k, -0.2 * k);
  glVertex3f(-0.2 * k, 0.2 * k, -0.2 * k);

  glEnd();

  //  боковая грань право
  glBegin(GL_POLYGON);
  glColor3f(1.0 + r, 0.0 + g, 1.0 + b);

  glVertex3f(0.2 * k, 0.2 * k, 0.2 * k);
  glVertex3f(0.2 * k, 0.2 * k, -0.2 * k);
  glVertex3f(0.4 * k, -0.2 * k, -0.2 * k);
  glVertex3f(0.4 * k, -0.2 * k, 0.2 * k);

  glEnd();

  //  боковая грань лево
  glBegin(GL_POLYGON);
  glColor3f(0.0 + r, 0.65 + g, 1 + b);

  glVertex3f(-0.4 * k, -0.2 * k, 0.2 * k);
  glVertex3f(-0.4 * k, -0.2 * k, -0.2 * k);
  glVertex3f(-0.2 * k, 0.2 * k, -0.2 * k);
  glVertex3f(-0.2 * k, 0.2 * k, 0.2 * k);

  glEnd();

  //  задняя грань
  glBegin(GL_POLYGON);
  glColor3f(0.65 + r, 1 + g, 0 + b);

  glVertex3f(-0.4 * k, -0.2 * k, 0.2 * k);
  glVertex3f(0.4 * k, -0.2 * k, 0.2 * k);
  glVertex3f(0.2 * k, 0.2 * k, 0.2 * k);
  glVertex3f(-0.2 * k, 0.2 * k, 0.2 * k);

  glEnd();

  //  Нижняя грань
  glBegin(GL_POLYGON);
  glColor3f(0.0 + r, 1.0 + g, 0.82 + b);

  glVertex3f(0.4 * k, -0.2 * k, 0.2 * k);
  glVertex3f(0.4 * k, -0.2 * k, -0.2 * k);
  glVertex3f(-0.4 * k, -0.2 * k, -0.2 * k);
  glVertex3f(-0.4 * k, -0.2 * k, 0.2 * k);

  glEnd();
}

// ----------------------------------------------------------
// Вызов одной из фигур на экран
// ----------------------------------------------------------

void display() {
  int _bg = round(bg);
  //  Задание цвета фона
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

  //  Очистка экрана и буфера
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //  Очистка матрицы
  glLoadIdentity();

  //  Изменение положения в пространстве
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);

  // Выборка фигуры
  switch (figure % 2) {
    case 0:
      display_octahedron();
      break;
    case 1:
      display_trapezoid();
      break;
  }

  //  Очистка буферов
  glFlush();
  glutSwapBuffers();
}

// ----------------------------------------------------------
//  Вызов функции для работы со служебными клавишами
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {
  switch (key) {
      //  Клавиша "Right" - повернуть на 2 градуса вправо
    case GLUT_KEY_RIGHT:
      rotate_y += 2;
      break;
      //  Клавиша "Left" - повернуть на 2 градуса влево
    case GLUT_KEY_LEFT:
      rotate_y -= 2;
      break;
      //  Клавиша "Up" - повернуть на 2 градуса вверх
    case GLUT_KEY_UP:
      rotate_x += 2;
      break;
      //  Клавиша "Down" - повернуть на 2 градуса вниз
    case GLUT_KEY_DOWN:
      rotate_x -= 2;
      break;
      //  Клавиша "F1" - увеличить фигуру на 0.1
    case GLUT_KEY_F1:
      if (k < 2) k += 0.1;
      break;
      //  Клавиша "F2" - уменьшить фигуру на 0.1
    case GLUT_KEY_F2:
      if (k > 0) k -= 0.1;
      break;
      //  Клавиша "F3" - увеличичить значения красного цвета на 0.01
    case GLUT_KEY_F3:
      r += 0.01;
      break;
      //  Клавиша "F4" - увеличичить значения зеленого цвета на 0.01
    case GLUT_KEY_F4:
      g += 0.01;
      break;
      //  Клавиша "F5" - увеличичить значения синего цвета на 0.01
    case GLUT_KEY_F5:
      b += 0.01;
      break;
      //  Клавиша "F6" - уменьшить значения синего цвета на 0.01
    case GLUT_KEY_F6:
      r -= 0.01;
      break;
      //  Клавиша "F7" - уменьшить значения синего цвета на 0.01
    case GLUT_KEY_F7:
      g -= 0.01;
      break;
      //  Клавиша "F8" - уменьшить значения синего цвета на 0.01
    case GLUT_KEY_F8:
      b -= 0.01;
      break;
      //  Клавиша "F9" - вернуть цвета по умолчанию
    case GLUT_KEY_F9:
      r = 0;
      g = 0;
      b = 0;
      break;
      //  Клавиша "F10" - сбросить размеры объекта до состояния по умолчанию
    case GLUT_KEY_F10:
      k = 1.5;
      break;
      //  Клавиша "F11" - сбросить углы поворота объекта
    case GLUT_KEY_F11:
      rotate_x = 0;
      rotate_y = 0;
  }

  //  обновление активного окна
  glutPostRedisplay();
}

// ----------------------------------------------------------
//  Вызов функции для работы с остальной клавиатурой
// ----------------------------------------------------------

void keyboard_ascii(unsigned char key, int x, int y) {
  switch (key) {
      //  Клавиша "Tab" - сменить показываемый объект
    case 9:
      figure++;
      break;
      //  Клавиша "Esc" - завершить работу программы
    case 27:
      exit(0);
      break;
  }
}

// ----------------------------------------------------------
//  Вызов функции для работы с мышью
// ----------------------------------------------------------
void mouse(int button, int state, int x, int y) {
  switch (button) {
      //  Левая кнопка мыши - поворот по диагонали влево вверх на 5 градусов
    case GLUT_LEFT_BUTTON:
      rotate_x -= 3;
      rotate_y -= 3;
      break;
      //  Правая кнопка мыши - поворот по диагонали вправо вверх на 5 градусов
    case GLUT_RIGHT_BUTTON:
      rotate_x -= 3;
      rotate_y += 3;
      break;
      // Средняя кнопка мыши - смена фона приложения
    case GLUT_MIDDLE_BUTTON:
      bg += 0.5;
      break;
  }

  //  Обновление активного окна
  glutPostRedisplay();
}

int main(int argc, char* argv[]) {
  //  Инициализация GlUT
  glutInit(&argc, argv);

  //  Задание размера вызываемого окна
  glutInitWindowSize(700, 700);

  //  Инициализация буферов обмена и координаты Z
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  //  Вызов окна с графическим интерфейсом
  glutCreateWindow(
      "Расчетно-графическая работа по компьютерной графике. АБ-021");

  //  Инициализация функции теста
  glEnable(GL_DEPTH_TEST);

  //  Вызов дисплея и управления клавишами клавиатуры и мыши
  glutDisplayFunc(display);

  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(keyboard_ascii);
  glutMouseFunc(mouse);

  //  Зацикливание показа кадров
  glutMainLoop();

  //  Выход из программы
  return 0;
}
#endif
