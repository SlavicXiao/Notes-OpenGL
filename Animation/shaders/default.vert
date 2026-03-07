#version 330 core
layout(location = 0) in vec3 Position;
uniform float Time;

void main()
{
    gl_Position = vec4(Position.x + cos(Time) / 2, Position.y + sin(Time) * sin(Time) / 2, Position.z, 1.0);
}