#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        if (pattern.compare("I") == 0){
            return "12";
        }
        if (pattern.compare("D") == 0){
            return "21";
        }
        this->pattern = pattern;
        backtrack(0, digits);
        return to_string(result);
    }
    string pattern;
    vector<int> digits = {1,2,3,4,5,6,7,8,9};
    int result;
    vector<int> current_result;
    bool target_found = false;
    void backtrack(int position, vector<int> digits){
        for (int i = 0; i < digits.size(); i++){
            int value = digits[i];
            digits.erase(digits.begin() + i);
            if (position == 0){
                current_result.push_back(value);
                backtrack(position+1, digits);
                current_result.pop_back();
            } else if (position == pattern.length()){
                if (pattern[position-1] == 'I'){
                    if (current_result[current_result.size()-1] < value){
                        current_result.push_back(value);
                        string temp_result = "";
                        for (int j = 0; j < current_result.size(); j++){
                            temp_result += to_string(current_result[j]);
                        }
                        result = stoi(temp_result);
                        target_found = true;
                        current_result.pop_back();
                    } else {
                        return;
                    }
                } else {
                    if (current_result[current_result.size()-1] > value){
                        current_result.push_back(value);
                        string temp_result = "";
                        for (int j = 0; j < current_result.size(); j++){
                            temp_result += to_string(current_result[j]);
                        }
                        result = stoi(temp_result);
                        target_found = true;
                        current_result.pop_back();
                    } else {
                        return;
                    }
                }
            } else {
                if (pattern[position-1] == 'I'){
                    if (current_result[current_result.size()-1] < value){
                        current_result.push_back(value);
                        backtrack(position+1, digits);
                        current_result.pop_back();
                    } else {
                        return;
                    }
                } else {
                    if (current_result[current_result.size()-1] > value){
                        current_result.push_back(value);
                        backtrack(position+1, digits);
                        current_result.pop_back();
                    } else {
                        return;
                    }
                }
            }
            digits.insert(digits.begin() + i, value);
        }
        if (target_found){
            return;
        }
    }
};


int main() {
    Solution s;
    string pattern = "DDDIII";
    cout << s.smallestNumber(pattern) << endl;
    return 0;
}