/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// fl                   motor         2               
// fr                   motor         1               
// bl                   motor         3               
// br                   motor         4               
// Controller1          controller                    
// intake               motor         6               
// intake_spinner       motor         5               
// grabber_pneumatics   digital_out   A               
// grabber_pneumatics2  digital_out   B               
// optical7             optical       7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// Define your global instances of motors and other devices here
float drive_power = 1;
bool l_wing_in = true;
bool r_wing_in = true;
bool goal_grabbed = false;
bool isRed = true;
bool isPos = true;
bool isAWP = true;
bool brainPressed = false;

// Colour sensor function
void senseColour(void) {
  Brain.Screen.clearScreen();
  double hue = optical7.hue();
  if (320 > hue and hue > 40 == 0) {
    intake.setVelocity(50, percent);
    intake_spinner.setVelocity(50, percent);
  } else if (145 < hue and hue < 225) {
    intake.setVelocity(-50, percent);
    intake_spinner.setVelocity(-50, percent);
  }
}

// Functions for driving
void driveForwardOrBack(int drivePower) {
  fl.setVelocity(drivePower, percent);
  fr.setVelocity(drivePower, percent);
  bl.setVelocity(drivePower, percent);
  br.setVelocity(drivePower, percent);
}
void driveLeftOrRight(int turnPower) {
  fl.setVelocity(turnPower, percent);
  fr.setVelocity(-turnPower, percent);
  bl.setVelocity(turnPower, percent);
  br.setVelocity(-turnPower, percent);
}

bool goal_grab(bool goal_grabbed) {
  if (goal_grabbed) {
    grabber_pneumatics.set(false);
    grabber_pneumatics2.set(false);
    goal_grabbed = false;
    wait(0.5, sec);
  } else {
    grabber_pneumatics.set(true);
    grabber_pneumatics2.set(true);
    goal_grabbed = true;
    wait(0.5, sec);
  }
  return goal_grabbed;
}

void auton_blue_negative(void) {
  // Autonomous Program for positioning on the Blue Alliance Negative Corner area
  driveForwardOrBack(-50);
  wait(1.8, sec);
  driveForwardOrBack(0);
  goal_grabbed = goal_grab(goal_grabbed);
  driveForwardOrBack(50);
  wait(0.2, sec);
  driveForwardOrBack(0);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1, sec);
  driveLeftOrRight(20);
  intake.setVelocity(75, percent);
  wait(0.8, sec);
  intake.setVelocity(-75, percent);
  wait(0.35, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(50);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1.2, sec);
  driveForwardOrBack(0);
  wait(0.5, sec);
  intake_spinner.setVelocity(100, percent);
  wait(1.5, sec);
  intake.setVelocity(0, percent);
  intake_spinner.setVelocity(0, percent);
  driveLeftOrRight(-50);
  wait(0.6, sec);
  driveForwardOrBack(-75);
  wait(0.35, sec);
  driveForwardOrBack(0);
  // driveLeftOrRight(20);
  // wait(1.1, sec);
  // driveLeftOrRight(0);
  // driveForwardOrBack(50);
  // intake.setVelocity(-75, percent);
  // intake_spinner.setVelocity(-100, percent);
  // wait(0.7, sec);
  // driveForwardOrBack(0);
  // wait(5, sec);
  // intake.setVelocity(0, percent);
  // intake_spinner.setVelocity(0, percent);
}

void auton_red_negative(void) {
  // Autonomous Program for positioning on the Red Alliance Negative Corner area
  driveForwardOrBack(-50);
  wait(1.8, sec);
  driveForwardOrBack(0);
  goal_grabbed = goal_grab(goal_grabbed);
  driveForwardOrBack(50);
  wait(0.2, sec);
  driveForwardOrBack(0);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1, sec);
  driveLeftOrRight(-20);
  intake.setVelocity(75, percent);
  wait(0.8, sec);
  intake.setVelocity(-75, percent);
  wait(0.35, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(50);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1.2, sec);
  driveForwardOrBack(0);
  wait(0.5, sec);
  intake_spinner.setVelocity(100, percent);
  wait(1.5, sec);
  intake.setVelocity(0, percent);
  intake_spinner.setVelocity(0, percent);
  driveLeftOrRight(50);
  wait(0.6, sec);
  driveForwardOrBack(-75);
  wait(0.35, sec);
  driveForwardOrBack(0);
  // intake.setVelocity(-100, percent);
  // intake_spinner.setVelocity(-100, percent);
  // wait(1.1, sec);
  // driveForwardOrBack(0);
  // wait(5, sec);
  // intake.setVelocity(0, percent);
  // intake_spinner.setVelocity(0, percent);
}

void auton_blue_negative_awp(void) {
  driveForwardOrBack(-50);
  intake_spinner.setVelocity(100, percent);
  wait(1.05, sec);
  driveForwardOrBack(0);
  driveLeftOrRight(40);
  wait(0.7, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(-40);
  wait(0.7, sec);
  intake.setVelocity(-100, percent);
  wait(0.8, sec);
  intake.setVelocity(100, percent);
  wait(0.25, sec);
  intake.setVelocity(0, percent);
  driveForwardOrBack(20);
  wait(0.95, sec);
  driveForwardOrBack(0);
  driveLeftOrRight(-60);
  wait(1.03, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(-70);
  wait(1.3, sec);
  driveForwardOrBack(0);
  wait(0.2, sec);
  goal_grabbed = goal_grab(goal_grabbed);
  wait(1, sec);
  driveLeftOrRight(75);
  wait(0.53, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(70);
  intake.setVelocity(-100, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(0.3, sec);
  driveForwardOrBack(0);
  wait(3, sec);
  driveLeftOrRight(-60);
  wait(0.78, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(90);
  wait(0.9, sec);
  driveForwardOrBack(0);
}

void auton_red_negative_awp(void) {
  driveForwardOrBack(-50);
  intake_spinner.setVelocity(100, percent);
  wait(1.1, sec);
  driveForwardOrBack(0);
  driveLeftOrRight(-40);
  wait(0.7, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(-40);
  wait(0.7, sec);
  intake.setVelocity(-100, percent);
  wait(0.8, sec);
  intake.setVelocity(100, percent);
  wait(0.25, sec);
  intake.setVelocity(0, percent);
  driveForwardOrBack(20);
  wait(0.95, sec);
  driveForwardOrBack(0);
  driveLeftOrRight(60);
  wait(1.03, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(-70);
  wait(1.3, sec);
  driveForwardOrBack(0);
  wait(0.2, sec);
  goal_grabbed = goal_grab(goal_grabbed);
  wait(1, sec);
  driveLeftOrRight(-75);
  wait(0.53, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(70);
  intake.setVelocity(-100, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(0.3, sec);
  driveForwardOrBack(0);
  wait(3, sec);
  driveLeftOrRight(60);
  wait(0.78, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(90);
  wait(0.9, sec);
  driveForwardOrBack(0);
}

void skills(void) {
  intake.setVelocity(-100, percent);
  intake_spinner.setVelocity(-100, percent);
  driveForwardOrBack(-40);
  wait(1, sec);
  intake.setVelocity(100, percent);
  driveForwardOrBack(40);
  wait(0.7, sec);
  intake.setVelocity(-100, percent);
  driveLeftOrRight(50);
  wait(0.5, sec);
  driveForwardOrBack(-80);
  wait(0.4, sec);
  driveForwardOrBack(0);
  wait(0.5, sec);
  goal_grabbed = goal_grab(goal_grabbed);
  wait(0.5, sec);
  driveLeftOrRight(40);
  wait(1.3, sec);
  driveForwardOrBack(50);
  wait(1, sec);
  driveForwardOrBack(30);
  wait(1.5, sec);
  driveForwardOrBack(0);
  wait(1, sec);
  driveForwardOrBack(-50);
  wait(1.2, sec);
  driveForwardOrBack(0);
  wait(0.5, sec);
  driveLeftOrRight(-20);
  wait(0.5, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(40);
  wait(1, sec);
  driveForwardOrBack(0);
  wait(1.5, sec);
  driveLeftOrRight(-50);
  wait(1, sec);
  driveForwardOrBack(-50);
  wait(1, sec);
  driveForwardOrBack(0);
  goal_grabbed = goal_grab(goal_grabbed);
  wait(0.5, sec);
  driveForwardOrBack(50);
  wait(1, sec);
  driveForwardOrBack(0);
}


void auton_blue_positive(void) {
  // Autonomous Program for positioning on the Red Alliance Negative Corner area
  driveForwardOrBack(-50);
  wait(1.8, sec);
  driveForwardOrBack(0);
  goal_grabbed = goal_grab(goal_grabbed);
  driveForwardOrBack(50);
  wait(0.2, sec);
  driveForwardOrBack(0);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1, sec);
  driveLeftOrRight(-20);
  intake.setVelocity(75, percent);
  wait(0.8, sec);
  intake.setVelocity(-75, percent);
  wait(0.35, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(50);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1.2, sec);
  driveForwardOrBack(0);
  wait(0.5, sec);
  intake_spinner.setVelocity(100, percent);
  wait(4, sec);
  intake.setVelocity(0, percent);
  intake_spinner.setVelocity(0, percent);
}

void auton_red_positive(void) {
  // Autonomous Program for positioning on the Blue Alliance Negative Corner area
  driveForwardOrBack(-50);
  wait(1.8, sec);
  driveForwardOrBack(0);
  goal_grabbed = goal_grab(goal_grabbed);
  driveForwardOrBack(50);
  wait(0.2, sec);
  driveForwardOrBack(0);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1, sec);
  driveLeftOrRight(20);
  intake.setVelocity(75, percent);
  wait(0.8, sec);
  intake.setVelocity(-75, percent);
  wait(0.35, sec);
  driveLeftOrRight(0);
  driveForwardOrBack(50);
  intake.setVelocity(-75, percent);
  intake_spinner.setVelocity(-100, percent);
  wait(1.2, sec);
  driveForwardOrBack(0);
  wait(0.5, sec);
  intake_spinner.setVelocity(100, percent);
  wait(4, sec);
  intake.setVelocity(0, percent);
  intake_spinner.setVelocity(0, percent);
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // grabby_grab.setStopping(hold);
  fl.spin(forward);
  fr.spin(forward);
  bl.spin(forward);
  br.spin(forward);
  intake.spin(forward);
  intake_spinner.spin(forward);
  grabber_pneumatics.set(false);
  grabber_pneumatics2.set(false);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

  // Reset all motors
  fl.setVelocity(0, percent);
  fr.setVelocity(0, percent);
  bl.setVelocity(0, percent);
  br.setVelocity(0, percent);
  fl.setStopping(coast);
  fr.setStopping(coast);
  bl.setStopping(coast);
  br.setStopping(coast);
  intake.setVelocity(100, percent);
  intake_spinner.setVelocity(0, percent);
  wait(0.2, sec);
  intake.setVelocity(0, percent);

  // Check what autonomous has been selected
  if (isRed == true && isPos == true && isAWP == true) {
    auton_blue_negative_awp();
  }
  if (isRed == true && isPos == true && isAWP == false) {
    auton_red_positive();
  }
  if (isRed == true && isPos == false && isAWP == true) {
    auton_red_negative_awp();
  }
  if (isRed == true && isPos == false && isAWP == false) {
    auton_blue_positive();
  }
  if (isRed == false && isPos == true && isAWP == true) {
    auton_red_negative_awp();
  }
  if (isRed == false && isPos == true && isAWP == false) {
    auton_blue_positive();
  }
  if (isRed == false && isPos == false && isAWP == true) {
    auton_blue_negative_awp();
  }
  if (isRed == false && isPos == false && isAWP == false) {
    auton_red_positive();
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  fl.setStopping(brake);
  fr.setStopping(brake);
  bl.setStopping(brake);
  br.setStopping(brake);
  Controller1.Screen.print("Driver Control! ");
  // grabby_grab.spin(forward);
  while (1) {
    // if (Controller1.ButtonL1.pressing()) {
    //   auton_4();
    // } else if (Controller1.ButtonL2.pressing()) {
    //   auton_3();
    // }
    if (Controller1.ButtonUp.pressing()) {
      drive_power = 1;
    } else if (Controller1.ButtonDown.pressing()) {
      drive_power = 0.25;
    }

    fl.spin(forward, drive_power * Controller1.Axis3.position(percent) - (drive_power * 0.5 * Controller1.Axis1.position(percent)), percent);
    fr.spin(forward, drive_power * Controller1.Axis3.position(percent) + (drive_power * 0.5 * Controller1.Axis1.position(percent)), percent);
    bl.spin(forward, drive_power * Controller1.Axis3.position(percent) - (drive_power * 0.5 * Controller1.Axis1.position(percent)), percent);
    br.spin(forward, drive_power * Controller1.Axis3.position(percent) + (drive_power * 0.5 * Controller1.Axis1.position(percent)), percent);

    if (Controller1.ButtonX.pressing()) {
      intake_spinner.setVelocity(-100, percent);
    } else if (Controller1.ButtonR2.pressing()) {
      intake.setVelocity(100, percent);
      intake_spinner.setVelocity(100, percent);
    } else if (Controller1.ButtonR1.pressing()) {
      intake.setVelocity(-100, percent);
      intake_spinner.setVelocity(-100, percent);
    } else {
      intake.setVelocity(0, percent);
      intake_spinner.setVelocity(0, percent);
    }

    if (Controller1.ButtonL1.pressing()) {
      goal_grabbed = goal_grab(goal_grabbed);
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    Brain.Screen.clearScreen();
    if (isRed == true) {
      Brain.Screen.setFillColor(red);
    } else {
      Brain.Screen.setFillColor(blue);
    }
    Brain.Screen.drawRectangle(0, 0, 480, 272);

    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(0, 116, 480, 40);
    if (isPos == true) {
      Brain.Screen.drawRectangle(220, 0, 40, 272);
    }

    if (isAWP) {
      Brain.Screen.setFont(mono60);
      Brain.Screen.print("AWP");
      Brain.Screen.setCursor(1, 1);
    }

    if (Brain.Screen.pressing() && brainPressed == false) {
      if (isRed && !isAWP) {
        isPos = !isPos;
      }
      if (!isAWP) {
        isRed = !isRed;
      }
      isAWP = !isAWP;
    }
    brainPressed = Brain.Screen.pressing();
    
    wait(100, msec);
  }
}
