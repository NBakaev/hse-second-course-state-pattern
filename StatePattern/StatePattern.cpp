#include "stdafx.h"
#include <iostream>

using namespace std;

class Machine{
	class MachineActions *current;

  public:
    Machine();
	void setCurrent(MachineActions *s) {
        current = s;
    }

	int currentSpeed;

	 string getName();
	 int getMaxSpeed();
	 int getCurrentSpeed();

};


class MachineActions{
public:
	virtual void faster(Machine *m) = 0;
	virtual void slower(Machine *m) = 0;
	virtual string getName(Machine *m) = 0;
	virtual int getMaxSpeed(Machine *m) = 0;

};




string Machine::getName(){
	return current->getName(this);
}

int Machine::getMaxSpeed(){
	return current->getMaxSpeed(this);
}

int Machine::getCurrentSpeed(){
	return currentSpeed;
}


class DefaultMachine : public MachineActions , public Machine{
public:

	virtual string getName(Machine *m){
		return "DefaultMachine";
	}

	virtual void faster(Machine *m){
	}

	virtual void slower(Machine *m) {
	}

	virtual int getMaxSpeed(Machine *m){
		return maxSpeed;
	}

	private:
		int maxSpeed = 0;
};


class CoolCabriolet :  public Machine,  public MachineActions{
  public:
	  CoolCabriolet() {
        cout << "   You have choose CoolCabriolet ";
    };
	  ~CoolCabriolet()  {
        cout << "   You have broke CoolCabriolet :( ";
    };


	virtual string getName(Machine *m){
		return "CoolCabriolet";
	}

	virtual void faster(Machine *m){
		m->currentSpeed += 10;
	}

	virtual void slower(Machine *m) {
		m->currentSpeed -= 10;
	}

	virtual int getMaxSpeed(Machine *m){
		return maxSpeed;
	}

	private:
		int maxSpeed = 60;

};

class OldRussianCar : public MachineActions, public Machine
{
  public:
	  OldRussianCar()
    {
        cout << "   You have choose OldRussianCar ";
    };
	  ~OldRussianCar()
    {
        cout << "    You have broke OldRussianCar";
    };

	  virtual void faster(Machine *m){
		  m->currentSpeed += 3;
	  }

	  virtual void slower(Machine *m) {
		  m->currentSpeed -= 5;
	  }

	  virtual string getName(Machine *m){
		  return "OldRussianCar";
	  }

	  virtual int getMaxSpeed(Machine *m){
		  return maxSpeed;
	  }

	  

	private:
		int maxSpeed = 20;


};




Machine::Machine(){
}



void chooseCar(int car, Machine &fsm){
	if (car == 1){
		fsm.setCurrent(new CoolCabriolet() );
	}

	if (car == 2){
		fsm.setCurrent(new OldRussianCar);
	}

	if (car == 3){
		cout << "\n\n";
		cout << "\n\n Your car is: \n";
		cout << fsm.getName().c_str();
		system("pause");
		cout << "\n\n";
	}

	/*if (car == 4){
		cout << "\n\n";
		cout << "\n\n Your car is: \n";
		cout << fs;
		system("pause");
		cout << "\n\n";
	}

	if (car == 5){
		cout << "\n\n";
		cout << "\n\n Your car is: \n";
		cout << fsm.getName().c_str();
		system("pause");
		cout << "\n\n";
	}*/



}


int main(){

	Machine fsm = *new Machine();
	fsm.setCurrent(new DefaultMachine());

	string defaultMachine = "DefaultMachine";

  int num;
  while (1)
  {
	  system("cls");

	  if (fsm.getName().c_str() == defaultMachine){
		  cout << "You can press following key to choose car: ";
		  cout << "\n ";
		  cout << "1 - choose Cool Cabriolet";
		  cout << "\n ";
		  cout << "2 - choose old russian car";
		  cout << "\n ";
		  cin >> num;
		  chooseCar(num, fsm);

	  }
	  else{

		  if (fsm.getName().c_str() != defaultMachine){
			  cout << "You have a car";
			  cout << fsm.getName().c_str();
			  cout << "\n ";
			  cout << "\n ";

			  cout << "You can press following key to interact with car: ";
			  cout << "\n ";
			  cout << "3 - get name";
			  cout << "\n ";

			  cout << "1 - choose Cool Cabriolet";
			  cout << "\n ";
			  cout << "2 - choose old russian car";
			  cout << "\n ";
			  cin >> num;
			  cout << "\n ";

			  chooseCar(num, fsm);
		  }



	  }


	  }
}