#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Vaccine.h"
#include"ArrayList.cpp"
#include <fstream>
#include <sstream>
#include<algorithm>


//External Library to make a table 
#include"tabulate/tabulate.hpp"
using namespace tabulate;


using namespace std;

//Global Variables to get data from file
ArrayList<User>users;
ArrayList<Vaccine>allVaccs;
ArrayList<string>dataUsersLogIn;
ArrayList<string>vaccinedata;
ArrayList<string>IDS;
ArrayList<string>allCountries;
ArrayList<string>allGoverns;


void getInitAllData();
void displayVaccinesInfo(); //display a table of information about every vaccine
void getAllVaccines(); // get the data from vaccines file
void getAllCountries();
void getAllIDS();
void getAllGoverns();
void SingIn(); //Sign In (LogIn) function
void Register(); //Register Function
void AdminLogIn(); //AdminLogin
void AdminPage(); //Admin Page
void RequestVaccine(User& u, int index);
void getAllUsersData();
void saveData();
void DisplayData(string id);
int checkIdValidation(string id);
bool isFound(string id);
bool checkPhoneNumber(string phoneNumber);
bool checkEmail(string email);
bool checkCountryExsist(string country);
bool checkGovernExsist(string govern);
void DisplayStats();
void displayInformation(User user);



int main() {

	getInitAllData();

	cout << "\t\t\t\t============================================\n";
	cout << "\t\t\t\t|| Welcome To Vaccine Track System GEN 24 ||\n";
	cout << "\t\t\t\t============================================\n";


	while (true) {
		string answer;


		Table menue;

		menue.add_row({ "1-Sign In","2- Register","3-Close System" });
		menue.row(0).format().font_color(Color::yellow);
		cout << menue << endl;
		cout << "Choose what do you Want : ";

		ws(cin);
		getline(cin, answer);
		string rev_string = answer;
		int len = answer.length();
		bool fal = true;
		switch (answer[0])
		{
		case '1':
			SingIn();
			break;
		case '2':
			Register();
			break;
		case '*':
			if (!(answer[0] == '*' && answer[len - 1] == '#'))
				fal = false;
			for (int i = 1; i < len - 1; i++) {
				if (answer[i] != answer[len - 1 - i])
					fal = false;
			}
			if (fal) {
				AdminLogIn();
			}
			else {
				cout << "Wrong Choice" << endl;
			}
			break;
		}
		if (answer[0] == '3') {
			saveData();
			break;
		}
	}
	return 0;
}

void SingIn() {

	string mytext;
	ifstream data("Files\\Accounts.txt");
	for (int i = 0; i < dataUsersLogIn.getcount(); i++) {
		dataUsersLogIn.RemoveElement(i);
	}
	while (getline(data, mytext))
	{
		dataUsersLogIn.append(mytext);

	}
	data.close();

	string id;
	string password;
	bool flagid = 0;
	bool flagpass = 0;
	int counter = 0;
	cout << "enter your id : ";
	ws(cin);
	getline(cin, id);
	cout << "please enter your password : ";
	ws(cin);
	getline(cin, password);

	for (int i = 0; i < dataUsersLogIn.getcount(); i += 2)
	{


		//check the id
		if (dataUsersLogIn.getElementAtposition(i) == id)
		{

			flagid = 1;

		}
		//check the password
		if (dataUsersLogIn.getElementAtposition(i + 1) == password)
		{
			flagpass = 1;

		}



		if (flagid == 1 && flagpass == 1)
			break;

		else if (flagid == 1 && flagpass == 0)
			flagid = 0;

		else if (flagid == 0 && flagpass == 1)
			flagpass = 0;

	}
	if (flagid == 1 && flagpass == 1)
	{
		User u;
		int index = 0;
		for (int i = 0; i < users.getcount(); i++) {
			if (users.getElementAtposition(i).getNationalID() == id) {
				u = users.getElementAtposition(i);
				index = i;
				break;
			}
		}
		bool Delete = false;
		while (!Delete) {
			User user;
			int index;
			for (int i = 0; i < users.getcount(); i++) {
				if (id == users.getElementAtposition(i).getNationalID()) {
					user = users.getElementAtposition(i);
					index = i;
					break;
				}
			}
			int answer;
			Table menue;

			menue.add_row({ "1- Request Vaccine","2- See Vaccines Information","3-Show Information","4-Update", "5-Delete Account", "6-Log Out" });
			menue.row(0).format().font_color(Color::yellow);

			cout << menue << endl;
			cout << "Choose what do you Want : ";
			cin >> answer;
			if (answer == 1)
				RequestVaccine(u, index);
			else if (answer == 2)
				displayVaccinesInfo();
			else if (answer == 3) {

				displayInformation(user);

			}
			else if (answer == 4) {

				Table table;
				table.add_row({ "1-Name", "2-Age", "3-Gender", "4-Country","5-Government","6-Address","7-Phone","8-Password","9-Email"});
				table.row(0).format().font_background_color(Color::red).font_style({ FontStyle::bold, FontStyle::italic });


				cout << table << endl << endl;
				while (true) {
					int num;
					cout << "Enter number the feild that you want to Update : ";
					cin >> num;
					if (num == 1) {
						string name;
						cout << "Your current Name is : " << user.getName() << endl;
						cout << "Enter Your New Name : ";
						ws(cin);
						getline(cin, name);
						user.setName(name);
						users.RemoveElement(index);
						users.insert(index, user);
						break;
					}
					else if (num == 2) {
						int Age;
						cout << "Your old Age is : " << user.getAge() << endl;
						cout << "Enter Your New Name : ";
						cin >> Age;
						user.setAge(Age);
						users.RemoveElement(index);
						users.insert(index, user);
						break;
					}
					else if (num == 3) {
						string Gender;
						cout << "Your current Gender is : " << user.getAge() << endl;
						while (true) {
							cout << "Enter Your New Gender : ";
							ws(cin);
							getline(cin, Gender);
							for_each(Gender.begin(), Gender.end(), [](char& c) {
								c = tolower(c);
								});

							if (Gender == "male" || Gender == "female") {
								break;
							}
							else {
								cout << "Wrong , Make Sure to enter your gender as (male or female)" << endl;
							}
						}
						user.setGender(Gender);
						users.RemoveElement(index);
						users.insert(index, user);
						break;

					}
					else if (num == 4) {

						string country;
						string govern;
						cout << "Your Previous Country : " << users.getElementAtposition(index).getCountry() << endl;
						while (true) {
							cout << "Enter Your New Country : ";
							ws(cin);
							getline(cin, country);
							bool check = checkCountryExsist(country);
							if (check) {
								break;
							}
							else {
								cout << "This Country Doesn't Exsist , Please Enter Your Country" << endl;
							}
						}
						if (country == "egypt") {
							while (true) {
								cout << "Enter Your Government : ";
								ws(cin);
								getline(cin, govern);
								bool check = checkGovernExsist(govern);
								if (check) {
									break;
								}
								else {
									cout << "This Government Doesn't Exsist , Please Enter Your Government" << endl;
								}
							}
						}
						else {
							govern = "none";
						}

						user.setCountry(country);
						user.setGovern(govern);
						users.RemoveElement(index);
						users.insert(index, user);
						break;

					}
					else if (num == 5) {
						string govern;
						while (true) {
							cout << "Enter Your Government : ";
							ws(cin);
							getline(cin, govern);
							bool check = checkGovernExsist(govern);
							if (check) {
								break;
							}
							else {
								cout << "This Government Doesn't Exsist , Please Enter Your Government" << endl;
							}
						}

						user.setGovern(govern);
						users.RemoveElement(index);
						users.insert(index, user);
						break;
					}
					else if (num == 6) {
						cout << "Your old Adress is : " << user.getAddress() << endl;
						string address;
						while (true) {
							int Isnumber = 0;
							cout << "Enter Address : ";
							ws(cin);
							getline(cin, address);
							for (int i = 0; i < address.length(); i++) {
								int ascinumber = (int)address[i];
								if (ascinumber >= 48 && ascinumber <= 57) {
									Isnumber = 1;
								}

							}
							if (Isnumber == 1) {
								break;
							}
							else
								cout << "address should has number of street" << endl;
						}
						user.setAddress(address);
						users.RemoveElement(index);
						users.insert(index, user);
						break;
					}
					else if (num == 7) {
						cout << "Your current Phone is : " << user.getphoneNumber() << endl;
						string phoneNumber;
						int lengthOfPhone = 0;
						while (true) {
							cout << "Enter Phone Number : ";
							ws(cin);
							getline(cin, phoneNumber);
							lengthOfPhone = phoneNumber.length();
							if (lengthOfPhone == 11) {
								if (checkPhoneNumber(phoneNumber))
									break;
							}
							else
								cout << "phone number must be 11 digits" << endl;
						}
						user.setphoneNumber(phoneNumber);
						users.RemoveElement(index);
						users.insert(index, user);
						break;
					}
					else if (num == 8) {
						string Pass;
						int lengthOfPass = 0;
						bool LowerLetter, IsNumber, SpecialCharacter, UpperLetter = false;
						while (true) {

							cout << "Enter Password (your password must be more than 8 digits and like Password123$ ): ";
							ws(cin);
							getline(cin, Pass);

							lengthOfPass = Pass.length();


							for (int i = 0; i < lengthOfPass; i++) {

								int asci_number = (int)password[i];
								if (asci_number >= 33 && asci_number <= 45) {
									SpecialCharacter = true;
								}
								if (asci_number >= 65 && asci_number <= 90) {
									UpperLetter = true;
								}
								if (asci_number >= 48 && asci_number <= 57) {
									IsNumber = true;
								}
								if (asci_number >= 97 && asci_number <= 122) {
									LowerLetter = true;
								}

							}

							if (IsNumber == true && SpecialCharacter == true && UpperLetter == true && LowerLetter == true && lengthOfPass >= 8) {
								cout << "congrats your password is valid" << endl;
								break;
							}
							else
								cout << "password is invalid" << endl;
						}
						user.setPassword(Pass);
						users.RemoveElement(index);
						users.insert(index, user);
						break;
					}
					else if (num == 9) {
						cout << "Your current Email is : " << user.getEmail() << endl;
						string Email;
						bool EmailChar = false;
						while (true)
						{
							cout << "Enter Email : ";
							ws(cin);
							getline(cin, Email);
							for (int i = 0; i < Email.length(); i++) {

								int asci_number = (int)Email[i];
								if (asci_number == 64) {
									EmailChar = true;
								}

							}
							if (EmailChar == true) {
								if (checkEmail(Email)) {
									break;
								}
								else {
									cout << "This Email is already exsist" << endl;
								}

							}
							else if (EmailChar == false) {
								cout << "enter email like that example@.com" << endl;
							}
						}

						user.setEmail(Email);
						users.RemoveElement(index);
						users.insert(index, user);
						break;
					}
				}

			}

			else if (answer == 5) {
				while (true) {
					string value;
					cout << "Are you sure to delete Your Acount (Y/N) : ";
					cin >> value;
					if (value[0] == 'y' || value[0] == 'Y') {
						users.RemoveElement(index);
						saveData();
						User::TotalUsers--;
						Delete = true;
						break;

					}
					else if (value[0] == 'N' || value[0] == 'n') {
						break;

					}
				}

			}
			else if (answer == 6) {
				break;
			}

			else
				cout << "Wrong Choice , Enter A Number from(1 to 6)" << endl;
		}
	}

	else
	{
		cout << "check your id or password" << endl;
	}
}

void Register() {
	string name, gender, nid, address, phoneNumber, country, password, Email, passwordAgain, government;
	int age, lengthOfPass, lengthOfID, lengthOfPhone, Isnumber;
	Isnumber = 0;
	bool UpperLetter, SpecialCharacter, IsNumber, LowerLetter, EmailChar;
	UpperLetter = SpecialCharacter = IsNumber = LowerLetter = EmailChar = false;
	cout << "Enter Name : ";
	ws(cin);
	getline(cin, name);
	cout << "Enter Age : ";
	cin >> age;
	//IDfile.open("Files/IDS.txt");
	int error = 0;
	while (error != 200) {
		cout << "Enter National ID : ";

		ws(cin);
		getline(cin, nid);
		error = checkIdValidation(nid);


	}


	cout << "Enter Gender (male / female) : ";
	while (gender != "male" && gender != "female") {
		ws(cin);
		getline(cin, gender);

		for_each(gender.begin(), gender.end(), [](char& c) {
			c = tolower(c);
			});

		if (gender != "male" && gender != "female") {
			cout << "Make Sure to enter your gender(male or female)" << endl;
		}
	}

	while (true) {
		cout << "Enter Country : ";
		ws(cin);
		getline(cin, country);

		for_each(country.begin(), country.end(), [](char& c) {
			c = tolower(c);
			});
		bool check = checkCountryExsist(country);
		if (check) {
			if (country == "egypt") {
				while (true) {
					cout << "Enter the government: ";
					ws(cin);
					getline(cin, government);
					for_each(government.begin(), government.end(), [](char& c) {
						c = tolower(c);
						});
					bool checkgovern = checkGovernExsist(government);
					if (checkgovern) {
						break;
					}
					else {
						cout << "Sorry, but this government doesn't exsist" << endl;
					}
				}
			}
			break;
		}
		else {
			cout << "Sorry,but this country doesn't exsist" << endl;
		}
	}
	while (true) {
		cout << "Enter Address : ";
		ws(cin);
		getline(cin, address);
		for (int i = 0; i < address.length(); i++) {
			int ascinumber = (int)address[i];
			if (ascinumber >= 48 && ascinumber <= 57) {
				Isnumber = 1;
			}

		}
		if (Isnumber == 1) {
			break;
		}
		else
			cout << "address should has number of street" << endl;
	}
	while (true) {
		cout << "Enter Phone Number : ";
		ws(cin);
		getline(cin, phoneNumber);
		lengthOfPhone = phoneNumber.length();
		if (lengthOfPhone == 11) {
			if (checkPhoneNumber(phoneNumber))
				break;
		}
		else
			cout << "phone number must be 11 digits" << endl;
	}
	while (true) {
		cout << "Enter Password (your password must be more than 8 digits and like Password123$ ): ";



		ws(cin);
		getline(cin, password);

		lengthOfPass = password.length();


		for (int i = 0; i < lengthOfPass; i++) {

			int asci_number = (int)password[i];
			if (asci_number >= 33 && asci_number <= 45) {
				SpecialCharacter = true;
			}
			if (asci_number >= 65 && asci_number <= 90) {
				UpperLetter = true;
			}
			if (asci_number >= 48 && asci_number <= 57) {
				IsNumber = true;
			}
			if (asci_number >= 97 && asci_number <= 122) {
				LowerLetter = true;
			}



		}

		if (IsNumber == true && SpecialCharacter == true && UpperLetter == true && LowerLetter == true && lengthOfPass >= 8) {
			cout << "congrats your password is valid" << endl;
			while (true)
			{
				cout << "enter your password again: " << endl;
				ws(cin);
				getline(cin, passwordAgain);
				if (passwordAgain == password) {

					cout << "congrats your password matched" << endl;
					break;

				}
				else
					cout << "the password didn't match ,please try again" << endl;
			}

			break;
		}
		else
			cout << "password is invalid" << endl;




	}

	while (true)
	{
		cout << "Enter Email : ";
		ws(cin);
		getline(cin, Email);
		for (int i = 0; i < Email.length(); i++) {

			int asci_number = (int)Email[i];
			if (asci_number == 64) {
				EmailChar = true;
			}

		}
		if (EmailChar == true) {
			if (checkEmail(Email)) {
				break;
			}
			else {
				cout << "This Email is already exsist" << endl;
			}

		}
		else if (EmailChar == false) {
			cout << "enter email like that example@.com" << endl;
		}
	}



	Vaccine vac;
	User u(
		name,
		nid,
		gender,
		age,
		address,
		phoneNumber,
		country,
		government,
		password,
		Email,
		vac,
		-1,
		false,
		false
	);
	users.append(u);
	User::incTotalUsers();
	saveData();
}

void getAllVaccines() {
	//intial vaccine to store it
	Vaccine Vacc;

	//Intial Variables to store it in Vaccine to store it in all Vacccines vectors
	string text;
	bool whoapp;
	int NumberOfDose;
	int Degree;

	ifstream MyReadFile("Files\\Vaccines.txt");    // get the file to read data from it

	int counter = 0; // to know which line we are at (1,2,3,4,5)

	//LOOP To store data
	while (getline(MyReadFile, text)) {
		counter++;
		switch (counter)
		{
		case 1:
			Vacc.setVaccineCompanyName(text);
			break;
		case 2:
			istringstream(text) >> whoapp;
			Vacc.setApprove(whoapp);
			break;
		case 3:
			istringstream(text) >> NumberOfDose;
			Vacc.setNumberofDose(NumberOfDose);
			break;
		case 4:
			istringstream(text) >> Degree;
			Vacc.setDegree(Degree);
			break;

		default:
			break;
		}

		if (counter == 4) {
			allVaccs.append(Vacc);
			counter = 0;
		}

	}
	//Make Sure to Close File after get the data from it :)
	MyReadFile.close();
}

void displayVaccinesInfo() {
	Table vaccTable;
	vaccTable.add_row({ "Company", "WHO Approve", "Doses", "Storage" });

	for (int i = 0; i < allVaccs.getcount(); i++) {
		vaccTable.add_row({
			allVaccs.getElementAtposition(i).getVaccineCompanyName(),
			(allVaccs.getElementAtposition(i).getApprove() ? "T" : "F"),
			(to_string(allVaccs.getElementAtposition(i).getNumberofDose()) + ""),
			(to_string(allVaccs.getElementAtposition(i).getDegree()) + " C")
			});
	}
	for (int i = 0; i < 7; i++) {
		if (vaccTable[i][1].get_text() == "F") {
			vaccTable[i][1].format().font_color(Color::red);
		}
		else {
			vaccTable[i][1].format().font_color(Color::green);
		}
	}
	for (int i = 0; i < 4; i++)
		vaccTable.column(i).format()
		.font_align(FontAlign::center);

	for (int i = 0; i < 4; i++) {
		vaccTable[0][i].format()
			.font_color(Color::blue)
			.font_align(FontAlign::center)
			.font_style({ FontStyle::bold });
	}
	cout << vaccTable << endl;
}

void AdminLogIn() {

	ArrayList<string> datafile;
	ifstream data;
	data.open("Files/Admins.txt");
	string fromfile;
	while (getline(data, fromfile)) {
		datafile.append(fromfile);
	}
	string ad_id;
	string ad_pass;
	while (true) {
		cout << "ID : ";
		ws(cin);
		getline(cin, ad_id);
		cout << "Password : ";
		ws(cin);
		getline(cin, ad_pass);

		if (datafile.getElementAtposition(0) == ad_id) {
			if (datafile.getElementAtposition(1) == ad_pass) {
				AdminPage();
				break;
			}
			else {
				cout << "Wrong password" << endl;
			}
		}
		else {
			cout << "Wrong ID" << endl;
		}
	}

}

void AdminPage() {

	while (true) {
		int answer;
		Table table;
		table.add_row({ "1-Vaccine Data", "2-See Record", "3-Vaccines Statistics", "4-Update Number Of Doses Taken","5-Log Out"});
		table.row(0).format().font_background_color(Color::red).font_style({ FontStyle::bold, FontStyle::italic });
		cout << table << endl << endl;
		cin >> answer;
		if (answer == 1)
		{
			displayVaccinesInfo();
		}
		else if (answer == 2) {
			cout << "Enter ID to show the data : ";
			string id;
			ws(cin);
			getline(cin, id);
			DisplayData(id);
		}
		else if (answer == 3) {
			DisplayStats();
		}
		else if (answer == 4) {
			while (true) {
				string id;
				int index = -1;
				User user;
				cout << "Enter User ID : ";
				ws(cin);
				getline(cin, id);
				for (int i = 0; i < users.getcount(); i++) {
					if (id == users.getElementAtposition(i).getNationalID()) {
						user = users.getElementAtposition(i);
						index = i;
						break;
					}
				}
				if (index == -1) {
					cout << "Sorry , This id doesn't exsist , Please Try Again Later" << endl;
					break;
				}
				else {
					cout << "User Name : " << users.getElementAtposition(index).getName() << endl;
					cout << "Number Of Doses Should Be Taken : ";
					(users.getElementAtposition(index).getNumberOfDosesTaken() == -1) ? cout << "0" << endl : cout << users.getElementAtposition(index).getNumberOfDosesTaken() << endl;

					char ch;
					while (true) {
						cout << "Did This User Take A Dose (Y/N) ?";
						cin >> ch;
						if (ch == 'Y' || ch == 'y') {
							if (users.getElementAtposition(index).getNumberOfDosesTaken() == 0) {
								cout << "This Person is already get Vaccined" << endl;
								break;
							}
							else if (users.getElementAtposition(index).getNumberOfDosesTaken() == -1) {
								cout << "This Person didn't request any vaccine , yet" << endl;
								break;
							}
							else {
								user.setNumberOfDosesTaken(user.getNumberOfDosesTaken() - 1);
								users.RemoveElement(index);
								users.insert(index, user);
								User::oneDoseNo++;
								saveData();
								break;
							}
						}
						else if(ch == 'n'||ch=='N') {
							break;
						}
						else {
							cout << "Wrong Answer ,Please Try Again" << endl;
						}
					}
					break;
				}
			}
		}
		else if (answer == 5) {
			break;
		}
		else {
			cout << "Wrong Answer , Enter A Number from(1 to 5)" << endl;
		}
	}
}

void RequestVaccine(User& u, int index)
{
	string mytext;
	ifstream data("Files\\Vaccines.txt");
	while (getline(data, mytext))
	{
		vaccinedata.append(mytext);

	}
	int count = 1;
	for (int i = 0; i < vaccinedata.getcount(); i += 4)
	{
		cout << count << "-";
		cout << vaccinedata.getElementAtposition(i) << endl;
		count++;
	}

	data.close();

	cout << "Enter Your Choice (Please , Make Sure to Choose one of the above Vaccines (1-6) : ";
	int choice;
	cin >> choice;
	if (choice <= 0 || choice > 6) {
		cout << "Wrong choice" << endl;
	}
	else {
		Vaccine vacc = allVaccs.getElementAtposition(choice - 1);
		User temp = u;
		temp.setNumberOfDosesTaken(vacc.getNumberofDose());
		temp.setVaccine(vacc);
		users.RemoveElement(index);
		users.insert(index, temp);
		saveData();
		User::incRequestedNo();
		cout << "English : " << endl;
		cout << "Congratulations, you have booked an appointment to get the Coronavirus vaccine, and it is " << vacc.getVaccineCompanyName() << " And you have to take a  " << vacc.getNumberofDose() << "number of doses" << endl;
		cout << "French : " << endl;
		cout << "Félicitations, vous avez prévu un rendez-vous pour obtenir le vaccin contre le coronavirus et c'est " << vacc.getVaccineCompanyName() << " Vous devez prendre " << vacc.getNumberofDose() << "nombre de doses" << endl;

	}

}

void getAllUsersData() {
	ifstream usersfile("Files/Users.txt");
	string dataline;

	int age;
	bool getVaccined;
	bool Abroad;
	int number_of_doses_taken = 0;
	User u;
	int counter = 0;
	while (getline(usersfile, dataline)) {
		counter++;

		if (counter == 1) {
			u.setNationalID(dataline); //save id in the first line 
		}
		else if (counter == 2) {
			u.setName(dataline); //save name in the second line
		}
		else if (counter == 3) {
			stringstream(dataline) >> age;
			u.setAge(age); //save age in the third line
		}
		else if (counter == 4) {
			u.setGender(dataline); //save gender in the forth line
		}
		else if (counter == 5) {
			u.setCountry(dataline); //save country in the fifth line
		}
		else if (counter == 6) {
			u.setGovern(dataline); //save government in the sixth line
		}
		else if (counter == 7) {
			u.setAddress(dataline); //save address in the seventh line
		}
		else if (counter == 8) {
			u.setphoneNumber(dataline);
		}
		else if (counter == 9) {
			u.setPassword(dataline);
		}
		else if (counter == 10) {
			u.setEmail(dataline);
		}
		else if (counter == 11) {
			Vaccine Vacc;
			for (int i = 0; i < allVaccs.getcount(); i++) {
				if (dataline == allVaccs.getElementAtposition(i).getVaccineCompanyName()) {
					Vacc = allVaccs.getElementAtposition(i);
					User::incRequestedNo();
					break;
				}

			}
			u.setVaccine(Vacc);
		}
		else if (counter == 12) {
			istringstream(dataline) >> getVaccined;
			u.setVacciend(getVaccined);
		}
		else if (counter == 13) {
			istringstream(dataline) >> Abroad;
			u.setIsAbroad(Abroad);

		}
		else if (counter == 14) {
			istringstream(dataline) >> number_of_doses_taken;
			u.setIsAbroad(number_of_doses_taken);
			users.append(u);
			User::incTotalUsers();
			counter = 0;
		}
	}
}

void  DisplayData(string id) {

	int index = 0;
	for (int i = 0; i < users.getcount(); i++) {
		if (id == users.getElementAtposition(i).getNationalID())
		{
			cout << "National ID : " << users.getElementAtposition(i).getNationalID() << endl;
			cout << "Name :  " << users.getElementAtposition(i).getName() << endl;
			cout << "Address: " << users.getElementAtposition(i).getAddress() << endl;
			cout << "Country : " << users.getElementAtposition(i).getCountry() << endl;
			users.getElementAtposition(i).getIsAbroad() ? cout << "" : cout << "Government : " << users.getElementAtposition(i).getGovern() << endl;
			cout << "Email : " << users.getElementAtposition(i).getEmail() << endl;
			cout << "Gender : " << users.getElementAtposition(i).getGender() << endl;
			cout << "Phone Number : " << users.getElementAtposition(i).getphoneNumber() << endl;
			!(users.getElementAtposition(i).getVaccine().getVaccineCompanyName() == " ") ? cout << "Vaccine Company Name : " << users.getElementAtposition(i).getVaccine().getVaccineCompanyName() << "\nNumber of Doses Should be Taken : " << users.getElementAtposition(i).getNumberOfDosesTaken() << endl : cout << "";
			index = i;
			break;
		}
	}
	while (true) {

		cout << "Do You Want Delete this Recored ? (y/n) : ";
		char answer;
		cin >> answer;

		if (answer == 'y' || answer == 'Y') {
			users.RemoveElement(index);
			break;
		}
		else if (answer == 'n' || answer == 'N') {
			break;
		}
		else {
			cout << "Wrong Choice please enter y for yes and n for no" << endl;
		}
	}
}


int checkIdValidation(string id) {

	for (int i = 0; i < id.length(); i++) {
		if (!(id[i] >= 48 && id[i] <= 57))
		{
			cout << "please Enter Right Id not contain character" << endl;
			return 404;
		}
	}
	if (id.length() < 14 || id.length() > 14)
	{
		cout << "Please Enter Id of 14 number only" << endl;
		return 405;
	}


	if (!isFound(id)) {
		IDS.append(id);
		ofstream Writer("Files/IDS.txt");
		for (int i = 0; i < IDS.getcount(); i++) {
			Writer << IDS.getElementAtposition(i) << endl;
		}
		Writer.close();
	}
	else {
		cout << "Sorry , This National ID is already Exsist in the system" << endl;
		return 401;
	}
	return 200;
}
bool isFound(string id) {

	for (int i = 0; i < IDS.getcount(); i++) {
		if (IDS.getElementAtposition(i) == id) {
			return true;
		}
	}

	return false;
}

bool checkPhoneNumber(string phoneNumber) {
	for (int i = 0; i < phoneNumber.length(); i++) {
		if (!(phoneNumber[i] >= 48 && phoneNumber[i] <= 57))
		{
			cout << "please Enter Right Phone Number not contain character" << endl;
			return false;
		}
	}
	return true;
}

bool checkEmail(string email) {
	for (int i = 0; i < users.getcount(); i++) {
		if (users.getElementAtposition(i).getEmail() == email) {
			return false;
		}
	}
	return true;
}

void getInitAllData() {
	getAllVaccines();
	getAllUsersData();
	getAllCountries();
	getAllGoverns();
	getAllIDS();
}
void getAllCountries() {
	ifstream data("Files/AllCountries.txt");
	string text;
	while (getline(data, text)) {
		transform(text.begin(), text.end(), text.begin(), ::tolower);
		allCountries.append(text);
	}
	data.close();
}
void getAllGoverns() {
	ifstream data("Files/Govs.txt");
	string text;
	while (getline(data, text)) {
		transform(text.begin(), text.end(), text.begin(), ::tolower);
		allGoverns.append(text);
	}
	data.close();
}

void getAllIDS() {
	ifstream infile("Files/IDS.txt");
	string ids;
	while (getline(infile, ids)) {
		IDS.append(ids);
	}
	infile.close();
}

bool checkCountryExsist(string country) {

	for (int i = 0; i < allCountries.getcount(); i++) {
		if (country == allCountries.getElementAtposition(i)) {
			return true;
		}
	}
	return false;
}
bool checkGovernExsist(string govern) {
	for (int i = 0; i < allGoverns.getcount(); i++) {
		if (govern == allGoverns.getElementAtposition(i)) {
			return true;
		}
	}
	return false;
}
void saveData() {

	ofstream AcountsFile, RegisterFile, IDSFile;
	AcountsFile.open("Files/Accounts.txt");
	RegisterFile.open("Files/Users.txt");
	IDSFile.open("Files/IDS.txt");
	for (int i = 0; i < users.getcount(); i++) {
		IDSFile << users.getElementAtposition(i).getNationalID() << endl;

		AcountsFile << users.getElementAtposition(i).getNationalID() << endl;
		AcountsFile << users.getElementAtposition(i).getPassword() << endl;

		RegisterFile << users.getElementAtposition(i).getNationalID() << endl;
		RegisterFile << users.getElementAtposition(i).getName() << endl;
		RegisterFile << users.getElementAtposition(i).getAge() << endl;
		RegisterFile << users.getElementAtposition(i).getGender() << endl;
		RegisterFile << users.getElementAtposition(i).getCountry() << endl;
		if (users.getElementAtposition(0).getCountry() == "egypt")
			RegisterFile << users.getElementAtposition(i).getGovern() << endl;
		else
			RegisterFile << "None" << endl;
		RegisterFile << users.getElementAtposition(i).getAddress() << endl;
		RegisterFile << users.getElementAtposition(i).getphoneNumber() << endl;
		RegisterFile << users.getElementAtposition(i).getPassword() << endl;
		RegisterFile << users.getElementAtposition(i).getEmail() << endl;
		RegisterFile << users.getElementAtposition(i).getVaccine().getVaccineCompanyName() << endl;
		RegisterFile << users.getElementAtposition(i).getIsAbroad() << endl;
		RegisterFile << users.getElementAtposition(i).getVacciend() << endl;
		RegisterFile << users.getElementAtposition(i).getNumberOfDosesTaken() << endl;

	}
	RegisterFile.close();
	AcountsFile.close();
	IDSFile.close();
}
void DisplayStats() {
	float RequestedPre = (float)User::getRequestedNo() / User::getTotalUsers();
	float fullyVacPre = (float)User::getVaccinedUsers() / User::getTotalUsers();
	float unVacPre = (float)(1 - fullyVacPre);
	float oneDosePre = (float)User::getOneDoseNo() / User::getTotalUsers();
	cout << "Total users: " << User::getTotalUsers() << endl;
	cout << "Number and percentage of users requested for vaccination: " << User::getRequestedNo() << "  " << RequestedPre * 100 << "%" << endl;
	cout << "Number of users took at least one dose: " << User::getOneDoseNo() << "  " << oneDosePre * 100 << "%" << endl;
	cout << "Number of totally vaccined users: " << User::getVaccinedUsers() << "  " << fullyVacPre * 100 << "%" << endl;

}

void displayInformation(User user) {
	Table date;
	date.add_row({ "National ID", "Name", "Age", "Gender", "Country","Government","Address","Phone","Email","Password","VaccineType","Number Of Dose","Vaccined" });
	date.add_row({
			user.getNationalID(),
			user.getName(),
			(to_string(user.getAge()) + ""),
			user.getGender(),
			user.getCountry(),
			user.getGovern(),
			user.getAddress(),
			user.getphoneNumber(),
			user.getEmail(),
			user.getPassword(),
			user.getVaccine().getVaccineCompanyName() == "" ? "None" : user.getVaccine().getVaccineCompanyName(),
			(to_string(user.getNumberOfDosesTaken()) + ""),
			user.getVacciend() == 0 ? "NO" : "Yes",


		});
	for (size_t i = 0; i < 13; ++i) {
		date[0][i].format()
			.font_color(Color::yellow)
			.font_align(FontAlign::center)
			.font_style({ FontStyle::bold });
	}
	for (size_t i = 0; i < 12; ++i) {
		date[1][0].format().font_background_color(Color::red).font_align(FontAlign::center);

		date[1][i + 1].format()
			.font_align(FontAlign::center)
			.font_style({ FontStyle::bold }).font_background_color(Color::green);

	}
	cout << date << endl << endl;

}