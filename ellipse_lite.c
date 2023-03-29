#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
// #include "circledrawing.c"

int  xc=0, yc=0;

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
    // glColor3f(0.0,0.0,0.0);

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

void pointsare(int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x+xc,y+yc);
    glVertex2i(-x+xc,y+yc);
    glVertex2i(x+xc,-y+yc);
    glVertex2i(-x+xc,-y+yc);
    glEnd();
}

void ellipse(int rx,int ry){
    
    // glEnd();
    
    float p1,q1;
    int dx,dy,x,y;
    x=0;
    y=ry;

    p1=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);
    glColor3f(0.0,1.0,0.0);
    dy=2*rx*rx*y;
    dx=2*ry*ry*x;

    // glBegin(GL_LINES);
    // glVertex3f(-rx,0.0f,0.0f);
    // glVertex3f(rx,0.0f,0.0f);
    // glEnd();
    // glColor3f(0.0,0.0,1.0);
    // glBegin(GL_LINES);
    // glVertex3f(0.0,ry,0.0f);
    // glVertex3f(0.0,-ry,0.0f);
    
    glColor3f(1.0,0.0,0.0);
    glPointSize(3.0);
    glClearColor(1.0,1.0,1.0,1.0);
    // glClear(GL_COLOR_BUFFER_BIT);


    while(dx<dy){
        
        if(p1<0){
            x++;
            dx=dx+2*ry*ry;
            p1=p1+dx+ry*ry;
            // printf("value of x %d\n",x);
        }
        else{
            x++;
            y--;
            dx=dx+2*ry*ry;
            dy=dy-(2*rx*rx);
            p1=p1+dx-dy+(ry*ry);
            // printf("value of y %d\n",y);
        }
        // printf("region 1 : \n");
        // printf("(%d, %d) and value of x = %d and y= %d\n", x + xc, y + yc,x,y);
        // printf("(%d, %d) and value of x = %d and y= %d\n", -x + xc, y + yc,x,y);
        // printf("(%d, %d) and value of x = %d and y= %d\n", x + xc, -y + yc,x,y);
        // printf("(%d, %d) and value of x = %d and y= %d\n", -x + xc, -y + yc,x,y);
        pointsare(x,y);
    }
    //  + ((rx*rx)(y-1)*(y-1))-(rx*rx*ry*ry);
    q1=((ry*ry)*(x+0.5)*(x+0.5));
    q1=q1+((rx*rx)*(y-1)*(y-1)) - (rx*rx*ry*ry);

    while(y>0){
        if(q1>0){
            y--;
            dy=dy-(2*rx*rx);
            q1=q1+(rx*rx)-dy;
            
        }
        else{
            y--;
            x++;
            dx=dx+2*ry*ry;
            dy=dy-(2*rx*rx);
            q1=q1+dx-dy+(rx*rx);
        }
        // printf("region 2 : \n");
        // printf("(%d, %d) and value of x = %d and y= %d\n", x + xc, y + yc,x,y);
        // printf("(%d, %d) and value of x = %d and y= %d\n", -x + xc, y + yc,x,y);
        // printf("(%d, %d) and value of x = %d and y= %d\n", x + xc, -y + yc,x,y);
        // printf("(%d, %d) and value of x = %d and y= %d\n", -x + xc, -y + yc,x,y);
        pointsare(x,y);
    }

    glFlush();

}

void display1(){
    
    // printf("Enter the minor axis and major axis : (a<b)");
    glClear(GL_COLOR_BUFFER_BIT);
    // ellipse(400,200);
    ellipse(200,100);
    ellipse(100,50);
    // glColor3f(0.0,1.0,0.0);
    // display(200,xc,yc);
    // glColor3f(0.0,0.0,1.0);
    // display(150,xc,yc);
    // printf("Enter the value of r1 : ");
    // scanf("%d",&r1);
    
    
}


void init(void)
{
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    // glOrtho(80.0,80.0,80.0,80.0,-80.0,80.0);
    gluOrtho2D(-400,400,-400,400);
}

int main(int argc, char** argv){
    // printf("Enter the radius of the circle : ");
    // scanf("%d",&r);

    // printf("Enter the center point of the circle : ");
    // scanf("%d%d",&xc,&yc);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("Bresenham's Line Algo");
    init();
    glutDisplayFunc(display1);
    

    glutMainLoop();
}