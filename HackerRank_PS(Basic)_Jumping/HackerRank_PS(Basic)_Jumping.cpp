// Problem Link: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&isFullScreen=false&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=warmup&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {
    int counter = 0;
    int streakCounter = 0;
    int jumps = 0;
    vector<int> streakLength;

    for (int i = 0; i < c.size(); i++) {
        if (c[i] == 0) {
            counter++;
        } // I will count the number of "0's" untill im stopped by a "1"
        else {
            streakLength.push_back(counter);
            counter = 0;
            streakCounter++;
        } // When I'm stopped by a "1", I will push the value
        // of the counter inside a vector, and reset counter to "0"
        // and will increment streakcounter by "1"
        // because I want to know how many consecutive "0's" I got
    }

    if (counter > 0) {
        streakLength.push_back(counter);
        streakCounter++;
    } // After ending the for loop, suppose i didnt end at a "1"
    // so it means I will never trigger the else cond
    // so im checking if the counter worked again or not.

    for (int i = 0; i < streakLength.size(); i++) {
        cout << streakLength[i] << endl;
        jumps += streakLength[i] / 2;
    } // Here I'm calculating the jumps from the values i saved into the vector
    // and adding them into the jumps variable

    jumps += streakCounter - 1;
    // the previous line to calculate the jumps between "1's"
    // and then deduct a 1 
    cout << "How Many Streaks? " << streakCounter << ", " << endl;
    //cout << "How Many Streaks? " << streakCounter << ", " << endl;
    return jumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
