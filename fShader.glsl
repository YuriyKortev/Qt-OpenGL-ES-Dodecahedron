varying vec4 color;
in vec3 LightIntens;

void main()
{
    gl_FragColor=color*vec4(LightIntens,1.0);
}
