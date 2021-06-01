#pragma once

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

int User::TotalUsers{ 0 };
int User::RequestedNo{ 0 };
int User::oneDoseNo{ 0 };
int User::VaccinedUsers{ 0 };


User::User() {
	Vaccine vacc;
	this->vacc = vacc;
	this->number_of_doses_taken = 0;
	this->vaccined = false;
	this->isAbroad = false;

}
User::User(
	string fullname,
	string NationalID,
	string Gender,
	int age,
	string address,
	string phoneNumber,
	string country,
	string govern,
	string password,
	string Email,
	Vaccine vacc,
	int number_of_doses_taken,
	bool vacciend,
	bool isAbroad) :Person(
		fullname,
		NationalID,
		Gender,
		age,
		address,
		phoneNumber,
		country,
		govern,
		password,
		Email
	) {
	this->vacc = vacc;
	this->number_of_doses_taken = number_of_doses_taken;
	this->vaccined = vacciend;
	this->isAbroad = isAbroad;


}

void User::setVacciend(bool vacciend) {
	this->vaccined = vacciend;
}

void User::setName(string name) {

	this->fullname = name;
}


void User::incRequestedNo() {
	RequestedNo++;
}
void User::incTotalUsers() {
	TotalUsers++;
}
void User::incOneDoseNo() {
	oneDoseNo++;
}
void User::incVaccinedUsers() {
	VaccinedUsers++;
}

void User::setVaccine(Vaccine vacc) {
	this->vacc = vacc;
}

void User::setNumberOfDosesTaken(int number_of_doses_taken) {
	this->number_of_doses_taken = number_of_doses_taken;
}

void User::setIsAbroad(bool isAbroad) {
	this->isAbroad = isAbroad;
}

bool User::getVacciend() {
	return vaccined;
}

bool User::getIsAbroad() {
	return isAbroad;
}

int User::getNumberOfDosesTaken() {
	return number_of_doses_taken;
}
Vaccine User::getVaccine() {
	return vacc;
}

int User:: getRequestedNo() {
	return RequestedNo;
}
int User::getOneDoseNo() {
	return oneDoseNo;
}
int User::getVaccinedUsers() {
	return VaccinedUsers;
}
int User::getTotalUsers() {
	return TotalUsers;
}

User::~User() {}