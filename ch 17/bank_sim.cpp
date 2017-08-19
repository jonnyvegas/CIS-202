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

bool gen_customer(int);
//void print_array(int* c);
void process_line(list<Customer>&,vector<Teller>&,int, double&, int&, int&, bool);
void print_list(list<Customer>);

const int TOTAL_TIME = 60*60*8;//8 hours in seconds. Probably how long the branch is open.
const int TELLERS = 4;

int main()
{
    Customer c;
    double num_of_customers = 0;//total of customers
    double total_wait_time = 0;
    int smallest, largest;
    bool first = true;
    cout << time(0) << endl;
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
            //total_wait_time = c.getTime() + total_time;
            print_list(bank_line);

        }
        //cout << "There are " << bank_line.size() << " customers in line. " << endl;
        process_line(bank_line,tellers,time_elapsed, total_wait_time, smallest, largest, first);//passes line, tellers, and the time elapsed
        if(first)
        {
            first = false;
        }
	}
	cout << "after " <<  (TOTAL_TIME/60/60) <<   " hours there are " << bank_line.size() << " customers in the line" << endl;
    cout << "Average: " << total_wait_time / num_of_customers  << " seconds per customer." << endl;
    cout << "Smallest wait time: " << smallest << " seconds." << endl;
    cout << "Largest wait time: " << largest << " seconds." << endl;
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
                  double& total_wait_time, int& smallest, int& largest, bool first)
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
            //cout << "adding customer, bankline size = " << bankline.size()<< endl;
            //cout << "Processing time: " << r << " ";
            //cout << "waiting time: " << c_cust.waitTime(ctime) << endl;
            total_wait_time = c_cust.waitTime(ctime) + total_wait_time;
            cout << "Wait time: " << c_cust.waitTime(ctime) << endl;
            if(first)
            {
                smallest = c_cust.waitTime(ctime);
                largest = c_cust.waitTime(ctime);
            }
            else
            {
                if(c_cust.waitTime(ctime) < smallest)
                {
                    smallest = c_cust.waitTime(ctime);
                }
                else if(c_cust.waitTime(ctime) > largest)
                {
                    largest = c_cust.waitTime(ctime);
                }
            }
            bankline.pop_front();
        }
        if(tellers[i].hasCustomer() && tellers[i].processed(ctime))
        {
            tellers[i].releaseCustomer();
            //cout << "Process time: " << tellers[i].getProcessTime() << " ";

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
