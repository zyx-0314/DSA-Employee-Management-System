#include "applicant.h"

struct StackApplicant::Applicant : PersonneInformation {
	string status, applicationDate;
};

struct StackApplicant::ApplicantNode {
	ApplicantNode* next = nullptr;
	Applicant data;
};

struct StackApplicant::Interview {
	ApplicantNode* applicant;
	string date, time, countTry, level;
};

struct StackApplicant::InterviewNode {
	InterviewNode* next = nullptr;
	Interview data;
};

StackApplicant::EmployeeNode*& StackApplicant::StartPoint(EmployeeNode*& employeeList) {
	employeeTail = employeeList;
	int choice;

	do {
		MainMenu(choice);
		switch (choice) {
		case 0:
			return employeeTail;
		case 1:
			AddApplicant(applicantTail);
			break;
		case 2:
			break;
		case 3:
			UpdateApplicantStatus(applicantTail);
			break;
		case 4:
			UpdateApplicantInformation(applicantTail);
			break;
		case 5:
			ViewApplicantListAndSpecific(applicantTail);
			break;
		case 6:
			DeleteApplicantInformation(applicantTail);
			break;
		default:
			cout << "Choose only from 1 - 4";
			system("CLS");
			break;
		}
	} while (choice != 0);

}

void StackApplicant::MainMenu(int& choice) {
	layer;
	cout << "\t\t  Applicant's Information\n";
	layer;
	cout << "\t1. Add an Applicant\n";
	cout << "\t2. Schedule an Applicant Interview\n";
	cout << "\t3. Update Status of an Applicant\n";
	cout << "\t4. Update Information of an Applicant\n";
	cout << "\t5. View Applicant's List\n";
	cout << "\t6. Delete Applicant Information\n";
	cout << "\t0. Return to Main Menu\n";
	layer;
	cin >> choice;
	cin.ignore();
	system("cls");
}

void StackApplicant::UpdateMenu(int& choice) {
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
		cout << "\t  0. Exit\n";
		layer;
		cin >> choice;
		cin.ignore();

		if (0 < choice || 9 > choice)
			return;
	} while (true);

	system("cls");
}

void StackApplicant::AddApplicant(ApplicantNode*& tail) {
	ApplicantNode* temp = new ApplicantNode;
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);

	if (!tail)
		temp->next = nullptr;
	else
		temp->next = tail;

	cout << "- Applicant Information - \n";
	temp->data.fullName = StringInputCatcher("Full Name");
	temp->data.ID = StringInputCatcher("Applicant ID No.");
	temp->data.gender = StringInputCatcher("Gender");
	cout << "Enter  Applicant's Age: ";
	cin >> temp->data.age;
	cin.ignore();
	temp->data.dob = StringInputCatcher("Date of birth");
	temp->data.contactNum = StringInputCatcher("Contact Number");
	temp->data.email = StringInputCatcher("Email");
	temp->data.applicationDate = to_string(++ltm.tm_mon) + "-" + to_string(ltm.tm_mday) + "-" + to_string(ltm.tm_year + 1900);
	temp->data.status = "Paper Evaluation";

	tail = temp;

	system("cls");
}

bool StackApplicant::ViewApplicantList(ApplicantNode*& employeeTail) {
	ApplicantNode* temp = employeeTail;

	if (temp) {
		do {
			layer;
			cout << "Full Name: " << temp->data.fullName << "\n";
			cout << "Applicant ID: " << temp->data.ID << "\n";
			temp = temp->next;
		} while (temp);
		layer;
		return true;
	}
	else {
		cout << "There's no any applicant's information.\n";
		system("pause");
		system("cls");
		return false;
	}
}

void StackApplicant::ViewSpecificApplicant(ApplicantNode*& temp) {
	layer;
	cout << "Status: " << temp->data.status << " - " << temp->data.applicationDate << "\n";
	cout << "Full Name: " << temp->data.fullName << "\n";
	cout << "Applicant ID: " << temp->data.ID << "\n";
	cout << "Gender: " << temp->data.gender << "\n";
	cout << "Age: " << temp->data.age << "\n";
	cout << "Birthday: " << temp->data.dob << "\n";
	cout << "Contact Number: " << temp->data.contactNum << "\n";
	cout << "Email: " << temp->data.email << "\n";
	layer;

}

void StackApplicant::ViewApplicantListAndSpecific(ApplicantNode*& applicantList) {
	bool listExist;
	string selected;
	ApplicantNode* prev = nullptr,* temp = applicantList;

	listExist = ViewApplicantList(applicantList);

	if (!listExist) return;

	cout << "- enter x to exit -\n";
	cout << "Select ID to Check: ";
	cin >> selected;

	if (selected == "x" || selected == "X") {
		system("cls");
		return;
	}

	temp = applicantList;

	while (nullptr != temp && selected != temp->data.ID) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		cout << "Applicant ID not found.\n";
		system("pause");
		system("cls");
		return;
	}
	system("cls");

	ViewSpecificApplicant(temp);

	system("pause");
	system("cls");
}

void StackApplicant::DeleteApplicantInformationUI(ApplicantNode*& tail) {
	string id;
	char confirm;
	ApplicantNode* temp = tail,* prev = nullptr;

	if (tail == nullptr) {
		NoticeNothingToDisplay("Applicant List", "delete");
		return;
	}

	this->ViewApplicantList(applicantTail);

	id = StringInputCatcher("Applicant ID No. to delete");

	while (temp != nullptr && temp->data.ID != id) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		NoticeNothingToDisplay("Applicant ID found", "delete");
		return;
	}
	ViewSpecificApplicant(temp);

	cout << "Are you sure you want to delete this applicant? (y/n): ";
	cin >> confirm;
	cin.ignore();

	if (confirm == 'y' || confirm == 'Y') {
		DeleteApplicantInformation(temp);
	}
	else {
		cout << "Deletion canceled.\n";
	}
}

void StackApplicant::DeleteApplicantInformation(ApplicantNode*& temp, bool deleteNode) {
	ApplicantNode* prev = nullptr;

	if (prev == nullptr) {
		applicantTail = temp->next;
	}
	else {
		prev->next = temp->next;
	}
	if (deleteNode) delete temp;
	cout << "Applicant deleted.\n";
}

void StackApplicant::UpdateApplicantInformation(ApplicantNode*& applicantTail) {
	string id;
	int choice;
	ApplicantNode* temp = applicantTail;

	if (nullptr == applicantTail) {
		NoticeNothingToDisplay("Applicant List", "update");
		return;
	}

	this->ViewApplicantList(applicantTail);

	id = StringInputCatcher("Applicant ID No. to update");
	system("cls");

	while (nullptr != temp && id != temp->data.ID) {
		temp = temp->next;
	}

	if (nullptr == temp) {
		NoticeNothingToDisplay("Applicant ID found", "update");
		return;
	}

	do {
		ViewSpecificApplicant(temp);
		UpdateMenu(choice);
		system("cls");

		ViewSpecificApplicant(temp);
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
		case 0:
			system("cls");
			return;
		default:
			cout << "Invalid choice. Please choose a valid option.\n";
		}
		system("cls");
	} while (choice != 0);

	cout << "Applicant information updated.\n";
}

void StackApplicant::UpdateApplicantStatus(ApplicantNode*&) {
	string id;
	ApplicantNode* temp = applicantTail;

	if (nullptr == applicantTail) {
		NoticeNothingToDisplay("Applicant List", "update");
		return;
	}

	this->ViewApplicantList(applicantTail);

	id = StringInputCatcher("Applicant ID No. to update");
	system("cls");

	while (nullptr != temp && id != temp->data.ID) {
		temp = temp->next;
	}

	if (nullptr == temp) {
		NoticeNothingToDisplay("Applicant ID found", "update");
		return;
	}

	ViewSpecificApplicant(temp);
	temp->data.status = StringInputCatcher("Status", "new");

	if (temp->data.status == "Hired") {
		MoveApplicantToEmployee(temp);
		DeleteApplicantInformation(temp, false);


		return;
	}
	cout << "Applicant information updated.\n";
	system("pause");
	system("cls");
}

void StackApplicant::NoticeNothingToDisplay(string prompt, string action) {
	cout << "There's no " << prompt << ", nothing to " << action << ".\n";
	system("pause");
	system("cls");
}

string StackApplicant::StringInputCatcher(string prompt, string additional) {
	string data = "";

	while (data.length() == 0) {
		cout << "Enter " << additional << " " << prompt << ": ";
		getline(cin, data);
	}

	return data;
}

void StackApplicant::MoveApplicantToEmployee(ApplicantNode*& newHired) {
	PersonneInformation temp;
	
	temp.fullName = newHired->data.fullName;
	temp.age = newHired->data.age;
	temp.contactNum = newHired->data.contactNum;
	temp.dob = newHired->data.dob;
	temp.email = newHired->data.email;
	temp.gender = newHired->data.gender;

	employeeTail = AddNewEmployee(temp, employeeTail);
}