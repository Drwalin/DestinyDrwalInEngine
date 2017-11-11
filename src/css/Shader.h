
#pragma once

class Shader
{
private:
	
	std::string name;
	
	std::map < std::string, std::string > arguments;		// ???
	
	/////////////////
	// OpenGL data //
	/////////////////
	
public:
	
	int LoadGeometryShader( const std::string fileName );
	int LoadVertexShader( const std::string fileName );
	int LoadFragmentShader( const std::string fileName );
	
	int BindArguments( const std::string argumentName, const void * data, const int dataLen );
	int Bind();
	void Destroy();
	
	Shader();
	~Shader();
};



