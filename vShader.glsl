#version 330 core

layout(location=0) in vec4 vertexAttr;
layout(location=1) in vec3 colorAttr;
layout(location=2) in vec3 normAttr;

uniform mat4 matrix;
uniform mat3 normal_m;
uniform mat4 modelview;

uniform vec4 LightPos;
uniform vec3 kd;
uniform vec3 ld;


out vec3 color;
out vec3 LightIntens;
void main()
{
    vec3 tnorm=normalize(normal_m*normAttr);
    vec4 eyecoord=modelview*vertexAttr;

    vec3 s=normalize(vec3(LightPos-eyecoord));

    LightIntens=ld*kd*max(dot(s,tnorm),0.0);

    gl_Position=matrix * vertexAttr;
    color=colorAttr;
}
