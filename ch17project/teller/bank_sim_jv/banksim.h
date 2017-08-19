//Name: Jonathan Villegas
//Assignment: Use the code found at http://boss.vvc.edu/tonningp/cis202/examples/bank_sim.cpp and do the following:
//Implement counters to track the average wait time in the line for the customers
//output the longest and shortest wait times.
//Implement counters for the bank teller processing time to find the average processing
//time for each bank teller, the average for all the tellers, the longest and
//shortest times per teller, and the longest and shortest times for all of the tellers.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//File: banksim.cpp

#ifndef BANKSIM_H_INCLUDED
#define BANKSIM_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>
using namespace std;

namespace villegastellers
{
    class Customer
    {
        public:
            //Constructors
            Customer() {};
            Customer(int);
            //Accessor
            int getTime();
            //Mutator
            int waitTime(int);
        private:
            int time_in;
    };

    class Teller
    {
        public:
            //Constructor
            Teller();
            //Accessor
            void setCustomer(Customer);
            //Releases customer
            void releaseCustomer();
            //Returns true if teller has customer
            bool hasCustomer();
            //returns true if processed
            bool processed(int);
            //Mutator
            void setProcessTime(int);
            //Accessor
            int getProcessTime();
        private:
            Customer currentCustomer;
            bool processing;
            int process_time;
    };

    class CustomerTracker
    {
    public:
        //Constructor
        CustomerTracker();
        //Mutators
        void set_highest(int the_highest);
        void set_lowest(int the_lowest);
        //Adds the wait time to the current wait time
        void add_wait_time(double the_wait_time);
        //Accessors
        int get_highest();
        int get_lowest();
        double get_wait_time();
    private:
        int highest;
        int lowest;
        double total_wait_time;
    };

    class TellerTracker
    {
    public:
        //Constructor
        TellerTracker();
        //Adds to the current total for a teller at the_element
        void add_to_total(int the_num, int the_element);
        //Adds to the grand total for all tellers
        void add_to_grand_total(int the_num);
        //Increases the customer number for the teller at the_element
        void increase_cust_num(int the_element);
        //Mutators
        void set_total(int the_total, int the_element);
        void set_grand_total(int the_total);
        void set_grand_shortest(int the_shortest);
        void set_grand_longest(int the_longest);
        void set_longest(int the_longest, int the_element);
        void set_shortest(int the_shortest, int the_element);
        void set_num_custs(int the_num, int the_element);
        //Accessors
        int get_total(int the_element);
        int get_grand_total();
        int get_grand_shortest();
        int get_grand_longest();
        int get_longest(int the_element);
        int get_shortest(int the_element);
        int get_customer_total(int the_element);
    private:
        int teller_totals[4];
        int grand_total;
        int grand_shortest;
        int grand_longest;
        int longest[4];
        int shortest[4];
        int custs_per_teller[4];
    };

    bool gen_customer(int);
    //void print_array(int* c);
    void process_line(list<Customer>&,vector<Teller>&,int, CustomerTracker& the_tracker, TellerTracker& teller_tracker);
    void print_list(list<Customer>);

    const int TOTAL_TIME = 60*60*8;//8 hours in seconds. Probably how long the branch is open.
    const int TELLERS = 4;
}

#endif // BANKSIM_H_INCLUDED
