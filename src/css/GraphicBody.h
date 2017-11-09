
#pragma once

class GraphicBody
{
protected:
	
	std::string name;
	
	ObjectOBJ * data;
	
public:
	
	virtual void DrawDebug() const=0;
	virtual void Draw( const int animation, const float time ) const=0;
	
	GraphicBody();
	~GraphicBody();
};



