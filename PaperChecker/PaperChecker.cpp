#include "employee.h"
#include "schedule.h"
#include "applicant.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    StackApplicant stackApplicant;
    StackEmployee stackEmployee;
    StackSchedule stackSchedule;

    int choice;
    do {
        cout << "=============================================================\n";
        cout << "\t\t  Hotel Management System \n";
        cout << "=============================================================\n";
        cout << "\t1. Employee Information Management\n";
        cout << "\t2. Applicant Information Management\n";
        cout << "\t3. Employee Schedule Management\n";
        cout << "\t0. Exit\n";
        cout << "\tEnter your choice: ";
        cin >> choice;
        system("CLS");

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                stackEmployee.StartPoint();
                break;
            case 2:
                stackApplicant.StartPoint();
                break;
            case 3:
                stackSchedule.StartPoint(stackEmployee.GetLinkedList());
                break;
            default:
                cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

/*
    This Sample Programs Implemented Topics as followed:
    Store Data:
    - Employee's
    - Applicant's
    Topics:
    - OOP
    - DRY
    - Linked List; Nested Linked List and Transfer Data from one to next Linked List to another
    - Single Responsibility
*/