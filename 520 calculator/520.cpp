#include <iostream>
#include <ctime>

using namespace std;

const long long SECONDS_PER_DAY = 3600L * 24L;

long long days_since(int year, int month, int day) {
    // Current time since epoch
    time_t now = time(nullptr);

    // Convert year, month and day to a tm object
    tm beg = *localtime(&now);
    beg.tm_year = year - 1900;
    beg.tm_mon = month - 1;
    beg.tm_mday = day;

    // difftime returns seconds
    time_t bd = mktime(&beg);
    return static_cast<long long>(difftime(now, bd))/SECONDS_PER_DAY;
}


// if you decompiled this, know I calculate from the day we meet, not the day I told you I love you.
int main(){
    cout << "I have loved you for " << days_since(2022, 9, 10) <<  " days." << endl;
    cin.get();
    return 0;
};
