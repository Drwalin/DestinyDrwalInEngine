
#pragma once

class Engine
{
private:
	
	World * world;
	
	std::string name;
	
	std::map < std::string, PhysicsBody * > physicsBody;
	std::map < std::string, GraphicBody * > graphicBody;
	std::map < std::string, Texture * > texture;
	
	unsigned char * threadsData;
	int threadsDataLength;
	
	float framesPerSecond;
	int framesCounter;
	int lastChecked
	
	FunctionVoidFloat * FunctionCustomDrawGUI;
	FunctionVoidFloat * FunctionCustomInput;
	
	void InitOpenGL( int argc, char ** argv )
	
public:
	
	World * GetWorld();
	
	int LoadPhysicsBody( std::string fileName, std::string name );
	int LoadGraphicBody( std::string fileName, std::string name );
	int LoadTexture( std::string fileName, std::string name );
	int LoadSound( std::string fileName, std::string name );
	
	PhysicsBody * GetPhysicsBody( std::string name );
	GraphicBody * GetGraphicBody( std::string name );
	Texture * GetTexture( std::string name );
	
	
	void SetFunctionCustomDrawGUI( FunctionVoidFloat * src );
	void SetFunctionCustomInput( FunctionVoidFloat * src );
	
	void MainLoop();
	
	Init( int argc, char ** argv );
	
	Engine();
	~Engine();
};



