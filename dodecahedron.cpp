#include "dodecahedron.h"


Dodecahedron::Dodecahedron()
{

    resolution=1;
    p_on_face=5;

    points={
        {1, 1, 1},
            {1, 1, -1},
            {1, -1, 1},
            {1, -1, -1},
            {-1, 1, 1},
            {-1, 1, -1},
            {-1, -1, 1},
            {-1, -1, -1},
            {0, 0.618, 1.618},
            {0, 0.618, -1.618},
            {0, -0.618, 1.618},
            {0, -0.618, -1.618},
            {0.618, 1.618, 0},
            {0.618, -1.618, 0},
            {-0.618, 1.618, 0},
            {-0.618, -1.618, 0},
            {1.618, 0, 0.618},
            {1.618, 0, -0.618},
            {-1.618, 0, 0.618},
            {-1.618, 0, -0.618}
    };

    ind={
        {0, 16, 2, 10, 8},
        {0, 8, 4, 14, 12},
        {0, 12, 1, 17, 16},
        {1, 9, 11, 3, 17},
        {1, 12, 14, 5, 9},
        {2, 13, 15, 6, 10},
        {2, 16, 17, 3, 13},
        {3, 11, 7, 15, 13},
        {4, 8, 10, 6, 18},
        {4, 18, 19, 5, 14},
        {5, 19, 7, 11, 9},
        {15, 7, 19, 18, 6}
    };

    start_p=points;
    start_ind=ind;

    crNormals();
}

void Dodecahedron::drawDode(QOpenGLShaderProgram* m_program, GLenum mode, GLenum type)
{



    initializeOpenGLFunctions();

    m_program->bind();


    m_program->setAttributeArray(0, points.data());
    m_program->setAttributeArray(2,normals.data());
    m_program->setAttributeValue("colorAttr",{0.4f,0.3f,0.1f});

    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(2);



    for(int i=0;i<12;i++){
        glPolygonMode(GL_FRONT_AND_BACK,mode);
        glDrawElements(type,p_on_face,GL_UNSIGNED_SHORT,ind[i].data());
    }

    //glDrawArrays(GL_LINE_STRIP,0,2);

    m_program->disableAttributeArray( 0);
    m_program->disableAttributeArray(2);
    m_program->release();


}

void Dodecahedron::setResolution(int res)
{

    points=start_p;
    ind=start_ind;
    p_on_face=5;

    if(res==1){
        this->resolution=1;
        crNormals();
        return;
    }


    this->resolution=res;
    for(int i=0;i<12;i++){
        int new_p_on_face=p_on_face;
        for(int j=0;j<new_p_on_face-1;j+=this->resolution){
            QVector3D fp=points[ind[i][j]];
            QVector3D edge=points[ind[i][j+1]]-fp;
            for(int k=1;k<this->resolution;k++){
                QVector3D new_p=fp+ edge*(float)k/(float)this->resolution;
                if(!points.contains(new_p)){
                    points.append(new_p);
                    ind[i].insert(j+k,points.size()-1);
                    new_p_on_face++;
                }
                else{
                    ind[i].insert(j+k,points.indexOf(new_p));
                    new_p_on_face++;
                }

            }

        }

        QVector3D fp=points[ind[i].last()];
        QVector3D edge=points[ind[i].first()]-fp;
        for(float k=1;k<this->resolution;k++){
            QVector3D new_p=fp+edge*k/this->resolution;
            if(!points.contains(new_p)){
                points.append(new_p);
                ind[i].push_back(points.size()-1);
                new_p_on_face++;
            }
            else{
                ind[i].push_back(points.indexOf(new_p));
                new_p_on_face++;
            }
        }

    }
    p_on_face=5*resolution;

    crNormals();
}

void Dodecahedron::crNormals()
{
    QVector<QVector3D> nrmls;

    for(int i=0;i<points.size();i++){
        nrmls.append(points[i]);
    }

    normals=nrmls;
}
