#include <GL/glut.h>
#include <stdio.h>///printf()�L�F��Ϊ�
float mouseX=0,mouseY=0;///�s�[��

void myTeapot(float x,float y)
{
    glPushMatrix();///�ƥ��x�}
    ///���ʷ|�ֿn�A�]�����|�ק�x�}
       // glTranslatef(0.5,0.5,0);///�k�W��
        glTranslatef(x,y,0);///
        glColor3f(1,1,0);///����
        glutSolidTeapot(0.1);///����
    glPopMatrix();///�٭�x�}(�٭��ª���m)
}
void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0);///�s�[��
     glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    printf("%d %d %d %d\n",button,state,x,y);
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
