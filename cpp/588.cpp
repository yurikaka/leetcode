//588. Design In-Memory File System
//Design an in-memory file system to simulate the following functions:
//
//ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.
//
//mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.
//
//addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.
//
//readContentFromFile: Given a file path, return its content in string format.
//
//Example:
//        Input:
//["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
//[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
//Output:
//[null,[],null,null,["a"],"hello"]
//Explanation:
//        filesystem
//Note:
//        You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
//You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
//You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.

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

struct tree{
    int index = -1;
    unordered_map<string,tree*> next;
};

void split(std::string& s, std::string& delim,std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);
    while (index!=std::string::npos)
    {
        ret->push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    if (index-last>0)
    {
        ret->push_back(s.substr(last,index-last));
    }
}

class FileSystem {
public:
    tree* root;
    int num;
    unordered_map<int,string> m;
    FileSystem() {
        root = new tree;
        num = 0;
    }

    vector<string> ls(string path) {
        tree* current = root;
        int pos = 1,next;
        int l = path.size();
        vector<string> r;
        while (pos < l){
            next = path.find('/',pos);
            if (next != string::npos) {
                r.push_back(path.substr(pos, next - pos));
                pos = next + 1;
            }
            else {
                r.push_back(path.substr(pos));
                break;
            }
        }
        for (string s: r){
            current = current->next[s];
        }
        if (current->index >= 0){
            string s = *r.rbegin();
            r.clear();
            r.push_back(s);
            return r;
        }
        r.clear();
        for (auto it = current->next.begin(); it != current->next.end(); ++it)
            r.push_back(it->first);
        sort(r.begin(),r.end());
        return r;

    }

    void mkdir(string path) {
        tree* current = root;
        int pos = 1,next;
        int l = path.size();
        vector<string> r;
        while (pos < l){
            next = path.find('/',pos);
            if (next != string::npos) {
                r.push_back(path.substr(pos, next - pos));
                pos = next + 1;
            }
            else {
                r.push_back(path.substr(pos));
                break;
            }
        }
        for (string s: r){
            if (current->next.count(s))
                current = current->next[s];
            else{
                current->next[s] = new  tree;
                current = current->next[s];
            }
        }
    }

    void addContentToFile(string filePath, string content) {
        tree* current = root;
        int pos = 1,next;
        int l = filePath.size();
        vector<string> r;
        while (pos < l){
            next = filePath.find('/',pos);
            if (next != string::npos) {
                r.push_back(filePath.substr(pos, next - pos));
                pos = next + 1;
            }
            else {
                r.push_back(filePath.substr(pos));
                break;
            }
        }
        string t = *r.rbegin();
        r.erase(r.end()-1);
        for (string s: r){
            current = current->next[s];
        }
        if (current->next.count(t)){
            current = current->next[t];
            m[current->index] += content;
        }
        else {
            current->next[t] = new tree;
            current = current->next[t];
            current->index = num++;
            m[current->index] = content;
        }
    }

    string readContentFromFile(string filePath) {
        tree* current = root;
        int pos = 1,next;
        int l = filePath.size();
        vector<string> r;
        while (pos < l){
            next = filePath.find('/',pos);
            if (next != string::npos) {
                r.push_back(filePath.substr(pos, next - pos));
                pos = next + 1;
            }
            else {
                r.push_back(filePath.substr(pos));
                break;
            }
        }
        for (string s: r){
            current = current->next[s];
        }
        return m[current->index];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */

int main(){
    FileSystem f;
    f.ls("/a/b/c/d/e");
}