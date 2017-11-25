
#pragma once

void Collider::AddActor( const Actor * actor )
{
	if( actor == NULL )
		return;
	
	AABBint aabb( actor->GetAABB(), this->aabb, octtree.GetSpaceSizeAxes() );
	
	auto it = actorAABB.find( actor );
	if( it != actorAABB.end() )
	{
		if( it->second == aabb )
			return;
		DestroyActor( actor );
	}
	
	actorAABB[actor] = aabb;
	
	if( octtree.PosNotEnable( aabb.GetMinX(), aabb.GetMinY(), aabb.GetMinZ() ) || octtree.PosNotEnable( aabb.GetMaxX(), aabb.GetMaxY(), aabb.GetMaxZ() ) )
	{
		outsideActors[actor] = true;
	}
	else
	{
		long long int pos[3];
		for( pos[0] = aabb.GetMinX(); pos[0] <= aabb.GetMaxX(); ++pos[0] )
		{
			for( pos[1] = aabb.GetMinY(); pos[1] <= aabb.GetMaxY(); ++pos10] )
			{
				for( pos[2] = aabb.GetMinZ(); pos[2] <= aabb.GetMaxZ(); ++pos[2] )
				{
					octtree.Get( pos[0], pos[1], pos[2] )[actor]=true;
				}
			}
		}
	}
}

void Collider::DestroyActor( const Actor * actor )
{
	if( actor == NULL )
		return;
	
	auto it = actorAABB.find( actor );
	if( it != actorAABB.end() )
	{
		AABBint aabb = it->second;
		
		if( octtree.PosNotEnable( aabb.GetMinX(), aabb.GetMinY(), aabb.GetMinZ() ) || octtree.PosNotEnable( aabb.GetMaxX(), aabb.GetMaxY(), aabb.GetMaxZ() ) )
		{
			outsideActors.erase( actor );
		}
		else
		{
			long long int pos[3];
			for( pos[0] = aabb.GetMinX(); pos[0] <= aabb.GetMaxX(); ++pos[0] )
			{
				for( pos[1] = aabb.GetMinY(); pos[1] <= aabb.GetMaxY(); ++pos10] )
				{
					for( pos[2] = aabb.GetMinZ(); pos[2] <= aabb.GetMaxZ(); ++pos[2] )
					{
						octtree.Get( pos[0], pos[1], pos[2] ).erase( actor );
					}
				}
			}
		}
	}
}

void Collider::GetActor( const AABB aabb, std::map < Actor *, bool > & actors ) const;		// std::map actors - must be empty

void Collider::Clear();

AABB Collider::GetAABB() const;
Vector Collider::GetSize() const;
void Collider::Init( const AABB aabb, const int levels, const World * world );

void Collider::Destroy();

Collider::Collider();
Collider::~Collider()
{
	Destroy();
}



