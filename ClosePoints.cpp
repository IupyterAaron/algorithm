/*
*			����������
*���룺��x�������е�n(n>=2)����ļ���S={(x1,y1),(x2,y2),...,(xn,yn)}

����������ľ���

1.���n==2���򷵻أ�x1,y1���ͣ�x2,y2��֮��ľ��룬�㷨������

2.���n==3���򷵻أ�x1,y1������x2,y2���ͣ�x3,y3��֮�����С���룬�㷨���������˲���Ҫ���ڣ���n==3����֮���Ȼ��һ��Ϊn==1�������޷���ȷִ�еݹ飩

3.���֣�m==S�и���x�������λ����

4.d1 = ����{(x1,y1),...,(xm,ym)}������Ծ��룻

5.d2 = ����{(xm,ym),...,(xn,yn)}������Ծ��룻

6.d = min(d1,d2);

7.���ο��켯��S�еĵ�p��x��y���������x<=xm ����x>=xm-d�����򽫵�p���뼯��P1�У������x>xm ����x<=xm+d�����򽫵�p���뼯��P2��;

8.������P1��P2��y�����������У�

9.�Լ���P1��P2�е�ÿ����p��x��y������y��������[y,y+d]�����ȡ��6����ѡ�㣬�������p���������d3��

10.����min{d��d3}��
*
*/


/*
	���� ����Եľ���
	���ߣ�Moyu
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
	�������㼯����Եľ���
	������vx����x����ĵ㼯
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