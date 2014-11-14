// byref.cpp 
// program to illustrate pass by reference 

#include <iostream>

using namespace std;

// speed is passed by refernce 
void accelerate(int& speed, int amount){
	speed = speed + amount;
}

int main(){
	int current_speed = 0;
	int accel_amount;

	cout << "current speed "<< current_speed << endl;
	cout << " Accelerate by how much" << endl;
	cin >> accel_amount;

	accelerate(current_speed, accel_amount);
	cout << "acclerated speed : "<< current_speed << endl;
 
	return 0;
}
