#ifndef WORKER_H
#define WORKER_H
#include <string>
#include <vector>
using namespace std;

class Task{
	private:
		string task;
	public:
		Task();
		string get_task();
		void set_task(string _task="None");
};
class Worker: public Task{
	public:
	    Worker( int _id, string _name, string _phone, double _salary);
	    ~Worker();
		void update_data( int _id, string _name, string _phone, double _salary);
	    //vector<variant<int, double, string>> get_worker_info();
	    void set_id(int _id);
	    void set_name(string _name);
		void set_phone(string _phone);
	    void set_phone(long int _phone);
	    void set_salary(double _salary);
	    
	    int get_id();
	    string get_name();
	    string get_phone();
	    double get_salary();
	private:
		string name, phone;
	    int id;
	    double salary;
	    
};

class AllWorkers{
	private:
		vector<Worker> worker_list;
	public:
		AllWorkers();
		void append(Worker worker);
		void pop();
		void pop_by_name(string _name);
		void display_list();
		void display_data_by_name(string name);
		void update_user(Worker worker);
		vector<Worker> get_list();
};
#endif // MYCLASS_H