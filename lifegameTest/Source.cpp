#include<iostream>
#include<Windows.h>
using namespace std;
void printworld(int world[][20] ,int min) {
	system("clc");
	cout << "the world: \t"<<min<<"sec:"<< endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (world[i][j] == 0) {
				cout << "□";
			}
			if (world[i][j] == 1) {
				cout << "■";
			}
		}
		cout << endl;
	}
}
int getneighboor(int world[][20], int i, int j) {
	int count = 0;
	for (int k = i - 1; k <= i + 1; k++) {
		for (int m = j - 1; m <= j + 1; m++) {
			if (m < 0 || m>20 || k < 0 || k>20) {}
			else {
				count += world[k][m];
			}
		}
	}
	return count - world[i][j];
}
void neighboor(int world[][20],int min) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (world[i][j] == 0 || getneighboor(world, i, j) == 3) {
				world[i][j] = 1;
			}
			if (world[i][j] == 1) {
				switch (getneighboor(world, i, j)) {
				case 2:
				case 3:
					break;
				default:
					world[i][j] = 0;
					break;
				}
			}
		}
	}
	printworld(world,min);
}
int main() {
	int world[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			world[i][j] = 0;
		}
	}
	world[10][10] = 1;
	world[10][9] = 1;
	world[10][8] = 1;
	world[9][9] = 1;
	cout << "请输入换代次数： " << endl;
	int k;
	cin >> k;
	int i = 0;
	printworld(world,i);
	while (i < k) {
		i++;
		Sleep(1000);
		neighboor(world,i);
	}
	system("pause");
}