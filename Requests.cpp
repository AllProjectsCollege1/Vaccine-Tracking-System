#include "Requests.h"
#include <string>

using namespace std;

int Requests::totalNumberofRequests{ 0 };


Requests::Requests() {

	user_id = " ";
	vaccineName = " ";
	ReuquestNumber = " ";
}

void Requests::setUserID(string id) {
	user_id = id;
}

void Requests::setVaccineName(string name) {
	vaccineName = name;
}

void Requests::setRequestNumber(string number) {
	ReuquestNumber = number;
}

string Requests::getUserID() {
	return user_id;
}

string Requests::getVaccineName() {
	return vaccineName;
}

string Requests::getRequestNumber() {
	return ReuquestNumber;
}