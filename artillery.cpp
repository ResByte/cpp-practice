//artillery.cpp
// Game with little physics
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int kNumShells = 10; // 10 shells per target
const int kMinDist = 200; // min distance for the target 
const int kMaxDist = 900; // max distance for a target
const double kVelocity = 200.0;
const double kGravity = 32.3;
const double kPi = 3.1415;


// returns the distance a shot travels 
int DistanceCalc(double in_angle){
	double time_in_air;
	// the following calculates how far the shot travels given 
	// its angle of projection, velocity and how long it stays in the air
	
	time_in_air = (2.0*kVelocity*sin(in_angle))/kGravity;
	return (int) round((kVelocity*cos(in_angle))*time_in_air);
}

// Get the user's angle input and calculates distance where shot lands.
//Returns the distance the shot lands

int CheckShot(){

	int distance; 
	double angle;
	cout << "What angle?" << endl;
	if(!(cin>>angle))
		return -1;

	//convert to radians
	angle = (angle * kPi) / 180.0;
	distance = DistanceCalc(angle);
	return distance;
}


//Generate random number for enemy position

int Initialize(){
	int enemy_position;
	
	//initialize random seed
	srand(time(NULL));

	//Generate random number between kMinDist and kMaxDist 
	enemy_position = rand() % kMaxDist + kMinDist;
	cout << "The enemy is " << enemy_position << " feet away!!! " << endl;
	return enemy_position;

}



//This function plays the game

int Fire(int number_killed){

	int enemy,shots,hit;
	int distance;
	
	//intialize variables
	shots = kNumShells;
	enemy = Initialize();
	distance = 0;
	hit = 0;

	do{
		// Get the distance where shot lands and compare it with the enemy position.
		distance = CheckShot();
		
		// some error checking on the input 
		if (distance == -1){
			cout << "Enter numbers only ..."<<endl;
			cin.clear();
			cin.ignore(10000,'\n');
			continue;
		} 
		// compare enemy position with the computed distance 
		if (abs(enemy - distance) <=1){
			hit = 1;
			number_killed++;
			cout << "You hit him!!"<< endl;
			cout << "It took you "<< kNumShells - shots + 1<< " shots ." << endl;
			cout << "You have killed " << number_killed << " enemies. " << endl;
		} else {
			shots--;
			if(distance > enemy){
				cout << "You over shot by "<< abs(enemy-distance) << endl;		
			} else {
				cout << "You under shot by "<< abs(enemy-distance) << endl;
			}

		}


	}while((shots > 0) && (!(hit)));

	if(shots == 0)
		cout << "You have run out of ammo ..." << endl;
	return number_killed;
}



int main(){
	int killed =0;
	char done; 
	cout << "Welcome to Artillery."<< endl;
	cout << "You killed" << killed << "of the enemy." << endl;
	do{
		killed = Fire(killed);
		cout << "I see another one care to take a shot again? (Y/N)" << endl;
		cin >> done;
	}while(done != 'n');
	
	cout << "You killed" << killed << "of the enemy." << endl;
	
	return 0;
}

