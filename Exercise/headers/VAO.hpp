#pragma once

#include<glad/glad.h>
#include"VBO.hpp"

class VAO
{
public:
    GLuint ID;
    VAO();
    void LinkVBO(VBO& VBO1, GLuint layout, GLuint stride, GLuint ptr);
    void Bind();
    void Unbind();
    void Delete();
};