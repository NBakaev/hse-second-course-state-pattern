HSE 13PI Second course "State Pattern"
===============================
Created by Bakaev Nikita

Sorry for my English

## How does it work?

We have class `Machine` which has field `current` which contains Class which implemented `IMachineActions` interfase.

And we have two implementation of the `IMachineActions`:

- **DefaultMachine** - You can't do anything with this car. You should choose another to continie
- **CoolCabriolet** - It's a *good* car. It's for you, bro.
- **OldRussianCar** - It's a *bad* car. It's for, bro.

## How to use ???
Create with public constructor and `setCurrent` which get an object implementing `IMachineActions`

Depends of implementaion, you will have different max speed of the car, changes in the number of speed when you call the slow and fast.
 

    Machine fsm = *new Machine();
    fsm.setCurrent(new DefaultMachine());

## IMachineActions
You should override following methods to creat and implementation of the interface:

	virtual bool faster ()
	virtual bool slower()
	virtual string getName()
	virtual int getMaxSpeed()


### That's all