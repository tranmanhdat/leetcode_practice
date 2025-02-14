#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <queue>


class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        // we initial an priority queue with the nums with the lowest element at the top
        std::priority_queue<long, std::vector<long>, std::greater<long>> pq(nums.begin(), nums.end());
        int result = 0;
        long top1, top2;
        long new_element;
        while (pq.top() <k){
            long top1 = pq.top();
            pq.pop();
            long top2 = pq.top();
            pq.pop();
            new_element = std::min(top1, top2)*2 + std::max(top1, top2);
            pq.push(new_element);
            result++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {85,93,100,90,40,7,62,90,68,88};
    int k = 88;
    int result = solution.minOperations(nums, k);
    std::cout << "Result: " << result << std::endl;
    return 0;
}