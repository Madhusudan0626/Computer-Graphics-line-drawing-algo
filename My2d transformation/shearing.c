#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include "commoncenter.h"
#define MAX 10
int vertices;
int x[MAX],y[MAX];
int xaux[MAX],yaux[MAX];
int shearfactor,choice;

void init(void)
{
    glPointSize(3.0);
    glClearColor(1.0,1.0,1.0,1.0);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    // glOrtho(80.0,80.0,80.0,80.0,-80.0,80.0);
    gluOrtho2D(-1920,1920,-1080,1080);
}

void display(void){
    
    // glutFullScreen();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex3f(-1920.0,0.0f,0.0f);
    glVertex3f(1920.0,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0,-1080.0f,0.0f);
    glVertex3f(0.0,1080.0f,0.0f);
    glEnd();
    glLineWidth(5.0);						                              
	glBegin(GL_LINE_LOOP);	
                                                    
        glColor3f(0, 0, 0);
        for(int i=0; i<vertices; i++)
            glVertex2i(x[i]+xc, y[i]+yc);
	glEnd();
    glBegin(GL_LINE_LOOP);	
                                                    
        glColor3f(1, 0, 0);
        for(int i=0; i<vertices; i++)
            glVertex2i(xaux[i]+xc, yaux[i]+yc);
	glEnd();
    glFlush();
}

void translation(){
    
    
    
    display();
}

int main(int argc,char **args){
    printf("Enter the number of vertices : \n");
    scanf("%d",&vertices);

    
    for(int i=0;i<vertices;i++){
        printf("Vertex : ");
        scanf("%d%d",&x[i],&y[i]);
        xaux[i]=x[i];
        yaux[i]=y[i];
    }
    printf("Enter the shearing factor: ");
    scanf("%d", &shearfactor);
    printf("Enter 1 for shearing along x-axis and 2 for shearing along y-axis: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            for (int i=0; i < vertices; i++) 
            {                                         
                xaux[i] = x[i] + shearfactor * y[i];
                yaux[i] = y[i];
            }
        }
        case 2: 
        {
            for (int i=0; i < vertices; i++) 
            {                                         
                xaux[i] = x[i];
                yaux[i] = y[i] + shearfactor * x[i];
            }
        }
        default: 
            printf("Wrong Choice\n"); 
            break;
    }

    glutInit(&argc, args);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 900);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("translation of 2d object");
    init();
    glutFullScreen();
    glutDisplayFunc(display);
    glutMainLoop();
}

