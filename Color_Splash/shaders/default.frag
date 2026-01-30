#version 330 core
out vec4 FragColor;

in vec3 Color;
uniform float Time;

void main()
{
   float redChange = sin(Time * 3.0);
   float blueChange = sin(Time);
   float greenChange = sin(Time * 2.0);

   vec3 change = vec3(redChange, greenChange, blueChange);
   vec3 final = Color * change;
   
   FragColor = vec4(final, 1.0);
}