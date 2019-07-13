/*
    Thành phố XYZ có một vườn bách thảo được mô tả dưới dạng bản đồ hình chữ nhật gồm m dòng n cột. Trong vườn có k loại cây khác nhau, đánh số từ 1 đến k
(k<=100). Mỗi ô của bản đồ chứa duy nhất số nguyên dương i (i <= k) nếu tại ô này có trồng một cây loại i, hoặc số 0 nếu ô này không có cây.
Chính quyền thành phố muốn chỉnh trang khu vườn cho đẹp hơn bằng cách giữ lại những hàng cây có ít nhất t cây liền nhau, thuộc
cùng một loại cây nằm trên cùng một dòng hoặc cùng một cột. Những cây không thuộc hàng cây nào đó sẽ được di chuyển đến vị trí khác phù hợp hơn.
    Yêu cầu: Cho trước bản đồ vườn cây như trên, hãy đếm số lượng cây cần phải di chuyển.
    Dữ liệu vào được cho từ file MOVE.INP có cấu trúc như sau:
- Dòng đầu chứa 3 số nguyên dương m,n,t (1<m ,n, t  100);
- Trong m dòng tiếp theo, mỗi dòng chứa n số nguyên không âm mô tả bản đồ
vườn bách thảo.
Dữ liệu kết quả được ghi ra file MOVE.OUT ghi một số nguyên duy nhất là số lượng
cây cần phải di chuyển.
Ví dụ:
MOVE.INP
5 6 3
1 3 3 3 3 4
1 2 3 2 0 4
3 2 2 2 4 4
1 0 0 2 4 0
1 2 3 0 4 4
MOVE.OUT
10
Giải thích
Những số gạch chân dưới đây biểu thị những cây
cần phải di chuyển:
_1  3  3  3  3  4
_1 _2 _3  2  0  4
_3  2  2  2  4  4
_1  0  0  2  4  0
_1 _2 _3  0  4 _4
*/
#include <bits/stdc++.h>

using namespace std;
int m,n,t;
struct position
{
    int type,movable=1;
};
position a[101][101];
void nhap()
{
    cin>>m>>n>>t;
    for (int i=0;i<m;++i)
    for (int j=0;j<n;++j)
    cin>>a[i][j].type;
}
void move_count()
{
    for (int i=0;i<m;++i)
    for (int j=0;j<n;++j)
        if (a[i][j].movable==1)
    {

    }
}
int main()
{
    nhap();
    return 0;
}
