#include"VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO& VBO1, GLuint layout, GLuint stride, GLuint ptr)
{
    VBO1.Bind();

    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(ptr * sizeof(float)));
    glEnableVertexAttribArray(layout);
    
    VBO1.Unbind();
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