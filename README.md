# Báo cáo Bài tập lớn - Nhóm 5

## 1. Thông tin nhóm
| STT |       Thành viên     | MSV        | Vai trò                     |
|-----|----------------------|------------|-----------------------------|
| 1   | Bùi Ngọc Phương Linh | 24022809   | làm slide                   |
| 2   | Nguyễn Lê Nhật Minh  | 24022817   | viết readme                 |
| 3   | Nguyễn Minh Quân     | 24022825   | tìm thông tin và thuật toán |
| 4   | Nguyễn Thủy Nguyên   | 24022821   | làm slide                   |
| 5   | Vũ Quang Huy         | 24022804   | thuật toán và code          |

## 2. Thông tin bài tập
- Bài toán Kalo: Có N đồ vật, khối lượng w[i], giá trị v[i]. Tìm cách chọn sao cho không quá W, giá trị lớn nhất.

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
- Bài toán yêu cầu tìm ra cách chọn số đồ vật sao cho tổng khối lượng không vượt quá giá trị W cho trước và giá trị V lớn nhất

#### Input:
+ Dòng đầu tiên chứa số đồ vật N
+ Dòng tiếp theo chứa số nguyên dương W
+ N dòng tiếp theo mỗi dòng chứa 2 số nguyên dương w thứ i và v thứ i

#### Output:
+ Dòng đầu tiên in ra tổng giá trị lớn nhất của các vật được chọn
+ Dòng thứ hai in ra chỉ số các vật được chọn theo thứ tự tăng dần
         
### b. Thuật toán / Hướng tiếp cận
- Sử dụng đệ quy (recursion) và thuật toán quay lui (backtracking) để giải quyết bài toán.
- Hàm `knapsack` tính giá trị lớn nhất có thể đạt được với khối lượng tối đa là `W`.
- Hàm `itemsSelected` xác định các đồ vật được chọn để đạt được giá trị lớn nhất.

#### Thuật toán:
1. Nếu số đồ vật là 0 hoặc khối lượng tối đa là 0, trả về 0.
2. Nếu khối lượng của đồ vật thứ N lớn hơn khối lượng tối đa, bỏ qua đồ vật này và gọi đệ quy cho N-1 đồ vật còn lại.
3. Tính giá trị khi bao gồm đồ vật thứ N và khi không bao gồm đồ vật thứ N.
4. Trả về giá trị lớn hơn giữa hai giá trị trên.
5. Hàm `itemsSelected` xác định các đồ vật được chọn bằng cách duyệt ngược lại từ kết quả của hàm `knapsack`.

#### Sơ đồ cây mô phỏng thuật toán

```plaintext
knapsack(N, W)  // Bắt đầu với N đồ vật và sức chứa W
    |
    +-- knapsack(N-1, W)  // Loại bỏ đồ vật thứ N
    |       |
    |       +-- knapsack(N-2, W)  // Loại bỏ đồ vật thứ N-1
    |       |       |
    |       |       +-- ...  // Tiếp tục loại bỏ các đồ vật
    |       |
    |       +-- knapsack(N-2, W-w[N-1])  // Bao gồm đồ vật thứ N-1
    |               |
    |               +-- ...  // Tiếp tục với sức chứa giảm
    |
    +-- knapsack(N-1, W-w[N-1])  // Bao gồm đồ vật thứ N
            |
            +-- knapsack(N-2, W-w[N-1])  // Loại bỏ đồ vật thứ N-1
            |       |
            |       +-- ...  // Tiếp tục loại bỏ các đồ vật
            |
            +-- knapsack(N-2, W-w[N-1]-w[N-2])  // Bao gồm đồ vật thứ N-1
                    |
                    +-- ...  // Tiếp tục với sức chứa giảm
```

#### Ưu điểm:
- Thuật toán sử dụng đệ quy và backtracking, giúp dễ dàng hiểu và triển khai.
- Cấu trúc mã nguồn rõ ràng và dễ theo dõi.
- Chính xác: Thuật toán đảm bảo tìm ra giá trị lớn nhất có thể đạt được với khối lượng tối đa cho trước. 
- Tổng quát: Thuật toán có thể áp dụng cho bất kỳ số lượng đồ vật và khối lượng tối đa nào, miễn là các giá trị đầu vào hợp lệ.

#### Nhược điểm:
- Mỗi lần gọi đệ quy tạo ra một khung ngăn xếp mới, dẫn đến việc sử dụng nhiều bộ nhớ khi số lượng đồ vật lớn.
- Phức tạp, tính toán lại nhiều lần cho cùng một trạng thái dẫn đến không hiệu quả cho các bài toán có số lượng đồ vật lớn.

## 4. Ví dụ minh họa
### Ví dụ 1
#### input:
- Enter the number of items: 4
- Enter the max capacity: 10
- Enter the weight and value of each item: 
- 5	60
- 4	40
- 6	30
- 3	50
#### output:
- The max value possible is 110
- Items that were selected: 1 4

### Giải thích cách giải ví dụ 1
1. **Khởi tạo và nhập dữ liệu**:
   - Số lượng đồ vật `N` là 4.
   - Khối lượng tối đa `W` là 10.
   - Mảng khối lượng `w` là [5, 4, 6, 3].
   - Mảng giá trị `v` là [60, 40, 30, 50].

2. **Tính giá trị lớn nhất**:
   - Sử dụng hàm `knapsack` để tính giá trị lớn nhất có thể đạt được với khối lượng tối đa là 10.
   - Hàm `knapsack` sẽ gọi đệ quy để tính toán giá trị lớn nhất bằng cách thử bao gồm hoặc không bao gồm từng đồ vật.
   - Ví dụ: 
     - Đồ vật thứ 4 có khối lượng 3, nhỏ hơn 10, nên có thể chọn hoặc không chọn.
     - Gọi đệ quy `knapsack(3, [5, 4, 6, 3], [60, 40, 30, 50], 7)` và `knapsack(3, [5, 4, 6, 3], [60, 40, 30, 50], 10)`.
     - Đồ vật thứ 3 có khối lượng 6, nhỏ hơn 7, nên có thể chọn hoặc không chọn.
     - Gọi đệ quy `knapsack(2, [5, 4, 6, 3], [60, 40, 30, 50], 1)` và `knapsack(2, [5, 4, 6, 3], [60, 40, 30, 50], 7)`.
     - Tiếp tục tính toán cho các đồ vật còn lại.

3. **Xác định các đồ vật được chọn**:
   - Sử dụng hàm `itemsSelected` để xác định các đồ vật được chọn để đạt được giá trị lớn nhất.
   - Hàm `itemsSelected` sẽ duyệt ngược lại từ kết quả của hàm `knapsack` để xác định các đồ vật được chọn.
   - Ví dụ: 
     - Đồ vật thứ 4 được chọn, gọi đệ quy `itemsSelected(3, [5, 4, 6, 3], [60, 40, 30, 50], 7, selected)`.
     - Đồ vật thứ 1 được chọn, gọi đệ quy `itemsSelected(2, [5, 4, 6, 3], [60, 40, 30, 50], 7, selected)`.
     - Tiếp tục xác định các đồ vật còn lại.

4. **Kết quả cuối cùng**:
   - Giá trị lớn nhất có thể đạt được là 110.
   - Các đồ vật được chọn là 1 và 4.

### Ví dụ 2
#### input:
- Enter the number of items: 5
- Enter the max capacity: 15
- Enter the weight and value of each item: 
- 12 24
- 7 13
- 11 23
- 8 15
- 9 16
#### output:
- The max value possible is 39
- Items that were selected: 2 4

### Giải thích cách giải ví dụ 2
1. **Khởi tạo và nhập dữ liệu**:
   - Số lượng đồ vật `N` là 5.
   - Khối lượng tối đa `W` là 15.
   - Mảng khối lượng `w` là [12, 7, 11, 8, 9].
   - Mảng giá trị `v` là [24, 13, 23, 15, 16].

2. **Tính giá trị lớn nhất**:
   - Sử dụng hàm `knapsack` để tính giá trị lớn nhất có thể đạt được với khối lượng tối đa là 15.
   - Hàm `knapsack` sẽ gọi đệ quy để tính toán giá trị lớn nhất bằng cách thử bao gồm hoặc không bao gồm từng đồ vật.
   - Ví dụ: 
     - Đồ vật thứ 5 có khối lượng 9, nhỏ hơn 15, nên có thể chọn hoặc không chọn.
     - Gọi đệ quy `knapsack(4, [12, 7, 11, 8, 9], [24, 13, 23, 15, 16], 6)` và `knapsack(4, [12, 7, 11, 8, 9], [24, 13, 23, 15, 16], 15)`.
     - Đồ vật thứ 4 có khối lượng 8, lớn hơn 6, không thể chọn.
     - Gọi đệ quy `knapsack(3, [12, 7, 11, 8, 9], [24, 13, 23, 15, 16], 6)`.
     - Tiếp tục tính toán cho các đồ vật còn lại.

3. **Xác định các đồ vật được chọn**:
   - Sử dụng hàm `itemsSelected` để xác định các đồ vật được chọn để đạt được giá trị lớn nhất.
   - Hàm `itemsSelected` sẽ duyệt ngược lại từ kết quả của hàm `knapsack` để xác định các đồ vật được chọn.
   - Ví dụ: 
     - Đồ vật thứ 4 được chọn, gọi đệ quy `itemsSelected(3, [12, 7, 11, 8, 9], [24, 13, 23, 15, 16], 7, selected)`.
     - Đồ vật thứ 2 được chọn, gọi đệ quy `itemsSelected(2, [12, 7, 11, 8, 9], [24, 13, 23, 15, 16], 7, selected)`.
     - Tiếp tục xác định các đồ vật còn lại.

4. **Kết quả cuối cùng**:
   - Giá trị lớn nhất có thể đạt được là 39.
   - Các đồ vật được chọn là 2 và 4.

### Ví dụ 3
#### input:
- Enter the number of items: 6
- Enter the max capacity: 20
- Enter the weight and value of each item: 
- 5 30
- 10 40
- 15 50
- 7 20
- 8 25
- 9 35
#### output:
- The max value possible is 75
- Items that were selected: 1 2 4

### Giải thích cách giải ví dụ 3
1. **Khởi tạo và nhập dữ liệu**:
   - Số lượng đồ vật `N` là 6.
   - Khối lượng tối đa `W` là 20.
   - Mảng khối lượng `w` là [5, 10, 15, 7, 8, 9].
   - Mảng giá trị `v` là [30, 40, 50, 20, 25, 35].

2. **Tính giá trị lớn nhất**:
   - Sử dụng hàm `knapsack` để tính giá trị lớn nhất có thể đạt được với khối lượng tối đa là 20.
   - Hàm `knapsack` sẽ gọi đệ quy để tính toán giá trị lớn nhất bằng cách thử bao gồm hoặc không bao gồm từng đồ vật.
   - Ví dụ: 
     - Đồ vật thứ 6 có khối lượng 9, nhỏ hơn 20, nên có thể chọn hoặc không chọn.
     - Gọi đệ quy `knapsack(5, [5, 10, 15, 7, 8, 9], [30, 40, 50, 20, 25, 35], 11)` và `knapsack(5, [5, 10, 15, 7, 8, 9], [30, 40, 50, 20, 25, 35], 20)`.
     - Đồ vật thứ 5 có khối lượng 8, nhỏ hơn 11, nên có thể chọn hoặc không chọn.
     - Gọi đệ quy `knapsack(4, [5, 10, 15, 7, 8, 9], [30, 40, 50, 20, 25, 35], 3)` và `knapsack(4, [5, 10, 15, 7, 8, 9], [30, 40, 50, 20, 25, 35], 11)`.
     - Tiếp tục tính toán cho các đồ vật còn lại.

3. **Xác định các đồ vật được chọn**:
   - Sử dụng hàm `itemsSelected` để xác định các đồ vật được chọn để đạt được giá trị lớn nhất.
   - Hàm `itemsSelected` sẽ duyệt ngược lại từ kết quả của hàm `knapsack` để xác định các đồ vật được chọn.
   - Ví dụ: 
     - Đồ vật thứ 4 được chọn, gọi đệ quy `itemsSelected(3, [5, 10, 15, 7, 8, 9], [30, 40, 50, 20, 25, 35], 13, selected)`.
     - Đồ vật thứ 2 được chọn, gọi đệ quy `itemsSelected(2, [5, 10, 15, 7, 8, 9], [30, 40, 50, 20, 25, 35], 13, selected)`.
     - Tiếp tục xác định các đồ vật còn lại.

4. **Kết quả cuối cùng**:
   - Giá trị lớn nhất có thể đạt được là 75.
   - Các đồ vật được chọn là 1, 2 và 4.

## 5. Link video báo cáo
- [Video báo cáo nhóm 5](https://l.facebook.com/l.php?u=https%3A%2F%2Fwww.canva.com%2Fdesign%2FDAGg4_S5Gxs%2FLKAY6TielNYqrxCD7Jg5qw%2Fedit%3Futm_content%3DDAGg4_S5Gxs%26utm_campaign%3Ddesignshare%26utm_medium%3Dlink2%26utm_source%3Dsharebutton%26fbclid%3DIwZXh0bgNhZW0CMTAAAR1AvK_hbmlwwTq7SJMc5huJjq6A6_8vRaVlaHZMM-RXZrYHfB5k5la9NNY_aem_agq9c2xC6pVfMRNADZQczA&h=AT2KKvOSuQyuPATMtaAmjgNkeklJwMcQXY5zttlTgN1fMdZqI5NuNcTWefr0JhHRz72A3ItO3Wi7jHoK92rMwfQbTJ8EtsWO5K94CqPWlxzUQsqYhnRFTD5UzI-mrkQpL_-E62GK2JStv_E)

## 6. Link source code
- [Link src](https://github.com/Minh151/bai-tap-nhom/tree/main/src)