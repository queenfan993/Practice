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











