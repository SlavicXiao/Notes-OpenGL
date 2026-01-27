#include"VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO& VBO, GLuint layout, GLuint num, GLuint num2)
{
    VBO.Bind();

    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, num * sizeof(float), (void*)(num2 * sizeof(float)));
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