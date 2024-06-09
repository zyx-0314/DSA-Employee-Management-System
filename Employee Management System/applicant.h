#ifndef APPLICANT_H
#define APPLICANT_H

#include "personneInformation.h"
#include "employee.h"

#include <ctime>
#include <string>
#include <iostream>
#include <windows.h>

#define layer cout << "============================================================= \n"

using namespace std;

class StackApplicant : StackEmployee {
public:
    EmployeeNode*& StartPoint(EmployeeNode*&);

private:
    struct Applicant;
    struct ApplicantNode;
    struct Interview;
    struct InterviewNode;

    EmployeeNode* employeeTail = nullptr;
    ApplicantNode* applicantTail = nullptr;
    InterviewNode* interviewScheduleTail = nullptr;

    void MainMenu(int&);
    void UpdateMenu(int&);

    bool ViewApplicantList(ApplicantNode*&);
    void ViewSpecificApplicant(ApplicantNode*&);
    void ViewApplicantListAndSpecific(ApplicantNode*&);

    void AddApplicant(ApplicantNode*&);

    void UpdateApplicantInformation(ApplicantNode*&);
    void UpdateApplicantStatus(ApplicantNode*&);

    void MoveApplicantToEmployee(ApplicantNode*&);

    void DeleteApplicantInformationUI(ApplicantNode*&);
    void DeleteApplicantInformation(ApplicantNode*&, bool = true);

    void NoticeNothingToDisplay(string, string);
    string StringInputCatcher(string, string = "");
};

#endif