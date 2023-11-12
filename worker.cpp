#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

Worker::Worker( int _id, string _name, string _phone, double _salary)
{
	id=_id;
	name=_name;
	phone=_phone;
	salary=_salary;
	//data_list=[];
}
Worker::~Worker(){}
/*
vector<variant<int, double, string>> get_worker_info(){
	id=_id;
	name=_name;
	phone=_phone;
	salary=_salary;
	data_list=[id,name,phone,salary];
	return data_list;
}
*/

void Worker::set_id(int _id){id=_id;}
void Worker::set_name(string _name){name=_name;}
void Worker::set_phone(string _phone){phone=_phone;}
void Worker::set_salary(double _salary){salary=_salary;}

int Worker::get_id(){return id;}
string Worker::get_name(){return name;}
string Worker::get_phone(){return phone;}
double Worker::get_salary(){return salary;}


