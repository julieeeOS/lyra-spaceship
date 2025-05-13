#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "events.h"
#include "ShipData.h"

int main() {
	/*ship status declaration*/
	ShipData Ship;
	Ship.health = 100;
	Ship.energy = 30;
	Ship.materials = 50;
	Ship.data = 0;
	Ship.exotic_matter = 30;

	/*Declaration of event vector and events*/
	std::vector<Event*> AllEvents;
	class Event1 : public Event {
	public:
		int Weight = 3;
		std::string EventName = "one";
		std::string EventText = "Gather materials or data";
		void EventEffect(ShipData& Ship, bool YesNo) override {
			if (YesNo) {
				Ship.materials += 10;
			}
			else {
				Ship.data += 10;
			}
		}
	} one;
	AllEvents.push_back(&one);
	/*
	Event1 one;
	one.Weight = 3;
	one.EventName = "one";
	one.EventText = "Gather materials or data";
	AllEvents.push_back(&one);
	*/
	class Event2 : public Event {
	public:
		void EventEffect(ShipData& Ship, bool YesNo) override {
			if (YesNo) {
				Ship.energy += 10;
			}
			else {
				Ship.exotic_matter += 10;
			}
		}
	};
	Event2 two;
	two.Weight = 2;
	two.EventName = "two";
	two.EventText = "Extract energy or exotic matter";
	AllEvents.push_back(&two);

	class Event3 : public Event {
	public:
		void EventEffect(ShipData& Ship, bool YesNo) override {
			if (YesNo) {
				Ship.materials -= 15;
				Ship.energy += 5;
				Ship.health += 5;
			}
			else {
				Ship.health -= 10;
				Ship.energy -= 10;
			}
		}
	};
	Event3 three;
	three.Weight = 2;
	three.EventName = "three";
	three.EventText = "Fix ship?";
	AllEvents.push_back(&three);

	class Event4 : public Event {
	public:
		void EventEffect(ShipData& Ship, bool YesNo) override {
			if (YesNo) {
				Ship.exotic_matter -= 5;
				Ship.data += 10;
			}
			else {
				Ship.data -= 5;
			}
		}
	};
	Event4 four;
	four.Weight = 1;
	four.EventName = "four";
	four.EventText = "Perform a jump?";
	AllEvents.push_back(&four);

	class Event5 : public Event {
	public:
		void EventEffect(ShipData& Ship, bool YesNo) override {
			if (YesNo) {
				Ship.health -= 100;
			}
			else {
				Ship.health += 1;
			}
		}
	};
	Event5 kill;
	kill.Weight = 3;
	kill.EventName = "kills u";
	kill.EventText = "Die?";
	AllEvents.push_back(&kill);
	

	while (Ship.health > 0 && Ship.energy > 0) {
		std::cout << "Health: " << Ship.health << "\n";
		std::cout << "Energy: " << Ship.energy << "\n";
		std::cout << "Materials: " << Ship.materials << "\n";
		std::cout << "Data: " << Ship.data << "\n";
		std::cout << "Exotic Matter: " << Ship.exotic_matter << "\n";
		if (Ship.health > 100) {
			Ship.health = 100;
		}
		if (Ship.energy > 200) {
			Ship.energy = 200;
		}
		EventRandomizer(AllEvents, Ship);
	}
	std::cout << "You lose! End status: " << "\n";
	std::cout << "Health: " << Ship.health << "\n";
	std::cout << "Energy: " << Ship.energy << "\n";
	std::cout << "Materials: " << Ship.materials << "\n";
	std::cout << "Data: " << Ship.data << "\n";
	std::cout << "Exotic Matter: " << Ship.exotic_matter << "\n";
	

	

	//CallEvent(*AllEvents[0], Ship);
	//Event* Ptr[4];
	//Ptr[0] = &one;
	//Ptr[0]->EventEffect(Ship, true);
	//AllEvents[0]->EventEffect(Ship, true);

	return 0;
}