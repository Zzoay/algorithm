
# 不考虑顺序的最小匹配子串

## 题目

```markdown
Input: S = "ADXBECYDEBAXCAXY", T = "ABC"

Output: "BAXC"

包含T里所有字母的S最小子串
假设T没有重复字母
不考虑顺序
```

## 题解

这是一道字符串的匹配问题，题目中的关键信息：

- 不考虑顺序
- 模式串T中没有重复字母
  
由此，我们可以维护一个数据结构positions，记录T中字符在S中的出现位置，只要所有字符都出现过一次，那么对应位置的大区间即是匹配的字串区间。以题目为例，最早出现的A,B,C的位置分别是0,3,5，那么匹配的子串就是s[0-5]即"ADXBEC"。

当同一字符c重复出现，则需把原来的positions[c]以及前面位置的字符位置信息清除（可置为-1），同时更新相应位置positions[c]。比如第二次出现B时，原来B的位置是5，现如今更新为9，原来比5靠前的位置信息都失效了，比如最开始在0号位置的A。

每次检查positions，如果其中所有元素的位置信息都有效，则认为可构成一个匹配子串，再生成的子串与前面生成的子串对比长度，取较短的一个。遍历字符串S后即可求得所求。

## 代码

```c++
string check(map<char, int> mp, string s, string preRes){
    int mi = 1000, ma = 0;
    string res;
    
    map<char, int>::iterator iter;
    for(iter=mp.begin(); iter!=mp.end(); iter++){
        char key = iter -> first;
        int value = iter -> second;
        
        cout << key << ": "<< value << endl;
        
        if (value == -1) return preRes;
        if (mi > value) mi = value;
        if (ma < value) ma = value;
    }
    
    res = s.substr(mi, ma-mi+1);
    
    if (res.size() > preRes.size())
        res = preRes;
    return res;
}

void replacePre(map<char, int> mp, int pos){
    map<char, int>::iterator iter;
    for(iter=mp.begin(); iter!=mp.end(); iter++){
        if (iter -> second < pos)
            iter -> second = -1;   // replace the previous position
    }
}

string func(string s, string t){
    map<char, int> mp;
    string res=s;   // initialize as a longest string
    int maxLen = 0;
    for(auto& c:t) 
        mp[c] = -1;
    for(int i=0; i<s.size(); i++){
        char s_c = s[i];
        auto fd_sc = mp.find(s_c);
        if(fd_sc != mp.end()){   // found
            int value = fd_sc -> second;
            if(value != -1)  replacePre(mp, value);   // had appeared
            mp[s_c] = i;
            res = check(mp, s, res);
            cout << "res: " << res << endl;
            cout << "-+-+-+-+" << endl;
        }
    }
    return res;
}



int main() {
    string s = "ADXBECYDEBAXCAXY";
    string t = "ABC";
    auto res = func(s, t);
    std::cout << "Finished. \n";
}
```
