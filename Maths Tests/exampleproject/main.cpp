#include "exampleprogram.h"

int main() {
	
	// allocation
	auto app = new exampleprogram();

	// initialise and loop
	app->run("example", 1920, 1080, true);

	// deallocation
	delete app;

	return 0;
}