//605. Can Place Flowers
//Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
//
//Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
//
//Example 1:
//Input: flowerbed = [1,0,0,0,1], n = 1
//Output: True
//Example 2:
//Input: flowerbed = [1,0,0,0,1], n = 2
//Output: False
//Note:
//        The input array won't violate no-adjacent-flowers rule.
//The input array size is in the range of [1, 20000].
//n is a non-negative integer which won't exceed the input array size.

#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;
using ll = long long;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n)
            return true;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        int l = flowerbed.size();
        int la = flowerbed[1], lala = flowerbed[0], cur;
        for (int i = 2; i < l && n; ++i){
            cur = flowerbed[i];
            if (!lala && !la && !cur){
                la = 1;
                n--;
            }
            lala = la;
            la = cur;
        }
        return n == 0;
    }
};

int main(){

}