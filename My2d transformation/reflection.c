#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include "commoncenter.h"

#define MAX 10
int vertices;
int x[MAX],y[MAX];
int xaux[MAX],yaux[MAX];
int choice;
int line_x[2],c;
float slope;

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
    if(choice==6){
        glBegin(GL_LINES);
        glColor3f(0, 1, 0);
            glVertex2f(line_x[0], ((slope*line_x[0]) + c));
            glVertex2f(line_x[1], ((slope*line_x[1]) + c));
        glEnd();
    }                              
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

void about_x_axis(){
    printf("\n\nREFLECTION ABOUT X-AXIS\n");
    for (int i = 0; i < vertices; i++)                                          
        yaux[i] = -yaux[i];
}

void about_y_axis(){
    printf("\n\nREFLECTION ABOUT Y-AXIS\n");
    for (int i = 0; i < vertices; i++)                                          
        xaux[i] = -xaux[i];
}

void about_y_equal_x()           
{
    printf("\n\nREFLECTION ALONG LINE y = x\n");
    for(int i=0; i<vertices; i++)
    {
        xaux[i] = y[i];
        yaux[i] = x[i];
    }                                          
}

void about_y_equal_mx()       
{
    printf("\n\nREFLECTION ALONG LINE y = -x\n");
    for(int i=0; i<vertices; i++)
    {
        xaux[i] = -y[i];
        yaux[i] = -x[i];
    }                                          
}

void about_origin()
{
    printf("\n\nREFLECTION ABOUT ORIGIN\n");
    for (int i = 0; i < vertices; i++) 
    {                                         
        xaux[i] = -xaux[i];
        yaux[i] = -yaux[i];
    }
}

void about_a_straight_line(){
    printf("\n\nREFLECTION ALONG A STRAIGHT LINE\n");

    printf("Enter starting x-coordinate of line: ");
    scanf("%d", &line_x[0]);
    printf("Enter ending x-coordinate of line: ");
    scanf("%d", &line_x[1]);
    printf("Enter slope of line: ");
    scanf("%f", &slope);
    printf("Enter intercept of line: ");
    scanf("%d", &c);
    printf("\nEquation of given line is -> y = %0.2fx + %d\n", slope, c);

    for (int i=0; i < vertices; i++)
    {
        xaux[i] = (((1 - slope*slope) * x[i]) + (2 * slope * (y[i] - c))) / (1 + slope*slope);
        yaux[i] = (((slope*slope - 1) * y[i]) + (2 * slope * x[i]) + 2*c) / (1 + slope*slope);
    }
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
    
    printf("\n\nOperation for reflection:\n1.reflection about x-axis.\n2.Reflection about y-axis\n3.about origin\n4.y = x\n5.y = -x\n6.y=mx+c\n\nEnter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            about_x_axis();
            break;
        case 2:
            about_y_axis();
            break;
        case 3:
            about_origin();
            break;
        case 4:
            about_y_equal_x();
            break;
        case 5:
            about_y_equal_mx();
            break;
        case 6:
            about_a_straight_line();
            break;
        default:
            printf("Wrong choice.\n");
    }
    glutInit(&argc, args);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 900);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("reflection of 2d object");
    init();
    glutFullScreen();
    glutDisplayFunc(display);
    glutMainLoop();
}

