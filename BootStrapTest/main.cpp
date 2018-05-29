#include "BootStrapTestApp.h"

int main() {
	
	// allocation
	auto app = new BootStrapTestApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}