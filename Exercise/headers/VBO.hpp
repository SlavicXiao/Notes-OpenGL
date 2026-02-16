#pragma once
#ifndef VAO_HPP
#define VAO_HPP

#include<glad/glad.h>

class VBO
{
public:
    GLuint ID;
    VBO(GLfloat* vertices);
    void Bind();
    void Unbind();
    void Delete();
};

#endif