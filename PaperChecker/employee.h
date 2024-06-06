#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "personneInformation.h"

#include <iostream>
#include <string>
#include <windows.h>

#define layer cout << "============================================================= \n"

using namespace std;

class StackEmployee {
protected:
    struct EmployeeNode;
    struct Employee;
    struct Benefit;
    struct BenefitNode;

    EmployeeNode* employeeTail;

    void MainMenu(int&);
    void UpdateMenu(int&);
    void BenefitUpdateMenu(int&);

    BenefitNode* AddBenefit();
    void AddEmployeeInformation(EmployeeNode*&);

    void ViewBenefits(BenefitNode*&);
    void ViewEmployeeList(EmployeeNode*&);
    void ViewSpecificEmployee(EmployeeNode*&);
    void ViewEmployeeListAndSpecific(EmployeeNode*&);

    void DeleteEmployeeInformation(EmployeeNode*&);

    void UpdateBenefit(BenefitNode*&);
    void UpdateEmployeeInformation(EmployeeNode*&);

    void NoticeNothingToDisplay(string, string);

    string StringInputCatcher(string, string = "");

public:
    EmployeeNode*& GetLinkedList();

    StackEmployee();
    void StartPoint();
};

#endif
