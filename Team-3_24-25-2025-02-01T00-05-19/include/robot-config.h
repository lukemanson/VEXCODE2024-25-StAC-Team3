using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor fl;
extern motor fr;
extern motor bl;
extern motor br;
extern controller Controller1;
extern motor intake;
extern motor intake_spinner;
extern digital_out grabber_pneumatics;
extern digital_out grabber_pneumatics2;
extern optical optical7;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );