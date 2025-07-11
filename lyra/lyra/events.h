﻿#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ShipData.h"
/*klasa obiektów event - zdarzenie*/
class Event {
public:
	int Weight;
	std::string EventText;
	std::string EventName;
	virtual void EventEffect(ShipData& Ship, bool YesNo) {
		std::cout << "This isnt supposed to appear" << "\n";
	};
	virtual bool EventCondition(std::vector<Event*> EventVector, ShipData Ship) {
		return true;
	};
};

void CallEvent(Event& CalledEvent, ShipData& Ship);
void EventRandomizer(std::vector<Event*> EventVector, std::vector<Event*>& Previous, ShipData& Ship);
void WeightIncrement(std::vector<Event*>& EventVector);


