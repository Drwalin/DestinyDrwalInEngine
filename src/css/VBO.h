
#pragma once

class VBO
{
private:
	
	const static int drawModeTriangle = 4;
	const static int drawModeLine = 3;
	const static int drawModePoints = 2;
	const static int drawModeNone = 1;
	
	class Vertex
	{
	private:
		Vector pos;
		Vector normal;
		float uvx, uvy;
		unsigned char r, g, b, a;
		
	public:
		Vertex( Vector posSrc, Vector normalSrc, float uvxSrc, float uvySrc, unsigned char rSrc, unsigned char gSrc, unsigned char bSrc, unsigned char aSrc );
		Vertex();
	};
	
	std::vector < Vertex > vertices;
	std::vector < int > indices;
	
	Texture * texture;
	
	bool useNormals;
	bool useTexture;
	bool useColors;
	
	int drawMode;		// if drawMode == drawModeNone then VBO wasn't generated
	
	//////////////////////
	// some OpenGL data //
	//////////////////////
	
public:
	
	int AddVertex( const Vector p, const Vector normal, const float uvx, const float uvy, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const float uvx, const float uvy, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const Vector normal, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const Vector normal, const float uvx, const float uvy );
	int AddVertex( const Vector p, const float uvx, const float uvy );
	int AddVertex( const Vector p, const Vector normal );
	int AddVertex( const Vector p );
	void AddIndice( const int id );
	
	void Generate( const int drawModeSrc, const Texture * textureSrc, const bool useNormalsSrc, const bool useTextureSrc, const bool useColorsSrc );
	
	void Draw() const;
	
	void ClearMemory();
	void Destroy();
	
	VBO();
	~VBO();
};



