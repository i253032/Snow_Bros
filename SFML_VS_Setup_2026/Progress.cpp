#include "Progress.h"

Progress::Progress()
{
    username = "";
    current_level = 1;
    lives_remaining = 2;
    gem_count = 0;
    high_score = 0;
    last_updated = "";
}

Progress::Progress(const string& name)
{
    username = name;
    current_level = 1;
    lives_remaining = 2;
    gem_count = 0;
    high_score = 0;
    last_updated = "";
}

void Progress::username_set(const string& name) { username = name; }
void Progress::level_set(int level) { current_level = level; }
void Progress::lives_set(int lives) { lives_remaining = lives; }
void Progress::gems_set(int gems) { gem_count = gems; }
void Progress::score_set(int score) { high_score = score; }
void Progress::updated_set(const string& when) { last_updated = when; }

string Progress::username_get() const { return username; }
int    Progress::level_get()    const { return current_level; }
int    Progress::lives_get()    const { return lives_remaining; }
int    Progress::gems_get()     const { return gem_count; }
int    Progress::score_get()    const { return high_score; }
string Progress::updated_get()  const { return last_updated; }

void Progress::reset()
{
    current_level = 1;
    lives_remaining = 2;
    gem_count = 0;
    high_score = 0;
    last_updated = "";
}