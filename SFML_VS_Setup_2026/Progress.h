#pragma once
#include <string>
using namespace std;

class Progress
{
private:
    string username;
    int    current_level;
    int    lives_remaining;
    int    gem_count;
    int    high_score;
    string last_updated;
public:
    Progress();
    Progress(const string& name);

    // Setters
    void username_set(const string& name);
    void level_set(int level);
    void lives_set(int lives);
    void gems_set(int gems);
    void score_set(int score);
    void updated_set(const string& when);

    // Getters
    string username_get() const;
    int    level_get()    const;
    int    lives_get()    const;
    int    gems_get()     const;
    int    score_get()    const;
    string updated_get()  const;

    void reset();   // sets defaults for a brand-new game
};