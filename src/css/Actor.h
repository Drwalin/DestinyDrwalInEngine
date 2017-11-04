
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
	
	virtual void operator = ( Actor * src );
	
	virtual Vector GetPhysicsAABB();
	virtual Vector GetGraphicAABB();
	
	virtual void Update( float deltaTime );
	
	virtual int GetBinaryLength();				// includes name and type (class)
	virtual int GetBinary( char * dst );		// includes name and type (class)
	virtual void SetFromBinary( const char * src, int len );	// includes name and type (class)
	
	Actor();
	~Actor();
};



