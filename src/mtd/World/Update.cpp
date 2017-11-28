
#pragma once

void World::UpdateCollider()
{
	for( auto it = actor.begin(); it != actor.end(); *it++ )
		collider->AddActor( it->second );
}

void World::UpdateCollision()///////////////////////////////////////////////////////////////////////////////////
{
	std::map < Actor*, bool > actors;
	for( auto it = actor.begin(); it != actor.end(); *it++ )
	{
		if( it->second )
		{
			if( dynamic_cast < DynamicActor * > ( it->second ) )
			{
				actors.clear();
				AABB aabb = it->second->GetAABB();
				GetActors( aabb, actors );
				for( auto it1 = actors.begin(); it1 != actors.end(); *it1++ )
				{
					if( it1->first > it->second )
					{
						Collision::UpdateContact( it->second, it1->first );
					}
				}
			}
		}
	}
}

void World::Update( const float deltaTime )
{
	this->deltaTime = deltaTime * timeScale;
	
	if( engine )
	{
		if( !physicsPaused )
		{
			for( auto it = actor.begin(); it != actor.end(); *it++ )
			{
				if( it->second )
				{
					it->second->Update( this->deltaTime );
				}
			}
		}
		
		engine->CallFunctionCustomInput();
		
		if( !physicsPaused )
		{
			for( auto it = actor.begin(); it != actor.end(); *it++ )
			{
				if( it->second )
				{
					it->second->IdentityCollisionData();
				}
			}
		}
		
		UpdateCollider();
		UpdateCollision();
	}
}



