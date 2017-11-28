
#pragma once

class Engine
{
public:
	
	static int HostNone = 0;
	static int HostClient = 1;
	static int HostServer = 2;
	
private:
	
	// engine instance can be one of (or none):
	ServerEngine * server;		// defines engine instance as server
	ClientEngine * client;		// defines engine instance as client
	
	World * world;
	
	SoundEngine * soundEngine;
	
	std::string name;
	
	std::map < std::string, StaticActor * > physicsBody;
	std::map < std::string, GraphicBody * > graphicBody;
	std::map < std::string, Texture * > texture;
	std::map < std::String, ObjectOBJ * > obj;
	
	unsigned char * threadsData;
	int threadsNumber;
	
	float framesPerSecond;			// real time
	int framesCounter;				// real time
	int lastFramesWereReset;		// real time ////////////////
	
	float timeScale;
	float deltaTime;		// with timeScale
	
	FunctionVoidFloat * FunctionCustomDrawGUI;
	FunctionVoidFloat * FunctionCustomInput;
	
	bool debug;
	
public:
	
	bool GetDebug() const;
	void SetDebug( const bool debug );
	
	World * GetWorld() const;
	SoundEngine * GetSoundEngine() const;
	
	void CallFunctionCustomDrawGUI();
	void CallFunctionCustomInput( const float deltaTime );
	
	int LoadPhysicsBody( const std::string fileName, const std::string name );		// override if exist
	int LoadGraphicBody( const std::string fileName, const std::string name );		// override if exist
	int LoadTexture( const std::string fileName, const std::string name );			// override if exist
	int LoadSound( const std::string fileName, const std::string name );			// override if exist
	int LoadOBJ( const std::string fileName, const std::string name );				// override if exist
	
	StaticActor * GetPhysicsBody( const std::string name ) const;
	GraphicBody * GetGraphicBody( const std::string name ) const;
	Texture * GetTexture( const std::string name ) const;
	ObjectOBJ * GetOBJ( const std::string name ) const;
	
	void DestroyPhysicsBody( const std::string name );
	void DestroyGraphicBody( const std::string name );
	void DestroyTexture( const std::string name );
	void DestroySound( const std::string name );
	void DestroyOBJ( const std::string name );
	
	
	void SetFunctionCustomDrawGUI( FunctionVoidFloat * src );
	void SetFunctionCustomInput( FunctionVoidFloat * src );
	
	void Iteration( const float deltaTime );
	void Render();
	
	int Init( int argc, char ** argv, int hostMode, const AABB aabbWorld, const std::string name, const std:string worldName, const unsigned int frequencyParticleUpdate );
	
	void Destroy();
	
	Engine();
	~Engine();
};



