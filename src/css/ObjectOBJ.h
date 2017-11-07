
#pragma once

class ObjectOBJ
{
private:
	
	class MaterialObject
	{
	public:
		class Face
		{
		public:
			class Vertex
			{
			public:
				int v;		// vertex
				int vt;		// texture
				int vn;		// normal
			};
			
			Vertex ids[3];
		};
		
		std::string textureName;
	};
	
	std::string hitSoundName;
	
	std::vector < Vector > posvert;				// vertex possition
	std::vector < Vector > textvert;			// texture possition
	std::vector < Vector > normal;				// normal vector
	std::vector < MaterialObject > object;		// vertices id
	
	
public:
	
	int LoadFromFileOBJ( std::string fileName );
	
};



