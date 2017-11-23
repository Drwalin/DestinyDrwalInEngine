
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
	
	TriggerVolumeActor();
	virtual ~TriggerVolumeActor() override;
};



