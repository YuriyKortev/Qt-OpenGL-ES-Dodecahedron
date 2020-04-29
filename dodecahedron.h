#ifndef DODECAHEDRON_H
#define DODECAHEDRON_H

#include <QVector>
#include <QVector3D>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include <QOpenGLBuffer>

class Dodecahedron: protected QOpenGLFunctions
{
public:
    Dodecahedron();
    ~Dodecahedron();

    void drawDode(QOpenGLShaderProgram* m_program,GLenum mode,GLenum type);
    void setResolution(int resolution);

private:
    QVector<QVector3D> start_p;
    QVector<QVector<GLushort>> start_ind;

    QVector<QVector3D> points;
    QVector<QVector3D> normals;
    QVector<QVector<GLushort>> ind;

    void crNormals();

    int p_on_face;
    int resolution;
};

#endif // DODECAHEDRON_H
