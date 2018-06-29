#include<iostream>
#include<queue>
#include<array>

using namespace std;

int main() {

	queue<int> myqueue;

	myqueue.push(3);
	myqueue.push(4);
	myqueue.push(1);
	myqueue.push(2);
	myqueue.push(0);
	myqueue.push(5);
	myqueue.push(7);
	myqueue.push(6);

	while(!myqueue.empty()) 
	{
		cout << myqueue.front() ;
		myqueue.pop();
		cout << " : size = " << myqueue.size() << endl;

	}
	

	return 0;
}
