#ifndef VAO_CLASS_HPP
#define VAO_CLASS_HPP

#include<glad/glad.h>
#include"VBO.hpp"

class VAO
{
public:
	GLuint ID;
	VAO();

	void LinkVBO(VBO& VBO, GLuint layout);
	
	void Bind();
	void Unbind();
	void Delete();
};
#endif