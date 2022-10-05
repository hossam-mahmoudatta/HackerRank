
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Define the structs Workshops and Available_Workshops.

struct Workshop {
    int startTime;
    int duration;
    int endTime;
};

struct Available_Workshops {
    
    int n; // the number of workshops the student signed up for
    vector<Workshop> workshops; // created vector since we can controll its size
    
    /*
    Workshop** workshops; // creating an array of size of n
    Available_Workshops(int number) {
        n = number;
        workshops = new Workshop * [number];
    }
    ~Available_Workshops() {
        for (int i = 0; i < n; i++) {
            delete workshops[n];
        }
    }
    */
};

//Implement the functions initialize and CalculateMaxWorkshops

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    // return ptr to Available_Workshops object
    // i need to initialize the members of the 
    // Workshop struct thru this function, but how ?
    //Available_Workshops* a1 = { 0 }; // my old initialization
    
    // Initializing a new object for Available_Workshops
    Available_Workshops* a1 = new Available_Workshops;
    a1->n = n;

    // doing a for loop, i was actually thinking of doing it.
    for (int i = 0; i < n; i++) {
        Workshop w1;
        // So the difference b/w this and my syntax is that
        // this implementation instead of pointing from available_workshops,
        // it points from workshops struct
        w1.startTime = start_time[i];
        w1.duration = duration[i];
        w1.endTime = start_time[i] + duration[i];

        a1 -> workshops.push_back(w1);
        // it means that after assigning the values of w1
        // i will access the workshops member inside the
        // available_workshops struct and then assign w1 to it.
    }

    sort(a1->workshops.begin(),
        a1->workshops.end(),
        [](const Workshop& one, const Workshop& two) {
            return one.endTime < two.endTime;
        });
    // Dunno why he used this function, maybe to sort the order of workshops?

    return a1;
}

/*
bool compare(Workshop* one, Workshop* two) {
    return (one->endTime) < (one->endTime);
    // Don't know what is the use of this function
}
*/

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    
    //int workshopEnd= 0;
    int valid = 1;
    int currentWorkshop = 0;

    for (int i = 0; i < ptr->n; i++) {
        if (ptr->workshops[i].startTime >= ptr->workshops[currentWorkshop].endTime) {
            valid++;
            currentWorkshop = i;
            //workshopEnd = ptr->workshops[i]->endTime;
            // this logic is pretty fathomable
            
        }
    }
    return valid;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
