
#pragma once

class GraphicBodyInstance
{
private:
	
	float currentFrameTime;
	int currentAnimation;
	
	Vector rotator;
	
	GraphicBody * graphicBody;
	
public:
	
	GraphicBody * GetGraphicBody() const;
	float GetFrameTime() const;
	int GetAnimation() const;
	
	void SetGraphicBody( const GraphicBody * graphicBody );
	void SetFrameTime( const float t );
	void SetAnimation( const int id );
	void Rotate( const Vector rotator );
	
	void Update( const float deltaTime );
	void Draw() const;
	
	GraphicBodyInstance();
	~GraphicBodyInstance();
};



