//Name: Jonathan Villegas
//Assignment: Use the code found at http://boss.vvc.edu/tonningp/cis202/examples/bank_sim.cpp and do the following:
//Implement counters to track the average wait time in the line for the customers
//output the longest and shortest wait times.
//Implement counters for the bank teller processing time to find the average processing
//time for each bank teller, the average for all the tellers, the longest and
//shortest times per teller, and the longest and shortest times for all of the tellers.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//File: main.cpp

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>
#include "banksim.h"
using namespace std;
using namespace villegastellers;

int main()
{
    Customer c;
    CustomerTracker c_tracker;
    TellerTracker t_tracker;
    int num_of_customers = 0;//total of customers
    srand(time(0));//seeding the random number generator
	list<Customer> bank_line;//list of customers.
    vector<Teller> tellers;//vector of tellers.

    for(int i = 0; i < TELLERS; i++)//makes a vector of tellers (4)
        tellers.push_back(Teller());

	for(int time_elapsed = 0; time_elapsed < TOTAL_TIME; time_elapsed++)
	{
        if(gen_customer(time_elapsed))//if a customer is randomly generated
        {
            bank_line.push_back(Customer(time_elapsed));//generating a customer with the time in.
            num_of_customers++;
            c = bank_line.back();
            print_list(bank_line);

        }
        process_line(bank_line,tellers,time_elapsed, c_tracker, t_tracker);//passes line, tellers, and the time elapsed
	}

	cout << "after " <<  (TOTAL_TIME/60/60) <<   " hours there are " << bank_line.size() << " customers in the line" << endl;
	cout << endl;

    cout << "Average wait time per customer: " << c_tracker.get_wait_time() / static_cast<double>(num_of_customers)  << " seconds per customer." << endl;
    cout << "Shortest wait time of all customers: " << c_tracker.get_lowest() << " seconds." << endl;
    cout << "Longest wait time of all customers: " << c_tracker.get_highest() << " seconds." << endl;
    cout << endl;

    for (int i = 0; i < TELLERS; i++)
    {
        cout << "Average for teller: " << i + 1 << ": "
             << static_cast<double>(t_tracker.get_total(i)) / static_cast<double>(t_tracker.get_customer_total(i)) << endl;
    }
    cout << "Average for all tellers: " << t_tracker.get_grand_total() / static_cast<double>(num_of_customers) << " seconds." << endl;
    cout << endl;

    for(int i = 0; i < TELLERS; i++)
    {
        cout << "Shortest service time for Teller " << i + 1 << ": " << t_tracker.get_shortest(i) << endl;
        cout << "Longest service time for Teller " << i + 1 << ": " << t_tracker.get_longest(i) << endl;
    }

    cout << "Shortest service time of all tellers: " << t_tracker.get_grand_shortest() << endl;
    cout << "Longest service time of all tellers: " << t_tracker.get_grand_longest() << endl;
    cout << endl;

    print_list(bank_line);

	return 0;
}
