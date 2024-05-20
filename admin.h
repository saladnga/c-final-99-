#pragma once
#include "user.h"
#include "task.h"
#include "staff.h"
#include <string>
#include <fstream>

class Admin : public User
{
public:
    Admin();
    Admin(const string &name, const string &password);
    ~Admin();
    void displayUserInfo() const override;
    void displayStaff(vector<User *> &userList) const;
    void adminMenu(vector<User *> &userList, vector<Task *> &taskList);
    void addStaff(vector<User *> &userList);
    void removeStaff(vector<User *> &userList);
    void addTask(vector<Task *> &taskList);
    void removeTask(vector<Task *> &taskList);
    void assignTask(vector<User *> &userList, vector<Task *> &taskList);
};