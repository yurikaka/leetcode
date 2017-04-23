//149. Max Points on a Line
//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// * Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> points) {
        unordered_map<long double,int> k;
        unordered_map<long double,int>::iterator itk;
        vector<Point>::iterator it,it2;
        int ver, all, result = 0;
        long double kk;
        for (it = points.begin(); it != points.end(); ++it){
            k.clear();
            ver = 0;
            all = 1;
            for (it2 = points.begin(); it2 != points.end(); ++it2){
                if (it2 == it)
                    continue;
                if (it->x == it2->x){
                    if (it->y == it2->y)
                        ++all;
                    else
                        ++ver;
                }
                else {
                    kk = (long double)((long double)(it->y - it2->y)/(long double)(it->x - it2->x));
                    cout << kk <<endl;
                    if (k.find(kk) != k.end())
                        ++k[kk];
                    else
                        k[kk] = 1;
                }
            }
            for (itk = k.begin(); itk != k.end(); ++itk)
                if (itk->second > ver)
                    ver = itk->second;
            if (ver + all > result)
                result = ver + all;
        }
        return result;
    }
};

int main() {
    Solution s;
    Point a(0,0),b(94911151,94911150),c(94911152,94911151);
    cout << s.maxPoints(vector<Point>({a,b,c})) << endl;
    return 0;
}

