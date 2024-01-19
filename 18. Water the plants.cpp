/*
Water the plants
MediumAccuracy: 55.22%Submissions: 25K+Points: 4
Boost your resume to top companies via this Free Hiring Contest! 

banner
A gallery with plants is divided into n parts, numbered 0, 1, 2, 3, ..., n-1. There are provisions for attaching water sprinklers in every division. A sprinkler with range x at division i can water all divisions from i-x to i+x.

Given an array gallery[] consisting of n integers, where gallery[i] is the range of the sprinkler at partition i (a power of -1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the entire gallery. If there is no possible way to water the full length using the given sprinklers, print -1.

Example 1:

Input:
n = 6
gallery[] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: 
Sprinklers at index 2 and 5
can water the full gallery, span of
sprinkler at index 2 = [0,4] and span
of sprinkler at index 5 = [5,5].
Example 2:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 2, 0, 0, -1, 0}
Output:
-1
Explanation: 
No sprinkler can throw water
at index 7. Hence all plants cannot be
watered.
Example 3:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 0, 0, 0, 0, 0}
Output:
3
Explanation: 
Sprinkler at indexes 2, 7 and
8 together can water all plants.
*/

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int, int>> range;
        for(int i=0; i<n; i++){
            if(gallery[i] != -1){
                int left = max(0, i-gallery[i]);
                int right = min(n-1, i+gallery[i]);
                range.push_back({left, right});
            }
        }
        sort(range.begin(), range.end());
        int start = 0, ans = 0, i = 0, end = INT_MIN;
        while(start < n){
            end = INT_MIN;
            while(i < n && range[i].first <= start){
                end = max(end, range[i].second);
                i++;
            }
            if(end == INT_MIN) return -1;
            
            ans++;
            start = end+1;
        }
        return ans;
    }
};