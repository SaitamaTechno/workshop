#include <iostream>
#include <string>
#include "sqlitee3.h"

using namespace std;

int main(){
    Sql sql("mydata.db");
    //sql.print_worker_data(1);
    //sql.add_worker("Enes", "Telli", "boss", 21, "123 Main St", 1000);
    //sql.delete_worker(3);
    //sql.add_worker("Mikasa", "Ackerman", "cooker", 21, "123 Main St", 500);
    //sql.update_worker(1, "SALARY", 5000); //overloading
    //sql.update_worker(2, "SURNAME", "Jaeger");
    sql.print_all_workers();
    return 0;
}