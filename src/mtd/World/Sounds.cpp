
#pragma once

void World::PlaySound( const std::string name, const float volume )
{
	if( engine )
		if( engine->GetSoundEngine() )
			engine->GetSoundEngine()->PlaySound( name, volume );
}

void World::PlaySound( const std::string name, const Vector origin )
{
	if( engine )
		if( engine->GetSoundEngine() )
			engine->GetSoundEngine()->PlaySound( name, origin );
}

void World::PlaySound( const std::string name, const Vector origin, const float minDistance )
{
	if( engine )
		if( engine->GetSoundEngine() )
			engine->GetSoundEngine()->PlaySound( name, origin, minDistance );
}



