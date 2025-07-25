//Job Sequencing Problem

/*
    Problem Statment:
    You are given two arrays: deadline[], and profit[], which represent a set of jobs, 
    where each job is associated with a deadline, and a profit. 
    Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
    You will earn the profit associated with a job only if it is completed by its deadline.
*/
/*
    Apprach:
    1. create a vector of pairs to store jobs with their profits and deadlines.
      2. Sort the jobs in descending order of profit.
      // sort(jobs.begin(), jobs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
      //     return a.second > b.second;
      // 
   });

   3. create 3 variables : totalProfit, count  and maxDeadline.
   4. find the maximum deadline from the jobs.
     for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.first);
         
         }
   5. create a vector of size maxDeadline+1 initialized with -1 to keep track of scheduled jobs.
   6. iterate through the jobs and for each job, find a free slot before its deadline.
      - if a free slot is found, schedule the job and update totalProfit and count.
      for i=0 to jobs.size()
      {
          for j=job[i].deadline to 0
          {
              if slot[j] == -1
              {
                  slot[j] = i;
                  totalProfit += job[i].second;
                  count++;
                  break;
              }
          }
      }

   return {totalProfit, count};
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> jobsequencing(vector<pair<int,int>>& jobs){
   // Sort jobs in descending order of profit
   sort(jobs.begin(),jobs.end(),[](const pair<int,int> &a, const pair<int,int>& b) {
       return a.second > b.second;
   });
   int toalProfit = 0, count = 0, maxDeadline = 0;
   // Find the maximum deadline
   for(auto job: jobs){
      maxDeadline = max(maxDeadline, job.first);
   }
   // Create a vector to keep track of scheduled jobs
   vector<int> slot(maxDeadline+1,-1);

   for(int i=0;i<jobs.size();i++){
      for(int j=jobs[i].first;j>0;j--){
         if(slot[j]==-1){
            slot[j]=i; // Schedule the job
            toalProfit += jobs[i].second; // Update total profit
            count++;
            break; // Break the loop once the job is scheduled
         }
      }
   }
   return {toalProfit, count};
}

int main() {
    vector<pair<int, int>> jobs = {{2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15}};
    pair<int, int> result = jobsequencing(jobs);
    cout << "Total Profit: " << result.first << ", Number of Jobs Scheduled: " << result.second << endl;
    return 0;
}