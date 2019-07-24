/*
Một câu lạc bộ tổ chức sinh hoạt hè tập trung cho học sinh trong thành phố, có n học sinh tham gia. Mỗi học sinh đăng ký tham gia phải được kiểm tra
trình độ chung về các môn khoa học tự nhiên, môn khoa học xã hội và ghi vào tờ khai 3 mục: số điểm về môn khoa học tự nhiên, số điểm về môn khoa học xã hội
và giới tính. Câu lạc bộ muốn phân hai em ở một phòng trong thời gian sinh hoạt. Để các em có thể bổ sung kiến thức cho nhau, ban tổ chức dự định
sắp xếp 2 em ở cùng phòng, trước hết phải cùng giới tính, trong 2 môn khoa học chỉ có duy nhất một môn trùng điểm. Vì vậy, câu lạc bộ muốn biết có bao nhiêu
cặp học sinh thỏa mãn điều kiện trên.
Yêu cầu: Cho trước n và danh sách điểm môn khoa học tự nhiên, môn khoa học xã hội, giới tính là ai, bi, ci (1≤i≤n). Đếm số lượng các cặp (i, j)
sao cho i<j và (ai=aj; bi≠bj; ci=cj) hoặc (ai≠aj; bi=bj; ci=cj).
Dữ liệu vào từ tệp CLUB.INP:
- Dòng đầu ghi số tự nhiên n (2≤n≤10^5)
- Dòng thứ i trong n dòng tiếp theo ghi 3 số ai, bi, ci; với ai, bi là các số nguyên dương (1≤ai,bi,≤100) biểu thị điểm số môn khoa học tự nhiên và
khoa học xã hội của học sinh thứ i, còn ci=1 hoặc ci=2 thể hiện học sinh thứ i là nam hay nữ tương ứng.
Kết quả ghi ra tệp CLUB.OUT: Số nguyên duy nhất là số lượng tìm được
Ví dụ:
CLUB.INP
6
3 5 1
3 1 2
5 3 2
3 2 2
4 5 1
3 2 2
CLUB.OUT
3
Giải thích
Các cặp thỏa mãn:
(1, 5) cùng giới tính và cùng điểm KHXH=5; điểm KHTN
khác nhau
(2, 4) cùng giới tính và cùng điểm KHTN=3; điểm KHXH
khác nhau
(2, 6) cùng giới tính và cùng điểm KHTN=3; điểm KHXH
khác nhau
*/
#include <bits/stdc++.h>

using namespace std;
struct diem
{
    int tn,xh,gt=0;
};
int n,res=0;
diem a[100001];
vector <int> tnn[101];
vector <int> xhh[101];
void nhap()
{
    //freopen("CLUB.INP","r",stdin);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i].tn>>a[i].xh>>a[i].gt;
}
int socap(int n)
{
    return n*(n+1)/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    nhap();
    //xet nam
    for (int i=0;i<n;++i)
    {
        if (a[i].gt==1)
        {
            tnn[a[i].tn].push_back(a[i].xh);
            xhh[a[i].xh].push_back(a[i].tn);
        }
    }
    for (int i=0;i<=100;++i)
    {
        if (!tnn[i].empty())
        {
            res+=socap(tnn[i].size());
            map <int,int> m;
            for (int j=0;j<tnn[i].size();++j)
                m[tnn[i][j]]++;
            for (auto it=m.begin();it!=m.end();it++)
                res-=socap(it->second);
        }
        if (!xhh[i].empty())
        {
            res+=socap(xhh[i].size());
            map <int,int> m;
            for (int j=0;j<xhh[i].size();++j)
                m[xhh[i][j]]++;
            for (auto it=m.begin();it!=m.end();it++)
                res-=socap(it->second);
        }
    }
    //clear
    for (int i=0;i<=100;++i)
    {
        tnn[i].clear();
        xhh[i].clear();
    }
    //xet nu

    for (int i=0;i<n;++i)
    {
        if (a[i].gt==2)
        {
            tnn[a[i].tn].push_back(a[i].xh);
            xhh[a[i].xh].push_back(a[i].tn);
        }
    }
    for (int i=0;i<=100;++i)
    {
        if (!tnn[i].empty())
        {
            res+=socap(tnn[i].size());
            map <int,int> m;
            for (int j=0;j<tnn[i].size();++j)
                m[tnn[i][j]]++;
            for (auto it=m.begin();it!=m.end();it++)
                res-=socap(it->second);
        }
        if (!xhh[i].empty())
        {
            res+=socap(xhh[i].size());
            map <int,int> m;
            for (int j=0;j<xhh[i].size();++j)
                m[xhh[i][j]]++;
            for (auto it=m.begin();it!=m.end();it++)
                res-=socap(it->second);
        }
    }
    cout<<res;
    return 0;
}
/*
8
1 3 1
5 4 1
1 9 1
2 4 1
7 3 1
5 4 1
3 9 1
5 4 1
*/
