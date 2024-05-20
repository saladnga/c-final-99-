#pragma once
#include "user.h"

using namespace std;

class Staff : public User
{
private:
    // vector<Task *> assignedTasks;
    int ID;
    static int idCounter;

public:
    Staff();
    Staff(const string &name, const string &password);
    ~Staff();
    int getID() const;
    void displayUserInfo() const override;
    void staffMenu(vector<User *> &userList, vector<Task *> &taskList);
    void myAssignedTask(vector<Task *> &taskList);
    void markTaskDone(vector<Task *> &taskList);
    bool assignTask(Task *task);

    // bool assignTask(vector<Task *> &taskList);
};