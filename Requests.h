#pragma once
#include<string>
using namespace std;

class Requests
{

	string user_id;
	string vaccineName;
	string ReuquestNumber;
	

public:
	static int totalNumberofRequests;
	Requests();
	void setUserID(string id);
	string getUserID();
	void setVaccineName(string vaccineName);
	string getVaccineName();
	void setRequestNumber(string RequestNumber);
	string getRequestNumber();
};

