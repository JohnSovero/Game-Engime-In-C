#pragma once
#include <GL/glew.h>
#include <string>
using namespace std;

class HLSLProgram
{
private:
	GLuint programID;
	GLuint fragmentShaderID;
	GLuint vertexShaderID;
	int numAtribute;
	void compileShader(const string& shaderPath, GLuint id);
public:
	HLSLProgram();
	~HLSLProgram();
	void addAtribute(const string attributeName);
	void use();
	void unuse();
	void compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath);
	void linkShader();
	GLuint getUniformLocation(const string& name);
};

