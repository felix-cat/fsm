#include "NumbersGenerator.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>

void StateOff::Start()
{
	printf("\nEndtered StateOff::Start()\n");
	static bool first_seed = true;
	// init random number (with simplified seed)

	if (first_seed)
	{
		first_seed = false;
		std::srand((unsigned int)time(0));
	}
	// the next state:

	change_state<StateOn>();
}

void StateOn::Stop()
{
	printf("\nEndtered StateOn::Stop()\n");
	change_state<StateOff>();
}

void StateOn::Generate()
{	//just generate random number and put it in data

	printf("\nEndtered StateOn::Generate()\n");
	state().number = std::rand() % 100; //Pick a number between 0-100

	//state is not changed
}
