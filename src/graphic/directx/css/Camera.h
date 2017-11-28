
#pragma once

class Camera
{
private:
	
	std::string name;
	
	Vector pos;
	Vector rotator;
	
	Vector forwardVector;
	Vector upVector;
	
	//Texture * textureColor;
	//Texture * textureNormalMap;
	//Texture * textureDepthMap;		// or: DepthMap * depthMap;
	
	float fov;
	float zFar;
	float zNear;
	
	float width;
	float height;
	
public:
	
	void SetPos( const Vector src );
	void SetRotator( const Vector src );
	
	Vector GetRightSideVector() const;
	Vector GetLeftSideVector() const;
	Vector GetForwardVector() const;
	Vector GetUpVector() const;
	Vector GetRotator() const;
	Vector GetPos() const;
	
	//Texture * GetTextureColor() const;
	//Texture * GetTextureNormalMap() const;
	//Texture * GetTextureDepthMap() const;
	
	AABB GetViewAABB() const;
	bool IsAABBInside( const AABB aabb ) const;
	
	void Init( const std::string srcName, const Vector srcPos, const Vector srcRotator, const float srcFov, const float srcZFar, const float srcZNear, const float width, const float height );
	
	void SetView();										// set main matrices by
	void SetTarget();									// set main target by (target texture, depth, normal)
	static void SetView( const Camera * camera );		// set main matrices by
	static void SetTarget( const Camera * camera );		// set main target by (target texture, depth, normal)
	
	void Destroy();
	
	Camera();
	~Camera();
};



