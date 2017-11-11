
#pragma once

class Texture
{
private:
	
	static const int Linear = 1;
	static const int Nearest = 2;
	
	std::string name;
	
	int mipMaps;
	
	/////////////////
	// OpenGL data //
	/////////////////
	
public:
	
	int Load( const std::string fileName, const std::string nameSrc, const int interpolationMode, const int mipMapsSrc );
	
	int Bind();
	void Destroy();
	
	Texture();
	~Texture();
};



