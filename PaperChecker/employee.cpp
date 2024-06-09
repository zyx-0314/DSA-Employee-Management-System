#include "employee.h"

struct StackEmployee::Employee : PersonneInformation {
	string jobRole;
	BenefitNode* benefitList = nullptr;
};

struct StackEmployee::EmployeeNode {
	EmployeeNode* next = nullptr;
	Employee data;
};

struct StackEmployee::Benefit {
	string name;
	string level;
	string description;
};

struct StackEmployee::BenefitNode {
	BenefitNode* next = nullptr;
	Benefit data;
};

StackEmployee::EmployeeNode*& StackEmployee::StartPoint(EmployeeNode*& tail) {
	employeeTail = tail;
	int choice;

	do {
		MainMenu(choice);
		switch (choice) {
		case 0:
			return employeeTail;
		case 1:
			ViewEmployeeListAndSpecific(employeeTail);
			break;
		case 2:
			UpdateEmployeeInformation(employeeTail);
			break;
		case 3:
			DeleteEmployeeInformation(employeeTail);
			break;
		default:
			cout << "Choose only from 0 - 4";
			system("CLS");
			break;
		}
	} while (0 != choice);
}

void StackEmployee::MainMenu(int& choice) {
	do {
		layer;
		cout << "\t\t  Employee's Information\n";
		layer;
		cout << "\t1. View Employee's Information\n";
		cout << "\t2. Update Employee's Information\n";
		cout << "\t3. Delete Employee's Information\n";
		cout << "\t0. Return to Main Menu\n";
		layer;
		cin >> choice;
		cin.ignore();
		system("cls");

		if (0 < choice || 5 > choice)
			return;
	} while (true);
}

void StackEmployee::BenefitUpdateMenu(int& choice) {
	do
	{
		layer;
		cout << "\t\t  Benefits Options\n";
		layer;
		cout << "\t1. Update Benefit Information\n";
		cout << "\t2. Add New Benefit Information\n";
		cout << "\t0. Return to Main Menu\n";
		layer;
		cin >> choice;
		cin.ignore();
		system("cls");

		if (0 < choice || 3 > choice)
			return;
	} while (true);
}

void StackEmployee::UpdateMenu(int& choice) {
	do
	{
		layer;
		cout << "\t  Select the field you want to update:\n";
		layer;
		cout << "\t  1. Full Name\n";
		cout << "\t  2. Gender\n";
		cout << "\t  3. Age\n";
		cout << "\t  4. Birthday\n";
		cout << "\t  5. Contact Number\n";
		cout << "\t  6. Email\n";
		cout << "\t  7. Job Role\n";
		cout << "\t  8. Benefits\n";
		cout << "\t  0. Exit\n";
		layer;
		cin >> choice;
		cin.ignore();

		if (0 < choice || 9 > choice)
			return;
	} while (true);

	system("cls");
}

// Obsolete Code
//void StackEmployee::AddEmployeeInformation(EmployeeNode*& employeeTail) {
//	EmployeeNode* temp = new EmployeeNode;
//	temp->data.benefitList = new BenefitNode;
//
//	cout << "Enter Employee's Full Name: ";
//	cin.ignore();
//	getline(cin, temp->data.fullName);
//	cout << "Enter Employee ID No.: ";
//	cin >> temp->data.ID;
//	cout << "Enter Employee's Gender: ";
//	cin >> temp->data.gender;
//	cout << "Enter Employee's Age: ";
//	cin >> temp->data.age;
//	cin.ignore();
//	cout << "Enter Employee's Birthday: ";
//	getline(cin, temp->data.dob);
//	cout << "Enter Employee's Contact Number: ";
//	cin >> temp->data.contactNum;
//	cin.ignore();
//	cout << "Enter Employee's Email: ";
//	getline(cin, temp->data.email);
//	cout << "Enter Job Role: ";
//	getline(cin, temp->data.jobRole);
//	temp->data.benefitList = AddBenefit();
//
//	temp->next = employeeTail;
//	employeeTail = temp;
//}

StackEmployee::EmployeeNode*& StackEmployee::AddNewEmployee(PersonneInformation& newEmployee, EmployeeNode*& employeeList) {
	EmployeeNode* temp = new EmployeeNode;
	temp->data.benefitList = new BenefitNode;

	temp->data.fullName = newEmployee.fullName;
	temp->data.age = newEmployee.age;
	temp->data.contactNum = newEmployee.contactNum;
	temp->data.dob = newEmployee.dob;
	temp->data.email = newEmployee.email;
	temp->data.gender = newEmployee.gender;

	temp->data.ID = StringInputCatcher("Employee ID No.");
	temp->data.benefitList = AddBenefit();

	temp->next = employeeList;
	employeeList = temp;

	return employeeList;
}

StackEmployee::BenefitNode* StackEmployee::AddBenefit() {
	BenefitNode* temp = new BenefitNode;
	BenefitNode* tail = new BenefitNode;
	temp->next = tail = nullptr;

	string selection;

	do
	{
		cout << "-- Add Benefit --\n";
		cout << "Name: ";
		getline(cin, temp->data.name);
		cout << "Level: ";
		getline(cin, temp->data.level);
		cout << "Description: ";
		getline(cin, temp->data.name);

		temp->next = tail;
		tail = temp;

		cout << "- X to Exit | Any key to add another -\n";
		cin >> selection;
		cin.ignore();

		system("cls");

		if ("X" == selection || "x" == selection)
			return temp;
	} while (true);
}

void StackEmployee::ViewSpecificEmployee(EmployeeNode*& temp) {
	layer;
	cout << "Full Name: " << temp->data.fullName << "\n";
	cout << "Employee ID: " << temp->data.ID << "\n";
	cout << "Gender: " << temp->data.gender << "\n";
	cout << "Age: " << temp->data.age << "\n";
	cout << "Birthday: " << temp->data.dob << "\n";
	cout << "Contact Number: " << temp->data.contactNum << "\n";
	cout << "Email: " << temp->data.email << "\n";
	cout << "Job Role: " << temp->data.jobRole << "\n";
	ViewBenefits(temp->data.benefitList);
	layer;

	system("pause");
	system("cls");
}

void StackEmployee::ViewBenefits(BenefitNode*& List) {
	BenefitNode* temp = List;

	if (temp) {
		cout << "Benefits: \n";
		do {
			layer;
			cout
				<< " - " << temp->data.name << " : "
				<< temp->data.level << " :: "
				<< temp->data.description << "\n";
			temp = temp->next;
		} while (temp);
	}
	else {
		cout << "There's no any employee's information.\n";
	}
}

void StackEmployee::ViewEmployeeListAndSpecific(EmployeeNode*& employeeTail) {
	bool listExist;
	string selected;
	EmployeeNode* prev = nullptr,* temp = employeeTail;

	listExist = ViewEmployeeList(employeeTail);

	if (!listExist) return;

	cout << "- enter x to exit -\n";
	cout << "Select ID to Check: ";
	cin >> selected;

	if (selected == "x" || selected == "X") {
		system("cls");
		return;
	}

	temp = employeeTail;

	while (nullptr != temp && selected != temp->data.ID) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		cout << "Employee ID not found.\n";
		system("pause");
		system("cls");
		return;
	}
	system("cls");

	ViewSpecificEmployee(temp);
}

bool StackEmployee::ViewEmployeeList(EmployeeNode*& employeeTail) {
	EmployeeNode* temp = employeeTail;

	if (temp) {
		do {
			layer;
			cout << "Full Name: " << temp->data.fullName << "\n";
			cout << "Employee ID: " << temp->data.ID << "\n";
			temp = temp->next;
		} while (temp);
		layer;
		return true;
	}
	else {
		cout << "There's no any employee's information.\n";
		system("pause");
		system("cls");
		return false;
	}
}

void StackEmployee::DeleteEmployeeInformation(EmployeeNode*& employeeTail) {
	string id;
	char confirm;
	EmployeeNode* temp = employeeTail;
	EmployeeNode* prev = nullptr;

	if (nullptr == employeeTail) {
		NoticeNothingToDisplay("Employee List", "delete");
		return;
	}

	this->ViewEmployeeList(employeeTail);

	cout << "Enter Employee ID No. to delete: ";
	cin >> id;

	while (nullptr != temp && id != temp->data.ID) {
		prev = temp;
		temp = temp->next;
	}

	if (nullptr == temp) {
		NoticeNothingToDisplay("Employee ID found", "delete");
		return;
	}
	ViewSpecificEmployee(temp);

	cout << "Are you sure you want to delete this employee? (y/n): ";
	cin >> confirm;
	cin.ignore();

	if ('y' == confirm || 'Y' == confirm) {
		if (nullptr == prev) {
			employeeTail = temp->next;
		}
		else {
			prev->next = temp->next;
		}
		delete temp;
		cout << "Employee deleted.\n";
	}
	else {
		cout << "Deletion canceled.\n";
	}

	system("cls");
}

void StackEmployee::UpdateBenefit(BenefitNode*& benefitList) {
	string id;
	BenefitNode* temp = benefitList;

	if (nullptr == temp) {
		NoticeNothingToDisplay("benefit's", "update");
		return;
	}
}

void StackEmployee::UpdateEmployeeInformation(EmployeeNode*& employeeTail) {
	string id;
	int choice;
	EmployeeNode* temp = employeeTail;

	if (nullptr == employeeTail) {
		NoticeNothingToDisplay("Employee List", "update");
		return;
	}

	this->ViewEmployeeList(employeeTail);

	cout << "Enter Employee ID No. to update: ";
	cin >> id;

	system("cls");

	while (nullptr != temp && id != temp->data.ID) {
		temp = temp->next;
	}

	if (nullptr == temp) {
		NoticeNothingToDisplay("Employee ID found", "update");
		return;
	}

	do {
		UpdateMenu(choice);

		layer;
		switch (choice) {
		case 1:
			temp->data.fullName = StringInputCatcher("Full Name", "new");
			break;
		case 2:
			temp->data.gender = StringInputCatcher("Gender", "new");
			break;
		case 3:
			cout << "Enter new Age: ";
			cin >> temp->data.age;
			break;
		case 4:
			temp->data.dob = StringInputCatcher("Birthday", "new");
			break;
		case 5:
			temp->data.contactNum = StringInputCatcher("Contact Number", "new");
			break;
		case 6:
			temp->data.email = StringInputCatcher("Email", "new");
			break;
		case 7:
			temp->data.jobRole = StringInputCatcher("Job Role", "new");
			break;
		case 8:
			BenefitUpdateMenu(choice);
			if (1 == choice)
				UpdateBenefit(temp->data.benefitList);
			else
				AddBenefit();
			break;
		case 0:
			return;
		default:
			cout << "Invalid choice. Please choose a valid option.\n";
		}
		system("cls");
	} while (0 != choice);

	cout << "Employee information updated.\n";
	system("cls");
}

void StackEmployee::NoticeNothingToDisplay(string prompt, string action) {
	cout << "There's no " << prompt << ", nothing to " << action << ".\n";
	system("pause");
	system("cls");
}

string StackEmployee::StringInputCatcher(string prompt, string additional) {
	string data = "";

	while (data.length() == 0) {
		cout << "Enter " << additional << " " << prompt << ": ";
		getline(cin, data);
	}

	return data;
}