#pragma once
#include<string>
#include "Vaccine.h"
#include "Person.h"

using namespace std;

struct date {

	int day = 0;
	int month = 0;
	int year = 2020;
};

class User : public Person
{
	Vaccine vacc;
	int number_of_doses_taken;
	bool vaccined;
	bool isAbroad;
	date firstVaccineDoseDate;
	date SecondVaccineDoseDate;
public:
	static int TotalUsers;
	static int RequestedNo;
	static int oneDoseNo;
	static int VaccinedUsers;
	User();
	User(
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
		bool vaccined,
		bool isAbroad
	);
	void setFirstDoseDate(int day , int month ,int year);
	void setSecondDoseDate();
	int getFirstDoseDay();
	int getFirstDoseMonth();
	int getFirstDoseYear();
	int getSecondDoseDay();
	int getSecondDoseMonth();
	int getSecondDoseYear();
	void setName(string name);
	void setVacciend(bool vacciend);
	void setIsAbroad(bool isAbroad);
	int getNumberOfDosesTaken();
	void setNumberOfDosesTaken(int);
	bool getVacciend();
	void setVaccine(Vaccine vacc);
	Vaccine getVaccine();
	bool getIsAbroad();
	static int getTotalUsers();
	static int getRequestedNo();
	static int getOneDoseNo();
	static int getVaccinedUsers();
	static void incRequestedNo();
	static void incOneDoseNo();
	static void incVaccinedUsers();
	static void incTotalUsers();
	~User();
};

