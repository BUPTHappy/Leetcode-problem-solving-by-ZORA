//
// Created by Zhuoer LIU on 2025-06-10.
//
#include<iostream>
using namespace std;

//不过我这个解答是一个时间复杂度为O(m+n)的
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i<nums2.size();++i){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2==0){
            double result = static_cast<double>(nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2;
            return result;
        }else{
            return nums1[(nums1.size())/2];
        }
    }
};

//正解应该是用二分法： 主要是考虑两种特殊细节，一个是交叉比较得到条件；一个是数组越界的特殊处理
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //首先，我们先安排好都让第一个数组为较短的数组，第二个数组为较长的数组
        if(nums1.size()>nums2.size()){
            vector<int>temp=nums1;
            nums1=nums2;
            nums2=temp; //如果不是，我们做交换调整
        }
        int m=nums1.size();  //数组1的长度
        int n=nums2.size();  //数组2的长度


        //定义一个变量为分割线左侧所有的元素和
        int totalLeft=(m+n+1)/2;  //无论m+n之和是奇还是偶，都可以总结为这个，因为偶数是m+n/2但编译器除法是向下取整，所以+1也不影响结果


        /*定义分割线：
        1. 分割线在第1个数组右边的第1个元素的下标i = 分割线在第1个数组左边一共的元素个数（由于数组下标从0开始）
        2. 分割线在第2个数组右边的第1个元素的下标j = 分割线在第2个数组左边一共的元素个数

        所以所有左边元素的和就是i+j，也就是 (m+n+1) / 2 = totalLeft

        然后再加上特殊情况下得出的条件，就比如第一个数组（比较短）的所有元素都在分割线左边：
            要满足交叉比较的条件：数组1[i-1] <= 数组2[j] && 数组2[j-1] <= 数组1[i]
        */
        int left = 0 ;
        int right = m ;
        while(left<right){
            int i = left + (right-left+1)/2;
            int j = totalLeft-i;
            if(nums1[i-1] > nums2[j]){ //如果上面得到的交叉比较的条件不满足， 就说明分割线取得不合适，需要调整
                //分割线太靠第一个数组的左侧了，下一轮的搜索区间就是[left,i-1]
                right=i-1;
            }else{
                left = i; //也就是满足条件，直接设置可以终止循环
            }
        }
        //推出循环之后，我们就已经找到了满足条件的left的位置
        int i = left;
        int j = totalLeft-i;

        //然后我们获取两个数组左右两侧的四个元素,但需要考虑数组越界访问不到这个元素的情况
        int num1LeftMax = i==0 ? INT_MIN : nums1[i-1]; //[i-1]没有意义，直接赋值为整型最小值
        int num1RightMin = i==m ? INT_MAX : nums1[i];  //nums[i]没有意义，直接赋值为整形最大值
        int num2LeftMax = j==0 ? INT_MIN: nums2[j-1];
        int num2RightMin = j==n ? INT_MAX : nums2[j];

        //这下我们就可以开始利用这四个元素找到中位数：
        if((m+n)%2 == 1){  //当数组长度和为奇数，直接返回分割线左边元素的最大值
            return max(num1LeftMax,num2LeftMax);
        }else{  //如果为偶数, 返回分割线左边最大的和右边最小的两个元素的平均数
            return ((max(num1LeftMax,num2LeftMax))+(min(num1RightMin,num2RightMin))) /2.0;
        }

    }
};