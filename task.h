#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task
{
private:
    int taskId;
    string taskName;
    bool taskStatus;
    string assignedUserName;
    string type;

protected:
    static int taskIdCounter;

public:
    Task();
    Task(string name, bool status, string assignedUserName);
    virtual ~Task();
    virtual string getType() const = 0;
    int getTaskId();
    string getTaskName();
    bool getTaskStatus();
    virtual string getAssignedUserName() const = 0;
    virtual string getDescription() const = 0;
    void setTaskId(int id);
    void setTaskName(string name);
    void setTaskStatus(bool status);
    void setAssignedUsername(string name);
    virtual void displayDetails() = 0;
    void markComplete();
    bool isComplete();
    // void displayTaskList(vector<Task *> &taskList);
};