#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>

#include <QGLWidget>
#include <QMouseEvent>
class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = nullptr);
    ~MyGLWidget();
protected:
    //对3个纯虚函数的重定义
    //设置OpenGL渲染环境，定义显示列表等。该函数只在第一次调用resizeGL()或paintGL()前被自动调用一次。
    void initializeGL();
    //设置OpenGL的视口、投影等。每次部件改变大小时都会自动调用该函数。
    void resizeGL(int w, int h);
    //渲染OpenGL场景。每当部件需要更新时都会调用该函数。
    void paintGL();

    void keyPressEvent(QKeyEvent *event);           //处理键盘按下事件

    void mousePressEvent(QMouseEvent *event);        //单击
private:
    bool fullscreen;                                //是否全屏显示
    GLfloat m_rtri;                                 //控制三角形的角度
    GLfloat m_rquad;                                //控制四边形的角度
signals:
    void gameIn();
};

#endif // MYGLWIDGET_H
