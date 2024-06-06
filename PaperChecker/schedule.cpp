#include "schedule.h"
#include <iostream>
#include <string>

using namespace std;

struct StackSchedule::Schedule {
    string employeeId;
    string jobRole;
    string scheduleDate;
    string shift;
};

struct StackSchedule::ScheduleNode {
    ScheduleNode* next = nullptr;
    Schedule data;
};

StackSchedule::StackSchedule() : scheduleTail(nullptr){}

void StackSchedule::StartPoint(EmployeeNode*& employeeList) {
    employeeTail = employeeList;
    ScheduleNode* head = nullptr;
    
    int choice;

    do {
        MainMenu(choice);
        switch (choice) {
            case 0:
                return;
            case 1:
                AddSchedule(scheduleTail);
                break;
            case 2:
                ViewSchedules(scheduleTail);
                break;
            case 3:
                UpdateSchedule(scheduleTail);
                break;
            default:
                cout << "Choose only from 0 - 3" << endl;
                break;
        }
    } while (choice != 0);
}

void StackSchedule::MainMenu(int &choice) {
    cout << "=============================================================\n";
    cout << "\t\t  Employee Schedule Management\n";
    cout << "=============================================================\n";
    cout << "\t1. Add Employee Schedule\n";
    cout << "\t2. View Employee Schedules\n";
    cout << "\t3. Update Employee Schedule\n";
    cout << "\t0. Exit\n";
    cout << "-------------------------------------------------------------\n";
    cin >> choice;
    cin.ignore();
}

void StackSchedule::AddSchedule(ScheduleNode*& head) {
    ScheduleNode* newNode = new ScheduleNode;

    ViewEmployeeList(employeeTail);
    
    cout << "Enter Employee ID: ";
    cin >> newNode->data.employeeId;
    cin.ignore();
    cout << "Enter Job Role: ";
    getline(cin, newNode->data.jobRole);
    cout << "Enter Schedule Date (YYYY-MM-DD): ";
    cin >> newNode->data.scheduleDate;
    cin.ignore();
    cout << "Enter Shift (e.g., Morning, Evening): ";
    getline(cin, newNode->data.shift);
    
    newNode->next = head;
    head = newNode;
    
    cout << "Employee schedule added successfully.\n";
}

void StackSchedule::ViewSchedules(ScheduleNode*& head) {
    if (!head) {
        cout << "No schedules to display.\n";
        return;
    }
    
    ScheduleNode* temp = head;
    while (temp) {
        cout << "=============================================================\n";
        cout << "Employee ID: " << temp->data.employeeId << "\n";
        cout << "Job Role: " << temp->data.jobRole << "\n";
        cout << "Schedule Date: " << temp->data.scheduleDate << "\n";
        cout << "Shift: " << temp->data.shift << "\n";
        temp = temp->next;
    }
}

void StackSchedule::UpdateSchedule(ScheduleNode*& head) {
    if (!head) {
        cout << "No schedules to update.\n";
        return;
    }
    
    string id;
    cout << "Enter Employee ID to update schedule: ";
    cin >> id;
    cin.ignore();
    
    ScheduleNode* temp = head;
    while (temp && temp->data.employeeId != id) {
        temp = temp->next;
    }
    
    if (!temp) {
        cout << "Employee ID not found.\n";
        return;
    }
    
    int choice;
    do {
        cout << "=============================================================\n";
        cout << "Select the field to update:\n";
        cout << "1. Job Role\n";
        cout << "2. Schedule Date\n";
        cout << "3. Shift\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------------------------------\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter new Job Role: ";
                getline(cin, temp->data.jobRole);
                break;
            case 2:
                cout << "Enter new Schedule Date (YYYY-MM-DD): ";
                cin >> temp->data.scheduleDate;
                cin.ignore();
                break;
            case 3:
                cout << "Enter new Shift: ";
                getline(cin, temp->data.shift);
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Please choose a valid option.\n";
        }
    } while (choice != 0);
    
    cout << "Schedule updated successfully.\n";
}