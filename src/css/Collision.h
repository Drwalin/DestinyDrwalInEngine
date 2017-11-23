
#pragma once

class Collision
{
private:
	
	static void UpdateContact( DynamicActor * a, DynamicActor * b );
	static void UpdateContact( DynamicActor * a, StaticActor * b );
	static void UpdateContact( DynamicActor * a, TriggerVolumeActor * b );
	
public:
	
	static inline void UpdateContact( Actor * a, Actor * b );
};
