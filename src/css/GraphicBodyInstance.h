
#pragma once

class GraphicBodyInstance
{
private:
	
	float currentFrameTime;
	int currentAnimation;
	
	GraphicBody * graphicBody;
	
public:
	
	GraphicBody * GetGraphicBody() const;
	float GetFrameTime() const;
	int GetAnimation() const;
	
	void SetGraphicBody();
	void SetFrameTime();
	void SetAnimation();
	
	void Update( const float deltaTime );
	void Draw() const;
	
	GraphicBodyInstance();
	~GraphicBodyInstance();
};



