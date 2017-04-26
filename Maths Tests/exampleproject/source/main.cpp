#include "exampleprogram.h"

int main() {
	
	// allocation
	auto app = new exampleprogram();

	// initialise and loop
    // set to 1080p and fullscreen
	app->run("example", 1920, 1080, true);

	// deallocation
	delete app;

	return 0;
}