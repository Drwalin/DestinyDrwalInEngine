
#pragma once

#define CUSTOM_FULL_FVF ( D3DFVF_XYZ | D3DFVF_DIFFUSE | ((texture!=NULL)?D3DFVF_TEX1:0) )

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
	int verticesNumber;
	
	Texture * texture;	// NULL if do not want to use texture
	
	bool useNormals;
	//bool useTexture;
	
	
	int primitiveType;		// if primitiveType == drawModeNone then VBO wasn't generated
	
	
	
	bool generated;
	//////////////////////
	// some OpenGL data //
	//////////////////////
	LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
	void * pVoid;
	
	void ClearMemory();
	
public:
	
	D3DPRIMITIVETYPE GetPrimitiveType() const;
	int GetVerticesCountPerPrimitive() const;
	bool GeneratrdGood() const;
	
	int AddVertex( const Vector p, const Vector normal, const float uvx, const float uvy, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const float uvx, const float uvy, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const Vector normal, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 );
	int AddVertex( const Vector p, const Vector normal, const float uvx, const float uvy );
	int AddVertex( const Vector p, const float uvx, const float uvy );
	int AddVertex( const Vector p, const Vector normal );
	int AddVertex( const Vector p );
	
	void Generate( const int drawModeSrc, const Texture * textureSrc, const bool useNormalsSrc );
	
	void Draw() const;
	
	void Destroy();
	
	VBO();
	~VBO();
};



