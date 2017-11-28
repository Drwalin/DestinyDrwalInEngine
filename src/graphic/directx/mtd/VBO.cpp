
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
	int verticesNumber;
	
	Texture * texture;	// NULL if do not want to use texture
	
	bool useNormals;
	bool useColors;
	
	int drawMode;		// if drawMode == drawModeNone then VBO wasn't generated
	
	
	
	//////////////////////
	// some OpenGL data //
	//////////////////////
	LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
	void * pVoid;
}

VBO::Vertex::Vertex( Vector posSrc, Vector normalSrc, float uvxSrc, float uvySrc, unsigned char rSrc, unsigned char gSrc, unsigned char bSrc, unsigned char aSrc )
{
	pos = posSrc;
	normal = normalSrc;
	uvx = uvxSrc;
	uvy = uvySrc;
	r = rSrc;
	g = gSrc;
	b = bSrc;
	a = aSrc;
}

VBO::Vertex::Vertex()
{
	memset( this, 0, sizeof(VBO::Vertex) );
}

int VBO::AddVertex( const Vector p, const Vector normal, const float uvx, const float uvy, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, normal, uvx, uvy, r, g, b, a );
	return vertices.size() - 1;
}

int VBO::AddVertex( const Vector p, const float uvx, const float uvy, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, Vector(0.0f,0.0f,0.0f), uvx, uvy, r, g, b, a );
	return vertices.size() - 1;
}

int VBO::AddVertex( const Vector p, const Vector normal, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, normal, 0.0f, 0.0f, r, g, b, a );
	return vertices.size() - 1;
}

int VBO::AddVertex( const Vector p, const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 255 )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, Vector(0.0f,0.0f,0.0f), 0.0f, 0.0f, r, g, b, a );
	return vertices.size() - 1;
}

int VBO::AddVertex( const Vector p, const Vector normal, const float uvx, const float uvy )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, Vector(0.0f,0.0f,0.0f), uvx, uvy, 255, 255, 255, 255 );
	return vertices.size() - 1;
}

int VBO::AddVertex( const Vector p, const float uvx, const float uvy )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, Vector(0.0f,0.0f,0.0f), uvx, uvy, 255, 255, 255, 255 );
	return vertices.size() - 1;
}

int VBO::AddVrtex( const Vector p, const Vector normal )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, normal, 0.0f, 0.0f, 255, 255, 255, 255 );
	return vertices.size() - 1;
}

int VBO::AddVertex( const Vector p )
{
	vertices.resize( vertices.size() + 1 );
	vertices.back() = VBO::Vertex( p, Vector(0.0f,0.0f,0.0f), 0.0f, 0.0f, 255, 255, 255, 255 );
	return vertices.size() - 1;
}

D3DPRIMITIVETYPE VBO::GetPrimitiveType() const
{
	switch( primitiveType )
	{
	case drawModePoints:
		return D3DPT_POINTLIST;
	case drawModeLine:
		return D3DPT_LINELIST;
	case drawModeTriangle:
		return D3DPT_TRIANGLELIST;
	}
	return D3DPT_POINTLIST;
}

int VBO::GetVerticesCountPerPrimitive() const
{
	switch( primitiveType )
	{
	case drawModePoints:
		return 1;
	case drawModeLine:
		return 2;
	case drawModeTriangle:
		return 3;
	}
	return 1;
}

bool VBO::GoodPrimitive() const
{
	switch( primitiveType )
	{
	case drawModePoints:
		return true;
	case drawModeLine:
		return true;
	case drawModeTriangle:
		return true;
	}
	return false;
}

void VBO::Generate( const int drawModeSrc, const Texture * textureSrc, const bool useNormalsSrc )
{
	Destroy();
	drawMode = drawModeSrc;
	texture = textureSrc;
	verticesNumber = vertices.size();
	if( verticesNumber > 0 && GoodPrimitive() )
	{
		GetD3DDevice()->CreateVertexBuffer( verticesNumber * sizeof(VBO::Vertex), 0, CUSTOM_FULL_FVF, D3DPOOL_DEFAULT, &vertexBuffer, NULL );
		vertexBuffer->Lock( 0, sizeof(VBO::Vertex)*verticesNumber, (void**)&pVoid, 0 );
		memcpy( pVoid, vertices.begin(), sizeof(VBO::Vertex)*verticesNumber );
		vertexBuffer->Unlock();
		generated = true;
		ClearMemory();
	}
}

void VBO::Draw() const
{
	if( generated && GoodPrimitive() )
	{
		GetD3DDevice()->SetFVF( CUSTOM_FULL_FVF );
		GetD3DDevice()->SetStreamSource( 0, vertexBuffer, 0, sizeof(VBO::Vertex) );
		GetD3DDevice()->DrawPrimitive( GetPrimitiveType(), 0, verticesNumber / GetVerticesCountPerPrimitive() );
	}
}

void VBO::ClearMemory()
{
	vertices.clear();
	vertices.shrink_to_fit();
}

void VBO::Destroy()
{
	if( generated )
		vertexBuffer->Release();
	generated = false;
	verticesNumber = 0;
	primitiveType = 0;
}

VBO::VBO()
{
	verticesNumber = 0;
	texture = NULL;
	useNormals = false;
	primitiveType = 0;
	generated = false;
	pVoid = NULL;
}

VBO::~VBO()
{
	Destroy();
	texture = NULL;
	useNormals = false;
	pVoid = NULL;
}



