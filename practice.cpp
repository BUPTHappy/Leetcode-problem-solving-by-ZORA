#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr){}
  ListNode(int x): val(x), next(nullptr){}
  ListNode(int x, ListNode *next) : val(x), next(next){}
};

struct DoubleListNode{
  int val;
  DoubleListNode *next;
  DoubleListNode *last;
  DoubleListNode() : val(0), next(nullptr), last(nullptr) {}
  DoubleListNode(int x) : val(x), next(nullptr), last(nullptr) {}
  DoubleListNode(int x, DoubleListNode *next, DoubleListNode *last) : val(x), next(next), last(last) {}
};
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

//------------------------------------------------------------------------------------------

// 打印正整数的二进制
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

//无序数组的二分搜索（搜索峰值）
int randomPeak(vector<int> array){
  int n = array.size();
  if (n==1) return 0;
  if(array[0]>array[1]) return 0;
  if(array[n-1]>array[n-2]) return n-1;

  //如果上面的都没返回出去，那就是落入了0和n-1都不是峰值的情况，必有峰值在1~n-1
  int l = 1, r = n - 2, m, ans = -1;
  while(l<=r){
    m = (l + r) / 2;
    if(array[m-1]>array[m]){
      r = m - 1; //左边大去左边二分
    }
    else if (array[m+1]>array[m])
    {
      l = m + 1; //右边大去右边二分
    }else{ //那落到这里的就是左边也不大，右边也不大
      ans = m;
      break;
    }
  }
  return ans;
}

//单链表的反转
ListNode* reverseSingleList(ListNode* head){
  ListNode *pre = nullptr;
  ListNode *next = nullptr;
  while (head)
  {
    next = head->next; //先记一下head的下一个，不然一断开就检索不到了
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

//双链表的反转
DoubleListNode *reverseDoubleList(DoubleListNode *head)
{
  DoubleListNode *pre = nullptr;
  DoubleListNode *next = nullptr;
  while(head){
    next = head->next;
    head->next = pre; //双链表改俩指针
    head->last = next;
    pre = head;
    head = next;
  }
  return pre;
}

//合并两个有序链表
ListNode *mergeList(ListNode *list1, ListNode *list2){
  if(!list1 || !list2){
    return !list1 ? list2 : list1;
  }
  ListNode *ans = list1->val > list2->val ? list1 : list2;
  ListNode *curr1 = ans->next;
  ListNode *curr2 = ans == list1 ? list2 : list1;
  ListNode *pre = ans; //刚挂上去节点的前一个

  while (curr1->next && curr2->next){
      if(curr1->val <= curr2->val){
        pre->next = curr1;
        curr1 = curr1->next;
      }else{
        pre->next = curr2;
        curr2 = curr2->next;
      }
      pre = pre->next; //注意更新pre
  }
  pre->next = curr1 ? curr1 : curr2;
  return ans;
}

//两数相加（链表存储进位）
ListNode *addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* ans = nullptr, *curr =nullptr;
    int carry=0;
    for (int val = 0, sum = 0;
         l1 != nullptr || l2 != nullptr;
        l1 == nullptr ? nullptr : l1->next,
        l2 == nullptr ? nullptr : l2->next){
      sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
      val = sum % 10;
      carry = sum / 10;

      if(!ans){
        ans = new ListNode(val);
        curr = ans;
      }else{
        curr->next = new ListNode(val);
        curr = curr->next;
      }
    }

    //这里注意如果都循环完了，还要处理检查一下剩余进位
    if(carry = 1){
      curr->next = new ListNode(1);
    }
    return ans;
}

//分隔链表（小于x的都出现在大于等于x的前边）
ListNode *partition(ListNode*head, int x){
  ListNode *leftHead = nullptr, *leftTail = nullptr, *rightHead = nullptr, *rightTail = nullptr;
  ListNode *next = nullptr;

  while(head){
    next = head->next; //因为一会要动head了，要先记录一下它最开始的下一个，好更新
    head->next = nullptr;
    if(head->val < x){ //小于的放左边
      if(!leftHead){
        leftHead = head;
      }else{
        leftTail->next = head;
      }
      leftTail = head; //在这动态更新
    }else{ //大于等于的放右边
      if(!rightHead){
        rightHead = head;
      }else{
        rightTail->next = head;
      }
      rightTail = head;
    }
    head = next; //这里动态更新遍历元素
  }

  if(!leftHead){
    return rightHead;
  }
  leftTail->next = rightHead;
  return leftHead;
}

//循环队列实现（用固定数组物理结构实现这一逻辑结构）
class MyCircularDeque
{
  public:
    vector<int> queue;
    int l, r, limit, size = 0;
    MyCircularDeque(int k)
    {
      queue.resize(k);
      limit = k;
    }

    bool insertFront(int value)
    {
      if(isFull()){
        return false;
      }
      if(isEmpty()){
        l = r = 0;
        queue[l] = value;
        size++;
      }else{
        l = l == 0 ? (limit-1) : l-1;
        queue[l] = value;
        size++;
      }
      return true;
    }

    bool insertLast(int value)
    {
      if (isFull())
      {
        return false;
      }
      if (isEmpty())
      {
        l = r = 0;
        queue[r] = value;
        size++;
      }
      else
      {
        r = r == (limit - 1) ? 0 : r + 1;
        queue[r] = value;
        size++;
      }
      return true;
    }

    bool deleteFront()
    {
      if(isEmpty()) return false;
      l = l == (limit - 1) ? 0 : l + 1;
      size--;
      return true;
    }

    bool deleteLast()
    {
      if (isEmpty())
        return false;
      r = r == 0 ? (limit - 1) : r - 1;
      size--;
      return true;
    }

    int getFront()
    {
      if(isEmpty()){
        return -1;
      }else{
        return queue[l];
      }
    }

    int getRear()
    {
      if (isEmpty())
      {
        return -1;
      }
      else
      {
        return queue[r];
      }
    }

    bool isEmpty()
    {
      return size == 0;
    }

    bool isFull()
    {
      return size == limit;
    }
};

//二叉树的中序遍历（左中右）
vector<int> inorderTraversal(TreeNode *root){
    vector<int> ans;
    if(!root)
      return {};
    vector<int>left = inorderTraversal(root->left);
    ans.insert(ans.end(), left.begin(), left.end());

    ans.push_back(root->val);

    vector<int> right = inorderTraversal(root->right);
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}

//归并排序（左排好，右排好，二者合并->递归从最小的开始逐渐拼出完整的大的）
static int MAX = 50001; 
vector<int> help(MAX); //这里是避坑一个动态内存的问题
class mergeSort
{
public:
  vector<int> sortArray(vector<int>& nums)
  {
    if (nums.size() > 1)
    {
      sort(nums, 0, nums.size() - 1);
    }
    return nums;
  }

  void sort(vector<int>& nums, int l, int r)
  {
    // base case: 这是个主递归函数，需要有一个最小点的出口
    if (l == r)
    {
      return;
    }
    int m = (l + r) / 2;
    sort(nums, l, m);
    sort(nums, m + 1, r);
    merge(nums, l, m, r);
  }

  void merge(vector<int>& nums, int l, int m, int r)
  {
    int a = l;
    int b = m + 1;
    int i = l; // 这个是辅助数据的遍历元素

    while (a <= m && b <= r){
      help[i++] = nums[a] < nums[b] ? nums[a++] : nums[b++];
    }
    while(a<=m){
      help[i++] = nums[a++];
    }
    while(b<=r){
      help[i++] = nums[b++];
    }

    for (int j = l; j <= r;j++){ //这里j要<=r，r也得复制到！
      nums[j] = help[j];
    }
  }
};

//快速排序（从整体到局部一点点调整（递归），选一个随机数，小的放左边大的放右边）
class quickSort{
public:
  vector<int> sortArray(vector<int>& nums){
    if(nums.size()>1){
      sort(nums, 0, nums.size() - 1);
    }
    return nums;
  }

  void sort(vector<int>nums, int l, int r){  //主递归函数
    if(l>=r){
      return;
    }
    int x = nums[l + rand() % (r - l + 1)]; //这里要注意是l+一个随机，这样确保在不同的范围内x都在里面
    pair<int,int>sign = partition(nums, l, r, x);
    int left = sign.first;
    int right = sign.second;
    sort(nums, l, left - 1);
    sort(nums, right + 1, r);
  }

  void swap(vector<int>nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  pair<int,int> partition(vector<int>nums, int l, int r, int x){
    int first = l;
    int last = r;
    int i = l;
    while(i<=last){
      if(nums[i]==x){
        i++;
      }else if(nums[i]<x){
        swap(nums, first++, i++);
      }else if(nums[i]>x){
        swap(nums, last--, i);
      }
    }
    return {first, last}; //first记录<x区域右侧第一个元素，last记录>x区域左侧第一个元素
  }
};











//------------------------------------------------------------------------------------------
int main()
{
  srand(time(nullptr));
  int other = rand() % 100; // 0～99
  cout << "1. generate random number:" << other << endl;

  double x = rand() / static_cast<double>(RAND_MAX);
  cout << "2. generate random number [0,1):" << x << endl;

  int a = 7;
  print_binary(a);

  vector<int> array1 = {1, 4, 7, 13, 26, 37, 42, 54, 60};
  int num = 37;
  cout << "4. separate search for num " << num << ", result is: " << exist(array1, num) << endl;

  vector<int> array2 = {7, 8, 13, 9, 6, 4};
  cout << "5. separate search used for unordered array to find peak index: " << randomPeak(array2) << endl;
}
