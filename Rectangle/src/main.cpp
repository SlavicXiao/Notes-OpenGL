#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cmath>

#include"shaderClass.hpp"
#include"VAO.hpp"
#include"VBO.hpp"
#include"EBO.hpp"

void Resize(GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h);
}

void Input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

GLfloat vertices[] = 
{
     0.5f,  0.5f, 0.0f, //top right
     0.5f, -0.5f, 0.0f, //bottm right
    -0.5f, -0.5f, 0.0f, //bottom left
    -0.5f,  0.5f, 0.0f  //top left
};

GLuint indices[]
{
    0, 1, 3,
    1, 2, 3
};

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "My funny window", NULL, NULL);

    if(window == NULL)
    {
        std::cout << "The window creation failed.";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, Resize);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "I am not glad to hear this.\n";
        return -1;
    }

    Shader shaderProgram("../shaders/default.vert", "../shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0, 3, 0);

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    while(!glfwWindowShouldClose(window))
    {
        Input(window);
        
        glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float timeValue = glfwGetTime();
        shaderProgram.Activate();

        float timeLocation = glGetUniformLocation(shaderProgram.ID, "Time");
        float colorLocaton1 = glGetUniformLocation(shaderProgram.ID, "Color1");
        float colorLocaton2 = glGetUniformLocation(shaderProgram.ID, "Color2");

        glUniform1f(timeLocation, timeValue);
        glUniform3f(colorLocaton1, 1.0f, 0.0f, 1.0f);
        glUniform3f(colorLocaton2, 0.0f, 1.0f, 1.0f);

        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwTerminate();    
    return 0;
}