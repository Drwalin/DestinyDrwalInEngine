
#pragma once

void Camera::SetPos( const Vector src )
{
	pos = src;
}

void Camera::SetRotator( const Vector src )
{
	rotator = src;
	Quat quat = Math::GetQaternion( rotator );
	forwardVector = quat * Vector( 0.0f, 0.0f, 1.0f );
	upVector = quat * Vector( 0.0f, 1.0f, 0.0f );
	leftVector = quat * Vector( 1.0f, 0.0f, 0.0f );
}

Vector Camera::GetRightSideVector() const
{
	return leftVector * (-1.0f);
}

Vector Camera::GetLeftSideVector() const
{
	return leftVector;
}

Vector Camera::GetForwardVector() const
{
	return forwardVector;
}

Vector Camera::GetUpVector() const
{
	return upVector;
}



Vector Camera::GetRotator() const
{
	return rotator;
}

Vector Camera::GetPos() const
{
	return pos;
}


AABB Camera::GetViewAABB() const
{
	AABB aabb( pos, pos );
	
	float tgAng = tan( angleView * M_PI / 360.0f ) * farPlane;
	Vector sideVec = ( forwardVector && upVector ).Versor() * tgAng;
	Vector upVec = upVector * tgAng;
	
	Vector tmp = pos + ( forwardVector * farPlane );
	
	aabb.AddPoint( tmp );
	aabb.AddPoint( tmp + upVec + sideVec );
	aabb.AddPoint( tmp + upVec - sideVec );
	aabb.AddPoint( tmp - upVec - sideVec );
	aabb.AddPoint( tmp - upVec + sideVec );
	
	this->aabb = aabb;
	
	return aabb;
}

bool Camera::IsAABBInside( const AABB aabb ) const
{
	AABB tmp;
	return this->aabb.SharedPart( aabb, tmp );
}

void Camera::Init( const std::string srcName, const Vector srcPos, const Vector srcRotator, const float srcFov, const float srcZFar, const float srcZNear, const float width, const float height );

void Camera::SetView()
{
	Camera::SetView( this );
}

static void Camera::SetView( const Camera * camera )
{
	D3DXMATRIX matView;
	D3DXVECTOR3 camPos = D3DXVECTOR3( camera->pos[0], camera->pos[1], camera->pos[2] );
	D3DXVECTOR3 lookAt( camera->pos[0]+camera->forwardVector[0], camera->pos[1]+camera->forwardVector[1], camera->pos[2]+camera->forwardVector[2] );
	D3DXVECTOR3 up( camera->upVector[0], camera->upVector[1], camera->upVector[2] );
	
	D3DXMatrixLookAtLH( &matView, &camPos, &lookAt, &up );
	GetD3DDevice()->SetTransform( D3DTS_VIEW, &matView );
	
	D3DXMATRIX matProjection;
	D3DXMatrixPerspectiveFovLH( &matProjection, D3DXToRadian( camera->fov ), float(camera->width)/float(camera->height), camera->zNear, camera->zFar );
	GetD3DDevice()->SetTransform( D3DTS_PROJECTION, &matProjection );
}

void Camera::Destroy();////////////////////////////////////////////////////////////////////////////////////////

Camera::Camera()//////////////////////////////////////////////////////////////////////////////////////////////
{
	SetRotator( Vector( 0.0f, 0.0f, 0.0f ) );
}

Camera::~Camera();/////////////////////////////////////////////////////////////////////////////////////////////



