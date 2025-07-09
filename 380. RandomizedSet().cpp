//
// Created by Zhuoer LIU on 2025-07-09.
//
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;   //这里是关键！
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (valToIndex.count(val)){
            return false;
        }else{
            nums.push_back(val);
            valToIndex[val] = nums.size() - 1;
            return true;
        }
    }

    bool remove(int val) {
        if(!valToIndex.count(val)){
            return false;
        }
        int index = valToIndex[val];
        int last = nums.back();
        nums[index] = last;
        valToIndex[last] = index;

        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */