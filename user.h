#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "task.h"

using namespace std;

class User
{
private:
    string name;
    string role;
    string password;

public:
    User();
    User(const string &name, const string &role, const string &password);
    virtual ~User();
    string getName() const;
    string getRole() const;
    string getPassword() const;
    void setName(string &name);
    void setRole(string &role);
    void setPassword(string &password);
    virtual void displayUserInfo() const = 0;
    void displayTaskList(vector<Task *> taskList);
};