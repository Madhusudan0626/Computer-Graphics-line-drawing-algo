#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int x1=0,x2=0,y1=0,y2=0;

void display_buttomUp(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f(0.0,0.0,0.0);

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
    printf("%d\n",t);
}

void display_topDown(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f(0.0,0.0,0.0);

    int dy,dx,step,x,y,k,Xin,Yin,p_init,p_next;

    x=x2;
    y=y2;
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
        x=x-1;
        if(p_init<0){
            p_next=p_init+2*dy;
        }
        else{
            p_next=p_init+2*dx-2*dy;
            y=y-1;
        }
        t++;
        p_init=p_next;
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        printf("%d , %d\n",x,y);
    }
    glEnd();
    glFlush();
    printf("%d\n",t);
}

void init(void)
{
    glPointSize(3.0);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    glOrtho(80.0,80.0,80.0,80.0,-80.0,80.0);
    gluOrtho2D(-100,100,-100,100);
}