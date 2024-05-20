#include "task.h"

int Task::taskIdCounter = 0;

Task::~Task(){};

Task::Task() : taskName("Unnamed Task"), taskStatus(false)
{
    taskId = taskIdCounter++;
}

Task::Task(string name, bool status, string assignedUser)
    : taskName(name), taskStatus(status), assignedUserName(assignedUser)
{
    taskId = ++taskIdCounter;
}

int Task::getTaskId()
{
    return taskId;
}

string Task::getTaskName()
{
    return taskName;
}

bool Task::getTaskStatus()
{
    return taskStatus;
}

string Task::getAssignedUserName() const
{
    return assignedUserName;
}

void Task::setTaskId(int id)
{
    this->taskId = id;
}

void Task::setTaskName(string name)
{
    this->taskName = name;
}

void Task::setTaskStatus(bool status)
{
    this->taskStatus = status;
}

void Task::setAssignedUsername(string name)
{
    this->assignedUserName = name;
}

void Task::markComplete()
{
    this->taskStatus = true;
    cout << endl;
    cout << ">> Task: " << taskId << "has been marked as completed." << endl;
    cout << endl;
};

bool Task::isComplete()
{
    return taskStatus;
};

// void Task::displayTaskList(vector<Task *> &taskList)
// {
//     if (taskList.empty())
//     {
//         cout << "-----------No task found!-----------" << endl;
//     }
//     else
//     {
//         cout << "-------------Task List--------------" << endl;
//         for (int i = 0; i < taskList.size(); i++)
//         {
//             cout << "Task ID: " << taskList[i]->getTaskId() << endl;
//             cout << "Task name: " << taskList[i]->getTaskName() << endl;
//             cout << "Task status: " << (taskList[i]->getTaskStatus() ? "Completed" : "Not Completed") << endl;
//             cout << "Name of assigned staff: " << taskList[i]->getAssignedUserName() << endl;
//             cout << "------------------------------------" << endl;
//         }
//     }
// }