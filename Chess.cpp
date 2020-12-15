/*
*		棋盘覆盖问题
*	有一个特殊方格 故有4^k 种棋盘
*	要求用4种不同形状的L型骨牌 覆盖所有棋盘
*
*		算法实验
*	棋盘 board[size][size]
*   子棋盘 
*   特殊方格
*	L型骨牌
*
*/

#include <iostream>
using namespace std;
int N, X, Y; //棋盘大小， 残缺位置 X,Y
char map[1000][1000]; //棋盘数组
int dir[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 0 } }; //四种L棋的放置
char pieces[4] = { 'A', 'B', 'C', 'D' }; //4种表示
int title = 0;

//style 表示那种类型的骨牌; r,t表示放置骨牌的区域(2*2)的左上角位置
void set_piece(int style, int r, int c) {
	title++;
	for (int i = 0; i < 4; i++)
		if (i == style) { //每种style 对用dir中的摆放方式
			for (int j = 0; j < 4; j++)
				if (i != j)
					map[r + dir[j][0]][c + dir[j][1]] = pieces[i];
		}
}

//startR,starC（行，列）区域的左上角位置； dr,dc（行，列）残缺位置； 区域大小
void chessBoard(int startR, int startC, int dr, int dc, int size) {
	if (size == 1)
		return;
	int s = size / 2;
	int rr = dr >= startR + s; //rr 为1 表示在右方
	int cc = dc >= startC + s; //cc 为1表示在下方
	for (int i = 0; i < 4; i++) {
		if (dir[i][0] == rr && dir[i][1] == cc) {

			//根据残缺的位置，在区域中间放置一个骨牌.
			//例：如果是 rr=0 cc=0  即残缺位置在左上方，对应 dir[0] = {0,0}
			//即style=0, 第一种骨牌
			set_piece(i, startR + s - 1, startC + s - 1);

			for (int j = 0; j < 4; j++) {
				if (j == i) //摆放有残缺位置的 1/4
					chessBoard(startR + s * dir[j][0], startC + s * dir[j][1],
						dr, dc, s);
				else {
					//分别摆放余下的3/4. 残缺位置即在区域中央放置的骨牌 在当前区域的位置 （例：对于右上角区域，残缺位置在坐下角位置）
					chessBoard(startR + s * dir[j][0], startC + s * dir[j][1],
						startR + s - 1 + dir[j][0],
						startC + s - 1 + dir[j][1], s);
				}
			}
		}
	}
}

int main() {

	std::cout << "欢迎使用棋盘覆盖程序：" << endl;
	cout << "分别A,B,C,D代表4种不同方向的骨牌:" << endl << endl;
	cout << " 	 A    B     CC   DD" << endl;
	cout << "	AA    BB    C     D" << endl << endl;
	cout << "输入3个数，分别为棋盘大小N(小于1000)，残缺位置X,Y(1到N之间):" << endl;

	cin >> N >> X >> Y;
	//判断N是否为2的n次方
	if ((N & (N - 1)) || X > N || X < 1 || Y < 1 || Y > N) {
		cout << "输入不合法" << endl;
	}
	else {
		chessBoard(0, 0, X - 1, Y - 1, N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}