#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	//int d[4][11], b[4];
	int w, n;
	cin>>w>>n;

	int **d = new int*[n + 1],
		*b = new int[n +1];

	d[0] = new int[w + 1];
	for (int i = 1; i <= n; i++){
		cin>>b[i];
		d[i] = new int[w + 1];
	}
	for (int i = 0; i <= w; i++)
		d[0][i] = 0;
	
	for (int i = 0; i <= n; i++)
		d[i][0] = 0;

	for (int i =1; i <= n; i++){
		for (int j = 1; j <= w; j++){
			if(j >= b[i])
				d[i][j] = max(d[i - 1][j], d[i - 1][j - b[i]] + b[i]);
			else
				d[i][j] = d[i - 1][j];
		}
	}
	cout<<d[n][w];
	return 0;
}