#version 330 core
out vec4 FragColor;

uniform vec3 Color1;
uniform vec3 Color2;
uniform float Time;

void main()
{
   float pulse = (sin(2 * Time + 5));
   vec3 Color = mix(Color1, Color2, pulse);
   FragColor = vec4(Color, 1.0);
}