#include "admin.h"
#include "staff.h"
#include "singletask.h"
#include "sharedtask.h"

Admin::Admin() : User() {}

Admin::Admin(const string &name, const string &password)
    : User(name, "Admin", password) {}

void Admin::displayUserInfo() const
{
    cout << endl;
    cout << "----------< Admin Information >----------" << endl;
    cout << ">> User Name: " << this->getName() << endl;
    cout << ">> Role : " << this->getRole() << endl;
    cout << "-----------------------------------------" << endl;
}

Admin::~Admin(){};

void Admin::displayStaff(vector<User *> &userList) const
{
    if (userList.empty())
    {
        cout << endl;
        cout << "----------< No users found! >----------" << endl;
    }
    else
    {
        cout << endl;
        cout << "----------< USERS LIST >----------" << endl;
        for (int i = 0; i < userList.size(); i++)
        {
            cout << i + 1 << ". User Name : " << userList[i]->getName() << " | Role : " << userList[i]->getRole() << "." << endl;
        }
        cout << endl;
    }
}

void Admin::adminMenu(vector<User *> &userList, vector<Task *> &taskList)
{
    int option;
    do
    {
        cout << endl;
        cout << "----------< Admin Menu >----------" << endl;
        cout << "1. Display User Information" << endl;
        cout << "2. Display User List" << endl;
        cout << "3. Display Task List" << endl;
        cout << "4. Add New Staff" << endl;
        cout << "5. Remove Staff" << endl;
        cout << "6. Add New Task" << endl;
        cout << "7. Remove Task" << endl;
        cout << "8. Assign Task to Staff" << endl;
        cout << "9. Log out" << endl;
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
            displayStaff(userList);
            break;
        case 3:
            displayTaskList(taskList);
            break;
        case 4:
            addStaff(userList);
            break;
        case 5:
            removeStaff(userList);
            break;
        case 6:
            addTask(taskList);
            break;
        case 7:
            removeTask(taskList);
            break;
        case 8:
            assignTask(userList, taskList);
            break;
        case 9:
            cout << endl;
            cout << "----------< Logging Out... >----------" << endl;
            cout << endl;
            break;
        default:
            cout << endl;
            cout << "----------< Invalid Value. Please Try Again! >----------" << endl;
            cout << endl;
            break;
        }
    } while (option != 9);
}

void Admin::addStaff(vector<User *> &userList)
{
    string name, password;
    cout << endl;
    cout << "----------< Add A New Staff >----------" << endl;
    cout << ">> Enter staff name: ";
    getline(cin, name);
    cout << ">> Enter password for staff: ";
    getline(cin, password);
    userList.push_back(new Staff(name, password));
    cout << endl;
    cout << "----------< Add new staff successfully! >----------" << endl;
    cout << endl;
}

void Admin::removeStaff(vector<User *> &userList)
{
    string name;
    cout << endl;
    cout << "----------< Remove A Staff >----------" << endl;
    cout << ">> Enter staff name to remove: ";
    getline(cin, name);

    for (int i = 0; i < userList.size(); i++)
    {
        if (name == userList[i]->getName())
        {
            userList.erase(userList.begin() + i);
            cout << endl;
            cout << "----------< Staff Removed Successfully! >----------" << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "----------< No Staff with Name: " << name << "is found.  >----------" << endl;
            cout << endl;
        }
    }
}

void Admin::addTask(vector<Task *> &taskList)
{
    int id;
    string description, choice;
    string name, userName;
    cout << endl;
    cout << "----------< Add A New Task >----------" << endl;
    cout << ">> Enter New Task Name: ";
    getline(cin, name);
    cout << "Enter task's description: ";
    getline(cin, description);
    cout << ">> Enter Task Type (Single | Shared): ";
    cin >> choice;
    if (choice == "Single" || choice == "single" || choice == "SINGLE")
    {
        taskList.push_back(new SingleTask(name, description));
    }
    else if (choice == "Shared" || choice == "shared" || choice == "SHARED" || choice == "Share" || choice == "SHARE" || choice == "share")
    {
        taskList.push_back(new SharedTask(name, description));
    }
    cout << endl;
    cout << "----------< New Task Added successfully! >----------" << endl;
    cout << endl;
}

void Admin::removeTask(vector<Task *> &taskList)
{
    int taskId;
    cout << endl;
    cout << "----------< Remove A Task >----------" << endl;
    cout << ">> Enter task ID to remove: ";
    cin >> taskId;
    cin.ignore();
    cin.clear();

    for (int i = 0; i < taskList.size(); i++)
    {
        if (taskId == taskList[i]->getTaskId())
        {
            taskList.erase(taskList.begin() + i);
            cout << endl;
            cout << "----------< Task removed successfully! >----------" << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "----------< No Task Found >----------" << endl;
            cout << endl;
        }
    }
}

void Admin::assignTask(vector<User *> &userList, vector<Task *> &taskList)
{
    int taskId;
    Task *taskToAssign = nullptr;
    string staffName;
    Staff *staffToAssign = nullptr;

    cout << endl;
    cout << "----------< Assign Task To A Staff >----------" << endl;
    cout << ">> Enter task ID to assign: ";
    cin >> taskId;
    cin.ignore();
    cin.clear();

    for (auto i = taskList.begin(); i != taskList.end(); ++i)
    {
        Task *task = *i;
        if (taskId == task->getTaskId())
        {
            taskToAssign = task;
            break;
        }
    }

    if (!taskToAssign)
    {
        cout << "Task ID not found!" << endl;
        return;
    }

    cout << ">> Enter a Staff Name to assign: ";
    getline(cin, staffName);
    for (auto i = userList.begin(); i != userList.end(); ++i)
    {
        User *user = *i;
        if (user->getRole() == "Staff" && user->getName() == staffName)
        {
            staffToAssign = dynamic_cast<Staff *>(user);
            break;
        }
    }

    if (!staffToAssign)
    {
        cout << "Staff member not found!" << endl;
        return;
    }

    if (SingleTask *singleTask = dynamic_cast<SingleTask *>(taskToAssign))
    {
        if (singleTask->assignStaff(staffToAssign))
        {
            cout << "Task assigned to " << staffToAssign->getName() << " successfully!" << endl;
        }
        else
        {
            cout << "Failed to assign task to " << staffToAssign->getName() << endl;
        }
    }
    else if (SharedTask *sharedTask = dynamic_cast<SharedTask *>(taskToAssign))
    {
        if (sharedTask->assignStaff(staffToAssign))
        {
            cout << "Task assigned to " << staffToAssign->getName() << " successfully!" << endl;
        }
        else
        {
            cout << "Failed to assign task to " << staffToAssign->getName() << endl;
        }
    }
    else
    {
        cout << "Unknown task type!" << endl;
    }
}

// void Admin::assignTask(vector<User *> &userList, vector<Task *> &taskList)
// {
//     int id;
//     cout << endl;
//     cout << "----------< Assign Task To A Staff >----------" << endl;
//     cout << ">> Enter task ID to assign: ";
//     cin >> id;
//     cin.ignore();
//     cin.clear();
//     for (int i = 0; i < taskList.size(); i++)
//     {
//         if (id == taskList[i]->getTaskId())
//         {
//             // if (taskList[i]->getTaskStatus() == true)
//             if (taskList[i]->getAssignedUserName() == "NONE")
//             {
//                 string name;
//                 cout << ">> Enter a Staff Name to assign: ";
//                 getline(cin, name);
//                 // cin.ignore();
//                 // cin.clear();
//                 taskList[i]->setAssignedUsername(name);
//                 cout << endl;
//                 cout << "----------< Task Assigned To Staff Successfully! >----------" << endl;
//                 cout << endl;
//             }
//             else
//             {
//                 cout << endl;
//                 cout << "----------< This task is already assigned! >----------" << endl;
//                 cout << endl;
//             }
//         }
//     }
// }