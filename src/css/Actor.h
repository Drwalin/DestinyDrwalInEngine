
#pragma once

class Actor
{
private:
	
	World * world;
	std::string name;
	
	Vector pos;
	Vector bpos;
	
	int currentAnimationId;
	float currentAnimationTime;
	GraphicBody * graphicBody;
	
public:
	
	virtual void Draw();
	virtual void DrawDebug();
	
	virtual void Set( Actor * src );
	
	virtual Vector GetPhysicsAABB();
	virtual Vector GetGraphicAABB();
	
	virtual void Update( float deltaTime );
	
	virtual int GetBinaryLength();				// includes name, type (class),
	virtual int GetBinary( char * binary );		// includes name and type (class), paste binary data in this pointer
	virtual void SetBinary( const char * binary, int len );	// includes name and type (class)
	
	static void IsBinaryDynamicActor( const char * binary, int len );
	static void IsBinaryStaticActor( const char * binary, int len );
	
	Actor();
	~Actor();
};



