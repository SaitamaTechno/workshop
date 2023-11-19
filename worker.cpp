#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "worker.h"

Task::Task(){
	set_task();
}
string Task::get_task(){
	return task;
}
void Task::set_task(string _task){
	task="Task:"+_task;
}

Worker::Worker( int _id, string _name, string _phone, double _salary)
	:Task()
{
	id=_id;
	name=_name;
	phone=_phone;
	salary=_salary;
}
Worker::~Worker(){}


void Worker::set_id(int _id){id=_id;}
void Worker::set_name(string _name){name=_name;}
void Worker::set_phone(string _phone){phone=_phone;}
void Worker::set_phone(long int _phone){phone=to_string(_phone);}
void Worker::set_salary(double _salary){salary=_salary;}

int Worker::get_id(){return id;}
string Worker::get_name(){return name;}
string Worker::get_phone(){return phone;}
double Worker::get_salary(){return salary;}

AllWorkers::AllWorkers(){}
void AllWorkers::append(Worker worker){
	worker_list.push_back(worker);
}
void AllWorkers::pop(){
	worker_list.pop_back();
}
vector<Worker> AllWorkers::get_list(){
	return worker_list;
}
void AllWorkers::display_list(){
	for (int i=0; i<worker_list.size(); i++){
		cout<<worker_list[i].get_id()<<endl<<worker_list[i].get_name()<<endl<<worker_list[i].get_phone()<<endl<<worker_list[i].get_salary()<<endl<<worker_list[i].get_task()<<endl;
		cout<<endl;
	}
}
void AllWorkers::display_data_by_name(string name){
	int a=0;
	for (int i=0; i<worker_list.size(); i++){
		if (name==worker_list[i].get_name()){
			a=1;
			cout<<worker_list[i].get_id()<<endl<<worker_list[i].get_name()<<endl<<worker_list[i].get_phone()<<endl<<worker_list[i].get_salary()<<endl<<worker_list[i].get_task()<<endl;
		}
	}
	if (a==0){cout<<name<<" is not registered!"<<endl;}
}
void AllWorkers::pop_by_name(string name){
	int a=0;
	for (int i=0; i<worker_list.size(); i++){
		if (name==worker_list[i].get_name()){
			a=1;
			worker_list.erase(worker_list.begin()+(i));
		}
	}
	if (a==0){cout<<name<<" is not registered!"<<endl;}
}
void AllWorkers::update_user(Worker worker){
	int a=0;
	string name=worker.get_name();
	pop_by_name(name);
	append(worker);
}