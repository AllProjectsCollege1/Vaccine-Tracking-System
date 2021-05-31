#pragma once
#include<iostream>
#include <string>

using namespace std;

class Person {
protected:
	string fullname;
	string NationalID;
	string Gender;
	string address;
	int age;
	string phoneNumber;
	string country;
	string govern;
	string password;
	string Email;
public:
	Person();
	Person(string fullname,
		string NationalID,
		string Gender,
		int age,
		string address,
		string phoneNumber,
		string country,
		string govern,
		string password,
		string Email
		);
	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge();
	void setGender(string gender);
	string getGender();
	void setCountry(string country);
	string getCountry();
	void setNationalID(string id);
	string getNationalID();
	void setPassword(string password);
	string getPassword();
	void setphoneNumber(string phone_number);
	string getphoneNumber();
	void setAddress(string Address);
	string getAddress();
	void setEmail(string Email);
	string getEmail();
	void setGovern(string govern);
	string getGovern();
	~Person();
};

