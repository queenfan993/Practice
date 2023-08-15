linux-5.19.0

[bt architecture][./img/arch]

# hci_core.h
- 位置 include/net/bluetooth/hci_core.h

## 實作 
1. net/bluetoot/hci_core.c
2. net/bluetoot/hci_conn.c
3. net/bluetoot/sco.c
4. net/bluetoot/l2cap.c

## 內容˙
1. HCI interface to upper protocols     807
- l2cap
- sco
2. Inquiry cache                        827
3. HCI Connections                      886
4. HCI Devices                          1236
5. LMP capabilities                     1428
6. Extended LMP capabilities            1454
7. Host capabilities                    1462
8. HCI protocols                        1519
9. HCI callbacks                        1547
10. HCI Sockets                         1745


# hci_core.c
ref: https://blog.51cto.com/u_15314083/3190495

## hci_cmd_work
```
1. 使用 skb_dequeue 函數 hdev cmd_q 中取出一個數據包，並將其賦值給變數 skb
2. res = hci_send_frame(hdev, skb); 將數據包 skb 透過 hdev 發送，並將結果存儲在變數 res 中判斷錯誤，做例外處理
```
- hci_rx_work
```
1. 從 hdev->rx_q 取數據
2. switch (hci_skb_pkt_type(skb)) {
        case HCI_EVENT_PKT: // 
        case HCI_ACLDATA_PKT: //
        case HCI_SCODATA_PKT: //
```
# hci_tx_work
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


# Reference

LE data packet
- https://novelbits.io/bluetooth-5-speed-maximum-throughput/ 

protocol
- https://blog.csdn.net/feiwatson/article/details/81712933
- https://blog.csdn.net/feiwatson/article/details/81705823?spm=1001.2014.3001.5502
- https://blog.csdn.net/feiwatson/article/details/121732415
- https://xroundaudio.com/blog/blog_detail.php?id=38 : 藍牙耳機部份，編碼 codec
- https://www.techbang.com/posts/103938-the-indispensable-le-audio-next-generation-bluetooth : 耳機相關，有一些壓縮數據

HCI uart
- https://blog.csdn.net/walkingman321/article/details/7375708


overview
- https://medium.com/@yuchunlin/003-%E8%97%8D%E8%8A%BD%E7%AD%86%E8%A8%98-975b4f44ccc8
- https://ithelp.ithome.com.tw/articles/10252873
- http://www.baluntek.com/news/news.asp?pk=135

study
- https://wlink.blog.csdn.net/article/details/107727900?spm=1001.2014.3001.5502




