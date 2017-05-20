#pragma once
#include "fsm.h"

struct Data
{
	int number;
	Data() : number(0xdeadbeef) {}
};



struct NumbersGeneratorTransitions : public impl_ctx<NumbersGeneratorTransitions, Data>
{
	virtual void Start() {}
	virtual void Stop() {}
	virtual void Generate() {
	}
};

struct StateOff : public impl_state<StateOff, NumbersGeneratorTransitions>
{
	virtual void Start();
};

struct StateOn : public impl_state<StateOn, NumbersGeneratorTransitions>
{
	virtual void Stop();
	virtual void Generate();
};
