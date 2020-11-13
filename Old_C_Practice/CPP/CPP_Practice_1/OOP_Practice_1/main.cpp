#include <windows.h>
#include <Resource.h>
// 
using namespace std;
//
int main() {
	//	GAME CLOCK : TICK = 1000ms
	int tickRate = 750;
	int tickCount = 0;
	//	INITIALIZE RESOURCES
	Resource wood;
	Resource ore;
	wood.setName("Wood");
	ore.setName("Ore");
	//	GAME LOOP
	while(1) {
		//	CLEAR SCREEN
		system("CLS");
		//	UPDATE DATA
		++tickCount;
		if(tickCount % 10 == 0) {
			wood.incrementAmount();
			ore.incrementAmount();	
		}		
		if(tickCount % 250 == 0) {
			wood.incrementMod();
			ore.incrementMod();
		}				
		//	UPDATE DISPLAY
		wood.printResource();
		ore.printResource();
		Sleep(tickRate/10);
	}
	return 0;
}

/*
system("CLS");
		tickCount++;
		for(Resource *r: {wood, ore}) {
			if(tickCount % 10 == 0) r.incrementAmount();
			if(tickCount % 250 == 0) r.incrementMod();
			r.printResource();
		}
		Sleep(tickRate/10);
	}
*/
/*

*/