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

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>

#include "banksim.h"
using namespace std;
namespace villegastellers
{
    Customer::Customer(int t)
    {
        time_in = t;
    }

    int Customer::getTime()
    {
        return time_in;
    }

    int Customer::waitTime(int ctime)
    {
        return ctime - time_in;
    }

    Teller::Teller()
    {
        processing = false;
    }

    void Teller::setCustomer(Customer c)
    {
        currentCustomer = c;
        processing = true;
    }

    void Teller::releaseCustomer()
    {
        if (processing)
            processing = false;
    }

    bool Teller::hasCustomer()
    {
        return processing;
    }

    bool Teller::processed(int currentTime)
    {
        return (currentTime - currentCustomer.getTime()) >= process_time;
    }

    void Teller::setProcessTime(int tp)
    {
        process_time = tp;
    }

    int Teller::getProcessTime()
    {
        return process_time;
    }

    CustomerTracker::CustomerTracker()
    {
        highest = 0;
        lowest = 100;
        total_wait_time = 0;
    }

    void CustomerTracker::set_highest(int the_highest)
    {
        highest = the_highest;
    }

    void CustomerTracker::set_lowest(int the_lowest)
    {
        lowest = the_lowest;
    }

    void CustomerTracker::add_wait_time(double the_wait_time)
    {
        total_wait_time += the_wait_time;
    }

    int CustomerTracker::get_highest()
    {
        return highest;
    }

    int CustomerTracker::get_lowest()
    {
        return lowest;
    }

    double CustomerTracker::get_wait_time()
    {
        return total_wait_time;
    }

    TellerTracker::TellerTracker()
    {
        grand_total = 0;
        grand_shortest = 100;
        grand_longest = 0;
        for(int i = 0; i < 4; i++)
        {
            teller_totals[i] = 0;
            longest[i] = 0;
            shortest[i] = 100;
            custs_per_teller[i] = 0;
        }
    }

    void TellerTracker::add_to_total(int the_num, int the_element)
    {
        teller_totals[the_element] = the_num + teller_totals[the_element];
    }

    void TellerTracker::add_to_grand_total(int the_num)
    {
        grand_total = the_num + grand_total;
    }

    void TellerTracker::increase_cust_num(int the_element)
    {
        custs_per_teller[the_element]++;
    }

    void TellerTracker::set_total(int the_total, int the_element)
    {
        teller_totals[the_element] = the_total;
    }

    void TellerTracker::set_grand_total(int the_num)
    {
        grand_total = the_num;
    }

    void TellerTracker::set_grand_shortest(int the_shortest)
    {
        grand_shortest = the_shortest;
    }

    void TellerTracker::set_grand_longest(int the_longest)
    {
        grand_longest = the_longest;
    }

    void TellerTracker::set_longest(int the_longest, int the_element)
    {
        longest[the_element] = the_longest;
    }

    void TellerTracker::set_shortest(int the_shortest, int the_element)
    {
        shortest[the_element] = the_shortest;
    }

    void TellerTracker::set_num_custs(int the_num, int the_element)
    {
        custs_per_teller[the_element] = the_num;
    }

    int TellerTracker::get_total(int the_element)
    {
        return teller_totals[the_element];
    }

    int TellerTracker::get_grand_total()
    {
        return grand_total;
    }

    int TellerTracker::get_grand_shortest()
    {
        return grand_shortest;
    }

    int TellerTracker::get_grand_longest()
    {
        return grand_longest;
    }

    int TellerTracker::get_longest(int the_element)
    {
        return longest[the_element];
    }

    int TellerTracker::get_shortest(int the_element)
    {
        return shortest[the_element];
    }

    int TellerTracker::get_customer_total(int the_element)
    {
        return custs_per_teller[the_element];
    }

    bool gen_customer(int time_elapsed)
    {
        bool gen = false;
        int r = rand() % 100 + 1;//random number 1-100.
        if(time_elapsed < 14400)
        {
            if(time_elapsed % 180 == 0 &&  r <= 70  || time_elapsed % 120 == 0 &&  r <= 60  || time_elapsed % 60 == 0 &&   r <= 50  || r < 6)
                gen =  true;
        }
        else if (time_elapsed < 18000)
        {
            if(time_elapsed % 180 == 0 &&  r <= 90  || time_elapsed % 120 == 0 &&  r <= 80  || time_elapsed % 60 == 0 &&   r <= 70  || r < 6)
                gen =  true;
        }
        else if (time_elapsed < 28800)
        {
            if(time_elapsed % 180 == 0 &&  r <= 80  || time_elapsed % 120 == 0 &&  r <= 70  || time_elapsed % 60 == 0 &&   r <= 60  || r < 6)
                gen =  true;
        }
        return gen;
    }

    /*
    bool gen_customer(int time_elapsed)
    {
        bool gen = false;
        int r = random() %100 + 1;
        if(time_elapsed < 14400)
        {
            if(r <= 10 )
                gen =  true;
        }
        else if (time_elapsed < 18000)
        {
            if(r <= 40 )
                gen =  true;
        }
        else if (time_elapsed < 28800)
        {
            if(r <= 30 )
                gen =  true;
        }
        return gen;
    }
    */
    /*
    void print_array(int* c)
    {
        for (int i = 0; i < 6; i++)
            cout << "i=" << i << " - " << c[i] << endl;
    }
    */

    void process_line(list<Customer>& bankline,vector<Teller>& tellers,int ctime,
                      CustomerTracker& the_tracker, TellerTracker& t_tracker)
    {
        Customer c_cust;
        for(int i = 0; i < TELLERS; i++)//All tellers
        {
            if(bankline.size() != 0 && !tellers[i].hasCustomer())
            {
                int r = rand() % 120 + 60;  // this will give a time between 60 - 120 seconds
                c_cust = bankline.front(); //customer at front
                tellers[i].setCustomer(c_cust);
                tellers[i].setProcessTime(r);//sets processing time for the teller to something between 60-120 or 1-2 minutes.
                the_tracker.add_wait_time(c_cust.waitTime(ctime));

                if(c_cust.waitTime(ctime) < the_tracker.get_lowest())
                {
                    the_tracker.set_lowest(c_cust.waitTime(ctime));
                }
                else if(c_cust.waitTime(ctime) > the_tracker.get_highest())
                {
                    the_tracker.set_highest(c_cust.waitTime(ctime));
                }
                bankline.pop_front();
            }
            if(tellers[i].hasCustomer() && tellers[i].processed(ctime))
            {
                tellers[i].releaseCustomer();
                t_tracker.add_to_total(tellers[i].getProcessTime(), i);
                t_tracker.add_to_grand_total(tellers[i].getProcessTime());
                t_tracker.increase_cust_num(i);
                if(tellers[i].getProcessTime() > t_tracker.get_longest(i))
                {
                    t_tracker.set_longest(tellers[i].getProcessTime(), i);
                    if(tellers[i].getProcessTime() > t_tracker.get_grand_longest())
                        t_tracker.set_grand_longest(tellers[i].getProcessTime());
                }

                else if(tellers[i].getProcessTime() < t_tracker.get_shortest(i))
                {
                    t_tracker.set_shortest(tellers[i].getProcessTime(), i);
                    if(tellers[i].getProcessTime() < t_tracker.get_grand_shortest())
                        t_tracker.set_grand_shortest(tellers[i].getProcessTime());
                }
            }
                //tellers[i].releaseCustomer();
        }
    }
    void print_list(list<Customer> lc)
    {
       list<Customer>::iterator p;
       if (lc.size() == 0)
       {
           cout << "empty" << endl;
           return;
       }
       for (p = lc.begin(); p != lc.end(); p++)//iterating through the list.
       {
           cout << "*";
       }
    //      cout << (*p).getTime() << " ";

       cout << endl;
    }

}
