/*
*		���̸�������
*	��һ�����ⷽ�� ����4^k ������
*	Ҫ����4�ֲ�ͬ��״��L�͹��� ������������
*
*		�㷨ʵ��
*	���� board[size][size]
*   ������ 
*   ���ⷽ��
*	L�͹���
*
*/

#include <iostream>
using namespace std;
int N, X, Y; //���̴�С�� ��ȱλ�� X,Y
char map[1000][1000]; //��������
int dir[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 0 } }; //����L��ķ���
char pieces[4] = { 'A', 'B', 'C', 'D' }; //4�ֱ�ʾ
int title = 0;

//style ��ʾ�������͵Ĺ���; r,t��ʾ���ù��Ƶ�����(2*2)�����Ͻ�λ��
void set_piece(int style, int r, int c) {
	title++;
	for (int i = 0; i < 4; i++)
		if (i == style) { //ÿ��style ����dir�еİڷŷ�ʽ
			for (int j = 0; j < 4; j++)
				if (i != j)
					map[r + dir[j][0]][c + dir[j][1]] = pieces[i];
		}
}

//startR,starC���У��У���������Ͻ�λ�ã� dr,dc���У��У���ȱλ�ã� �����С
void chessBoard(int startR, int startC, int dr, int dc, int size) {
	if (size == 1)
		return;
	int s = size / 2;
	int rr = dr >= startR + s; //rr Ϊ1 ��ʾ���ҷ�
	int cc = dc >= startC + s; //cc Ϊ1��ʾ���·�
	for (int i = 0; i < 4; i++) {
		if (dir[i][0] == rr && dir[i][1] == cc) {

			//���ݲ�ȱ��λ�ã��������м����һ������.
			//��������� rr=0 cc=0  ����ȱλ�������Ϸ�����Ӧ dir[0] = {0,0}
			//��style=0, ��һ�ֹ���
			set_piece(i, startR + s - 1, startC + s - 1);

			for (int j = 0; j < 4; j++) {
				if (j == i) //�ڷ��в�ȱλ�õ� 1/4
					chessBoard(startR + s * dir[j][0], startC + s * dir[j][1],
						dr, dc, s);
				else {
					//�ֱ�ڷ����µ�3/4. ��ȱλ�ü�������������õĹ��� �ڵ�ǰ�����λ�� �������������Ͻ����򣬲�ȱλ�������½�λ�ã�
					chessBoard(startR + s * dir[j][0], startC + s * dir[j][1],
						startR + s - 1 + dir[j][0],
						startC + s - 1 + dir[j][1], s);
				}
			}
		}
	}
}

int main() {

	std::cout << "��ӭʹ�����̸��ǳ���" << endl;
	cout << "�ֱ�A,B,C,D����4�ֲ�ͬ����Ĺ���:" << endl << endl;
	cout << " 	 A    B     CC   DD" << endl;
	cout << "	AA    BB    C     D" << endl << endl;
	cout << "����3�������ֱ�Ϊ���̴�СN(С��1000)����ȱλ��X,Y(1��N֮��):" << endl;

	cin >> N >> X >> Y;
	//�ж�N�Ƿ�Ϊ2��n�η�
	if ((N & (N - 1)) || X > N || X < 1 || Y < 1 || Y > N) {
		cout << "���벻�Ϸ�" << endl;
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