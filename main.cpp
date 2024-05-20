// #include "user.h"
// #include "task.h"
// #include "admin.h"
// #include "staff.h"
// #include "singletask.h"
// #include "sharedtask.h"

#include "user.cpp"
#include "task.cpp"
#include "admin.cpp"
#include "staff.cpp"
#include "singletask.cpp"
#include "sharedtask.cpp"

using namespace std;

void signIn(vector<User *> &userList, vector<Task *> &taskList);
void signUp(vector<User *> &userList, vector<Task *> &taskList);

int main()
{
    vector<User *> userList;
    vector<Task *> taskList;

    int option;
    do
    {
        cout << endl;
        cout << "====================================" << endl;
        cout << "|| Welcome to Task Management App ||" << endl;
        cout << "====================================" << endl;
        cout << "1. Sign In" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Exit" << endl;
        cout << "====================================" << endl;
        cout << ">> Enter your option: ";
        cin >> option;
        cin.ignore();
        cin.clear();

        switch (option)
        {
        case 1:
            signIn(userList, taskList);
            break;
        case 2:
            signUp(userList, taskList);
            break;
        case 3:
            cout << endl;
            cout << ">> Exiting. Thank you for using the app!" << endl;
            cout << endl;
            break;
        default:
            cout << endl;
            cout << ">> Invalid value. Please try again!" << endl;
            cout << endl;
            break;
        }
    } while (option != 3);

    for (User *user : userList)
    {
        delete user;
    }

    for (Task *task : taskList)
    {
        delete task;
    }

    return 0;
}

void signIn(vector<User *> &userList, vector<Task *> &taskList)
{
    while (true)
    {
        string name, password;
        cout << endl;
        cout << "=================" << endl;
        cout << "|| SIGN IN MENU||" << endl;
        cout << "=================" << endl;
        cout << ">> Enter User Name: ";
        getline(cin, name);
        cout << ">> Enter Password: ";
        getline(cin, password);

        for (int i = 0; i < userList.size(); i++)
        {
            if (name == userList[i]->getName())
            {
                if (password == userList[i]->getPassword())
                {
                    cout << endl;
                    cout << "=========================" << endl;
                    cout << "< Sign In Successfully! >" << endl;
                    cout << "=========================" << endl;
                    cout << ">> Hello, " << userList[i]->getName() << "." << endl;
                    cout << "=========================" << endl;
                    cout << endl;

                    if (userList[i]->getRole() == "Admin")
                    {
                        Admin *admin = dynamic_cast<Admin *>(userList[i]);
                        admin->adminMenu(userList, taskList);
                        break;
                    }
                    else if (userList[i]->getRole() == "Staff")
                    {
                        Staff *staff = dynamic_cast<Staff *>(userList[i]);
                        staff->staffMenu(userList, taskList);
                        break;
                    }
                }
                else
                {
                    cout << endl;
                    cout << "========================================" << endl;
                    cout << ">> Incorrect password. Please try again!" << endl;
                    cout << "========================================" << endl;
                    cout << endl;
                }
                break;
            }
        }
    }
}

void signUp(vector<User *> &userList, vector<Task *> &taskList)
{
    while (true)
    {
        string name, password, role;
        cout << endl;
        cout << "=================" << endl;
        cout << "|| SIGN UP MENU||" << endl;
        cout << "=================" << endl;
        cout << ">> Enter User Name: ";
        getline(cin, name);
        cout << ">> Enter Password: ";
        getline(cin, password);
        // cout << ">> Choose Your Role (Admin / Staff): ";
        // getline(cin, role);

        userList.push_back(new Admin(name, password));
        cout << endl;
        cout << "======================================" << endl;
        cout << "< New Admin Registered Successfully! >" << endl;
        cout << "======================================" << endl;
        cout << endl;
        signIn(userList, taskList);

        // if (role == "Admin")
        // {
        //     userList.push_back(new Admin(name, password));
        //     cout << endl;
        //     cout << "======================================" << endl;
        //     cout << "< New Admin Registered Successfully! >" << endl;
        //     cout << "======================================" << endl;
        //     cout << endl;
        //     signIn(userList, taskList);
        // }
        // else if (role == "Staff")
        // {
        //     userList.push_back(new Staff(name, password));
        //     cout << endl;
        //     cout << "======================================" << endl;
        //     cout << "< New Staff Registered Successfully! >" << endl;
        //     cout << "======================================" << endl;
        //     cout << endl;
        //     signIn(userList, taskList);
        // }
        // else
        // {
        //     cout << endl;
        //     cout << "=============================================" << endl;
        //     cout << ">> Invalid Role. Please Enter Admin Or Staff!" << endl;
        //     cout << "=============================================" << endl;
        //     cout << endl;
        // }
    }
}