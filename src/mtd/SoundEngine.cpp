


/////////////////////
// End playing sound:
class MySoundEndReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	virtual void OnSoundStopped( irrklang::ISound * sound, irrklang::E_STOP_EVENT_CAUSE reason, void * userData )
	{
		sound -> drop();
		return;
	}
};
MySoundEndReceiver* myGlobalReceiver = new MySoundEndReceiver();



//////////////////
// Sample Methods:

SoundEngine::SoundSource::SoundSource()
{
	source = NULL;
}

SoundEngine::SoundSource::~SoundSource()
{
	if( source != NULL )
		source->drop();
}



////////////////////////
// Sound Engine Methods:

void SoundEngine::Init()
{
	SEngine = irrklang::createIrrKlangDevice();
}

void SoundEngine::DeInit()
{
	if( SEngine != NULL )
		SEngine->drop();
	samples.resize( 0 );
}

void SoundEngine::Update( const Vector pos, const Vector forward, const Vector up )
{
	irrklang::vec3df position( pos[0], pos[1], pos[2] );			// position of the listener
	irrklang::vec3df lookDirection( forward[0], forward[1], forward[2] );	// the direction the listener looks into
	irrklang::vec3df velPerSecond( 0, 0, 0 );							// only relevant for doppler effects
	irrklang::vec3df upVector( up[0], up[1], up[2] );				// where 'up' is in your 3D scene
	
	SEngine->setListenerPosition( position, lookDirection, velPerSecond, upVector );
}

void SoundEngine::AddSound( const std::string fileName, const std::string name )
{
	ifstream file;
	file.open( fileName.c_str() );
	if( file.good() )
	{
		soundSource[name].source = SEngine->addSoundSourceFromFile( src.c_str() );
	}
}

void SoundEngine::PlaySound( const std::string name, const float volume )
{
	it auto = soundSource.find(src);
	if( it != soundSource.end() )
	{
		irrklang::ISound * snd_ = SEngine->play2D( it->second.source, false, false, true );
		snd_ -> setSoundStopEventReceiver(myGlobalReceiver);
		snd_ -> setVolume( volume * GlobalVolume );
		snd_ = NULL;
	}
}

void SoundEngine::PlaySound( const std::string name, const Vector origin )
{
	PlaySound( src, origin, 1.13f );
}

void SoundEngine::PlaySound( const std::string name, const Vector origin, const float minDistance )
{
	it auto = soundSource.find(src);
	if( it != soundSource.end() )
	{
		irrklang::ISound * snd_ = NULL;
		irrklang::vec3df position( origin[0], origin[1], origin[2] );
		
		snd_ = SEngine->play3D( it->second.source, position, false, false, true, false );
		snd_ -> setSoundStopEventReceiver(myGlobalReceiver);
		snd_ -> setMinDistance( minDistance );
		snd_ -> setVolume( GlobalVolume );
		snd_ = NULL;
	}
}

void SoundEngine::SetVolume( const float dst )
{
	GlobalVolume = dst;
}

float SoundEngine::GetVolume() const
{
	return GlobalVolume;
}

SoundEngine::SoundEngine()
{
	GlobalVolume = 1.0f;
	SEngine = NULL;
}

SoundEngine::~SoundEngine()
{
	GlobalVolume = 0.0f;
	DeInit();
}


