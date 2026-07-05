 #include<Texture.hpp>
 #include<glad/glad.h>
 #include<stb_image.h>
 #include<iostream>
 
    Texture::Texture(GLuint id, const char* path, int imgWidth, int imgHeight, int numColCh)
    {
        unsigned char* bytes = stbi_load(path, &imgWidth, &imgHeight, &numColCh, 0);
        Texture::ID = id;

        if (!bytes)
        {
            std::cout << "Failed to load texture\n";
            std::cout << stbi_failure_reason() << std::endl;
        }

        stbi_set_flip_vertically_on_load(true);

        glGenTextures(1, &ID);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        GLenum format = (numColCh == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, imgWidth, imgHeight, 0, format, GL_UNSIGNED_BYTE, bytes);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        stbi_image_free(bytes);
        glBindTexture(GL_TEXTURE_2D, 0);

    }
    