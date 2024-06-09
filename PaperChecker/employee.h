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

    EmployeeNode*& AddNewEmployee(PersonneInformation&, EmployeeNode*&);

    bool ViewEmployeeList(EmployeeNode*&);

private:
    struct Benefit;
    struct BenefitNode;

    void MainMenu(int&);
    void UpdateMenu(int&);
    void BenefitUpdateMenu(int&);

    BenefitNode* AddBenefit();
    //void AddEmployeeInformation(EmployeeNode*&);

    void ViewBenefits(BenefitNode*&);
    void ViewSpecificEmployee(EmployeeNode*&);
    void ViewEmployeeListAndSpecific(EmployeeNode*&);

    void DeleteEmployeeInformation(EmployeeNode*&);

    void UpdateBenefit(BenefitNode*&);
    void UpdateEmployeeInformation(EmployeeNode*&);

    void NoticeNothingToDisplay(string, string);

    string StringInputCatcher(string, string = "");

public:
    EmployeeNode* employeeTail = nullptr;

    EmployeeNode*& StartPoint(EmployeeNode*&);
};

#endif
