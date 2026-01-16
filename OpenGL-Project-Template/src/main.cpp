#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<iostream>

//Vertex Shader
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

//Fragment Shader
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
    "}\n\0";

//Screen Resize
void Resize(GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h);
}

//Input Handling
void Input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    //GLFW Init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "My funny window", NULL, NULL);

    //Verticies Coordinates
    GLfloat vertices[] = 
    {
        0.0f, 0.7f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    //Check if Window Creation worked 
    if(window == NULL)
    {
        std::cout << "GLFW\n";
        glfwTerminate();
        return -1;
    }

    //Use the Window
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, Resize);

    //Check if GLAD is working
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Not glad to hear.\n";
        return -1;
    }

    //Initiate Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //Initiate Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //Create Shader Program
    GLuint ShaderProgram = glCreateProgram();
    glAttachShader(ShaderProgram, vertexShader);
    glAttachShader(ShaderProgram, fragmentShader);
    glLinkProgram(ShaderProgram);

    //Delete the shaders cuz they useless now
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //Vertext Array Object and Vertex Buffer Object
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    //Binding
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //Tell it to draw.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    //Uhmmm.... glueee. . . !
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    //So like.. use my data now???
    glEnableVertexAttribArray(0);

    //Binding Part 2
    glBindBuffer(GL_ARRAY_BUFFER, 0);   
    glBindVertexArray(0);

    //Main Loop
    while(!glfwWindowShouldClose(window))
    {
        //Input
        Input(window);

        //Rendering
        glClearColor(0.7f, 0.2f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(ShaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //Like. . . Very important
        glfwSwapBuffers(window); //Basically double buffering, updates the image on the screen and makes any motion not flickery
        glfwPollEvents(); //Listens for inpurs and stuff and triggers appropriate callbacks.
    }

    //Delete Trash
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(ShaderProgram);

    glfwTerminate();
    return 0;
}
