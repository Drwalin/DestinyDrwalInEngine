
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
	inline void Init();
	inline void DeInit();
	
	inline void AddSound( char * src );		// file name with path
	inline void PlaySound( const char * src, float volume );
	inline void PlaySound( const char * src, Vector origin );
	inline void PlaySound( const char * src, Vector origin, float minDistance );
	inline int GetSoundId( char * src );
	
	inline void Update();
	
	inline void SetVolume( float dst );
	inline float GetVolume();
	
	SoundEngine();
	~SoundEngine();
};



