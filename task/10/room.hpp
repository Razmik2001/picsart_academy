#ifndef ROOM_HPP
#define ROOM_HPP

class Room
{
	bool status = true;//free
	const string type;
public:
	Room(const string& t):type(t){};
	bool getStatus()
	{
		return status;
	}
	string getType(){
		return type;
	}
	void res()
	{
		status =  false;
	}
	void free()
	{
		status = true;
	}
};

#endif