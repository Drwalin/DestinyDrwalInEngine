
#pragma once

class TriggerVolumeActor : public Actor
{
private:
	
	std::map < Actor*, bool > overlappingActors;		// includes only DynamicActors
	
	FunctionVoidActor onStepInFunction;
	FunctionVoidActor onStepOutFunction;
	FunctionVoidActor OverlappingFunction;
	
public:
	
	void SetOnStepInFunction( FunctionVoidActor src );
	void SetOnStepOutFunction( FunctionVoidActor src );
	void SetOverlappingFunction( FunctionVoidActor src );
	
	virtual void Update( float deltaTime ) override;
	
	virtual bool GetRayTrace( const Vector beg, const Vector end, Vector & point, Vector & normal ) override;
	
	TriggerVolumeActor();
	virtual ~TriggerVolumeActor() override;
};



