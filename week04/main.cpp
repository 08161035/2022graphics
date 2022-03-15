#include <GL/glut.h>///使用GLUT外掛簡化程式
float angle=0,oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫圖前先清畫面
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);///實心的茶壺
    glPopMatrix();
    glutSwapBuffers();///畫好後交換出來
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    display();
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;///定錨
}
int main(int argc,char** argv)///main()主函式 進階版
{
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week02_1");///開GLUT視窗

    glutDisplayFunc(display);///用來顯示的函式
    glutMotionFunc(motion);///mouse motion動
    glutMouseFunc(mouse);///上周教:mouse按下去、放開來
    glutMainLoop();///主要的程式迴圈
}
