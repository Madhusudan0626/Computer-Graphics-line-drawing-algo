#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int  xc , yc;

void pointsdraw(int x,int y,int xc,int yc){

    // glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc+y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-x, yc-y);
    glVertex2i(xc-y, yc-x);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc-y, yc+x);
    glEnd();
}

void display(int r,int xc,int yc){
    // glClear(GL_COLOR_BUFFER_BIT);
    // glEnd();
    glColor3f(0.0,0.0,0.0);

    int x0=0,y0=r;
    pointsdraw(x0,y0,xc,yc);
    float pinit=(5.0/4.0)-r;
    int x=x0,y=y0;
    while(x<y){
        x=x+1;
        if(pinit<0){
            pinit=pinit+2*x+1;
        }
        else{
            y=y-1;
            pinit=pinit+2*(x-y)+1;
        }
        pointsdraw(x,y,xc,yc);
    }
    glFlush();

}

void concentric(){
    int r1=100, r2=200;
    // printf("Enter the value of r1 : ");
    // scanf("%d",&r1);
    glClear(GL_COLOR_BUFFER_BIT);
    display(r1,xc,yc);
    // display(r2,xc,yc);
}

void init(void)
{
    glPointSize(3.0);
    glClearColor(1.0,1.0,1.0,1.0);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    // glOrtho(80.0,80.0,80.0,80.0,-80.0,80.0);
    gluOrtho2D(-600,600,-600,600);
}

int main(int argc, char** argv){
    // printf("Enter the radius of the circle : ");
    // scanf("%d",&r);

    printf("Enter the center point of the circle : ");
    scanf("%d%d",&xc,&yc);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 900);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("Bresenham's Line Algo");
    init();
    glutDisplayFunc(concentric);
    glutMainLoop();
}