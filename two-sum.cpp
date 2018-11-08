#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

vector<int> twoSum(vector<int>&, int);

int main(){
    vector<int> input_array, output;
    input_array.push_back(3);
    input_array.push_back(2);
    input_array.push_back(4);
    output = twoSum(input_array, 6);
    vector<int>:: iterator i;
    for(i=output.begin(); i!= output.end();i++){
        cout << *i;
    }
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target){
    vector<int> numbers;
    vector<int> sorted  = nums;
    sort(sorted.begin(), sorted.end());
    int start, end;
    start = 0;
    end = sorted.size() - 1;
    while(start<end){
        if(sorted[start] + sorted[end] == target){
            vector<int>:: iterator i;
            for(int i = 0; i < nums.size();i++){
                if(nums[i] == sorted[start]){
                  numbers.push_back(i);  
                  break;
                }
            }
            for(int i = 0; i < nums.size();i++){
                if(nums[i] == sorted[end] && i!=numbers[0]){
                  numbers.push_back(i);  
                  break;
                }
            }
            break;
        }else if(sorted[start] + sorted[end] < target){
            cout << start << end;
            start++;
        } else {
            end--;
        }
    }
    return numbers;
}