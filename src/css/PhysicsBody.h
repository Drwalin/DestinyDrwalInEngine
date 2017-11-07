
#pragma once

class PhysicsBody
{
private:
	
	std::string hitSoundName;
	
	std::vector < Vector > vertices;
	std::vector < Triangle > triangle;
	
public:
	
	void DrawDebug();
	
	void FromOBJData( 
	
	int GetBinaryLength();				// includes name, type (class),
	int GetBinary( char * binary );		// includes name and type (class), paste binary data in this pointer
	void SetBinary( const char * binary, int len );	// includes name and type (class)
	
	PhysicsBody();
	~PhysicsBody();
};



