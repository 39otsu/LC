/*
https://leetcode.com/problems/top-k-frequent-elements/description/
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        std::cin.tie(0);
        std::vector<int> sovl;
        std::unordered_map<int,int> counter;
        for (int i = 0; i < nums.size(); i++) {
            if (counter.contains(nums[i])) {
                counter[nums[i]]++;
            }
            else {
                counter[nums[i]] = 1;
            }
        }

        std::vector<std::pair<int, int>> elements(counter.begin(), counter.end());

        std::sort(elements.begin(), elements.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
        });

        int i = 0;
        for (const auto& element : elements) {
            if (i < k) {
                sovl.push_back(element.first);
            } else {
                break;
            }
            i++;
        }
        return sovl;
    }
};