#include<iostream>
using namespace std;
int main(){
    int selling_price , cost_price;
    int profit = selling_price-cost_price;
    int loss= cost_price-selling_price;

    int profit_percentage= (profit/cost_price)*100;
    int loss_percentage= (loss/cost_price)*100;
    cout<<"Enter the selling price of the product";
    cin>>selling_price;
    cout<<"Enter the cost price of the product";
    cin>>cost_price;
    if (selling_price<cost_price){
        cout<<"The loss has occured ! and the loss is :"<<loss;
        
    }
else if(cost_price<selling_price){
    cout<<"The profit has occured ! and the profit is :"<<profit;
    cout<<"The profit percentage is :"<<profit_percentage;
}
else{
    cout<<"No profit no loss";
    cout<<"The loss percentage is :"<<loss_percentage;
}
}
