
#pragma once

class Node
{
private:
	
	long long int x, y, z;
	
	std::vector < Node * > walkConnections;
	std::vector < Node * > swimConnections;
	std::vector < Node * > flyConnections;
	std::vector < Node * > climbConnections;
	std::vector < Node * > fallConnections;
	std::map < Node *, bool > cameFrom;
	
public:
	
	friend class NavMesh;
	
	void DestroyFromConnected();
	
	Node();
	Node( const Vector pos, const float scale );
	Node( const Node * src );
	Node( const Node & src );
	~Node();
};

class BaseNode
{
private:
	
	long long int x, y, z;
	
public:
	
	bool operator < ( BaseNode src );
	bool operator > ( BaseNode src );
	bool operator == ( BaseNode src );
	
	BaseNode();
	BaseNode( const Vector pos, const float scale );
	BaseNode( const BaseNode src );
};

class NavigationMeshPath
{
private:
	
	std::vector < Vector > path;
	int currentNode;
	
public:
	
	inline Vector GetNextNode();		// return path[currentNode++];
	inline bool GetExist() const;
	
	NavMeshPath();
	~NavMeshPath();
};

class NavMesh
{
private:
	
	std::string name;
	World * world;
	NavMesh * parent;
	
	std::map < Node *, int > distanceFromStart;		// on the path
	std::map < BaseNode, Node * > nodes;			// only in parent
	
	Vector begin, end;
	Node * beginNode, * endNode;
	
	float scale;
	float maximumDistanceNodeConnection;
	
	
	Node * GetNode( const BaseNode pos ) const;
	Node * GetNode( const Vector pos ) const;
	
public:
	
	void AddConnection( const Vector a, const Vector b );
	
	void BeginNewPath( const Vector a, const Vector b );
	void UpdateConnections( const int count );
	int UpdatePath( const int count );
	
	void Init( const float acceptableDistanceAsOneNode, const float maximumDistanceNodeConnection, const NavMesh * parent );
	
	void Destroy();
	
	NavMeshPath GetPath() const;
	
	NavMesh();
	~NavMesh();
};



