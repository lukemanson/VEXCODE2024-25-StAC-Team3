#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor fl = motor(PORT2, ratio18_1, false);
motor fr = motor(PORT1, ratio18_1, true);
motor bl = motor(PORT3, ratio18_1, false);
motor br = motor(PORT4, ratio18_1, true);
controller Controller1 = controller(primary);
motor intake = motor(PORT6, ratio6_1, false);
motor intake_spinner = motor(PORT5, ratio18_1, true);
digital_out grabber_pneumatics = digital_out(Brain.ThreeWirePort.A);
digital_out grabber_pneumatics2 = digital_out(Brain.ThreeWirePort.B);
optical optical7 = optical(PORT7);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}