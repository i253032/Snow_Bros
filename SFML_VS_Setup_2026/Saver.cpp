#include "Saver.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>

Saver::Saver(const string& path)
{
    directory = path;
}
Saver::~Saver()
{
    // Nothing dynamic — empty.
}

void Saver::parts_get(const string& line, string fields[]) const
{
    istringstream stream(line);
    int m = 0;
    while (m < PROGRESS_FIELDS)
    {
        getline(stream, fields[m], '|');
        m = m + 1;
    }
}

string Saver::time_now() const
{
    time_t current = time(0);
    tm time_current;
    localtime_s(&time_current, &current);
    int year = time_current.tm_year + 1900;
    int month = time_current.tm_mon + 1;
    int day = time_current.tm_mday;
    int hour = time_current.tm_hour;
    int minute = time_current.tm_min;

    ostringstream date;
    date << year << "-"
        << setfill('0') << setw(2) << month << "-"
        << setfill('0') << setw(2) << day << " "
        << setfill('0') << setw(2) << hour << ":"
        << setfill('0') << setw(2) << minute;
    return date.str();
}

bool Saver::save(const Progress& p) const
{
    bool   found = false;
    string accumulated = "";

    // ----- Step 1: read everything, replacing target line if found -----
    ifstream in_file(directory);
    if (in_file.is_open() == true)
    {
        string line;
        while (getline(in_file, line))
        {
            if (line.empty() == true)
            {
                continue;
            }

            string fields[PROGRESS_FIELDS];
            parts_get(line, fields);

            if (fields[0] == p.username_get())
            {
                ostringstream replaced;
                replaced << p.username_get() << "|"
                    << p.level_get() << "|"
                    << p.lives_get() << "|"
                    << p.gems_get() << "|"
                    << p.score_get() << "|"
                    << time_now();
                accumulated = accumulated + replaced.str() + "\n";
                found = true;
            }
            else
            {
                accumulated = accumulated + line + "\n";
            }
        }
        in_file.close();
    }

    // ----- Step 2: if user not found, append a new record -----
    if (found == false)
    {
        ostringstream fresh;
        fresh << p.username_get() << "|"
            << p.level_get() << "|"
            << p.lives_get() << "|"
            << p.gems_get() << "|"
            << p.score_get() << "|"
            << time_now();
        accumulated = accumulated + fresh.str() + "\n";
    }

    // ----- Step 3: rewrite the whole file -----
    ofstream out_file(directory);
    if (out_file.is_open() == false)
    {
        cout << "Error! Could not open progress file for writing." << endl;
        return false;
    }
    out_file << accumulated;
    out_file.close();
    return true;
}

bool Saver::load(const string& username, Progress& out) const
{
    ifstream file(directory);
    if (file.is_open() == false)
    {
        return false;
    }

    string line;
    while (getline(file, line))
    {
        if (line.empty() == true)
        {
            continue;
        }

        string fields[PROGRESS_FIELDS];
        parts_get(line, fields);

        if (fields[0] == username)
        {
            file.close();

            int level = 0;
            int lives = 0;
            int gems = 0;
            int score = 0;
            istringstream(fields[1]) >> level;
            istringstream(fields[2]) >> lives;
            istringstream(fields[3]) >> gems;
            istringstream(fields[4]) >> score;

            out.username_set(fields[0]);
            out.level_set(level);
            out.lives_set(lives);
            out.gems_set(gems);
            out.score_set(score);
            out.updated_set(fields[5]);
            return true;
        }
    }
    file.close();
    return false;
}

int Saver::high_score_get(const string& username) const
{
    Progress p;
    bool ok = load(username, p);
    if (ok == false)
    {
        return 0;
    }
    return p.score_get();
}

bool Saver::reset_progress(const string& username) const
{
    Progress fresh(username);   // defaults: level 1, lives 2, gems 0, score 0
    return save(fresh);
}
