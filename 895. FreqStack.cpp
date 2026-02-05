#include <unordered_map>
#include <vector>
using namespace std;

class FreqStack
{
private:
  int topFres = 0;
  unordered_map<int, vector<int>> cntLayers;
  unordered_map<int, int> freqs;

public:
  void push(int val)
  {
    freqs[val]++;
    int currentFreq = freqs[val];
    cntLayers[currentFreq].push_back(val);
    topFres = max(currentFreq, topFres);
  }

  int pop()
  {
    int ans = cntLayers[topFres].back();
    cntLayers[topFres].pop_back();
    freqs[ans]--;
    if (cntLayers[topFres].empty())
    {
      cntLayers.erase(topFres);
      topFres--;
    }
    return ans;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */