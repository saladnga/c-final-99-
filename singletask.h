#pragma once
#include "task.h"
#include "staff.h"

using namespace std;

class SingleTask : public Task
{
private:
    string description;
    Staff *assignedStaff;
    string type;

public:
    SingleTask();
    SingleTask(const string &name, const string &description);
    ~SingleTask();
    string getType() const override;
    string getDescription() const override;
    string getAssignedUserName() const override;
    void displayDetails() override;
    bool assignStaff(Staff *staff);
};