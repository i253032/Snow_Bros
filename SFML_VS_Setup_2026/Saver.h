#pragma once
#include "Progress.h"
#include <string>
using namespace std;

const int PROGRESS_FIELDS = 6;

class Saver
{
private:
    string directory;

    void   parts_get(const string& line, string fields[]) const;
    string time_now() const;

public:
    Saver(const string& path);

    // Saves a Progress (creates new line, or replaces existing line for same username)
    bool save(const Progress& p) const;

    // Loads a Progress for the given username; returns false if user has no record yet
    bool load(const string& username, Progress& out) const;

    // Convenience helper — quickly read just the high score
    int  high_score_get(const string& username) const;

    // Wipe a player's progress (for "New Game" reset)
    bool reset_progress(const string& username) const;

    ~Saver();
};