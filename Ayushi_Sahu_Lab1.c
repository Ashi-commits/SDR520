#pragma config(Sensor, dgtl6,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveStraight(float power) {

	while(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
	{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		motor[rightMotor] = power;			// Motor on port2 is run at (power) power forward
		motor[leftMotor]  = power;			// Motor on port3 is run at (power) power forward
	}

}

void turnLeft(float power) {

	// Turn Left at full power for 0.626 seconds
	motor[rightMotor] = power;			// Motor on port2 is run at (power) power forward
	motor[leftMotor]  = -power;		  // Motor on port3 is run at (-power) power reverse
	wait1Msec(626);					      // Robot runs previous code for 626 milliseconds before moving on
													      // Program ends, and the robot stops

}

void turnRight(float power) {

	// Turn Right at full power for 0.626 seconds
	motor[leftMotor] = power;			// Motor on port3 is run at (power) power forward
	motor[rightMotor]  = -power;		  // Motor on port2 is run at (-power) power reverse
	wait1Msec(626);					      // Robot runs previous code for 626 milliseconds before moving on
													      // Program ends, and the robot stops

}

task main()
{
	while(SensorValue(touchSensor) == 0)		// Loop while robot's bumper/touch sensor isn't pressed in
																					// For collision control
	{

		wait1Msec(2000);						// Robot waits for 2000 milliseconds before executing program

		moveStraight(127);
		repeat(2){
			turnLeft(127);
			moveStraight(127);
		}
		turnRight(127);
		moveStraight(127);

	}
}
