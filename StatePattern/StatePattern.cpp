#include "stdafx.h"
#include <iostream>

using namespace std;


/*
This is class which has property "current" which 'contain' (really just link) object which realise interface "IMachineActions"
*/
class Machine{
	class IMachineActions *current;

public:
	Machine();

	void setCurrent(IMachineActions *injectedCurrentState) {
		current = injectedCurrentState;
	}

	int currentSpeed;

	string getName();
	int getMaxSpeed();
	int getCurrentSpeed();
	bool faster();
	bool slower();

};

/*
In normal languages it should be just interface but...
*/
class IMachineActions{
public:
	virtual bool faster(Machine *injectedCurrentMachineState) = 0;
	virtual bool slower(Machine *injectedCurrentMachineState) = 0;
	virtual string getName(Machine *injectedCurrentMachineState) = 0;
	virtual int getMaxSpeed(Machine *injectedCurrentMachineState) = 0;
};



/*
Default constructor - may be interesting in some cases
*/
Machine::Machine(){
}



/*
Implementing methods of the object "Machine"
*/
string Machine::getName(){
	return current->getName(this);
}

int Machine::getMaxSpeed(){
	return current->getMaxSpeed(this);
}

int Machine::getCurrentSpeed(){
	return currentSpeed;
}

bool Machine::faster(){
	return current->faster(this) ;
}

bool Machine::slower(){
	return current->slower(this);
}


/*
Default car - can't ride and hasn't any actions like lada calina :)
*/

class DefaultMachine : public IMachineActions{
	public:

		virtual string getName(Machine *injectedCurrentMachineState){
			return name;
		}

		virtual bool faster(Machine *injectedCurrentMachineState){
			return false;
		}

		virtual bool slower(Machine *injectedCurrentMachineState){
			return false;
		}

		virtual int getMaxSpeed(Machine *injectedCurrentMachineState){
			return maxSpeed;
		}

	private:
		int maxSpeed = 0;
		string name = "DefaultMachine";
};


/*
Realisation of CoolCabriolet; Implementing IMachineActions
*/
class CoolCabriolet : public IMachineActions{
public:
	CoolCabriolet() {
		cout << "You have choosed CoolCabriolet";
	};
	~CoolCabriolet()  {
		cout << "You broked CoolCabriolet :( ";
	};


	virtual string getName(Machine *injectedCurrentMachineState){
		return name;
	}

	virtual bool faster(Machine *injectedCurrentMachineState){
		if (maxSpeed > injectedCurrentMachineState->getCurrentSpeed()){
			injectedCurrentMachineState->currentSpeed += 10;
			return true;
		}

		return false;
	}

	virtual bool slower(Machine *injectedCurrentMachineState) {
		if (injectedCurrentMachineState->getCurrentSpeed() - 10 >= 0){
			injectedCurrentMachineState->currentSpeed -= 10;
			return true;
		}

		return false;
	}

	virtual int getMaxSpeed(Machine *injectedCurrentMachineState){
		return maxSpeed;
	}

private:
	int maxSpeed = 60;
	string name = "CoolCabriolet";

};


/*
Realisation of OldRussianCar; Implementing IMachineActions
*/
class OldRussianCar : public IMachineActions
{
	public:
		OldRussianCar(){
			cout << "   You have choose OldRussianCar ";
		};

		~OldRussianCar(){
			cout << "    You have broke OldRussianCar";
		};

		virtual bool faster(Machine *injectedCurrentMachineState){
			if (maxSpeed > injectedCurrentMachineState->getCurrentSpeed()){
				injectedCurrentMachineState->currentSpeed += 5;
				return true;
			}

			return false;
		}

		virtual bool slower(Machine *injectedCurrentMachineState) {
			if (injectedCurrentMachineState->getCurrentSpeed() - 5 >= 0){
				injectedCurrentMachineState->currentSpeed -= 5;
				return true;
			}

			return false;
		}

		virtual string getName(Machine *injectedCurrentMachineState){
			return name;
		}

		virtual int getMaxSpeed(Machine *injectedCurrentMachineState){
			return maxSpeed;
		}


	private:
		int maxSpeed = 20;
		string name = "OldRussianCar";
};






void chooseCar(int car, Machine &fsm){
	if (car == 1){
		fsm.setCurrent(new CoolCabriolet());
	}

	if (car == 2){
		fsm.setCurrent(new OldRussianCar);
	}

	if (car == 3){
		cout << "\n\n";
		cout << "\n\n Your car is: ";
		cout << fsm.getName().c_str();
		cout << "\n\n";
		system("pause");
		cout << "\n\n";
	}

	
	if (car == 4){
	cout << "\n\n";
	cout << "\n\n Your car speed is : ";
	cout << fsm.getCurrentSpeed();
	cout << "\n\n";
	system("pause");
	cout << "\n\n";
	}

	if (car == 5){
		if (fsm.faster()){
			cout << "\n\n";
			cout << "\n\n Your car speed is increased and now it is: ";
			cout << fsm.getCurrentSpeed();
			cout << "\n\n";
			system("pause");
			cout << "\n\n";
		}
		else
		{
			cout << "can't faster \n Sorry. bro :(";
			cout << "\n\n";
			system("pause");
		}
	}

	if (car == 6){
		if (fsm.slower()){
			cout << "\n\n";
			cout << "\n\n Your car speed is decreased and now it is: ";
			cout << fsm.getCurrentSpeed();
			cout << "\n\n";
			system("pause");
			cout << "\n\n";
		}
		else{
			cout << "can't slower \n Sorry. bro :(";
			cout << "\n\n";
			system("pause");
		}
		
	}



}


/*
This is just demo that's why code may be not so beautiful
*/

int main(){

	Machine fsm = *new Machine();
	fsm.setCurrent(new DefaultMachine());

	string defaultMachine = fsm.getName();

	int num;
	while (1)
	{
		system("cls");

		if (fsm.getName().c_str() == defaultMachine){
			cout << "You can press following key to choose car: ";
			cout << "\n";
			cout << " 1 - choose Cool Cabriolet \n";
			cout << " 2 - choose old russian car \n";

			cin >> num;
			chooseCar(num, fsm);

		}
		else{

			if (fsm.getName().c_str() != defaultMachine){
				cout << "----------------------------------\n";
				cout << "You have a car:  ";
				cout << fsm.getName().c_str();
				cout << "\nMax speed is:  " << fsm.getMaxSpeed();
				cout << "\n\n\n";
				cout << "----------------------------------\n";

				cout << "\n";

				cout << "You can press following key to interact with car: \n";
				cout << " 3 - get name \n";
				cout << " 4 - get current speed \n";
				cout << " 5 - ride faster \n";
				cout << " 6 - ride slower \n";
				cout << "----------------------------------\n";

				cout << "\n";

				cout << "        Or you can choose another car\n";
				cout << " 1 - choose Cool Cabriolet \n";
				cout << " 2 - choose old russian car \n";
				cout << "----------------------------------\n";

				cout << "\n ";
				cin >> num;
				cout << "\n ";

				chooseCar(num, fsm);
			}



		}


	}
}