#include "Application2D.h"
#include "TestGame.h"
int main() {
	
	// allocation
	auto app = new TestGame();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}