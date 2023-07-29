#ref: https://www.youtube.com/watch?v=JuDAqNyTG4g&ab_channel=%E4%BA%94%E7%82%B9%E4%B8%83%E8%BE%B9

# 假設有一數組長度 N，整個數組是紅藍排序好的，藍色在前紅色在後，找出共有多少藍色，其實也就是在找藍紅邊界，第一個紅色的 index

# 重點 1 (初始值)
- left 初始化為 -1，right 初始化為 N, 目的是邊界條件，要是全藍，可以避免 left 指向藍色，反之亦然，
- 所以才從 index 的下界 -1 和上界 +1 作為 left 和 right 的初始值

# 重點 2 (mid 是否始終處於左閉右開區間以內 [0, N) 的範圍)
- 為什麼需要探討 mid 的區間，因為只有當 mid 在左閉右開區間，才是有意義的 index
- 討論，當 left min = -1 和 right min = 1 會進入循環，mid = 0
- 當 left max = N - 2 和 right max = N 會進入循環, mid = N-1
- 所以 0 <= mid < N

# 重點 3 (能不能把 left = mid + 1 或者 right = m - 1) 
- 如果當某次 mid 剛好是藍色或者紅色邊界，那 left 就可能會指向紅色，right 會指向藍色
- 當然有可能設計成 mid + 1 等等的情況，但這裡提供就是一種 general 寫法，提供一種思考方式


# 重點 4 (會不會變成無窮迴圈)
- 其實可以變成檢查以下情況，很顯然都會中止迴圈
- left + 1 = right
- left + 2 = right
- left + 3 = right........





    


 


