# TW-Coding-challenge

Solution Link:
https://ide.geeksforgeeks.org/eiYNAnvn80

#include<bits/stdc++.h>
using namespace std;
void calculateFare(int distance)
{
    //Mini
    int fare_mini=0,temp=0;
    if(distance>75)
    {
        fare_mini= distance*8;
    }
    else if(distance<=3)
    {
        fare_mini=50;
    }
    else if(distance>3 && distance<=18)
    {
        temp=distance-3;
        fare_mini=50+ temp*10;
    }
    else if(distance>18)
    {
        temp=distance-18;
        fare_mini=50+150+temp*8;
    }
   
    // Sedan
    int fare_sedan=0,temp1=0;
    if(distance>100)
    {
        fare_sedan= distance*10;
    }
    else if(distance<=5)
    {
        fare_sedan=80;
    }
    else if(distance>5 && distance<=20)
    {
        temp=distance-5;
        fare_sedan=80+ temp*12;
    }
    else if(distance>20)
    {
        temp=distance-20;
        fare_sedan=80+180+temp*10;
    }
    
    
    //SUV
    int fare_suv=0, temp2=0;
    
     if(distance<=5)
    {
        fare_suv=100;
    }
    else if(distance>5 && distance<=20)
    {
        temp=distance-5;
        fare_suv=100+ temp*15;
    }
    else if(distance>20)
    {
        temp=distance-20;
        fare_suv=100+225+temp*12;
    }
     cout<<"Mini- Rs."<<fare_mini<<" "<<"Sedan- Rs."<<fare_sedan<<" "<<"SUV- Rs."<<fare_suv;
    
}
int main()
{
    int distance;
    cin>>distance;
    calculateFare(distance);
    return 0;
}
