#pragma once
#include "task.h"
#include "staff.h"

using namespace std;

class SharedTask : public Task
{
private:
    string description;
    vector<Staff *> assignedStaff;
    vector<string> assignedUsernames;
    string type;

public:
    SharedTask();
    SharedTask(const string &name, const string &description);
    ~SharedTask();
    string getDescription() const override;
    string getType() const override;
    void displayDetails() override;
    bool assignStaff(Staff *staff);
    const vector<string> &getAssignedUsernames() const;
    string getAssignedUserName() const override;
};