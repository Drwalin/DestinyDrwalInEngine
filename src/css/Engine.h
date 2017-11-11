
#pragma once

class Engine
{
private:
	
	ServerEngine * server;
	ClientEngine * client;
	
	World * world;
	
	std::string name;
	
	std::map < std::string, StaticActor * > physicsBody;
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
	
	World * GetWorld();  const
	
	int LoadPhysicsBody( const std::string fileName, const std::string name );
	int LoadGraphicBody( const std::string fileName, const std::string name );
	int LoadTexture( const std::string fileName, const std::string name );
	int LoadSound( const std::string fileName, const std::string name );
	
	StaticActor * GetPhysicsBody( const std::string name ) const;
	GraphicBody * GetGraphicBody( const std::string name ) const;
	Texture * GetTexture( const std::string name ) const;
	
	
	void SetFunctionCustomDrawGUI( FunctionVoidFloat * src );
	void SetFunctionCustomInput( FunctionVoidFloat * src );
	
	void MainLoop();
	
	Init( int argc, char ** argv, int hostMode );
	
	Engine();
	~Engine();
};



