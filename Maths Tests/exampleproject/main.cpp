#include "exampleprogram.h"

int main() {
	
	// allocation
	auto app = new exampleprogram();

	// initialise and loop
	app->run("example", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}