
#pragma once

inline std::string & Actor::GetCustomString()
{
	return customString;
}

inline void ** Actor::GetCustomData()
{
	return &customData;
}

inline World * Actor::GetWorld() const
{
	return world;
}

inline std::string Actor::GetName() const
{
	return name;
}

static bool Actor::IsBinaryTriggerVolumeActor( const char * binary, const int len );///////////////////////////////////////////////////////////////////
static bool Actor::IsBinaryDynamicActor( const char * binary, const int len );/////////////////////////////////////////////////////////////////////////
static bool Actor::IsBinaryStaticActor( const char * binary, const int len );//////////////////////////////////////////////////////////////////////////
static Actor * Actor::GetNewActorByBinaryTemplate( const char * binary, const int len );///////////////////////////////////////////////////////////////
static Actor * Actor::GetNewActorByBinaryType( const char * binary, const int len );///////////////////////////////////////////////////////////////////
static Actor * Actor::GetNewActorByTemplate( const Actor * src );//////////////////////////////////////////////////////////////////////////////////////

Actor * Actor::GetNewActorByType( const Actor * src )
{
	if( dynamic_cast < DynamicActor* > (src) )				return new DynamicActor;
	if( dynamic_cast < StaticActor* > (src) )				return new StaticActor;
	if( dynamic_cast < TriggerVolumeActor* > (src) )		return new TriggerVolumeActor;
	return NULL;
}

inline void Actor::Destroy( Actor * src )
{
	if( src->GetWorld() )
		src->GetWorld()->DestroyActor( src->GetName() );
}

inline void Actor::QueueToDestroy()
{
	queueToDestroy = true;
}

Actor::Actor()
{
	world = NULL;
	name = "";
	bpos.Set( 0.0f, 0.0f, 0.0f );
	pos.Set( 0.0f, 0.0f, 0.0f );
	queueToDestroy = false;
	customData = NULL;		// this can use gameDeveloper, he must constract and destruct it on his own
}



