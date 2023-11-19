#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

int main() {
	Worker waiter(1, "Enes Telli", "5552225577", 1000);
	Worker cooker(2, "Furkan Usta", "5552225577", 2000);
	cout<<waiter.get_id()<<endl;
	cout<<waiter.get_name()<<endl;
	cout<<waiter.get_phone()<<endl;
	waiter.set_task("go to table1");
	cout<<waiter.get_task()<<endl;
	AllWorkers Workers;
	Workers.append(waiter);
	Workers.append(cooker);
	//Workers.pop();
	Workers.display_list();
	cout<<Workers.get_list()[0].get_task()<<endl;
	cout<<Workers.get_list()[1].get_task()<<endl;
	//Workers.display_data_by_name("Enes Telli");
	Workers.pop_by_name("Furkan Usta");
	waiter.set_phone(5551112233);
	//waiter.set_phone("5551112233");
	Workers.update_user(waiter);
	Workers.display_list();
	return 0;
}