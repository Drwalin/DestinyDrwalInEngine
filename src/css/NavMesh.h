
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
	
	friend class NavMesh;
	
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

class NavMeshPathFinderVetrtex
{
private:
	long long int distanceFromBegin;
	Node * cameFrom;
	
public:
	
	friend NavMesh;
	
	NavMeshPathFinderVetrtex();
	~NavMeshPathFinderVetrtex();
};

class NavMeshVertexToCheck
{
private:
	
	long long int distanceToDestiny;
	Node * node;
	
public:
	
	friend NavMesh;
	
	bool operator < ( const NavMeshVertexToCheck src ) const;		// compare distanceToDestiny (if equal compare node pointer)
	
	VertexToCheck();
	~VertexToCheck();
};

class NavMeshParent
{
private:
	
	std::string name;
	World * world;
	
	std::map < BaseNode, Node * > nodes;								// only in parent
	
	float scale;
	float maximumDistanceNodeConnection;
	
	inline Node * GetNode( const BaseNode pos ) const;
	inline Node * GetNode( const Vector pos ) const;
	
public:
	
	void AddConnection( const Vector a, const Vector b );
	void UpdateConnections( const int count );
	
	void Init( const float acceptableDistanceAsOneNode, const float maximumDistanceNodeConnection );
	void Destroy();
	
	NavMeshParent();
	~NavMeshParent();
};

class NavMesh
{
private:
	
	std::string name;
	World * world;
	NavMeshParent * parent;
	
	
	std::vector < NavMeshVertexToCheck > verticesToCheck;				// must be sorted before taking vertex
	std::map < Node *, NavMeshPathFinderVetrtex > checkedVertices;		// on the path
	
	Vector begin, end;
	Node * beginNode, * endNode;
	
	
	inline void AddVertexToCheck( const Node * node );
	inline Node * GetNextNodeToCheck();
	
	inline Node * GetNode( const BaseNode pos ) const;					// get from paretnm
	inline Node * GetNode( const Vector pos ) const;					// get from parent
	
public:
	
	void AddConnection( const Vector a, const Vector b );		// adds to parent
	
	void BeginNewPath( const Vector a, const Vector b );
	int UpdatePath( const int count );
	
	void Init( const float acceptableDistanceAsOneNode, const float maximumDistanceNodeConnection, const NavMeshParent * parent );
	
	void Destroy();
	
	NavMeshPath GetPath() const;
	
	NavMesh();
	~NavMesh();
};



