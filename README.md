#week02
##step01-1
```C++
///step02-1 10行最精簡的GLUT程式
///先全刪 目標5-10行寫完
#include <GL/glut.h>///使用GLUT外掛簡化程式
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫圖前先清畫面
        glColor3f(1,1,0);///設定色彩
        glutSolidTeapot(0.3);///實心的茶壺
    glutSwapBuffers();///畫好後交換出來
}
int main(int argc,char** argv)///main()主函式 進階版
{
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week02_1");///開GLUT視窗

    glutDisplayFunc(display);///用來顯示的函式
    glutMainLoop();///主要的程式迴圈
}
```

##step01-2
```C++
///step02-1 10行最精簡的GLUT程式
///先全刪 目標5-10行寫完
#include <GL/glut.h>///使用GLUT外掛簡化程式
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫圖前先清畫面
        glColor3f(1,1,0);///設定色彩
        ///glutSolidTeapot(0.3);///實心的茶壺
        glBegin(GL_POLYGON);
            glColor3f(1,0,0);///紅色
            glVertex2f(-1,-1);
            glColor3f(0,1,0);///綠色
            glVertex2f(+1,-1);
            glColor3f(0,0,1);///藍色
            glVertex2f(0,+1);
        glEnd();
    glutSwapBuffers();///畫好後交換出來
}
int main(int argc,char** argv)///main()主函式 進階版
{
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week02_1");///開GLUT視窗

    glutDisplayFunc(display);///用來顯示的函式
    glutMainLoop();///主要的程式迴圈
}
```
#week03-1
##step01
```C++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
    ///移動會累積，因為它會修改矩陣
    glTranslatef(0.5,0.5,0);///右上角
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣(還原舊的位置)
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02_1");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

##step02
```C++
#include <GL/glut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///備份矩陣
    ///移動會累積，因為它會修改矩陣
       // glTranslatef(0.5,0.5,0);///右上角
        glTranslatef(x,y,0);///
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣(還原舊的位置)
}
void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     myTeapot(0.5,0.5);
     myTeapot(0.5,-0.5);
     myTeapot(-0.5,-0.5);
     myTeapot(-0.5,0.5);
     glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02_1");

    glutDisplayFunc(display);
    glutMainLoop();
}
```
##step03
```C++
#include <GL/glut.h>
float mouseX=0,mouseY=0;
void myTeapot(float x,float y)
{
    glPushMatrix();///備份矩陣
    ///移動會累積，因為它會修改矩陣
       // glTranslatef(0.5,0.5,0);///右上角
        glTranslatef(x,y,0);///
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣(還原舊的位置)
}
void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0);
     glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    mouseX=x;mouseY=y;
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week02_1");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}

#week05
```C++
#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///R,G,B,A 其中A半透明功能，目前沒開
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale,scale,scale);///都縮放成scale倍
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(mouseX-oldX>0)scale*=1.01;
    if(mouseX-oldX<0)scale*=0.99;
   ///x+= (mouseX-oldX);y+=(mouseY-oldY);
    oldX=mouseX; oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
