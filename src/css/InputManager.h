
#pragma once

enum InputKeys
{
	NONE,
};

class InputManager
{
private:
	
	static std::map < std::string, InputKeys > stringToId;		// id - key id
	static std::map < InputKeys, std::string > idToString;		// id - key id
	
	int mouseX, mouseY;
	int wheelPos, deltaWheelPos;
	unsigned char * keyState;
	
public:
	
	static int GetKey( const std::strnig src );
	static int GetKeyName( const int id );
	
	bool IsKeyPressed( const int id ) const;
	bool IsKeyReleased( const int id ) const;
	bool IsKeyDown( const int id ) const;
	bool IsKeyUp( const int id ) const;
	bool IsKeyStillDown( const int id ) const;
	bool IsKeyStillUp( const int id ) const;
	
	void GetMousePos( int & x, int & y ) const;
	int GetWheelDeltaPos() const;					// delta since last update
	
	void Update();
	
	InputManager();
	~InputManager();
};



