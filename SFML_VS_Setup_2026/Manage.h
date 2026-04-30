#pragma once
#include <string>
#include <fstream>
#include "Encryption.h"
using namespace std;
const int USER_FIELDS = 5;
class Manage
{
private:
    Encryption* encrypted;
    string   directory;
    bool uniqueness(const string& username) const;
    int count_users() const;
    string get_timestamp() const;
    void data_get(const string& line, string parts[]) const;

public:
    Manage(const string& path);
    bool sign_up(const string& name,const string& username,const string& plain_password)const;
    bool log_in(const string& username,const string& plain_password) const;
    ~Manage();
};

