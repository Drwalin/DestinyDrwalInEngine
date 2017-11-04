
#pragma once

class Engine
{
private:
	
	World * world;
	
	std::map < std::string, Texture * > texture;
	std::map < std::string, GraphicBody * > graphicBody;
	
	unsigned char * threadsData;
	int threadsDataLength;
	
	
	
public:
	
	void PlaySound( std::string name, float volume );
	void PlaySound( std::string name, Vector origin );
	void PlaySound( std::string name, Vector origin, float minDistance );
	
	//void SpawnParticles(...);
	
	Actor * SpawnActor();
	
	
	
	Init();
	
	Engine();
	~Engine();
};



