#include<iostream>
#include<vector>
#include<map>
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
    map<int,int> table;
    vector<int> output;
    int complement;
    for(int index =0; index < nums.size(); index++){
        table.insert(pair<int, int>(nums[index], index));
    }
    for(int index = 0; index < nums.size(); index++){
        complement = target - nums[index];
        if(table.find(complement) != table.end() && table.find(complement)->second != index){
            output.push_back(index);
            output.push_back(table[complement]); 
            break;
        }
    }
    return output;
}