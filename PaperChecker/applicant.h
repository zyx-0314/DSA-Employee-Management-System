#ifndef APPLICANT_H
#define APPLICANT_H

#include "personneInformation.h"

#include <ctime>
#include <string>
#include <iostream>
#include <windows.h>

#define layer cout << "============================================================= \n"

using namespace std;

class StackApplicant {
public:
    void StartPoint();

private:
    struct Applicant;
    struct ApplicantNode;
    struct Interview;
    struct InterviewNode;

    ApplicantNode* applicantTail = nullptr;
    InterviewNode* interviewScheduleTail = nullptr;

    void MainMenu(int&);
    void UpdateMenu(int&);

    void ViewApplicantList(ApplicantNode*&);
    void ViewSpecificApplicant(ApplicantNode*&);
    void ViewEmployeeListAndSpecific(ApplicantNode*&);

    void AddApplicant(ApplicantNode*&);

    void UpdateApplicantInformation(ApplicantNode*&);
    void UpdateApplicantStatus(ApplicantNode*&);

    void MoveApplicantToEmployee();

    void DeleteApplicantInformationUI(ApplicantNode*&);
    void DeleteApplicantInformation(ApplicantNode*&);

    void NoticeNothingToDisplay(string, string);
    string StringInputCatcher(string, string = "");
};

#endif