#version 330 core

layout(location=0) in vec4 vertexAttr;
layout(location=1) in vec3 colorAttr;
layout(location=2) in vec3 normAttr;




uniform mat4 matrix;
uniform mat3 normal_m;
uniform mat4 modelview;

out vec3 color;
out vec3 tnorm;
out vec3 eyecoord;
void main()
{

    tnorm=normalize(normal_m*normAttr);
    eyecoord=vec3(modelview*vertexAttr);

    gl_Position=matrix * vertexAttr;
    color=colorAttr;
}
