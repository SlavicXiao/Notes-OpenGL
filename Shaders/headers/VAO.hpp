#pragma once
#include<glad/glad.h>
#include"VBO.hpp"

class VAO
{
    public:
        GLuint ID;
        VAO();
        
        void LinkVBO(VBO& VBO, GLuint layout, GLuint num, GLuint num2);

        void Bind();
        void Unbind();
        void Delete();
};