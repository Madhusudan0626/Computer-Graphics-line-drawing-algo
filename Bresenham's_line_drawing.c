//Bresenham's algorithm using c
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include "bersenham.h"

int main(int argc, char** argv) {
    printf("Enter the value of x1 : ");
    scanf("%d",&x1);
    printf("Enter the value of y1 : ");
    scanf("%d",&y1);
    printf("Enter the value of x2 : ");
    scanf("%d",&x2);
    printf("Enter the value of y2 : ");
    scanf("%d",&y2);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 900);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Bresenham's Line Algo");
    init();

    if(x1<x2)
    glutDisplayFunc(display_buttomUp);
    else
    glutDisplayFunc(display_topDown);
    
    glutMainLoop();

    return 0;
}