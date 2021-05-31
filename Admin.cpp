#pragma once

#include "Admin.h"
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;


Admin::Admin(
	string fullname,
	string NationalID,
	string Gender,
	int age,
	string address,
	string phoneNumber,
	string country,
	string govern,
	string password,
	string AdminID)
  :Person(
	fullname,
	NationalID,
	Gender,
	age,
	address,
	phoneNumber,
	country,
	govern,
	Email,
	password
) {

	this->AdminID = AdminID;
}
string Admin::getAdminID() {
	return AdminID;
}
Admin::~Admin() {}
