#include <iostream>
#include <stdlib.h>
using namespace std;

int data_in[45] = {1,0,1,};

int main() {
	int index = 0;
	int tcase;
	cin >> tcase;
	int* count =new int[tcase];
	
	while(index < tcase){
		cin >> count[index];
		index++;
	}
	
	for(index=3; index<45; index++){
		data_in[index] = data_in[index-1] + data_in[index-2];
	}
	
	for(index=0; index<tcase; index++){
		int what = count[index];
		cout << data_in[what] << " " << data_in[what+1] << endl;
	}
	
}
