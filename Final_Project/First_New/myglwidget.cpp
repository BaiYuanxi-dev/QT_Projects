#include "myglwidget.h"
#include<GL/glu.h>
#include<QKeyEvent>
#include <QTimer>
MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    fullscreen = false;
    m_rtri = 0.0f;
    m_rquad = 0.0f;

    QTimer *timer = new QTimer(this);                   //创建一个定时器
    //将定时器的计时信号与updateGL()绑定
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);

}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::initializeGL()                         //此处开始对OpenGL进行所以设置
{
    glClearColor(0.0, 0.0, 0.0, 0.0);                   //黑色背景,4个参数分别用来设置红、绿、蓝颜色分量和Alpha值，它们的取值范围都是0.0~1.0
    glShadeModel(GL_SMOOTH);                            //启用阴影平滑


    //接下来的三行必须做的是关于depth buffer（深度缓存）的。将深度缓存设想为屏幕后面的层。
    //深度缓存不断地对物体进入屏幕内部有多深进行跟踪。
    //我们本节的程序其实没有真正的使用深度缓存，但几乎所有在屏幕上显示3D场景OpenGL程序都使用深度缓存。
    //它的排序决定那个物体先画。这样就不会将一个圆形后面的正方形画到圆形前面来。深度缓存是OpenGL十分重要的部分。
    //最后我们希望进行最好的透视修正。这会十分轻微的影响性能，但使得透视图看起来好一点。
    glClearDepth(1.0);                                  //设置深度缓存
    glEnable(GL_DEPTH_TEST);                            //启用深度测试
    glDepthFunc(GL_LEQUAL);                             //所作深度测试的类型
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  //告诉系统对透视进行修正
}

void MyGLWidget::resizeGL(int w, int h)                 //重置OpenGL窗口的大小
{
    glViewport(0, 0, (GLint)w, (GLint)h);               //重置当前的视口
    glMatrixMode(GL_PROJECTION);                        //选择投影矩阵,投影矩阵用来为场景增加透视
    glLoadIdentity();                                   //重置投影矩阵,这样可以将投影矩阵恢复到初始状态
    //设置视口的大小
    //纵横比为窗口的纵横比，最近的位置为0.1，最远的位置为100，这两个值是场景中所能绘制的深度的临界值。
    gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0);//设置透视投影矩阵,这里设置视角为45°,
    glMatrixMode(GL_MODELVIEW);                         //选择模型观察矩阵
    glLoadIdentity();                                   //重置模型观察矩阵
}


void MyGLWidget::paintGL()                              //从这里开始进行所以的绘制
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕和深度缓存
    glLoadIdentity();                                   //重置当前的模型观察矩阵

    glTranslatef(-1.5f, 0.0f, -6.0f);                   //左移1.5单位，并移入屏幕6.0单位
    glRotatef(m_rtri, 1.0f, 1.0f, 0.0f);                //绕y轴旋转三角形
    glBegin(GL_TRIANGLES);                              //开始绘制金字塔
        glColor3f(1.0f, 0.0f, 0.0f);                    //红色
        glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(前侧面)
        glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
        glVertex3f(-1.0f, -1.0f, 1.0f);                 //左下(前侧面)
        glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
        glVertex3f(1.0f, -1.0f, 1.0f);                  //右下(前侧面)

        glColor3f(1.0f, 0.0f, 0.0f);                    //红色
        glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(右侧面)
        glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
        glVertex3f(1.0f, -1.0f, 1.0f);                  //左下(右侧面)
        glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
        glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(右侧面)

        glColor3f(1.0f, 0.0f, 0.0f);                    //红色
        glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(后侧面)
        glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
        glVertex3f(1.0f, -1.0f, -1.0f);                 //左下(后侧面)
        glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
        glVertex3f(-1.0f, -1.0f, -1.0f);                //右下(后侧面)

        glColor3f(1.0f, 0.0f, 0.0f);                    //红色
        glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点(左侧面)
        glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
        glVertex3f(-1.0f, -1.0f, -1.0f);                //左下(左侧面)
        glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
        glVertex3f(-1.0f, -1.0f, 1.0f);                 //右下(左侧面)
    glEnd();                                            //金字塔绘制结束

    glLoadIdentity();                                   //重置模型观察矩阵
    glTranslatef(1.5f, 0.0f, -6.0f);                    //右移1.5单位，并移入屏幕6.0单位
    glRotatef(m_rquad, 1.0f, 0.0f, 0.0f);               //绕x轴旋转四边形
    glBegin(GL_QUADS);                                  //开始绘制立方体
        glColor3f(0.0f, 1.0f, 0.0f);                    //绿色
        glVertex3f(1.0f, 1.0f, -1.0f);                  //右上(顶面)
        glVertex3f(-1.0f, 1.0f, -1.0f);                 //左上(顶面)
        glVertex3f(-1.0f, 1.0f, 1.0f);                  //左下(顶面)
        glVertex3f(1.0f, 1.0f, 1.0f);                   //右下(顶面)

        glColor3f(1.0f, 0.5f, 0.0f);                    //橙色
        glVertex3f(1.0f, -1.0f, 1.0f);                  //右上(底面)
        glVertex3f(-1.0f, -1.0f, 1.0f);                 //左上(底面)
        glVertex3f(-1.0f, -1.0f, -1.0f);                //左下(底面)
        glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(底面)

        glColor3f(1.0f, 0.0f, 0.0f);                    //红色
        glVertex3f(1.0f, 1.0f, 1.0f);                   //右上(前面)
        glVertex3f(-1.0f, 1.0f, 1.0f);                  //左上(前面)
        glVertex3f(-1.0f, -1.0f, 1.0f);                 //左下(前面)
        glVertex3f(1.0f, -1.0f, 1.0f);                  //右下(前面)

        glColor3f(1.0f, 1.0f, 0.0f);                    //黄色
        glVertex3f(1.0f, -1.0f, -1.0f);                 //右上(后面)
        glVertex3f(-1.0f, -1.0f, -1.0f);                //左上(后面)
        glVertex3f(-1.0f, 1.0f, -1.0f);                 //左下(后面)
        glVertex3f(1.0f, 1.0f, -1.0f);                  //右下(后面)

        glColor3f(0.0f, 0.0f, 1.0f);                    //蓝色
        glVertex3f(-1.0f, 1.0f, 1.0f);                  //右上(左面)
        glVertex3f(-1.0f, 1.0f, -1.0f);                 //左上(左面)
        glVertex3f(-1.0f, -1.0f, -1.0f);                //左下(左面)
        glVertex3f(-1.0f, -1.0f, 1.0f);                 //右下(左面)

        glColor3f(1.0f, 0.0f, 1.0f);                    //紫色
        glVertex3f(1.0f, 1.0f, -1.0f);                  //右上(右面)
        glVertex3f(1.0f, 1.0f, 1.0f);                   //左上(右面)
        glVertex3f(1.0f, -1.0f, 1.0f);                  //左下(右面)
        glVertex3f(1.0f, -1.0f, -1.0f);                 //右下(右面)
    glEnd();                                            //立方体绘制结束

    m_rtri -= 0.5f;                                     //增加金字体的旋转变量
    m_rquad += 0.5f;                                    //减少立方体的旋转变量
}

//void MyGLWidget::paintGL()                              //从这里开始进行所以的绘制
//{
////    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕和深度缓存
////    glLoadIdentity();                                   //重置当前的模型观察矩阵
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕和深度缓存
//    glLoadIdentity();                                   //重置当前的模型观察矩阵

//    //当调用了glLoadIdentity()之后，我们实际上将当前点移到了屏幕中心，x轴从左到右，y轴从下到上，z轴从里到外。其中，中心右面，上面，外面的坐标值为正值。
//    glTranslatef(-1.5f, 0.0f, -6.0f);                   //左移1.5单位，并移入屏幕6.0单位

//    glRotatef(m_rtri, 0.0f, 1.0f, 0.0f);                //绕y轴旋转三角形

//    glBegin(GL_TRIANGLES);                              //开始绘制三角形triangles

//    glColor3f(1.0f, 0.0f, 0.0f);                        //设置当前色为红色
//        glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点
//        glColor3f(0.0f, 1.0f, 0.0f);                    //设置当前色为绿色
//        glVertex3f(-1.0f, -1.0f, 0.0f);                 //左下
//        glColor3f(0.0f, 0.0f, 1.0f);                    //设置当前色为蓝色
//        glVertex3f(1.0f, -1.0f, 0.0f);                  //右下
//    glEnd();                                            //三角形绘制结束

//    glLoadIdentity();                                   //重置模型观察矩阵
//    glTranslatef(1.5f, 0.0f, -6.0f);                    //右移1.5单位，并移入屏幕6.0单位
//    glRotatef(m_rquad, 1.0f, 0.0f, 0.0f);               //绕x轴旋转四边形
//    glBegin(GL_QUADS);                                  //开始绘制四边形quads
//        glVertex3f(-1.0f, 1.0f, 0.0f);                  //左上
//        glVertex3f(1.0f, 1.0f, 0.0f);                   //右上
//        glVertex3f(1.0f, -1.0f, 0.0f);                  //左下
//        glVertex3f(-1.0f, -1.0f, 0.0f);                 //右下
//    glEnd();

//    //如果想要画更多的顶点时，可以使用GL_POLYGON

//    m_rtri += 0.5f;                                     //增加三角形的旋转变量
//    m_rquad -= 0.5f;                                    //减少四边形的旋转变量
//}

void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    //F1为全屏和普通屏的切换键
    case Qt::Key_F1:
        fullscreen = !fullscreen;
        if (fullscreen)
        {
            showFullScreen();
        }
        else
        {
            showNormal();
        }
        updateGL();
        break;
    //ESC为退出键
    case Qt::Key_Escape:
        close();
    }
}
void MyGLWidget::mousePressEvent(QMouseEvent *event){
    //在这里进入新的界面，这个界面将会是游戏开始的主界面，并且会经常利用
    //第二种想法：点击后只修改一个参数，然后在外面的主控制里创建游戏主界面
    //相当于发出一个信号
    this->close();
    emit this->gameIn();
}
