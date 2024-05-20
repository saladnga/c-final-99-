#include "user.h"
#include "sharedtask.h"

User::User() : name("Unnamed User"){};

User::User(const string &name, const string &role, const string &password)
    : name(name), role(role), password(password){};

User::~User(){};

string User::getName() const
{
    return name;
};

string User::getRole() const
{
    return role;
};

string User::getPassword() const
{
    return password;
};

void User::setName(string &name)
{
    this->name = name;
};

void User::setRole(string &role)
{
    this->role = role;
};

void User::setPassword(string &password)
{
    this->password = password;
};

void User::displayTaskList(vector<Task *> taskList)
{

    cout << endl;
    cout << "----------< Task List >----------" << endl;
    if (taskList.empty())
    {
        cout << "----------< No task found! >----------" << endl;
    }
    else
    {
        for (size_t i = 0; i < taskList.size(); ++i)
        {
            cout << i + 1 << ". Task ID: " << taskList[i]->getTaskId() << " | Name: " << taskList[i]->getTaskName() << " | Description: " << taskList[i]->getDescription() << " | Type: " << taskList[i]->getType() << " | Status: " << (taskList[i]->getTaskStatus() ? "Completed" : "Incomplete") << " | Assigned Staff: ";

            if (SharedTask *sharedTask = dynamic_cast<SharedTask *>(taskList[i]))
            {
                const vector<string> &assignedUsers = sharedTask->getAssignedUsernames();
                if (!assignedUsers.empty())
                {
                    for (size_t j = 0; j < assignedUsers.size(); ++j)
                    {
                        cout << (j == 0 ? "" : ", ") << assignedUsers[j];
                    }
                    cout << endl;
                }
                else
                {
                    cout << "None" << endl;
                    ;
                }
            }
            else
            {
                cout << taskList[i]->getAssignedUserName() << endl;
            }
        }
    }

    // cout << "----------< Task List >----------" << endl;
    // if (taskList.empty())
    // {
    //     cout << endl;
    //     cout << "----------< No task found! >----------" << endl;
    // }
    // else
    // {
    //     for (int i = 0; i < taskList.size(); i++)
    //     {
    //         cout << i + 1 << ". Task ID: " << taskList[i]->getTaskId() << " | Name: " << taskList[i]->getTaskName() << " | Description: " << taskList[i]->getDescription() << " | Type: " << taskList[i]->getType() << " | Status: " << (taskList[i]->getTaskStatus() ? "Completed" : "Incomplete") << " | Assigned Staff: ";
    //         // << taskList[i]->getAssignedUserName() << endl;
    //         for (size_t i = 0; i < taskList.size(); i++)
    //         {
    //             cout << (i == 0 ? "" : ", ") << taskList[i]->getAssignedUserName() << " " << endl;
    //         }
    //     }
    // }
};

// void User::displayTaskList(const std::vector<Task *> &taskList) const
// {
//     if (taskList.empty())
//     {
//         std::cout << "-----------No task found!-----------" << std::endl;
//     }
//     else
//     {
//         std::cout << "-------------Task List--------------" << std::endl;
//         for (const auto &task : taskList)
//         {
//             std::cout << "Task ID: " << task->getTaskId() << std::endl;
//             std::cout << "Task name: " << task->getTaskName() << std::endl;
//             std::cout << "Task status: " << (task->getTaskStatus() ? "Completed" : "Incomplete") << std::endl;
//             std::cout << "Name of assigned staff: " << task->getAssignedUserName() << std::endl;
//             std::cout << "------------------------------------" << std::endl;
//         }
//     }
// }