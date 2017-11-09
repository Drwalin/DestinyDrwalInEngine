
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
		
		std::vector < Face > faces;
		std::string textureName;
	};
	
	std::vector < Vector > posvert;				// vertex possition
	std::vector < Vector > textvert;			// texture possition
	std::vector < Vector > normal;				// normal vector
	std::vector < MaterialObject > object;		// vertices id
	
public:
	
	int LoadFromOBJFile( const std::string fileName );
	int SaveToOBJFile( const std::string fileName ) const;
	
	void Destroy();
	
	ObjectOBJ();
	~ObjectOBJ();
};



