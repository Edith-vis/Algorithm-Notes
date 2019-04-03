# 【算法笔记】第6章 C++标准模板库(STL)介绍
## 6.1 vector
### 1. 定义
```c
vector<int> name;
vector<vector<int> > array;
vector<int> array[size];
```
### 2. 容器内元素的访问 
1) `v[index]`
2) ```c
    vector<int>::iterator it;
    *it
    *(it+i)
    *(it++)
3) begin()指向数组第一个元素，而end()指向数组最后一个元素的后一个元素。(美国习惯左闭右开)
### 3. 常用函数  
1) `push_back()`
2) `pop_back()`
3) `size()`
4) `clear()`
5) `insert(it, x)`向`vector`的任意迭代器it处插入一个元素x
6) `erase()`
    1) 删除单个元素:  
    `erase(it)`删除迭代器为it处的元素
    2) 删除一个区间内的所有元素:  
    `erase(first, last)`删除`[first, last)`内的所有元素
### 4. 用途
- 存储数据
- 用邻接表存储图

## 6.2 set
### 1. 定义
* **内部自动有序** (通过红黑树实现)
* **不含重复元素**
* **只能通过迭代器访问**

```c
set<int> name;
set<int> array[size];
```
### 2. 容器内元素的访问 
1) **只能通过迭代器访问  
除vector和string之外的STL容器都不支持`*(it+i)`的访问方式**
2) ```c
    set<int>::iterator it;
    *it
    it++
3) begin()指向数组第一个元素，而end()指向数组最后一个元素的后一个元素。(美国习惯左闭右开)
### 3. 常用函数  
1) `insert(x)`自动排序和去重，时间复杂度`O(logN)`
2) `find(value)`返回set中对应值为value的*迭代器*，时间复杂度`O(logN)`
3) `size()`
4) `clear()`
5) `insert(it, x)`向`vector`的任意迭代器it处插入一个元素x
6) `erase()`
    1) 删除单个元素:  
    `erase(it)`删除迭代器为it处的元素  
    `st.erase(st.find(x))`  
    *`st.erase(value)`* 因为set有find所以可以直接找到该值进行删除
    2) 删除一个区间内的所有元素:  
    `erase(first, last)`删除`[first, last)`内的所有元素
### 4.其他
- 不去重但排序用`multiset`
- 去重但不排序用`unordered_set`(以散列代替红黑树)
### 5. 用途
- 需要去重
- 自动去重并按升序排序

## 6.3 string
*`string.h` 和 `string` 是不一样的头文件*  
使用`string`前需添加
```c++
#include <string>
using namespace std;
```
### 1. 定义
```c++
string str;
string str = "abcd";
```
### 2. 容器内元素的访问 
1) `str[i]`  
   输入字符串只能用`cin`：`cin >> str;`  
   输出字符串   
   1) `cout << str;`  
   2) `printf("%s\n", str.c_str())`  
    将`string`型`str`使用`c_str()`变为字符数组

2) ```c
    string::iterator it;
    *it
    *(it+i)
    *(it++)
   ```
    `string`和`vector`一样，支持直接对`vector`进行加减某个数字
### 3. 常用函数  
1) `operator+=`
   ```c++
   str3 = str1 + str2;
   str1 += str2;
   ```
2) `compare operator`  
   两个`string`类型可以直接使用==、!=、<、<=、=>、>比较大小，比较规则是*字典序*
3) `length() / size()`
4) `clear()`
5) `insert()`  
        1) `insert(pos, string)`  
            在`pos`号位置插入字符串`string`  
        2) `insert(it, it2, it3)`  
            `it`为原字符串的欲插位置，`it2`和`it3`为待插字符串的首位迭代器，用来表示`[it2, it3)`将被插在it位置上
   
6) `erase()`
    1) 删除单个元素:  
    `erase(it)`删除迭代器为it处的元素
    2) 删除一个区间内的所有元素:  
       1) `str.erase(first, last)`  
            删除`[first, last)`内的所有元素
       1) `str.erase(pos, length)`  
            其中`pos`为需要开始删除的起始位置，`length`为删除的字符个数
7) `substr()`  
   `substr(pos, len)`返回从pos号位开始、长度为len的子串
8) `string::npos`是值为-1的常数，`find()`函数找不到时的返回值
9) `find()`  
    1) `str.find(str2)` 当str2是str的子串时，返回其在str中第一次出现的位置；如果不是返回`string::npos`
    2) `str.find(str2, pos)`从str的pos号位开始匹配str2
10) `replace()`  
    1) `str.replace(pos, len, str2)`把str从pos号位开始、长度为len的子串替换为str2
    2) `str.replace(it1, it2, str2)`把str的迭代器[it1, it2)范围的子串替换为str2

## 6.4 map
### 1. 定义
- map可以将任何基本类型映射到任何基本类型 `map<typename1, typename2> mp;` 第一个是键的类型，第二个是值的类型
- **如果是字符串到整型的映射，必须使用string而不能用char数组** `map<string, int> mp;`，因为char数组作为数组，是不能被作为键值的。
- **map会以键从小到大的顺序自动排列(通过红黑树实现)**

### 2. 容器内元素的访问 
1) 通过下标访问，*map中的键是唯一的*
   ```c++
   map<char, int> mp;
   mp['c']
   ```
2) `map<ty1, ty2>::iterator it;`使用`it->first`来访问键；`it->second`来访问值
    
### 3. 常用函数  
1) `size()`
2) `clear()`
3) `find(key)` *返回键为key的映射的迭代器*
4) `erase()`
    1) 删除单个元素:  
    `mp.erase(it)`删除迭代器为it处的映射  
    `mp.erase(key)`删除键为key的映射
    2) 删除一个区间内的所有元素:  
    `erase(first, last)`删除`[first, last)`内的所有映射
### 4. 其他
- 不去重但排序用`multimap`
- 去重但不排序用`unordered_map`(以散列代替红黑树)
### 5. 用途
- 字符或字符串与整数之间的映射
- 判断大整数或者其他类型是否存在

## 6.5 queue
### 1. 定义  `queue<typename> q;`
### 2. 元素访问
- 队列是先进先出的限制性数据结构
- 只能通过`front()`来访问队首元素，或者通过`back()`来访问队尾元素
### 3. 常用函数
1) `push()`从队尾进队
2) `front()`, `back()`
3) `pop()`令队首元素出队
4) `empty()`
5) `size()`
### 4. 其他
- 双端队列(deque):首尾皆可插入删除
- 优先队列(priority_queue):使用堆实现的默认将当前最大元素置于队首的容器
  
## 6.6 priority_queue
### 1. 定义  `priority_queue<typename> pq;`
- 底层用堆来实现
- 队首元素一定是当前队列中优先级最高的那一个
### 2. 元素访问
- 没有`front()`和`back()`函数
- 只能通过`top()`来访问队首元素(堆顶元素)，即优先级最高的元素
### 3. 常用函数
1) `push()`
2) `top()`访问队首元素(堆顶元素)，使用前需先判断队列是否为空
3) `pop()`令队首元素(堆顶元素)出队，使用前需先判断队列是否为空
4) `empty()`
5) `size()`
### 4. priority_queue内元素的优先级的设置
- 基本数据类型(e.g int)
  ```c++
  priority_queue<int, vector<int>, less<int> > q;//大顶堆:优先级高的在队首，less<int>表示数字大的优先级越大
  priority_queue<int, vector<int>, greater<int> > q;//小顶堆
- 结构体
    ```c++
    //法一
    struct fruit{
        string name;
        int price;
        //重载(overload:对已有的运算符进行重新定义)小于号
        friend bool operator < (const fruit &f1, const fruit &f2) {
            return f1.price < f2.price;
        }
    };
    priority_queue<fruit> q;
    //法二
    struct fruit{
        string name;
        int price;
            //使用const和引用是为了提高效率
        bool operator < (const fruit & f2) const {
            return price < f2.price;
        }
    };
    priority_queue<fruit> q;
    //法三:优先队列中的cmp函数与sort中的cmp函数的效果是相反的
    struct fruit{
        string name;
        int price;
    };
    //只需要把friend去掉，把小于号改成一对小括号，然后把重载的函数写在结构体外面，同时将其用struct包装起来
    struct cmp{
        bool operator () (const fruit &f1, const fruit &f2) {
            return f1.price > f2.price;
        }
    }
    priority_queue<fruit, vector<fruit>, cmp> q;
    ```
### 5 用途
- 解决贪心问题
- 对Dijkstra算法进行优化
## 6.7 stack
### 1. 定义  `stack<typename> s;`
### 2. 元素访问
- 栈是后进先出的限制性数据结构
- 只能通过`top()`来访问栈顶元素
### 3. 常用函数
1) `push()`
2) `top()`获得栈顶元素
3) `pop()`弹出栈顶元素
4) `empty()`检测stack是否为空
5) `size()`
### 4. 用途
- 代替程序栈来模拟递归

## 6.7 pair
### 1. 定义  
一个内部有两个元素的结构体
```c++
#include <utility>
#include <map>
using namespace std;

pair<string, int> p;
pair<string, int> p("haha", 5);
//临时创建
pair<string, int>("haha", 5);
make_pair("haha", 5);
```
### 2. 元素访问
```c++
pair<string, int> p;
p.first = "haha";
p.second = 5;
cout << p.first << " " << p.second;
p = make_pair("xixi", 55);
p = pair<string, int>("heihei", 555);
```
### 3. 常用函数
比较操作数:先以first的大小作为标准，只有当first相等时才去判别second的大小
### 4. 用途
- 代替二元结构体及其构造函数
- 作为map的键值对进行插入
```c++
map<string, int> mp;
mp.insert(make_pair("heihei", 5));
mp.insert(pair<string, int>("haha", 55));
for (map<string, int>::iterator it = map.begin(); it != map.end(); it++) {
    cout << it->first << " " << it->second << endl;
}
```
## 6.9 algorithm
```c++
#include <algorithm>
using namespace std;
```
### 1. max()、min()、abs()
- max()和min()的参数可以是浮点数
- 返回三个数的最大值`max(x, max(y, z))`
- abs(x)的参数必须为整数，浮点型的绝对值用math头文件下的fabs
### 2. swap()
### 3. reverse()
`reverse(it, it2)`可以将数组指针在`[it, it2)`之间的元素或容器迭代器在`[it, it2)`范围内的元素进行反转
### 4. next_permutation()
- 给出一个序列在全排列时的下一个序列
- 在已经到达全排列的最后一个时会返回false
- 用do...while语句防止结果中少了第一个排列
```c++
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[10] = {1, 2, 3};
    do{
        printf("%d%d%d\n", a[0], a[1], a[2]);
    } while (next_permutation(a, a+3));
    return 0;
}
```
### 5. fill()
把数组或容器中的某一区段赋为某个相同的值  
`fill(a, a+5, 233);`
### 6. sort()
- `sort(首元素地址(必填), 尾元素地址的下一个地址(必填), 比较函数(非必填))`
- 在STL标准容器中，只有vector、string和deque是可以使用sort的，因为set和map是用红黑树实现的本身有序。
### 7. lower_bound()和upper_bound()
- 需要用在一个有序数组中
- `lower_bound(first, last, val)`用来寻找在数组或容器的`[first, last)`范围内**第一个值大于等于**val的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。如果数组或容器中没有需要寻找的元素，则返回可以插入该元素的位置的指针或迭代器(即假设存在该元素时，该元素应当在的位置)。
- `upper_bound(first, last, val)`用来寻找在数组或容器的`[first, last)`范围内**第一个值大于**val的元素的位置，如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器。如果数组或容器中没有需要寻找的元素，则返回可以插入该元素的位置的指针或迭代器(即假设存在该元素时，该元素应当在的位置)。
