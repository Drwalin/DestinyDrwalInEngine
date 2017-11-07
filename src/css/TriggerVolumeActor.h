
#pragma once

class TriggerVolumeActor : public Actor
{
private:
	
	std::map < Actor*, bool > overlappingActors;
	
	FunctionVoidActor onStepInFunction;
	FunctionVoidActor onStepOutFunction;
	FunctionVoidActor OverlappingFunction;
	
public:
	
	void SetOnStepInFunction( FunctionVoidActor src );
	void SetOnStepOutFunction( FunctionVoidActor src );
	void SetOverlappingFunction( FunctionVoidActor src );
	
	TriggerVolumeActor();
	~TriggerVolumeActor();
};



