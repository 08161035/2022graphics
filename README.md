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
```
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
#week06-1
```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);///
    ///偷來的程式要放在glutCreatWindow()之後,才有效
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

}
```
#week06-2
```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale,scale,scale);///都縮放成scale倍
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();
    glutSwapBuffers();
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
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);///
    ///偷來的程式要放在glutCreatWindow()之後,才有效
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}
```
#week06-3
```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glRotatef(angle,0,1,0);///對Y軸轉動
        glScalef(scale,scale,scale);///都縮放成scale倍
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    angle+=(mouseX-oldX);
    ///if(mouseX-oldX>0)scale*=1.01;
    ///if(mouseX-oldX<0)scale*=0.99;
   ///x+= (mouseX-oldX);y+=(mouseY-oldY);
    oldX=mouseX; oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);///
    ///偷來的程式要放在glutCreatWindow()之後,才有效
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}
```
#week06-4
```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0,now=1;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glRotatef(angle,0,1,0);///對Y軸轉動
        glScalef(scale,scale,scale);///都縮放成scale倍
        glColor3f(1,1,0);///黃色的
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='1' || key=='w' || key=='W')now=1;
    if(key=='2' || key=='e' || key=='E')now=2;
    if(key=='3' || key=='r' || key=='R')now=3;
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(now==1){
        x+=(mouseX-oldX);y+=(mouseY-oldY);
    }
    else if(now==2){
        angle+=(mouseX-oldX);
    }
    else if(now==3){
        if(mouseX-oldX > 0)scale*=1.01;
        if(mouseX-oldX < 0)scale*=0.99;
    }
    ///if(mouseX-oldX>0)scale*=1.01;
    ///if(mouseX-oldX<0)scale*=0.99;
   ///x+= (mouseX-oldX);y+=(mouseY-oldY);
    oldX=mouseX; oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);///
    ///偷來的程式要放在glutCreatWindow()之後,才有效
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}
#week08
```C++
#include <GL/glut.h>
#include "glm.h"
GLMmodel* pmodel = NULL;
void
drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/soccerball.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH);
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0,now=1;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);///黃色的
        drawmodel();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='1' || key=='w' || key=='W')now=1;
    if(key=='2' || key=='e' || key=='E')now=2;
    if(key=='3' || key=='r' || key=='R')now=3;
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(now==1){
        x+=(mouseX-oldX);y+=(mouseY-oldY);
    }
    else if(now==2){
        angle+=(mouseX-oldX);
    }
    else if(now==3){
        if(mouseX-oldX > 0)scale*=1.01;
        if(mouseX-oldX < 0)scale*=0.99;
    }
    ///if(mouseX-oldX>0)scale*=1.01;
    ///if(mouseX-oldX<0)scale*=0.99;
   ///x+= (mouseX-oldX);y+=(mouseY-oldY);
    oldX=mouseX; oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week08");

    glutDisplayFunc(display);///
    ///偷來的程式要放在glutCreatWindow()之後,才有效
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}
```
