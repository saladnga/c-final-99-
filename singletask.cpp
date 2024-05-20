#include "singletask.h"
#include "task.h"

SingleTask::SingleTask() : Task()
{
    assignedStaff = nullptr;
};

SingleTask::SingleTask(const string &name, const string &description) : Task(name, false, "NONE"), description(description)
{
    assignedStaff = nullptr;
    type = "Single";
};

SingleTask::~SingleTask(){};

string SingleTask::getDescription() const
{
    return description;
};

string SingleTask::getType() const
{
    return type;
};

string SingleTask::getAssignedUserName() const
{
    return assignedStaff ? assignedStaff->getName() : "None";
}

void SingleTask::displayDetails()
{
    cout << ">> ID: " << getTaskId() << ", Single Task: " << description << " (Assigned to: ";
    if (assignedStaff == nullptr)
    {
        cout << "None) ";
    }
    else
    {
        cout << assignedStaff->getName() << " | Status: ";
    }
    cout << (isComplete() ? "[Completed]" : "[Pending]") << endl;
};

bool SingleTask::assignStaff(Staff *staff)
{
    if (assignedStaff == nullptr)
    {
        assignedStaff = staff;
        staff->assignTask(this);
        return true;
    }
    else
    {
        cout << endl;
        cout << ">> Error: This task is already been assigned to another staff member." << endl;
        cout << endl;
        return false;
    }
}