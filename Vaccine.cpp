#pragma once

#include "Vaccine.h"
#include <string>

using namespace std;

Vaccine::Vaccine() {
	company_name = " ";
	NumberofDose = 0;
	degree = 0;
	who_approve = false;
}

Vaccine::Vaccine(
	string name,
	int NumberofDose,
	int degree,
	bool uk_approve
) {
	this->company_name = name;
	this->NumberofDose = NumberofDose;
	this->degree = degree;
	this->who_approve = uk_approve;
}

void Vaccine::setApprove(bool uk_approve) {

	this->who_approve = uk_approve;
}

void Vaccine::setDegree(int degree) {
	this->degree = degree;
}

void Vaccine::setNumberofDose(int NumberofDose) {
	this->NumberofDose = NumberofDose;
}

void Vaccine::setVaccineCompanyName(string name) {
	this->company_name = name;
}

string Vaccine::getVaccineCompanyName() {
	return this->company_name;
}

bool Vaccine::getApprove() {
	return this->who_approve;
}

int Vaccine::getDegree() {
	return this->degree;
}
int Vaccine::getNumberofDose() {
	return this->NumberofDose;
}

Vaccine::~Vaccine() {}