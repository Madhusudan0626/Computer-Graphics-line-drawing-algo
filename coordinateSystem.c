//DDA algorithm using c
#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, x2, y1, y2;

void display(void) {
    glColor3f(0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);

      //X-axis
      glVertex3f(-100.0,0.0f,0.0f);
      glVertex3f(100.0,0.0f,0.0f);
glBegin(GL_LINES);
      glVertex3f(0.0,-100.0f,0.0f);
      glVertex3f(0.0,100.0f,0.0f);
glBegin(GL_LINES);
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -2.0);
    glVertex3f(0.0, 0.0, 2.0);
      
// glBegin(GL_LINES);
//       glVertex2f(0,30);
//       glVertex2f(0,-30);
    // glVertex2f(80,0);
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

//   printf("Value of x1 : ");
//   scanf("%f", & x1);
//   printf("Value of y1 : ");
//   scanf("%f", & y1);
//   printf("Value of x2 : ");
//   scanf("%f", & x2);
//   printf("Value of y2 : ");
//   scanf("%f", & y2);

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (900, 900);
  glutInitWindowPosition (100,100);
  glutCreateWindow("");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();
}