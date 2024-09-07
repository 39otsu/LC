/*
https://leetcode.com/problems/group-anagrams/description/
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios::sync_with_stdio(false);
        std::cin.tie(0);
        std::vector<std::vector<std::string>> finalOutput;
        std::unordered_map<std::string,int> listExists;
        
        for (int i = 0; i < strs.size(); i++) {
            std::string word = strs[i];
            std::string sortedword = std::string(word);
            std::sort(sortedword.begin(), sortedword.end());
            if (listExists.contains(sortedword)) {
                finalOutput[listExists[sortedword]].push_back(word);
            }
            else {
                listExists[sortedword] = finalOutput.size();
                finalOutput.push_back(std::vector<std::string>{word});
            }
        }
        return finalOutput;
    }
};