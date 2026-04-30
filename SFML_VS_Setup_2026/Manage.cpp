#include "Manage.h"
#include <sstream>
#include <iostream>
#include <ctime>
#include <iomanip>

Manage::Manage(const string& path)
{
    directory = path;
    encrypted = new Encryption();
}
Manage::~Manage()
{
    if (encrypted != nullptr)
    {
        delete encrypted;
        encrypted = nullptr;
    }
}
void Manage::data_get(const string& user_data, string credientials[]) const
{
    istringstream stream(user_data);
    int m = 0;
    while (m < 5)
    {
        getline(stream, credientials[m], '|');
        m = m + 1;
    }
}
int Manage::count_users() const
{
    ifstream file(directory);
    if (file.is_open() == false)
    {
        return 0;
    }
    int count = 0;
    string user_data;
    while (getline(file, user_data))
    {
        if (user_data.empty() == false)
        {
            count++;
        }
    }
    file.close();
    return count;
}
string Manage::get_timestamp() const
{
    time_t current = time(0);
    tm time_current;
    localtime_s(&time_current, &current);
    tm* date_current = &time_current;
    int year = date_current->tm_year + 1900;
    int month = date_current->tm_mon + 1;
    int day = date_current->tm_mday;
    int hour = date_current->tm_hour;
    int minute = date_current->tm_min;
    int second = date_current->tm_sec;
    ostringstream date;
   date << year << "-"<< setfill('0') << setw(2) << month << "-"<< setfill('0') << setw(2) << day << " "<< setfill('0') << setw(2) << hour << ":"<< setfill('0') << setw(2) << minute << ":"<< setfill('0') << setw(2) << second;
    return date.str();
}
bool Manage::uniqueness(const string& username) const
{
    ifstream file(directory);
    if (file.is_open() == false)
    {
        return true;
    }
    string user_data;
    while (getline(file, user_data))
    {
        if (user_data.empty() == true)
        {
            continue;
        }
        string credientials[5];
        data_get(user_data, credientials);
        if (credientials[2] == username)
        {
            file.close();
            return false;
        }
    }
    file.close();
    return true; 
}
bool Manage::sign_up(const string& name,const string& username,const string& plain_password) const
{
    bool is_unique = uniqueness(username);
    if (is_unique == false)
    {
        cout << " Error !" << username << "' is already taken." << endl;
        return false;
    }
    string hashed_password = encrypted->input(plain_password);
    int existing = count_users();
    int new_id = existing + 1;
    string date = get_timestamp();
    ofstream file(directory, ios::app);
    if (file.is_open() == false)
    {
        return false;
    }
    file << new_id << "|"<< name << "|"<< username << "|"<< hashed_password << "|"<< "\n";
    file.close();
    return true;
}
bool Manage::log_in(const string& username,const string& plain_password) const
{
    string typed_hash = encrypted->input(plain_password);
    ifstream file(directory);
    if (file.is_open() == false)
    {
        return false;
    }
    string user_data;
    while (getline(file, user_data))
    {
        if (user_data.empty() == true)
        {
            continue;
        }
        string credientials[5];
        data_get(user_data, credientials);
        if (credientials[2] == username)
        {
            file.close();
            string stored_hash = credientials[3];
            if (stored_hash == typed_hash)
            {
                cout << "Logined successfully " << username << endl;
                return true;
            }
            if (stored_hash != typed_hash)
            {
                cout << "Login Failed ! wrong password." << endl;
                return false;
            }
        }
    }
    file.close();
    return false;
}