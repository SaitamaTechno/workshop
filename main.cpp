#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

int main() {
	Worker waiter(1, "Enes Telli", "5552225577", 1000);
	cout<<waiter.get_id()<<endl;
	cout<<waiter.get_name()<<endl;
	cout<<waiter.get_phone()<<endl;
	return 0;
}