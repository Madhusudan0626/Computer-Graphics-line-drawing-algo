#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int x1,x2,y1,y2;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f(1.0,1.0,1.0);

    int dy,dx,step,x,y,k,Xin,Yin,p_init,p_next;

    x=x1;
    y=y1;
    dx=x2-x1;
    dx=abs(dx);

    dy=y2-y1;
    dy=abs(dy);

    p_init=2*dy-dx;
    int t=0;

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    printf("Points are : %d , %d\n",x,y);
    while(t<=dx-1){
        x=x+1;
        if(p_init<0){
            p_next=p_init+2*dy;
        }
        else{
            p_next=p_init+2*dx-2*dy;
            y=y+1;
        }
        t++;
        p_init=p_next;
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        printf("%d , %d\n",x,y);
    }
    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    gluOrtho2D(-100,100,-100,100);
}

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
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Bresenham's Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}