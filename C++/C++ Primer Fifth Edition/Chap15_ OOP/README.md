# 15.1 OOP: An Overview
- OOP 的核心思想是數據抽象 (chap7 接口和實現分開)，繼承和動態綁定
- 通過繼承聯繫的類會形成一種層次關係，根部稱為基類，而繼承基類的稱為派生類，基類有所有類共同傭有的成員，派生則有各自特有成員
- 假設基類除了想要派聲類直接繼承的函數以外，還有想要派生類自定義以符合各自本版的函數，此時就會使用 virtual 聲明成虛函數
- 在 block 1 裡，Bulk_quote 派生類必須重新定義基類裡的虛函數，派生類可以在該函數面前也加上 virtual，但非必要
- C++11 允許派生類顯式地標住哪個成員函數式改寫自基類的虛函數，具體方法就是在該函數後面加上 override 關鍵字
```
block 1

class Quote {
    public:
        std::string isbn() const;
        virtual double net_price(std::size_t n) const;
};

class Bulk_quote : public Quote {
    public:
        double net_price(std::size_t) const override;
}
```
- 動態綁定 (dynamic binding)，讓我們能使用同一段代碼分別處理 Quote 以及其派生類 Bulk_quote 的物件
```
// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os,
                        const Quote &item, size_t n) {
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
```
- 關於上面的函數有兩個重點
1. 函數 print_total 的 item 參數是 Quote 的一個引用 (15.2.3)，所以我們能用基類也能使用派生類的物件調用
2. 又因為 net_price 是引用的物件調用，所以會自動調用各自的版本，因為是在運行時選擇版本，所以稱為動態綁定

# 15.2 Defining Base and Derived Classes








