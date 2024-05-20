#include "sharedtask.h"
#include "task.h"
#include "staff.h"

SharedTask::SharedTask() : Task(){};

SharedTask::SharedTask(const string &name, const string &description) : Task(name, false, "NONE"), description(description)
{
    type = "Shared";
};

SharedTask::~SharedTask(){};

string SharedTask::getDescription() const
{
    return description;
};

string SharedTask::getType() const
{
    return type;
};

void SharedTask::displayDetails()
{
    cout << "ID: " << getTaskId() << " | Share Task: " << description << " | Assigned to: ";
    if (assignedStaff.empty())
    {
        cout << "None) ";
    }
    else
    {
        for (size_t i = 0; i < assignedStaff.size(); i++)
        {
            cout << (i == 0 ? "" : ", ") << assignedStaff[i]->getName() << " ";
        }
    }
    cout << " | Status: " << (isComplete() ? "[Completed]" : "[Pending]") << endl;
};

const vector<string> &SharedTask::getAssignedUsernames() const
{
    return assignedUsernames;
}

string SharedTask::getAssignedUserName() const
{
}

bool SharedTask::assignStaff(Staff *staff)
{
    if (staff->assignTask(this))
    {
        assignedStaff.push_back(staff);
        bool found = false;
        for (const string &name : assignedUsernames)
        {
            if (name == staff->getName())
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            assignedUsernames.push_back(staff->getName());
        }

        return true;
    }
    else
    {
        return false;
    }
}

// bool SharedTask::assignStaff(Staff *staff)
// {
//     if (staff->assignTask(this))
//     {
//         assignedStaff.push_back(staff);
//         // Add the staff's name to a list of assigned usernames
//         if (find(assignedUsernames.begin(), assignedUsernames.end(), staff->getName()) == assignedUsernames.end())
//         {
//             assignedUsernames.push_back(staff->getName());
//         }
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool SharedTask::assignStaff(Staff *staff)
// {
//     if (staff->assignTask(this) == true)
//     {
//         assignedStaff.push_back(staff);
//         setAssignedUsername(staff->getName());
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// };

// const vector<Staff *> &SharedTask::getAssignedStaff() const
// {
//     return assignedStaff;
// }
