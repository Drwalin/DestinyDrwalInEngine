
#pragma once

int Texture::Load( const std::string fileName, const std::string nameSrc, const int interpolationMode, const int mipMapsSrc )
{
	Destroy();
	mipMaps = mipMapsSrc;
	name = nameSrc;
	bitmap = al_load_bitmap( fileName.c_str() );
	interpolationMode = interpolationModeSrc;
	if( bitmap == NULL )
	{
		Destroy();
		return 0;
	}
	return 1;
}

int Texture::Bind() const;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Texture::Destroy()
{
	name = "";
	if( bitmap )
		al_destroy_bitmap( bitmap );
	bitmap = NULL;
	mipMaps = 0;
	interpolationMode = Nearest;
}

Texture::Texture()
{
	name = "";
	bitmap = NULL;
	mipMaps = 1;
	interpolationMode = Nearest;
}

Texture::~Texture()
{
	Destroy();
}



