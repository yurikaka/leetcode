//599. Minimum Index Sum of Two Lists
//Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
//
//You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
//
//Example 1:
//Input:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//Output: ["Shogun"]
//Explanation: The only restaurant they both like is "Shogun".
//Example 2:
//Input:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["KFC", "Shogun", "Burger King"]
//Output: ["Shogun"]
//Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
//Note:
//        The length of both lists will be in the range of [1, 1000].
//The length of strings in both lists will be in the range of [1, 30].
//The index is starting from 0 to the list length minus 1.
//No duplicates in both lists.

#include <bits/stdc++.h>

using namespace std;

long long M = 1000000007;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int l1 = list1.size(), l2 = list2.size();
        unordered_map<string,int> m;
        for (int i = 0; i < l1; ++i)
            m[list1[i]] = i;
        int index = INT_MAX;
        vector<int> ans;
        for (int i = 0; i < l2; ++i)
            if (m.count(list2[i])){
                if (m[list2[i]]+i < index){
                    index = m[list2[i]] + i;
                    ans.clear();
                }
                if (m[list2[i]]+i == index)
                    ans.push_back(i);
            }
        vector<string> result;
        for (auto i : ans)
            result.push_back(list2[i]);
        return result;
    }
};

int main(){

}