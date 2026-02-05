#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedCollection
{
public:
  unordered_map<int, unordered_set<int>> record_map;
  vector<int> array;

  RandomizedCollection()
  {
    srand(time(nullptr));
  }

  bool insert(int val)
  {
    bool existed = record_map.find(val) != record_map.end();
    record_map[val].insert(array.size());
    array.push_back(val);
    return !existed;
  }

  bool remove(int val)
  {
    if (record_map.find(val) == record_map.end())
    {
      return false;
    }

    int recordIndex = *record_map[val].begin();
    int lastNum = array.back();

    // 这里需要一个特判，如果要删的这个index就是最后一个index
    if (recordIndex == array.size() - 1)
    {
      record_map[val].erase(recordIndex);
      if (record_map[val].empty())
      {
        record_map.erase(val);
      }
      array.pop_back();
      return true;
    }

    array[recordIndex] = lastNum;
    record_map[lastNum].erase(array.size() - 1);

    // 只有最后一个数不是val的时候才需要这么操作一番
    if (lastNum != val)
    {
      record_map[lastNum].insert(recordIndex);
      record_map[val].erase(recordIndex);
    }

    if (record_map[val].empty())
    {
      record_map.erase(val);
    }

    array.pop_back();
    return true;
  }

  int getRandom()
  {
    return array[rand() % array.size()];
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */