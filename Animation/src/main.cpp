#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>

#include"VBO.hpp"
#include"VAO.hpp"
#include"EBO.hpp"
#include"Shader.hpp"

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    float vertices[] = 
    {
        -0.05f,  0.05f, 0.0f,
         0.05f,  0.05f, 0.0f,
         0.05f, -0.05f, 0.0f,
        -0.05f, -0.05f, 0.0f
    };

    GLuint indices[] = 
    {
        3, 0, 1,
        1, 3, 2
    };

    GLFWwindow* window = glfwCreateWindow(800, 800, "My funny window", NULL, NULL);

    if(window == NULL)
    {
        std::cout << "Winodw creation failed\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "I am NOT glad to hear this.\n";
        return -1;
    }

    Shader shader("../shaders/default.vert", "../shaders/default.frag");

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
        //Input here

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Activate();

        float timeValue = glfwGetTime() * 10;

        float timeLocation = glGetUniformLocation(shader.ID, "Time");

        glUniform1f(timeLocation, timeValue);

        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shader.Delete();

    glfwTerminate();
    return 0;
}