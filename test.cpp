// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>

#include "NumbersGenerator.h"

int main()
{
	fsm<NumbersGeneratorTransitions> numbersGenerator;

	try {
		numbersGenerator->Generate();
	}
	catch (fsm<NumbersGeneratorTransitions>::uninitialized ex)
	{
		printf("%s\n", ex.what());
	}
	try {
		printf("\nData %d\n", numbersGenerator.state().number);
	}
	catch (fsm<NumbersGeneratorTransitions>::uninitialized ex)
	{
		printf("%s\n", ex.what());
	}
	printf("\n>>>\n");
	numbersGenerator.move_to_state<StateOff>();
	printf("\nData %X\n", numbersGenerator.state().number);
	numbersGenerator->Start();
	printf("\nData %X\n", numbersGenerator.state().number);
	numbersGenerator->Generate();
	printf("\nData %d\n", numbersGenerator.state().number);
	numbersGenerator->Stop();
	printf("\nData %d\n", numbersGenerator.state().number);
	numbersGenerator->Generate();
	printf("\nData %d\n", numbersGenerator.state().number);
	printf("\n<<<\n");

	printf("\nCopy old to new\n");
	fsm<NumbersGeneratorTransitions> newone = numbersGenerator;
	printf("\nData %d\n", newone.state().number);
	printf("\n>>>\n");
	numbersGenerator.move_to_state<StateOff>();
	printf("\nData %X\n", newone.state().number);
	numbersGenerator->Start();
	printf("\nData %X\n", newone.state().number);
	numbersGenerator->Generate();
	printf("\nData %d\n", newone.state().number);
	numbersGenerator->Stop();
	printf("\nData %d\n", newone.state().number);
	numbersGenerator->Generate();
	printf("\nData %d\n", newone.state().number);
	printf("\n<<<\n");
	return 0;
}

