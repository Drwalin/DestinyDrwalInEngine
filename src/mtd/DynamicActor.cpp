
#pragma once

virtual void DynamicActor::DrawDebug() const override
{
	VBO vbo;
	vbo.AddVertex( pos+Vector(-size[0],-size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0],-size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0],-size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0], size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0],-size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0],-size[1],-size[2]), 255, 255, 255 );
	
	vbo.AddVertex( pos+Vector( size[0], size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0], size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0], size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0],-size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0], size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0], size[1], size[2]), 255, 255, 255 );
	
	vbo.AddVertex( pos+Vector(-size[0],-size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0], size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0],-size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0],-size[1], size[2]), 255, 255, 255 );
	
	vbo.AddVertex( pos+Vector(-size[0], size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0], size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0], size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0],-size[1], size[2]), 255, 255, 255 );
	
	vbo.AddVertex( pos+Vector( size[0],-size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector(-size[0], size[1], size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0],-size[1],-size[2]), 255, 255, 255 );
	vbo.AddVertex( pos+Vector( size[0],-size[1], size[2]), 255, 255, 255 );
	
	vbo.Generate( VBO::drawModeLine, NULL, false );
	vbo.Draw();
	vbo.Destroy();
}

virtual void DynamicActor::Draw() const override
{
	graphicBodyInfo.Draw();
}

virtual AABB DynamicActor::GetAABB() const override
{
	return AABB( pos-size, pos+size );
}

virtual float DynamicActor::GetHeight() const override
{
	return size[1]*2.0f;
}

virtual void DynamicActor::Update( const float deltaTime ) override;
virtual void DynamicActor::IdentityCollisionData() override
{
	contact.Clear();
	collideUp = false;
	collideSide = false;
	collideDown = false;
}

virtual void DynamicActor::AddForce( const Vector src ) override
{
	force += src;
}

virtual void DynamicActor::AddVelocity( const Vector src ) override
{
	vel += src;
}

virtual void DynamicActor::AddPos( const Vector src ) override
{
	pos += src;
}

virtual void DynamicActor::Resize( const Vector src ) override;
{
	size = src * 0.5f;
}

virtual void DynamicActor::Rotatate( const Vector src ) override{}

virtual void DynamicActor::SetForce( const Vector src ) override
{
	force = src;
}

virtual void DynamicActor::SetVelocity( const Vector src ) override
{
	vel += src;
}

virtual void DynamicActor::SetPos( const Vector src ) override
{
	pos += src;
}

virtual void DynamicActor::SetRotation( const Vector src ) override{}

virtual Vector DynamicActor::GetForce() const override
{
	return force;
}

virtual Vector DynamicActor::GetVelocity() const override
{
	return vel;
}

virtual Vector DynamicActor::GetPos() const override
{
	return pos;
}

virtual Vector DynamicActor::GetSize() const override
{
	return size * 2.0f;
}

virtual Vector DynamicActor::GetRotation() const override
{
	return Vector( 0.0f, 0.0f, 0.0f );
}

virtual bool DynamicActor::GetRayTrace( const Vector beg, const Vector end, Vector & point, Vector & normal ) override;


virtual void DynamicActor::Destroy() override;
DynamicActor::DynamicActor();
virtual DynamicActor::~DynamicActor() override;



