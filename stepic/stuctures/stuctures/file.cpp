#include <iostream>
#include <fstream>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
	ofstream file("t.txt");
	for(int i = 0; i < 10; i++){
		file.width(20);
		file.precision(3);
		file<<1024*i<<endl;
	}
	file.close();
	system("notepad t.txt");
	return 0;
}
