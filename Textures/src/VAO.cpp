#include"VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint Components, GLenum type, GLsizeiptr stride, void* offset)
{
    VBO.Bind();

    glVertexAttribPointer(layout, Components, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);

    VBO.Unbind();
}

void VAO::Bind()
{
    glBindVertexArray(ID);
}

void VAO::Unbind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}