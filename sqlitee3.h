#ifndef sqlitee3
#define sqlitee3

#include <stdio.h>
#include <sqlite3.h> 
#include <string>
using namespace std;

class Sql {
   public:
      Sql(string filename);
      ~Sql();
      static int callback(void *data, int argc, char **argv, char **azColName);
      static int callback1(void *data, int argc, char **argv, char **azColName);
      void add_worker(string NAME, string SURNAME, string JOB, int AGE, string ADDRESS, double SALARY);
      void update_worker(int ID, string column_name, string data); // Function Overloading 
      void update_worker(int ID, string column_name, int data);
      void delete_worker(int ID);
      void print_worker_by_id(int ID);
      void print_worker_by_fullname(string fullname);
      void print_all_workers();
      double get_total_salaries();

   private:
      sqlite3 *db;
      int rc;
      static int id_counter;

};

#endif