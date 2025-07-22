//N meetings in one room

/*
    Problem Statment:
    You are given timings of n meetings in the form of (start[i], end[i]) 
    where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. 
    Return the maximum number of meetings that can be accommodated in a single meeting room, 
    when only one meeting can be held in the meeting room at a particular time. 
*/

/*
    Approach:
    1. Create a vector of pairs to store the start and end times of each meeting.
       - vector<pair<int, int>> meetings;
    2. Sort the meetings based on their end times.
       - sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.second < b.second;
       });
    3. Initialize a variable to keep track of the end time of the last meeting that was added to the schedule.
       - int lastEndTime = meetings[0].second;
    4. Initialize a counter to keep track of the number of meetings that can be accommodated.
       - int count = 1; // The first meeting is always counted
    5. Iterate through the sorted meetings starting from the second meeting
         - for (int i = 1; i < meetings.size(); i++) {
              - if (meetings[i].first >= lastEndTime) {
                - count++;
                - lastEndTime = meetings[i].second; // Update the end time of the last meeting
              - }
         - }
    6. Return the count of meetings that can be accommodated.
       - return count;

*/
/*
    Complexity Analysis:
    - Time Complexity: O(n log n), where n is the number of meetings. This is due to the sorting step.
    - Space Complexity: O(n), for storing the meetings in a vector of pairs.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMeetings(vector<int> start, vector<int> end){
    vector<pair<int,int>>Meetings;
    for(int i=0;i<start.size();i++){
        Meetings.push_back({start[i],end[i]});
    }
    sort(Meetings.begin(),Meetings.end(),[](const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second; // sort by end time
    });
    int lastEndTime = Meetings[0].second; // end time of the last meeting
    int count = 1; // count of meetings that can be accommodated
    for(int i=0;i<Meetings.size();i++){
        if(Meetings[i].first >= lastEndTime){ // if the start time of the current meeting is greater than or equal to the end time of the last meeting
            count++;
            lastEndTime = Meetings[i].second; // update the end time of the last meeting
        }
    }
    return count;
}
int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    int result = maxMeetings(start, end);
    cout << "Maximum number of meetings that can be accommodated: " << result << endl;

    return 0;
}