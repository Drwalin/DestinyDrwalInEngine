
#pragma once

#include "Math.hpp"
#include "Vector.hpp"

struct Quat
{
public:
	float x, y, z, w;
	
	
	bool operator == ( Quat src )
	{
		return x==src.x && y==src.y && z==src.z && w==src.w;
	}
	
	float & operator[]( int id )
	{
		switch( id )
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			return w;
		}
	}
	
	Quat operator * ( Quat src ) const
	{
		return Quat(
					w*src.x + x*src.w + y*src.z - z*src.y,
					w*src.y + y*src.w + z*src.x - x*src.z,
					w*src.z + z*src.w + x*src.y - y*src.x,
					w*src.w - x*src.x - y*src.y - z*src.z
					).Normalized();
	}
	
	Vector operator * ( Vector src ) const
	{
		Vector dst;
		
		float
			xx = x * x, yy = y * y, zz = z * z,
			xy = x * y, xz = x * z,
			yz = y * z, wx = w * x,
			wy = w * y, wz = w * z;
		
		dst[0] =
			( 1.0f - 2.0f * ( yy + zz ) ) * src[0] +
			( 2.0f * ( xy - wz ) ) * src[1]  +
			( 2.0f * ( xz + wy ) ) * src[2];
		
		dst[1] =
			( 2.0f * ( xy + wz ) ) * src[0] +
			( 1.0f - 2.0f * ( xx + zz )) * src[1] +
			( 2.0f * ( yz - wx ) ) * src[2];
		
		dst[2] =
			( 2.0f * ( xz - wy ) ) * src[0] +
			( 2.0f * ( yz + wx ) ) * src[1] +
			( 1.0f - 2.0f * ( xx + yy ) ) * src[2];
		
		return dst;
	}
	
	Vector GetAxis() const
	{
		float val__ = 1.0f - w * w;
		if( val__ <= 0.0f )
		{
			return Vector( 0.0f, 0.0f, 0.0f );
		}
		val__ = 1.0f / sqrtf( val__ );
		return Vector( x * val__, y * val__, z * val__ ).Versor();
	}
	
	float GetAngle() const
	{
		return safe_acos(w) * 360.0f / M_PI;
	}
	
	inline float Length() const
	{
		return sqrtf( x*x + y*y + z*z + w*w );
	}
	
	Quat & Inverse()
	{
		x = -x;
		y = -y;
		z = -z;
		
		return *this;
	}
	
	Quat Inversed() const
	{
		return Quat( -x, -y, -z, w );
	}
	
	Quat & Normalize()
	{
		float lenDiv = 1.0f / Length();
		x *= lenDiv;
		y *= lenDiv;
		z *= lenDiv;
		w *= lenDiv;
		return *this;
	}
	
	Quat Normalized() const
	{
		Quat dst;
		float lenDiv = 1.0f / Length();
		dst.x = x*lenDiv;
		dst.y = y*lenDiv;
		dst.z = z*lenDiv;
		dst.w = w*lenDiv;
		return dst;
	}
	
	bool IsOpposite( Quat src )
	{
		Vector axisThis = GetAxis(), axisSrc = src.GetAxis();
		float angleThis = GetAngle(), angleSrc = src.GetAngle();
		
		bool angleOpposite = ( angleThis < 0.0f && angleSrc > 0.0f ) || ( angleThis > 0.0f && angleSrc < 0.0f );
		bool axesOpposite = axisThis.Dot( axisSrc ) < 0.0f;
		
		return ( angleOpposite && !axesOpposite ) || ( !angleOpposite && axesOpposite );
	}
	
	Quat & operator = ( Quat src )
	{
		x = src.x;
		y = src.y;
		z = src.z;
		w = src.w;
		return *this;
	}
	
	Quat Slerp( Quat dst, float time )
	{
		float cosOmega = x*dst.x + y*dst.y + z*dst.z + w*dst.w;
		Quat mid = dst;
		
		if( cosOmega < 0.0f )
		{
			mid.x = -mid.x;
			mid.y = -mid.y;
			mid.z = -mid.z;
			mid.w = -mid.w;
			cosOmega = -cosOmega;
		}
		
		float k0, k1;
		if( cosOmega > 0.9999f )
		{
			k0 = 1.0f - time;
			k1 = time;
		}
		else
		{
			float sinOmega = sqrtf( 1.0f - cosOmega*cosOmega );
			float omega = atan2( sinOmega, cosOmega );
			float oneOverSinOmega = 1.0f / sinOmega;
			k0 = sin( (1.0f - time) * omega ) * oneOverSinOmega;
			k1 = sin( time * omega ) * oneOverSinOmega;
		}
		
		mid.x = x*k0 + mid.x*k1;
		mid.y = y*k0 + mid.y*k1;
		mid.z = z*k0 + mid.z*k1;
		mid.w = w*k0 + mid.w*k1;
		
		return mid;
	}
	
	void ClampAngle( float maxAngle )
	{
		float angle = GetAngle();
		if( abs(angle) > maxAngle )
		{
			*this = Quat( GetAxis(), angle > 0.0f ? maxAngle : -maxAngle );
		}
	}
	
	void SetAngle( float angle )
	{
		*this = Quat( GetAxis(), angle );
	}
	
	Quat( Quat src_a, Quat src_b )			// from a to b
	{
		*this = src_a.Inversed() * src_b;
		Normalize();
	}
	
	Quat( Vector axis, const float angle )		// from axis and angle
	{
		Vector axis_ = axis.Versor();
		float ang = angle * 0.5f * M_PI / 180.0f;
		w = cos( ang );
		ang = sin( ang );
		x = axis_[0] * ang;
		y = axis_[1] * ang;
		z = axis_[2] * ang;
		Normalize();
	}
	
	Quat()												// identity
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
	}
	
	Quat( const float a, const float b, const float c, const float d )					// raw values
	{
		x = a;
		y = b;
		z = c;
		w = d;
		Normalize();
	}
};



