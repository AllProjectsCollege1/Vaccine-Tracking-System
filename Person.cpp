#pragma once
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person() {
	this->fullname = " ";
	this->NationalID = " ";
	this->Gender = " ";
	this->age = 0;
	this->phoneNumber = " ";
	this->country = " ";
	this->govern = " ";
	this->password = " ";
	this->address = " ";
	this->Email = " ";
}

Person::Person(string fullname,
	string NationalID,
	string Gender,
	int age,
	string address,
	string phoneNumber,
	string country,
	string govern,
	string password,
	string Email) {
	this->fullname = fullname;
	this->NationalID = NationalID;
	this->Gender = Gender;
	this->age = age;
	this->phoneNumber = phoneNumber;
	this->country = country;
	this->govern = govern;
	this->password = password;
	this->address = address;
	this->Email = Email;
}

void Person::setName(string name) {
	this->fullname = name;
}
void Person::setphoneNumber(string phone_number) {
	phoneNumber = phone_number;
}
void Person::setGender(string gender) {
	Gender = gender;
}
void Person::setAge(int Age) {
	age = Age;
}
void Person::setPassword(string password) {
	password = password;
}

void Person::setCountry(string Country) {
	country = Country;
}
void Person::setAddress(string Address) {
	address = Address;
}

void Person::setEmail(string Email) {
	this->Email = Email;
}

void Person::setNationalID(string id) {
	this->NationalID = id;
}

void Person::setGovern(string govern) {
	this->govern = govern;
}

string Person::getName() {
	return this->fullname;
}

string Person::getNationalID() {
	return NationalID;
}

string Person::getPassword() {
	return password;
}
string Person::getphoneNumber() {
	return phoneNumber;
}

string Person::getAddress() {
	return address;
}

int Person::getAge() {
	return age;
}
string Person::getCountry() {
	return country;
}
string Person::getGender() {
	return Gender;
}
string Person::getEmail(){
	return Email;
}
string Person::getGovern() {
	return govern;
}

Person::~Person() {}