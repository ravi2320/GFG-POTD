/*
Job Sequencing Problem
Difficulty: MediumAccuracy: 34.51%Submissions: 241K+Points: 4
Given a set of n jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

Examples :

Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
Expected Time Complexity: O(nlogn)
Expected Auxilliary Space: O(n)

Constraints:
1 <= n <= 105
1 <= Deadline,id <= n
1 <= Profit <= 500
*/

class Solution 
{
public:
    // Function to compare two jobs based on profit in descending order.
    bool static comp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Sort jobs in descending order of profit.
        sort(arr, arr + n, comp);

        // Find the maximum deadline to determine the size of the slot array.
        int maxi = arr[0].dead;
        for(int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        // Initialize slot array to track the occupied time slots, initialized to -1 (unoccupied).
        int slot[maxi + 1];
        for(int i = 0; i <= maxi; i++) slot[i] = -1;

        int countJobs = 0;  // Count of jobs done.
        int jobProfit = 0;  // Total profit from jobs.

        // Iterate over each job in descending order of profit.
        for(int i = 0; i < n; i++) {
            // Try to find a free slot for this job, starting from its deadline.
            for(int j = arr[i].dead; j > 0; j--) {
                if(slot[j] == -1) {  // If the slot is free.
                    slot[j] = i;     // Assign this slot to the job.
                    countJobs++;     // Increment the job count.
                    jobProfit += arr[i].profit;  // Add the profit.
                    break;  // Move to the next job.
                }
            }
        }

        // Return the total number of jobs done and the total profit earned.
        return {countJobs, jobProfit};
    } 
};
