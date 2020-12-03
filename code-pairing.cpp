#include<bits/stdc++.h>
using namespace std;

class car {
  public:
   int base_distance, base_distance_charge, recurring_charge;
    int add_dist_charge,  total_ride_distance,  total_ride_charge;
  
    car(int base_distance, int base_distance_charge, int recurring_charge, int add_dist_charge, int total_ride_distance, int total_ride_charge)
    {
       this->base_distance=base_distance;
       this->base_distance_charge=base_distance_charge;
       this->recurring_charge=recurring_charge;
       this-> add_dist_charge=add_dist_charge;
       this->total_ride_distance=total_ride_distance;
       this-> total_ride_charge=total_ride_charge;
    }
    virtual int calculateFare(int distance) = 0;
};

class Mini: public car
{
   
    public:
    
    Mini(int base_distance, int base_distance_charge, int recurring_charge, int add_dist_charge, int total_ride_distance, int total_ride_charge):
    car (base_distance, base_distance_charge, recurring_charge, add_dist_charge, total_ride_distance, total_ride_charge)
    {
        
    }
     int calculateFare(int distance)
    {
        int fare_mini=0,temp=0;
        
        if(distance>total_ride_distance)
        {
            fare_mini= distance*total_ride_charge;
        }
        else if(distance<=base_distance)   
        {
            fare_mini=base_distance_charge; // base charges upto 3 km
        }
        else if(distance<=15+base_distance)
        {
            temp=distance-base_distance;
            fare_mini=50+ temp*10;
        }
        else if(distance>15+base_distance)
        {
            temp=distance-(15+base_distance);
            fare_mini=base_distance_charge + recurring_charge*15 +temp*8;
            // for additional 15km distance
        }
        return fare_mini;
    }
};

class Sedan: public car
{
    private:
    
    public:
    Sedan(int base_distance, int base_distance_charge, int recurring_charge, int add_dist_charge, int total_ride_distance, int total_ride_charge):
    car (base_distance, base_distance_charge, recurring_charge, add_dist_charge, total_ride_distance, total_ride_charge)
    {
       
    }
     int calculateFare(int distance)
    {
         int fare_sedan=0,temp=0;
        if(distance>total_ride_distance)
        {
            fare_sedan= distance*total_ride_charge;
        }
        else if(distance<=base_distance)
        {
            fare_sedan=base_distance_charge;
        }
        else if(distance<=(15+base_distance))
        {
            temp=distance-base_distance;
            fare_sedan=base_distance_charge + temp*recurring_charge;
        }
        else if(distance>15+base_distance)
        {
            temp=distance-(15+base_distance);
            fare_sedan=base_distance_charge +15*recurring_charge + temp*10;
        }   
        return fare_sedan;
    }
};

class SUV: public car
{
    private:
    
    public:
    SUV(int base_distance, int base_distance_charge, int recurring_charge, int add_dist_charge, int total_ride_distance, int total_ride_charge):
    car (base_distance, base_distance_charge, recurring_charge, add_dist_charge, total_ride_distance, total_ride_charge)
    {
        
    }
    int calculateFare(int distance)
    {
         int fare_suv=0, temp=0;
    
         if(distance<=base_distance)
        {
            fare_suv=base_distance_charge;
        }
        else if( distance<=(15+base_distance))
        {
            temp=(distance-base_distance);
            fare_suv=base_distance_charge+ temp*recurring_charge;
        }
        else if(distance>(15+base_distance))
        {
            temp=distance-(15+base_distance);
            fare_suv=base_distance_charge +recurring_charge*15+temp*add_dist_charge;
        }
        return fare_suv;
    }
};

class Booking
{
   public:
   unordered_map<string, int>bookings;
   Booking()
   {
       
   }
   double calculateDiscountedFair(string number, int distance, int total_fare)
   {
       double discount=0;
       
       if(bookings.count(number))
       {
           if(bookings[number]%2==0)
           {
               discount=0.1*total_fare;
           }
       }
       else
       {
            discount=0.25*total_fare;
       }
       double ans = double(total_fare) - discount;
       bookings[number]++;
       return ans;
   }
   
};







// Input ::
// 10
// 8448562808
// 10
// 20
// 80







   
int main()
{
    // calCulate fair example
    
    int distance;
    car *car1= new Mini(3, 50,10, 8,75,8);
    car *car2= new Sedan(5, 80,12, 10,100,10);
    car *car3= new SUV(5, 100,15, 12,-1,-1);
    cin>>distance;
    cout<<"Mini -Rs."<<car1->calculateFare(distance)<<" Sedan - Rs."<<car2->calculateFare(distance)<<" SUV - Rs."<<car3->calculateFare(distance) << endl;
    
    // calculate discounted fair example

    Booking car_booking1, car_booking2, car_booking3;

    string number;
    int dis1,dis2,dis3;
    cin >> number >> dis1 >> dis2 >> dis3;
    int total_fair1 = car1->calculateFare(dis1);
    int total_fair2 = car2->calculateFare(dis1);
    int total_fair3 = car3->calculateFare(dis1);
    int total_fair4 = car1->calculateFare(dis2);
    int total_fair5 = car2->calculateFare(dis2);
    int total_fair6 = car3->calculateFare(dis2);
    int total_fair7 = car1->calculateFare(dis3);
    int total_fair8 = car2->calculateFare(dis3);
    int total_fair9 = car3->calculateFare(dis3);
    cout << "discounted fair for car1: " << car_booking1.calculateDiscountedFair(number,dis1,total_fair1) << " "  << "discounted fair for car2: " << car_booking2.calculateDiscountedFair(number,dis1,total_fair2) << " " << "discounted fair for car3: " << car_booking3.calculateDiscountedFair(number,dis1,total_fair3) << endl; 
    cout << "discounted fair for car1: " << car_booking1.calculateDiscountedFair(number,dis2,total_fair4) << " "  << "discounted fair for car2: " << car_booking2.calculateDiscountedFair(number,dis2,total_fair5) << " " << "discounted fair for car3: " << car_booking3.calculateDiscountedFair(number,dis2,total_fair6) << endl; 
    cout << "discounted fair for car1: " << car_booking1.calculateDiscountedFair(number,dis3,total_fair7) << " "  << "discounted fair for car2: " << car_booking2.calculateDiscountedFair(number,dis3,total_fair8) << " " << "discounted fair for car3: " << car_booking3.calculateDiscountedFair(number,dis3,total_fair9) << endl; 
    
    return 0;
}