
#pragma once

void World::Draw() const
{
	if( !graphicPaused && mainCamera && collider && engine )
	{
		std::map < Actor*, bool > actors;
		GetActors( mainCamera->GetViewAABB();, actors );
		for( auto it = actors.begin(); it != actors.end(); *it++ )
		{
			if( it->first )
			{
				it->first->Draw();
				if( engine->GetDebug() )
					it->first->DrawDebug();
			}
		}
	}
}



