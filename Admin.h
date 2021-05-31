#pragma once
#include<string>
#include "Person.h"

using namespace std;


class Admin : public Person
{
	string AdminID;
public:
	Admin(
		string fullname,
		string NationalID,
		string Gender,
		int age,
		string address,
		string phoneNumber,
		string country,
		string govern,
		string password,
		string AdminID
	);
	string getAdminID();

	~Admin();
};

