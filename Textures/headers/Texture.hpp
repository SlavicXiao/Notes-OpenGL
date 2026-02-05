#include<glad/glad.h>
#pragma once

class Texture
{
    public:
        GLuint ID;
        Texture(GLuint id, const char* path, int imgWidth, int imgHeight, int numColCh);
};