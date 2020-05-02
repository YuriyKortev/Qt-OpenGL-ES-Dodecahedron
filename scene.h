#ifndef SCENE_H
#define SCENE_H

#include <QtGui/QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <vector>
#include <QMatrix4x4>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QtMath>

#include "triangle.h"
#include "axes.h"
#include "bspline3d.h"
#include "dodecahedron.h"

struct Light{
    QVector4D light_pos;
    QVector3D la;
    QVector3D ld;
    QVector3D ls;
};

struct Material{
    QVector3D ka;
    QVector3D kd;
    QVector3D ks;
    float Shininess;
};

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    Scene(QWidget* parent=0);
    Bspline3d* surface;
    Dodecahedron* dode;

    void setProject(bool f);
    void setAngleX(GLfloat angle);
    void setAngleY(GLfloat angle);
    void setAngleZ(GLfloat angle);
    void setFace(bool f);
    void setAxes(bool f);
    void setScX(GLfloat sc);
    void setScY(GLfloat sc);
    void setScZ(GLfloat sc);
    void setTrX(GLfloat tr);
    void setTrY(GLfloat tr);
    void setTrZ(GLfloat tr);
    void setFill(bool f);
    void setResolution(int res);
    void setLight(float l);
    void setType(GLenum type);
    void setDeep(int d);
    void setMat(bool f);

    void setCamXY();
    void setCamXZ();
    void setCamYZ();
protected:



private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;


    QOpenGLShaderProgram* def_sh;
    QOpenGLShaderProgram* spline_sh;


    GLuint m_frame;

    Axes* a;

    GLfloat cam_angle;
    GLfloat cam_y;
    GLfloat cam_r;
    QPointF start;

    bool persp;
    bool face;
    bool axes;
    bool fill;
    bool mouse_flag;
    bool mat_flag;

    GLfloat angle_x;
    GLfloat angle_y;
    GLfloat angle_z;

    GLfloat tr_x;
    GLfloat tr_y;
    GLfloat tr_z;

    GLfloat sc_x;
    GLfloat sc_y;
    GLfloat sc_z;

    GLenum type;

    int deep;

    Light l;
    Material glnc,mat;
};


#endif // SCENE_H
