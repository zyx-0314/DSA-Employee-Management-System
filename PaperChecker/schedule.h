#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "employee.h"

class StackSchedule : StackEmployee {
private:
    struct ScheduleNode;
    struct Schedule;
    ScheduleNode *scheduleTail = nullptr;
    EmployeeNode *employeeTail = nullptr;

    void MainMenu(int&);
    void AddSchedule(ScheduleNode*&);
    void ViewSchedules(ScheduleNode*&);
    void UpdateSchedule(ScheduleNode*&);

public:
    StackSchedule();
    void StartPoint(EmployeeNode*&);
};

#endif