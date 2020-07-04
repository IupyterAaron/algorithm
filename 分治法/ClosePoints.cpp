/*
*			最近点对问题
*输入：按x坐标排列的n(n>=2)个点的集合S={(x1,y1),(x2,y2),...,(xn,yn)}

输出：最近点的距离

1.如果n==2，则返回（x1,y1）和（x2,y2）之间的距离，算法结束；

2.如果n==3，则返回（x1,y1）、（x2,y2）和（x3,y3）之间的最小距离，算法结束；（此步必要在于，若n==3划分之后必然有一半为n==1，导致无法正确执行递归）

3.划分：m==S中各点x坐标的中位数；

4.d1 = 计算{(x1,y1),...,(xm,ym)}的最近对距离；

5.d2 = 计算{(xm,ym),...,(xn,yn)}的最近对距离；

6.d = min(d1,d2);

7.依次考察集合S中的点p（x，y），如果（x<=xm 并且x>=xm-d），则将点p放入集合P1中；如果（x>xm 并且x<=xm+d），则将点p放入集合P2中;

8.将集合P1和P2按y坐标升序排列；

9.对集合P1和P2中的每个点p（x，y），在y坐标区间[y,y+d]内最对取出6个候选点，计算与点p的最近距离d3；

10.返回min{d，d3}；
*
*/


/*
	程序： 最近对的距离
	作者：Moyu
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<sstream>

using namespace std;

struct Point {
	double x;
	double y;
};
inline bool Compx(const Point& p1, const Point& p2)
{
	return p1.x < p2.x;
}
inline bool Compy(const Point& p1, const Point& p2)
{
	return p1.y < p2.y;
}
inline double Distance(const Point& a, const Point& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Merge(vector<Point>& v, int lo, int m, int hi)
{
	vector<Point> vl(v.begin() + lo, v.begin() + m);
	int i = lo;
	int j = 0;
	int k = m;
	while (i < hi) {
		if (j < vl.size() && (k == hi || vl[j].y <= v[k].y))
			v[i++] = vl[j++];
		if (k < hi && (j == vl.size() || vl[j].y > v[k].y))
			v[i++] = v[k++];
	}
}
/*
	函数：点集最近对的距离
	参数：vx：以x排序的点集
*/
double Closest(vector<Point>& vx, int lo, int hi)
{
	if (hi - lo == 2) {
		if (vx[lo].y > vx[hi - 1].y) {
			swap(vx[lo], vx[hi - 1]);
		}
		return Distance(vx[lo], vx[hi - 1]);
	}
	if (hi - lo == 3) {
		sort(vx.begin() + lo, vx.begin() + hi, Compy);
		double d1 = Distance(vx[lo], vx[lo + 1]);
		double d2 = Distance(vx[lo], vx[hi - 1]);
		double d3 = Distance(vx[lo + 1], vx[hi - 1]);
		return min({ d1,d2,d3 });
	}
	int m = (lo + hi) / 2;
	double mx = vx[m].x;
	double dl = Closest(vx, lo, m);
	double dr = Closest(vx, m, hi);
	double d = min(dl, dr);
	Merge(vx, lo, m, hi);
	vector<Point> vp;
	for (int i = lo; i < hi; ++i) {
		if (abs(vx[i].x - mx) < d)
			vp.push_back(vx[i]);
	}
	for (int i = 0; i < vp.size(); ++i) {
		for (int j = i + 1; j < vp.size(); ++j) {
			if (vp[j].y - vp[i].y >= d)
				break;
			else {
				double dm = Distance(vp[i], vp[j]);
				if (dm < d)
					d = dm;
			}
		}
	}
	return d;
}
int main()
{
	vector<Point> v;
	ifstream file("point.txt", ifstream::in);
	string line;
	while (getline(file, line)) {
		Point p;
		stringstream liness(line);
		liness >> p.x >> p.y;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), Compx);
	cout << Closest(v, 0, v.size()) << endl;
	return 0;
}