
#pragma once

class VBO
{
private:
	
	const static int drawModeTriangle = 3;
	const static int drawModeLine = 2;
	const static int drawModePoints = 1;
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
	
	int AddVertex( Vector p, Vector normal, float uvx, float uvy, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255 );
	int AddVertex( Vector p, float uvx, float uvy, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255 );
	int AddVertex( Vector p, Vector normal, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255 );
	int AddVertex( Vector p, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255 );
	int AddVertex( Vector p, Vector normal, float uvx, float uvy );
	int AddVertex( Vector p, float uvx, float uvy );
	int AddVertex( Vector p, Vector normal );
	int AddVertex( Vector p );
	void AddIndice( int id );
	
	void Generate( const int drawModeSrc, const Texture * textureSrc, const bool useNormalsSrc, const bool useTextureSrc, const bool useColorsSrc );
	
	void Draw() const;
	
	void ClearMemory();
	void Destroy();
	
	VBO();
	~VBO();
};



