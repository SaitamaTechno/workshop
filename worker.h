#ifndef WORKER_H
#define WORKER_H
#include <string>
#include <vector>
using namespace std;


class Worker {
	public:
	    Worker( int _id, string _name, string _phone, double _salary);
	    ~Worker();
		void update_data( int _id, string _name, string _phone, double _salary);
	    //vector<variant<int, double, string>> get_worker_info();
	    void set_id(int _id);
	    void set_name(string _name);
	    void set_phone(string _phone);
	    void set_salary(double _salary);
	    
	    int get_id();
	    string get_name();
	    string get_phone();
	    double get_salary();
	private:
		string name, phone;
	    int id;
	    double salary;
	    //vector<variant<int, double, string>> data_list[];
};

#endif // MYCLASS_H