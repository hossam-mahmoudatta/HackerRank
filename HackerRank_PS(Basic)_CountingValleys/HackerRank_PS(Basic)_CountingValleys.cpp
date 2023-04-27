#include <bits/stdc++.h>
#include <iostream>
#include <string>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int tracker = 0; // Tracker of the steps as i go,
    //  whether I'm above or below sea level
    int upZeroRecorder = 0; // records as i leave a valley
    int downZeroRecorder = 0; // records as i leave a mountain

    for (int i = 0; i < steps; i++) {
        if (path[i] == 85) {
            tracker++;
            if (tracker == 0) {
                upZeroRecorder++;
            }
        } // If my step was UP, then I increment the counter
        // And I check if I reached sea level again,
        // now I know i was in a valley and I left it.

        else if (path[i] == 68) {
            tracker--;
            if (tracker == 0) {
                downZeroRecorder++;
            }
        }
        return upZeroRecorder;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
