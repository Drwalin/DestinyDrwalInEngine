
#pragma once

class StaticActor : public Actor
{
private:
	
	std::vector < std::string > hitSoundName;
	std::vector < Triangle* > triangle;
	Octtree < Triangle* > octtree;
	
	float frictionFactor;
	
public:
	
	void DrawDebug();
	
	void FromOBJData( 
	
	void FromPhysicsBody( const PhysicsBody * src );
	
	void Rotate( const Vector origin, const Vector rotator );
	void Move( const Vector );
	
	int GetBinaryLength();				// includes name,
	int GetBinary( char * binary );		// includes name, paste binary data at this point in memory
	void SetBinary( const char * binary, const int len );	// includes name
	
	
	
	StaticActor();
	~StaticActor();
};



