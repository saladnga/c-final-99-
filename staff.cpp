#include "staff.h"

int Staff::idCounter = 0;

Staff::Staff() : User()
{
    ID = idCounter++;
}

Staff::Staff(const string &name, const string &password)
    : User(name, "Staff", password)
{
    ID = idCounter++;
}

Staff ::~Staff(){};

int Staff::getID() const
{
    return ID;
}

void Staff::displayUserInfo() const
{
    cout << endl;
    cout << "----------< Staff Information >----------" << endl;
    cout << ">> User name: " << this->getName() << endl;
    cout << ">> Role: " << this->getRole() << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
}

void Staff::staffMenu(vector<User *> &userList, vector<Task *> &taskList)
{
    int option;
    do
    {
        cout << endl;
        cout << "----------< Staff Menu >----------" << endl;
        cout << "1. Display Staff Information" << endl;
        cout << "2. Display Task List" << endl;
        cout << "3. Mark Task Done" << endl;
        cout << "4. Log out" << endl;
        cout << "-----------------------------------" << endl;
        cout << ">> Enter your option: ";
        cin >> option;
        cin.ignore();
        cin.clear();

        switch (option)
        {
        case 1:
            displayUserInfo();
            break;
        case 2:
            myAssignedTask(taskList);
            break;
        case 3:
            markTaskDone(taskList);
            break;
        case 4:
            cout << "----------< Logging Out... >----------" << endl;
            break;
        default:
            cout << "----------< Invalid Value. Please Try Again! >----------" << endl;
            break;
        }
    } while (option != 4);
}

void Staff::myAssignedTask(vector<Task *> &taskList)
{

    cout << endl;
    cout << "----------< My Assigned Tasks >----------" << endl;
    if (taskList.empty())
    {
        cout << ">> No task assigned." << endl;
    }
    else
    {
        bool hasAssignedTasks = false;
        for (size_t i = 0; i < taskList.size(); ++i)
        {
            if (SharedTask *sharedTask = dynamic_cast<SharedTask *>(taskList[i]))
            {
                const vector<string> &assignedUsers = sharedTask->getAssignedUsernames();
                for (const string &assignedUser : assignedUsers)
                {
                    if (assignedUser == getName())
                    {
                        cout << i + 1 << ". Task ID: " << taskList[i]->getTaskId() << " | Description: " << taskList[i]->getTaskName() << " || Status: " << (taskList[i]->getTaskStatus() ? "Completed" : "Incomplete") << " | Assigned Staff: ";
                        for (size_t j = 0; j < assignedUsers.size(); ++j)
                        {
                            cout << (j == 0 ? "" : ", ") << assignedUsers[j];
                        }
                        cout << endl;
                        hasAssignedTasks = true;
                        break;
                    }
                }
            }
            else if (getName() == taskList[i]->getAssignedUserName())
            {
                cout << i + 1 << ". Task ID: " << taskList[i]->getTaskId() << " | Description: " << taskList[i]->getTaskName() << " || Status: " << (taskList[i]->getTaskStatus() ? "Completed" : "Incomplete") << " | Assigned Staff: " << taskList[i]->getAssignedUserName() << endl;
                hasAssignedTasks = true;
            }
        }

        if (!hasAssignedTasks)
        {
            cout << ">> No task assigned." << endl;
        }

        cout << endl;
    }

    // cout << endl;
    // cout << "----------< My Assigned Tasks >----------" << endl;
    // if (taskList.empty())
    // {
    //     cout << ">> No task assigned." << endl;
    // }
    // else
    // {
    //     for (int i = 0; i < taskList.size(); i++)
    //     {
    //         if (getName() == taskList[i]->getAssignedUserName())
    //         {
    //             cout << i + 1 << ". Task ID: " << taskList[i]->getTaskId() << " | Description: " << taskList[i]->getTaskName() << " || Status: " << (taskList[i]->getTaskStatus() ? "Completed" : "Incomplete") << " | Assigned Staff: " << taskList[i]->getAssignedUserName() << endl;
    //         }
    //     }
    //     cout << endl;
    // }
}

void Staff::markTaskDone(vector<Task *> &taskList)
{
    int id;
    bool status;
    cout << endl;
    cout << "----------< Set Task's Status >----------" << endl;
    if (taskList.empty())
    {
        cout << ">> No task assigned." << endl;
    }
    else
    {
        cout << endl;
        cout << ">> Enter Task's ID to set: ";
        cin >> id;
        cin.ignore();
        cin.clear();
        cout << endl;
        cout << ">> Mark task as Incomplete (0) or Completed (1): ";
        cin >> status;
        cin.ignore();
        cin.clear();
        cout << endl;
        bool found = false;
        for (int i = 0; i < taskList.size(); i++)
        {
            if (id == taskList[i]->getTaskId())
            {
                taskList[i]->setTaskStatus(status);
                cout << "----------< Task status set successfully! >----------" << endl;
                found = true;
                break;
            }
            if (!found)
            {
                cout << endl;
                cout << ">> Task with ID: " << id << "not found" << endl;
            }
        }
        cout << endl;
    }
};

bool Staff::assignTask(Task *task)
{
    cout << endl;
    cout << "----------< Assign Task >----------" << endl;
    if (task)
    {
        cout << "> Choose Task' with ID': " << task->getTaskId() << endl;
        return true;
    }
    cout << "> Failed to assign task." << endl;
    cout << endl;
    return false;
}

// bool Staff::assignTask(vector<Task *> &taskList)
// {
//     if (taskList.empty())
//     {
//         cout << "No task assigned." << endl;
//     }
//     else
//     {
//         for (int i = 0; i < taskList.size(); i++)
//         {
//             if (taskList[i]->getTaskId() == task->getID())
//             {
//                 return false;
//             }
//         }
//     }
// }