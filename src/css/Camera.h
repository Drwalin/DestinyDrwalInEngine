
#pragma once

class Camera
{
private:
	
	std::string name;
	
	Vector pos;
	Vector rotator;
	
	Texture * textureColor;
	Texture * textureDepth;
	
	float fov;
	float zFar;
	float zNear;
	float wh;		// width / height
	
	
	
public:
	
	void SetPos( Vector src );
	void SetRotator( Vector src );
	
	Vector GetRightSideVector() const;
	Vector GetLeftSideVector() const;
	Vector GetForwardVector() const;
	Vector GetUpVector() const;
	Vector GetRotator() const;
	Vector GetPos() const;
	
	void Init( std::string srcName, Vector srcPos, Vector srcRotator, Texture * srcTexutreColor, Texture * srcTextureDepth, float srcFov, float srcZFar, float srcZNear, float wh );
	
	void SetView();
	
	void Destroy();
	
	Camera();
	~Camera();
};



