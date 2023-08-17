# hci_core.h
- 位置 ./include/net/bluetooth/hci_core.h
- 定義在 host 上面的 hci 界面

## 函數類型
### 1. HCI interface to upper protocols     (807)
1. l2cap 的連線建立和中止，定義收到 acl 訊號時應該怎處裡
- 函數實作 ./net/bluetoot/l2cap_core.c

2. 相對於 acl，如果有傳統藍牙存在，定義連線和處理 sco 資料
- 函數實作 ./net/bluetoot/sco.c

### 2. Inquiry cache                        (827)
1. 設定 hci 設備的 inquiry state，可以是開始 discover，正在尋找，結束等等
2. 將掃到的結果可以存在快取裡，查詢周圍設備存在快取時間，操作 clean 或 update 等等
- 函數實作 ./net/bluetoot/hci_core.c

### 3. HCI Connections                      (886)
1. 對於邏輯鏈路 conn 的管理(ACL, AMP, LE, SCO)，針對 hash 進行新增刪除和查詢各種類連線數量
2. 建立或刪除藍牙通道 chan 數據類型，其中包括 chan list 和 queue 等資料
- 一個 conn 可以有多個 chan，可以理解為一個邏輯 link 上，有不同資料類型的傳輸，可能有控制訊號，音訊等
- 所以 chan list 就好像是某種目的的 list，例如有兩個音訊資料 chan 都在同一個 conn 上面
- 用到的 struct 部份就在 hci_core.h 裡
- 其他函數實作 ./net/bluetoot/hci_conn.c

### 4. HCI Devices                          (1236)
1. 向下提供 driver 註冊和 release hci dev
2. 向上給 socket 提供對 hci_dev 進行 open 或 close 等操作，進行檢查看可否開啟，以便後續藍牙通信
3. 提供根據地址查詢藍牙設備訊息，with irk or with flag，connection 的狀態
ref: [address with irk](http://www.wowotech.net/bluetooth/ble_address_type.html)
4. 對於 irk 和 ltk(long-term-key) 的加入和查找 
- 函數實作 ./net/bluetoot/hci_core.c 

### 5. LMP capabilities                     1428
1. 


### 6. Extended LMP capabilities            1454
### 7. Host capabilities                    1462
### 8. HCI protocols                        1519
### 9. HCI callbacks                        1547
### 10. HCI Sockets                         1745


# hci_core.c
ref: https://blog.51cto.com/u_15314083/3190495

## hci_cmd_work
```
1. 使用 skb_dequeue 函數 hdev cmd_q 中取出一個數據包，並將其賦值給變數 skb
2. res = hci_send_frame(hdev, skb); 將數據包 skb 透過 hdev 發送，並將結果存儲在變數 res 中判斷錯誤，做例外處理
```
## hci_rx_work
```
1. 從 hdev->rx_q 取數據
2. switch (hci_skb_pkt_type(skb)) {
        case HCI_EVENT_PKT: // 
        case HCI_ACLDATA_PKT: //
        case HCI_SCODATA_PKT: //
```
## hci_tx_work
ref: https://blog.csdn.net/android_lover2014/article/details/88421594  
ref: https://ithelp.ithome.com.tw/articles/10252873
```
1. 
2. if (!hci_dev_test_flag(hdev, HCI_USER_CHANNEL)) {
        /* Schedule queues and send stuff to HCI driver */
        hci_sched_sco(hdev); //
        hci_sched_esco(hdev); //
        hci_sched_acl(hdev); //
        hci_sched_le(hdev); // 
    }
```
- SCO 同步鏈路，對稱連接，主從可以同時發送數據，主要用來傳輸對時間要求較高的數據，透過鏈接管理（LM）協議來確立鏈接，並且分配 time slot 等
- ACL 異步，支援一對多，主設備決定代寬，從設備被選才能送，用未被分配的 slot 傳送，A2DP (Advanced Audio Distribution Profile) 跑在這上面
- ESCO，動態調整 slot 大小，支援更多編碼，ㄋ支援資料的重傳
