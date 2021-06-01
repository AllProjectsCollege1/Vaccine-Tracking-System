#pragma once
#include <string>
#include<iostream>

using namespace std;

class Vaccine
{
private:
	string company_name;
	int NumberofDose;
	int degree;
	bool who_approve;
public:
	Vaccine();
	Vaccine(
		string name,
		int NumberofDose,
		int degree,
		bool who_approve
	);
	void setVaccineCompanyName(string name);
	void setNumberofDose(int NumberofDose);
	void setDegree(int degree);
	void setApprove(bool who_approve);
	string getVaccineCompanyName();
	int getNumberofDose();
	int getDegree();
	bool getApprove();
	~Vaccine();
};

