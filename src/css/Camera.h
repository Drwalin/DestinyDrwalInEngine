
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
	
	void SetPos( const Vector src );
	void SetRotator( const Vector src );
	
	Vector GetRightSideVector() const;
	Vector GetLeftSideVector() const;
	Vector GetForwardVector() const;
	Vector GetUpVector() const;
	Vector GetRotator() const;
	Vector GetPos() const;
	
	AABB GetViewAABB() const;
	bool IsAABBInside( const AABB aabb ) const;
	
	void Init( const std::string srcName, const Vector srcPos, const Vector srcRotator, const Texture * srcTexutreColor, const Texture * srcTextureDepth, const float srcFov, const float srcZFar, const float srcZNear, const float wh );
	
	void SetView();
	static void SetView( const Camera * camera );
	
	void Destroy();
	
	Camera();
	~Camera();
};



