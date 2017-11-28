
#pragma once

class Texture
{
public:
	
	static const int Linear = 1;
	static const int Nearest = 2;
	
private:
	
	std::string name;
	
	int mipMaps;
	int interpolationMode;
	
	
	
	/////////////////
	// OpenGL data //
	/////////////////
	
	ALLEGRO_BITMAP * bitmap;
	
public:
	
	int Load( const std::string fileName, const std::string nameSrc, const int interpolationModeSrc, const int mipMapsSrc );
	
	int Bind() const;
	void Destroy();
	
	Texture();
	~Texture();
};



