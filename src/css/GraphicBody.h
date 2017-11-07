
#pragma once

class GraphicBody
{
protected:
	
	std::string name;
	
	ObjectOBJ * data;
	
public:
	
	virtual void DrawDebug()=0;
	virtual void Draw( int animation, float time )=0;
	
	GraphicBody();
	~GraphicBody();
};



