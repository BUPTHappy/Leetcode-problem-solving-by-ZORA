#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//打印正整数的二进制
void print_binary(int num)
{
  cout << "3. print binary of " << num << ": ";
  for (int i = 31; i >= 0; i--)
  {
    cout << ((num & (1 << i)) == 0 ? '0' : '1'); // 用按位与运算来"探测"原数字对应位是否为1
  }
  cout << endl;
}

// 二分搜索
bool exist(vector<int> array, int num)
{
  if (array.empty())
    return false;
  int left = 0, right = array.size() - 1;
  while (left <= right) //这里需要处理等号情况
  {
    int middle = left + ((right - left) >> 1);

    if (array[middle] == num)
    {
      return true;
    }
    else if (array[middle] > num)
    {
      right = middle - 1;
    }
    else
    {
      left = middle + 1;
    }
  }
  return false;
}






int main()
{
  srand(time(nullptr));
  int other = rand() % 100; // 0～99
  cout << "1. generate random number:" << other << endl;

  double x = rand() / static_cast<double>(RAND_MAX);
  cout << "2. generate random number [0,1):" << x << endl;

  int a = 7;
  print_binary(a);

  vector<int> array = {1, 4, 7, 13, 26, 37, 42, 54, 60};
  int num = 37;
  cout << "4. separate search for num " << num << ", result is: " << exist(array, num) << endl;
}
