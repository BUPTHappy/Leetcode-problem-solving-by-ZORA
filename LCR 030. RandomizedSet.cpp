#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet
{
public:
  /** Initialize your data structure here. */
  unordered_map<int, int> hash_map;
  vector<int> array;

  RandomizedSet()
  {
    srand(time(nullptr));
  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val)
  {
    if (hash_map.find(val) != hash_map.end())
    {
      return false;
    }
    hash_map[val] = array.size(); // 或者写成 hash_map.insert({val, array.size()});
    array.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val)
  {
    if (hash_map.find(val) == hash_map.end())
    {
      return false;
    }
    int recordIndex = hash_map[val];
    int lastNum = array[array.size() - 1];

    array[recordIndex] = lastNum;
    hash_map[lastNum] = recordIndex;
    array.pop_back();
    hash_map.erase(val);

    return true;
  }

  /** Get a random element from the set. */
  int getRandom()
  {

    int randomIndex = rand() % array.size();
    return array[randomIndex];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */