#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "events.h"
#include "ShipData.h"
/*klasa obiektów event - zdarzenie*/
class Event {
public:
	int Weight;
	std::string EventText;
	std::string EventName;
	virtual void EventEffect(ShipData& Ship, bool YesNo) {
		std::cout << "This isnt supposed to appear" << "\n";
	}
};

void CallEvent(Event& CalledEvent, ShipData& Ship);
void EventRandomizer(std::vector<Event*>& EventVector, ShipData& Ship);


