//Name: Jonathan Villegas
//Assignment: Using bank_sim.cpp from the Boss website,
//Implement counters to track the average wait time in the line for the customers
//output the longest and shortest wait times.
//Implement counters for the bank teller processing time to
//find the average processing time for each bank teller, the average for
//all the tellers, the longest and shortest times per teller, and the longest
//and shortest times for all of the tellers.
//Date: 3/11/14
//Email: jonathan.e.villegas@gmail.com
//File:

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>

using namespace std;

class Customer
{
	public:
        Customer() {};
		Customer(int);
        int getTime();
        int waitTime(int);
    private:
	    int time_in;
};

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

class Teller
{
    public:
        Teller();
        void setCustomer(Customer);
        void releaseCustomer();
        bool hasCustomer();
        bool processed(int);
        void setProcessTime(int);
        int getProcessTime();
    private:
        Customer currentCustomer;
        bool processing;
        int process_time;
};

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

class CustomerTracker
{
public:
    CustomerTracker();
    void set_highest(int the_highest);
    void set_lowest(int the_lowest);
    void add_wait_time(double the_wait_time);
    int get_highest();
    int get_lowest();
    double get_wait_time();
private:
    int highest;
    int lowest;
    double total_wait_time;
};

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

class TellerTracker
{
public:
    TellerTracker();
    void add_to_total(int the_num, int the_element);
    void add_to_grand_total(int the_num);
    void increase_cust_num(int the_element);
    void set_total(int the_total, int the_element);
    void set_grand_total(int the_total);
    void set_grand_shortest(int the_shortest);
    void set_grand_longest(int the_longest);
    void set_longest(int the_longest, int the_element);
    void set_shortest(int the_shortest, int the_element);
    void set_num_custs(int the_num, int the_element);
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

bool gen_customer(int);
//void print_array(int* c);
void process_line(list<Customer>&,vector<Teller>&,int, CustomerTracker& the_tracker, TellerTracker& teller_tracker);
void print_list(list<Customer>);

const int TOTAL_TIME = 60*60*8;//8 hours in seconds. Probably how long the branch is open.
const int TELLERS = 4;

int main()
{
    Customer c;
    CustomerTracker c_tracker;
    TellerTracker t_tracker;
    int num_of_customers = 0;//total of customers
    double total_wait_time = 0;
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
