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

void User::setFirstDoseDate(int day, int month, int year) {
	firstVaccineDoseDate.day = day;
	firstVaccineDoseDate.month = month;
	firstVaccineDoseDate.year = year;
}

void User::setSecondDoseDate() {
	int day = 0;
	int month = 0;
	int year = 0;
	if (this->getVaccine().getNumberofDose() > 1) {
		if (firstVaccineDoseDate.month != 2) {
			if ((firstVaccineDoseDate.month < 8 && firstVaccineDoseDate.month % 2 != 0) || (firstVaccineDoseDate.month >= 8 && firstVaccineDoseDate.month % 2 == 0)) {
				if (firstVaccineDoseDate.day > 10) {
					if (firstVaccineDoseDate.month == 12) {
						day = (firstVaccineDoseDate.day + 21) - 31;
						month = 1;
						year = firstVaccineDoseDate.year + 1;
					}
					else {
						day = (firstVaccineDoseDate.day + 21) - 31;
						month = firstVaccineDoseDate.month + 1;
						year = firstVaccineDoseDate.year;
					}
				}
				else {
					day = firstVaccineDoseDate.day + 21;
					month = firstVaccineDoseDate.month;
					year = firstVaccineDoseDate.year;

				}
			}
			else if ((firstVaccineDoseDate.month < 8 && firstVaccineDoseDate.month % 2 == 0) || (firstVaccineDoseDate.month > 8 && firstVaccineDoseDate.month % 2 != 0)) {
				if (firstVaccineDoseDate.day > 9) {
					day = (firstVaccineDoseDate.day + 21) - 30;
					month = firstVaccineDoseDate.month + 1;
					year = firstVaccineDoseDate.year;
				}
				else {
					day = firstVaccineDoseDate.day + 21;
					month = firstVaccineDoseDate.month;
					year = firstVaccineDoseDate.year;
				}
			}
		}
		else {
			if (firstVaccineDoseDate.year % 4 == 0) {
				if (firstVaccineDoseDate.day > 8) {
					day = (firstVaccineDoseDate.day + 21) - 29;
					month = firstVaccineDoseDate.month + 1;
					year = firstVaccineDoseDate.year;

				}
				else {
					day = firstVaccineDoseDate.day + 21;
					month = firstVaccineDoseDate.month;
					year = firstVaccineDoseDate.year;

				}
			}
			else {
				if (firstVaccineDoseDate.day > 7) {
					day = (firstVaccineDoseDate.day + 21) - 28;
					month = firstVaccineDoseDate.month + 1;
					year = firstVaccineDoseDate.year;

				}
				else {
					day = firstVaccineDoseDate.day + 21;
					month = firstVaccineDoseDate.month;
					year = firstVaccineDoseDate.year;

				}
			}
		}
	}
	
	SecondVaccineDoseDate.day = day;
	SecondVaccineDoseDate.month = month;
	SecondVaccineDoseDate.year = year;
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

int User::getFirstDoseDay() {
	return firstVaccineDoseDate.day;
}
int User::getFirstDoseMonth() {
	return firstVaccineDoseDate.month;
}
int User::getFirstDoseYear() {
	return firstVaccineDoseDate.year;
}
int User::getSecondDoseDay() {
	return SecondVaccineDoseDate.day;
}
int User::getSecondDoseMonth() {
	return SecondVaccineDoseDate.month;
}
int User::getSecondDoseYear() {
	return SecondVaccineDoseDate.year;
}
User::~User() {}