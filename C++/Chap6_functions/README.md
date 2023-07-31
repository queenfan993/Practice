# 6.2 Arugument Passing
- & 符號除了用來指示地址，C++ 給予 & 符號另一個意涵，用來聲明引用
- 例如要將 rodents 作為 rats 引用
```
int rats = 101;
int rodents = rats;
rodnets++;
```
- 其最後結果如下
```
rats = 102, rodents = 102,
rats address = rodents address
```
- 引用看起來很像指針，但是差別之一是，要引用前必須先給原始變數賦值
```
int rat;
int & rodents;
rodent = rat; // cant!!!
```
- 另外引用並不能，透過轉換改變地址，永遠都是指向第一次引用的對象，
```
int rats = 100;
int & rodents = rats;
int bunnies = 50;
rodents = bunnies;
```
- 在意義上，引用其實等於 int * const pr = &rats; 會始終效忠於原始的引用
- 所以結果最後會如以下，可以更改數值內容，但是地址卻不能更改
```
rats = 50, rodents = 50, bunnies = 50
rats address = rodents address != bunnies address
```
- 另外之前常看見的傳參呼叫，其實就是函數參數使用引用
- 和傳指標呼叫差別有以下兩點
```
1. 聲明參數的方式不同
2. 傳指標在函數內需要用 *
```
如果一個函數聲明如下
```
double refcub(double &a);
以下呼叫會錯
double x = 5.0;
recub(x + 2.0);
```

# 6.4 Overloaded 
- 重點就是函數名稱相同，但是輸入不同參數型別，可以有不同行為
```
void dribble (char* bits);
void dribble (const char* bits);
void B (char* bits);
void C (const char* bits);
使用以下呼叫
const char p1[20] = "aaa";
char p2 = "aaa";
dribble(p1); // dribble (const char* bits)
dribble(p2); // dribble (char* bits)
// 可以把 char* 丟進函數 const 參數，但不能反過來
B(p1); // no match
B(p2); // char*
C(p1); // const char*
C(p2); // char*
```
- 另外!!! 多載函數可以回傳不同型別，此時吃的參數要不同才可以
```
//ok 
long test(int n);
double test(int n);

//not ok 
long test(int n);
double test(int n);
```

# 6.5 Features for Specialized Uses
- 可以為函數設定參數初始值
```
typedef string::size_type sz;
string  screen(sz ht = 24, sz wid = 80, cahr backgrnd = '');

如果使用以下呼叫
string window;
window = screen(); // screen(24, 80, '');
window = screen(66); //screen(66, 80, '');
window = screen(, , '?') // error: 要空一定要從最右邊的參數開始空，向上面都是從右開始空
```

- 對於某些函數，只是要替換參數型態，可以使用模板代替，
```
聲明的時候寫一次
template <class T>
void swap(T &a, T &b);

定義的時候再寫一次
template <class T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
```
另外也可以抽換 class 為 typename
```
template <typename T>
```
- 如果要重載函數時，template 要再重寫一遍!
- 因為模板也可以用在 structure, 如果直接調用 swap(T a, T b) 的話，會把所有 sturcture 裡的物件都交換，那如果我只想要 swap 其中一個呢?
- 那顯然就不能使用 template 的 swap，在編譯器選擇調用哪個 swap 的時候，非模板版本會優先於顯示具體化和模板版本，而顯示優先於模板
```
struct job {
    char name[40];
    double salary;
    int floor;
}

//non-template
void swap(job &, job &);

//explicit specialization
template <> void swap <job>(job &, job &);
//template <> void swap(job &, job &); //simple form

//template
tempelate <typename T>
void swap(T &, T &);
```

- 簡單來講，具體化是指，把原本的模板指定一個特定的型別，然後有特別的定義和函數運行方式，在定義和宣告的時候做具體化
- 而實例化，指的是對於函數模板，把參數型別寫清楚，在呼叫函數的時候做實例化
```
template <typename T>
void swap(T &a, T &b);

template <> void swap <job> (job &, job &); //specialization

int main (void) {
    template void swap <char> (char&, char&); //explicit instantiation
    job n, m;
    swap(n, m); //call the specialization one

    char a, b;
    swap(a, b); // call the explicit instantiation

    int x, y;
    swap(x, y); // call the implicit template
}

```

# 6.7 function pointer
- 基本的函數指標如下
```
bool lengthCompare(const string &, const string &);
可以宣告一個 pf 指向回傳值是 bool 並且參數是兩個 const string 引用
bool (*pt) (const string &, const string &);
```
- 函數名稱等於函數地址，所以以下兩者等價
```
pt = lengthCompare;
pt = &lengthCompare; 
```
- 另外使用 pt 可以調用函數，以下三者等價
```
bool a1 = pt("a", "b");
bool a2 = (*pt)("a", "b");
bool a3 = lengthCompare("a", "b");
```
- 並不能返回一個函數，但是可以返回指向函數的指標
```
using F = int(int*, int); 這是一個 function 的型別
using PF = int(*)(int*, int); 這是一個 function pointer 型別，指向的函數要是回傳 int 並且有兩個參數
```
上面就是定義兩種類型，可以用來減化聲明
```
PF fi(int); // 合法，f1 可以返回一個函數指標 
F f1(int); // 非法，f1 不能返回函數
F* f1(int); // 合法，返回一個函數指標
```
如果不使用 using 簡化，也可以寫成以下
```
int (*f1(int))(int*, int);
```
- 由內向外順序，f1 有參數列表示一個函數，前面 * 表示回的一是一個指標，
- 是什麼的指標，是一個回傳 int，並接受 int* 和 int 兩參數的函數的指標






 


