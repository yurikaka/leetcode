//587. Erect the Fence My SubmissionsBack To Contest
//There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.
//
//Example 1:
//Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
//Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
//Explanation:
//
//        Example 2:
//Input: [[1,2],[2,2],[4,2]]
//Output: [[1,2],[2,2],[4,2]]
//Explanation:
//
//        Even you only have trees in a line, you need to use rope to enclose them.
//Note:
//
//        All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
//All input integers will range from 0 to 100.
//The garden has at least one tree.
//All coordinates are distinct.
//Input points have NO order. No order required for output.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>
#include <memory.h>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <math.h>

using namespace std;

long long M = 1000000007;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool cmp(Point a, Point b){
    if(a.y == b.y)  return a.x < b.x;
    return a.y < b.y;
}

bool turnRight(Point px1, Point px2, Point pp){
    return (px2.x - px1.x)*(pp.y - px2.y) < (pp.x - px2.x)*(px2.y - px1.y);
}

class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        vector<int> CH; //存放凸包顶点序号   模拟栈
        int nodeNum = points.size();
        if (nodeNum < 3)
            return points;
        CH.resize(nodeNum+1);
        sort(points.begin(), points.end(), cmp);
        CH[0] = 0;
        CH[1] = 1;

        int top = 1;
        //从起点0到到排序最后点作凸包右链  过程1
        for(int i=2; i<nodeNum; i++){
            while( top && turnRight(points[CH[top-1]], points[CH[top]], points[i]) )
                top--;
            CH[++top] = i;
        }

        int len = top;
        //从排序最高点到到起点0fab反向作凸包右链  过程2
        CH[++top] = nodeNum-2;
        for(int i=nodeNum-3; i>=0; i--){
            //top!=len, 不考虑已在过程1生成凸包上的点
            while( top!=len && turnRight(points[CH[top-1]], points[CH[top]], points[i]) )
                top--;
            CH[++top] = i;
        }

        int sPos;
        set<pair<int,int>> rr;
        vector<Point> r;
        //在栈中找到凸包起点
        for(sPos=0; sPos<top; sPos++)
            if(points[CH[sPos]].x == points[0].x && points[CH[sPos]].y == points[0].y)
                break;
        //从起点开始逆时针输出凸包
        for(int i=sPos; i<top; i++)
            rr.insert({points[CH[i]].x,points[CH[i]].y});
        for(int i=0; i<sPos; i++)
            rr.insert({points[CH[i]].x,points[CH[i]].y});
        rr.insert({points[CH[sPos]].x,points[CH[sPos]].y});
        for (auto i : rr)
            r.push_back(Point(i.first,i.second));
        return r;
    }
};

int main(){

}