
#pragma once

class PhysicsBody
{
private:
	
	std::vector < std::string > hitSoundName;
	
	std::vector < Vector > vertices;
	std::vector < Triangle > triangle;
	
public:
	
	void DrawDebug();
	
	void FromOBJData( 
	
	void FromPhysicsBody( PhysicsBody * src );
	
	int GetBinaryLength();				// includes name,
	int GetBinary( char * binary );		// includes name, paste binary data at this point in memory
	void SetBinary( const char * binary, int len );	// includes name
	
	PhysicsBody();
	~PhysicsBody();
};



