#include<bits/stdc++.h>
using namespace std;

struct Location{
	int pin;
 string streetName, locality, city, state;
};

enum class RoomStyle;

enum class RoomStatus;

class RoomKey{
	string keyId;
	string barCode;
	Date issedAt;
	bool isActive;
	bool isMaster;
public:
	void addRoom(Room room);
}

class Room{
	string roomNumber;
	RoomStyle roomStyle;
	RoomStatus roomStatus;
	vector<RoomKey> roomKeys;
	vector<HouseKeepinglog> hoseKeepingLog;
};

class HouseKeepingLog{
	string description;
	Date startDate;
	int duration;
	HouseKeeper houseKeeper;
public:
	void addRoom(Room room);
};

enum class AccountStatus{
	ACTIVE, CLOSED, BLOCKED
};

class Account{
	string username;
	string password;
	AccountStatus accountStatus;
};

class RoomBooking{
	string bookingId;
	Date startDate;
	int duration;
	vector<Guest> guestDetails;
	vector<Room> roominfo;
	BaseRoomCharge totalRoomCharge;
};

class Search{
public:
	vector<Room> searchRoom();
};

class Booking{
public:
	RoomBooking createBooking(Guest guest);
	RoomBooking cancleBooking(int bookingId);
};

class Person{
	string name;
	Account accountDetails;
	string phone;
};

class Guest: public Person{
	Search searchObj;
	Booking bookingObj;
public:
	void vector<RoomBooking> getAllRoomBookings();
};

class Receptionist: public Person{
	Search searchObj;
	Booking bookingObj;
};

class HouseKeeper: public Person{
public: 
	vector<Room> getRoomServiced(Date date);
};

class Admin: public Person{
	public:
	void addRoom(Room room);
	void removeRoom(Room room);
	void deleteRoom(Room room);
};

class Hotel{
	string name;
	int id;
	Location hotelLocation;
	vector<Room> roomList;
};