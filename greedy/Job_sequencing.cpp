//Job Sequencing Problem

/*
    Problem Statment:
    You are given two arrays: deadline[], and profit[], which represent a set of jobs, 
    where each job is associated with a deadline, and a profit. 
    Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
    You will earn the profit associated with a job only if it is completed by its deadline.
*/
/*
    Approach:
    1. Create a vector of pairs to store the jobs along with their deadlines and profits.
       - vector<pair<int, pair<int, int>>> jobs; // {profit, {deadline, index}}
    2. Sort the jobs based on profit in descending order.
       - sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
           return a.first > b.first; // sort by profit
       });
    3. Initialize a vector to keep track of the scheduled jobs.
       - vector<int> scheduledJobs(deadline.size(), -1); // -1 means no job scheduled
    4. Initialize a variable to keep track of the total profit.
       - int totalProfit = 0;
    

    return totalProfit;
}
*/