#include <GL/glut.h>///�ϥ�GLUT�~��²�Ƶ{��
float angle=0,oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�e�ϫe���M�e��
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);///��ߪ�����
    glPopMatrix();
    glutSwapBuffers();///�e�n��洫�X��
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    display();
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;///�w��
}
int main(int argc,char** argv)///main()�D�禡 �i����
{
    glutInit(&argc,argv);///��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("week02_1");///�}GLUT����

    glutDisplayFunc(display);///�Ψ���ܪ��禡
    glutMotionFunc(motion);///mouse motion��
    glutMouseFunc(mouse);///�W�P��:mouse���U�h�B��}��
    glutMainLoop();///�D�n���{���j��
}
