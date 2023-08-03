# Defining Abstract Data Type
＃ 類的基本思想是數據抽象和封裝
- 數據抽象 : 依賴接口和實現分離的編程技術，接口有能執行的操作，實現則包括數據成員和函數
- 封裝: 實現了接口和實現的分離，封裝後的類隱藏了它的實現細節，也就是說用戶只能使用接口，而無法訪問實現部分
- 成員函式聲明必須在類的內部，定義則可以在內或在外
- 而成員函式可能用到的非成員函式，聲明和定義都在類的外部
- 如果非成員函數是類的接口組成部分，那這些函數的聲明，應該要在同一個 header 裡面
- this 的引用，就是一個只像當前物件的指標，用於成員函數中引用當前物件

＃ 類的建構子
- constructor 用來初始化數據成員，建構子名稱和類的名稱相同，不可以是 const，另外建構子是沒有返回型的
- 如果沒有特別定義建構子，編譯器會合成一個默認建構子
``` 
block 1:
struct Sales_data {
    Sales_data() =  default; // 編譯器合成的建構子
    Sales_data(const std::string &s) : bookNo(s) {} // 多型的建構子，也可以用它來初始化
    Sales_data(std::istream &); //這是一個聲明，因為會用到外部函數 read，所以該建構子定義要在外部
    ...
}

注意某些類是不能使用編譯器合成的: 
1. 使用到一些數組和指標的類，如果使用編譯器的建構子，可能會得到未定義的值
2. 如果類中包含其他類的成員，且這個成員的類型沒有默認的建構子，都可能導致編譯器沒辦法生成默認建構子
```
- 在 block1 中, 可以看見以 istream 為參數的建構子，在函數體內需要調用 read 函數給數據成員賦以初始值
- 定義在外部時，必須指明該建構子是哪個類的成員，沒有回傳值，但要標明 Sales_data::Sales_data
```
block2:
在類的外部應該要有以下定義
Sales_data::Sales_data(::istream & is) {
    read(is, *this); // 從 is 讀取然後存數 this 對象裡
}
```
＃ 類的拷貝賦值和解構子
- 對於類的賦值可以直接用以下
```
block3:
total = trans;  
//默認賦值操作等價於下面這些操作
total.bookNo = trans.bookNo;
total.revenue = trans.revenue;
其他成員變數....  =  ....

```
- 而解構子，一樣可以依賴編譯器默認的，但管理動態內存的通常不行

# 7.2 Access Control and Encapsulation
- 定義在 public 說明符後面的成員在整個程序內都可被訪問，相當於 "接口"
- 定義在 private 說明符後的成員可以被類的成員訪問，但是不能被使用該類的代碼訪問，相當於 "封裝" 了實現細節
- 類可以都沒有訪問說明符，也可以一個重複出現多次，都沒有限制，直到類的結尾
- struct 和 class 的默認訪問權限不一樣，在兩者的第一個訪問符之前，struct 是 public, 而 class 是 private
＃ friend
- 友元表示允許其他類或者函數訪問他的非公有成員，可以用下面的例子說明
```
block4:

class Sales_data {
    //非成員函數的友元聲明
    friend Salse_data add(const Sales_data &, const Sales_data &);
    //其他成員函數
    public:
        Sales_data() = default;
        ...
    private:
        std::string bookNo;
        ...
};

```
- 友元的聲明只能出現在類的內部，在類內的位置不限，因為不是成員函數，所以不受訪問說明符控制
- 因為友元在類內的聲明只表示，他是類的友元，如果希望類的用戶可以調用某個友元，那應該要在類的外部再聲明一次
- 以 block 4 為例，Sales_data 的頭文件，應該為 read、 print、 add 提供獨立的聲明 (類的外部)，這樣類的用戶才可以使用

# 7.3 Additional Class Features
- 以 Screen 為例，實作 inline 可在聲明，也可在外部使用 inline 關鍵詞，並觀察 this 指標
```
block5:

class Screen {
    public:
        typedef std::string::size_type pos;
        Screen() = default;                     // needed because Screen has another constructor

        Screen(pos ht, pos wd, char c): height(ht), width(wd),
                                                contents(ht * wd, c) { }
        char get() const                        // get the character at the cursor
                { return contents[cursor]; }    // implicitly inline
        inline char get(pos ht, pos wd) const;  // explicitly inline
        Screen &move(pos r, pos c);             // can be made inline later
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};
```
- 函數聲明在類的內部或者說在標頭檔，實作則在對應的 cpp 當中
```
block6:

inline // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c; // move cursor to the column within that row
    return *this; // return this object as an lvalue
}
char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width; // compute row location
    return contents[row + c]; // return character at the given column
}
```
- 另外其實比較推薦 inline 在函數定義時寫就好，聲明可以忽略，但兩個地方都寫上也是合法的
- 實作時函數名稱前面都需要標明來自哪個類 (Screen::)，this 指標代表在物件內修改 cursor
- 另外補充以下兩點，
```
block7:

1. 使用 Screen & 作為返回，可以讓物件調用函數之後，直接當成左值，並且支援鍊式調用
Screen myScreen(5, 10, '#');
myScreen.move(2, 3).move(1, 8).move(3, 5);
以上如果想要鍊式調用一個有定義 const 成員函數返回 *this 的話會失敗，例如建立一個 display 秀出 Screen 內容
Screen myScreen;
myScreen.display(cout).move(2, 3);
這樣是會錯的

2. get 的 const 表示不修改類裡面的參數
但其實可以設定參數為 mutable 關鍵詞，表示永遠不能是 const
就算成員函數後面有 const 詞，還是可以修改該參數
```
# 7.3.4 友元再探
- 除了上述提到的可以定義非成員函數之外，其實其他類也可以被定義為 friend
- 如果今天有一個 Window_mgr 類，裡面有一個需要清除 Screen 的內容的函數 clear，表示 clear 需要訪問 Screen 的私有成員
```
block8:

// for the whole class Window_mgr
class Screen {
    // Window_mgr members can access the private parts of class Screen
    friend class Window_mgr;
    // . . . rest of the Screen class
};

class Window_mgr {
    public:
        // location ID for each screen on the window
        using ScreenIndex = std::vector<Screen>::size_type;
        // reset the Screen at the given position to all blanks
        void clear(ScreenIndex);
    private:
        std::vector<Screen> screens{Screen(24, 80, ’ ’)};
        };
        void Window_mgr::clear(ScreenIndex i)
        {
        // s is a reference to the Screen we want to clear
        Screen &s = screens[i];
        // reset the contents of that Screen to all blanks
        s.contents = string(s.height * s.width, ’ ’);
}
```
- 如果只讓 clean funtion成為友元，那 Window_mgr 必須事先聲明
- 順序要是，先在 Window_mgr 裡面聲明 clear 但不能定義，之後 Screen 聲明 clear 為其友元，最後定義 clear
```
block9:

class Screen {
    // Window_mgr::clear must have been declared before class Screen
    friend void Window_mgr::clear(ScreenIndex);
    // . . . rest of the Screen class
};
```
- 另外如果函數名稱有不同重載版本，友元的聲明要寫清楚是哪一個重載的函數是友元
- 上面有提到類的函數是另一個類的友元，那如果是非類的外部函數要聲明為友元呢，順序應該如下，其實是可以先 friend 聲明的
```
block10:

struct X {
    friend void f() { /* friend function can be defined in the class body */ }
    X() { f(); } // error: no declaration for f
    void g();
    void h();
};
void X::g() { return f(); } // error: f hasn’t been declared
void f(); // declares the function defined inside X
void X::h() { return f(); } // ok: declaration for f is now in scope
```

# 7.5 Constructors Revisited
- 如果成員函數是 const 或者引用的話則必須給定初始值
```
block11:

class ConstRef {
    public:
        ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }
    private:
        int i;
        const int ci;
        int &ri;
};
```
- 委託構造函數 (delegating constructor)
- 某個類的構造函數，使用該類中其他的構造函數幫忙初始化
```
class Sales_data {
    public:
        // nondelegating constructor initializes members from corresponding arguments
        Sales_data(std::string s, unsigned cnt, double price):
        bookNo(s), units_sold(cnt), revenue(cnt*price) { }
        // remaining constructors all delegate to another constructor
        Sales_data(): Sales_data("", 0, 0) {}
        Sales_data(std::string s): Sales_data(s, 0,0) {}
        Sales_data(std::istream &is): Sales_data()
        { read(is, *this); }
        // other members as before
};
```

# 7.6 static Class Members





