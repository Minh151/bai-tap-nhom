# Báo cáo Bài tập lớn - Nhóm 5
 
## 1. Thông tin nhóm
| STT |       Thành viên     | MSV        | Vai trò   |
|-----|----------------------|------------|-----------|
| 1   | Bùi Ngọc Phương Linh | 24022809   | Vai trò 1 |
| 2   | Nguyễn Lê Nhật Minh  | 24022817   | Vai trò 2 |
| 3   | Nguyễn Minh Quân     | 24022825   | Vai trò 3 |
| 4   | Nguyễn Thủy Nguyên   | 24022821   | Vai trò 4 |
| 5   | Võ Hồng Duy          | 24022804   | Vai trò 5 |

## 2. Thông tin bài tập
- Bài toán Kalo: Có N đồ vật, khối lượng w[i], giá trị v[i]. Tìm cách chọn sao cho không quá W, giá trị lớn nhất.

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
- Bài toán yêu cầu tìm ra cách chọn số đồ vật sao cho khối lượng không vượt quá giá trị W cho trước và giá trị V lớn nhất

#### Input:
+ Dòng đầu tiên chứa số đồ vật N
+ N dòng tiếp theo mỗi dòng chứa 2 số nguyên dương w thứ i và v thứ i

#### Output:
+ Dòng đầu tiên in ra tổng giá trị lớn nhất của các vật được chọn
+ Dòng thứ hai in ra chỉ số các vật được chọn theo thứ tự tăng dần
         
### b. Thuật toán / Hướng tiếp cận
- Sử dụng phương pháp quy hoạch động (dynamic programming) để giải quyết bài toán.
- ### b. Thuật toán / Hướng tiếp cận
- Sử dụng phương pháp quy hoạch động (dynamic programming) để giải quyết bài toán.
- Hàm `knapsack` tính giá trị lớn nhất có thể đạt được với khối lượng tối đa là `W`.
- Hàm `itemsSelected` xác định các đồ vật được chọn để đạt được giá trị lớn nhất.

#### Thuật toán:
1. Nếu số đồ vật là 0 hoặc khối lượng tối đa là 0, trả về 0.
2. Nếu khối lượng của đồ vật thứ N lớn hơn khối lượng tối đa, bỏ qua đồ vật này và gọi đệ quy cho N-1 đồ vật còn lại.
3. Tính giá trị khi bao gồm đồ vật thứ N và khi không bao gồm đồ vật thứ N.
4. Trả về giá trị lớn hơn giữa hai giá trị trên.
5. Hàm `itemsSelected` xác định các đồ vật được chọn bằng cách duyệt ngược lại từ kết quả của hàm `knapsack`.

#### Sơ đồ mô phỏng thuật toán

```plaintext
+--------------------+
| Start              |
+--------------------+
          |
          v
+--------------------+
| Initialize         |
| N, W, w[], v[]     |
+--------------------+
          |
          v
+----------------------------+
| Call knapsack(N, w, v, W)  |
+----------------------------+
          |
          v
+------------------------------------+
| If N == 0 or W == 0                |
|   Return 0                         |
| Else if w[N-1] > W                 |
|   Call knapsack(N-1, w, v, W)      |
| Else                               |
|   include = v[N-1] +               |
|   knapsack(N-1, w, v, W-w[N-1])    |
|   exclude = knapsack(N-1, w, v, W) |
|   Return max(include, exclude)     |
+------------------------------------+
          |
          v
+------------------------------------------+
| Call itemsSelected(N, w, v, W, selected) |
+------------------------------------------+
          |
          v
+-------------------------------------------------------+
| If N == 0 or W == 0                                   |
|   Return                                              |
| Else if w[N-1] > W                                    |
|   Call itemsSelected(N-1, w, v, W, selected)          |
| Else                                                  |
|   include = v[N-1] +                                  |
|   knapsack(N-1, w, v, W-w[N-1])                       |
|   exclude = knapsack(N-1, w, v, W)                    |
|   If include > exclude                                |
|     selected[N-1] = true                              |
|     Call itemsSelected(N-1, w, v, W-w[N-1], selected) |
|   Else                                                |
|     Call itemsSelected(N-1, w, v, W, selected)        |
+-------------------------------------------------------+
          |
          v
+--------------------+
| End                |
+--------------------+