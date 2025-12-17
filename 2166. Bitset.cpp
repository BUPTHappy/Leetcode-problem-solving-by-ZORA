//
// Created by Zhuoer LIU on 2025-12-17.
//
#include<vector>
#include<string>
using namespace std;

class Bitset {
private:
    vector<int> bits;
    const int size;
    int ones;
    int zeros;
    bool reversed;
public:
    Bitset(int n): size(n), zeros(n), ones(0), reversed(false){ //这个是用初始化列表来初始化所有成员变量
        bits.resize((n+31)/32,0);
    }

    void fix(int idx) {
        int number = idx/32;
        int bit = idx%32;

        if(!reversed){
            //现在就是1是存在，0是不存在
            //我们这个函数是为了给ind的不存在的变成存在
            if((bits[number] & (1<<bit))==0){
                zeros--;
                ones++;
                bits[number] |= (1<<bit);
            }
        }else{
            //现在就是被翻转后了，0是存在，1是不存在
            //如果查到这个数是1了，就要改为0，因为这个函数是让他存在
            if((bits[number] & (1<<bit)) !=0){ //这个地方因为你是移动1，所以必须是要写!=0的而不能写==1
                zeros--;
                ones++;
                bits[number] ^= (1<<bit);
            }
        }
    }

    void unfix(int idx) {
        int number = idx/32;
        int bit = idx%32;
        if(!reversed){
            //现在就是1是存在，0是不存在
            //我们这个函数是为了给ind的不存在的变成存在
            if((bits[number] & (1<<bit))!=0){
                zeros++;
                ones--;
                bits[number] ^= (1<<bit);
            }
        }else{
            //现在就是被翻转后了，0是存在，1是不存在
            //如果查到这个数是1了，就要改为0，因为这个函数是让他存在
            if((bits[number] & (1<<bit)) ==0){ //这个地方因为你是移动1，所以必须是要写!=0的而不能写==1
                zeros++;
                ones--;
                bits[number] |= (1<<bit);
            }
        }
    }

    void flip() {
        reversed = !reversed;
        int temp =zeros;
        zeros = ones;
        ones = temp;
    }

    bool all() {
        return ones == size; //1的数量是否等于整体的数量
    }

    bool one() {
        return ones>0;
    }

    int count() {
        return ones;
    }

    string toString() {
        string s="";
        for (int i = 0, k = 0, number, status; i < size; k++) {
			number = bits[k];
			for (int j = 0; j < 32 && i < size; j++, i++) {
				status = (number >> j) & 1;
				status ^= reversed ? 1 : 0;
				s += (status ? '1' : '0');
			}
		}
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */