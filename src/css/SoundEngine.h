
#pragma once

class SoundEngine
{
	irrklang::ISoundEngine * SEngine;
	
	class SoundSource
	{
	public:
		irrklang::ISoundSource * source;
		
		SoundSource();
		~SoundSource();
	};
	std::map < std::string, SoundSource > soundSource;
	
	float GlobalVolume;
	
public:
	void Init();
	void DeInit();
	
	void AddSound( const std::string fileName, const std::string name );		// file name with path
	
	void PlaySound( const std::string name, const float volume );
	
	void PlaySound( const std::string name, const Vector origin, const float minDistance );
	void PlaySound( const std::string name, const Vector origin );
	
	void Update();
	
	void SetVolume( const float dst );
	float GetVolume() const;
	
	SoundEngine();
	~SoundEngine();
};



