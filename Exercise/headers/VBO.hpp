#pragma once
#ifndef VAO_HPP
#define VAO_HPP

#include<glad/glad.h>

class VBO
{
public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size);
    void Bind();
    void Unblind();
    void Delete();
};

#endif