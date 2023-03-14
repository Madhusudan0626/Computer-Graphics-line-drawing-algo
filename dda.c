//DDA algorithm using c
#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, x2, y1, y2;

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  glEnd();
  glColor3f(0.0,0.0,0.0);
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y1;
  if (abs(dx) > abs(dy)){
    step = abs(dx);
  } else
  step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = y1;
  x=round(x);
  y=round(y);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    x=round(x);
    y=round(y);
    glBegin(GL_POINTS);
    glVertex2i(x,y);

  }
  glEnd();
  glFlush();
}

void myInit (void) {
    glPointSize(3.0);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    glOrtho(80.0,80.0,80.0,80.0,-80.0,80.0);
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char ** argv) {

  printf("Value of x1 : ");
  scanf("%f", & x1);
  printf("Value of y1 : ");
  scanf("%f", & y1);
  printf("Value of x2 : ");
  scanf("%f", & x2);
  printf("Value of y2 : ");
  scanf("%f", & y2);

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (900, 900);
  glutInitWindowPosition (100,100);
  glutCreateWindow("");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();
}