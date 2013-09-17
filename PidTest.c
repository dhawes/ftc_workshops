#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     intakeMotor,   tmotorTetrix, openLoop, encoder)

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Conveyorbot Gyro - Autonomous Score Routine

This program is designed for the the Virtual World 'FTC Block Party!'
It is designed to score the preload block in the blue box with a Conveyorbot
at start point B1.

Start at B1 with Conveyorbot
1) Move forward for 4000 encoder counts (using encoders)
2) Turn to the right until gyro reads 45 degrees (using gyroscope)
3) Line track onto the ramp for 3000 encoder counts (using light sensor and encoders)
4) Raise arm for 600 encoder counts (using the arm's encoder)
5) Turn to the right until gyro reads 140 degrees (using gyroscope)
6) Move forward until close enough to side wall (using sonar)
7) Lower arm for -200 encoder counts (using the arm's encoder)
8) Turn on intake (reversed) and score the preload object

Robot Model(s): TETRIX Conveyorbot (Gyro) (Virtual Worlds)

[I/O Port]          [Name]              [Type]                [Description]
Motor Port D        rightMotor          TETRIX Motor          Right side motor
Motor Port E                leftMotor                       TETRIX Motor                    Left side motor
Motor Port F                armMotor                        TETRIX Motor                    Arm motor
Motor Port G                intakeMotor                 TETRIX Motor                    Intake motor

Sensor Port 2               gyro                                HiTechnic Gyro              HiTechnic Gyro
Sensor Port 3               light                           Light Sensor                    NXT Light Sensor (Active)
Sensor Port 4               sonar                           Sonar Sensor                    NXT Sonar Sensor

----------------------------------------------------------------------------------------------------*/

#define KP        0.1

// Actually P drive
void pidDrive(const int speed, const int timeMillis);

int speed = 50;
int leftSpeed = 10;

task main()
{
    //Step 1
    //Clear the encoders
    nMotorEncoder(rightMotor) = 0;
    nMotorEncoder(leftMotor)  = 0;

    motor[rightMotor] = speed;
    motor[leftMotor] = leftSpeed;

    //wait1Msec(5000);

    pidDrive(speed, 1000);

    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
}

void pidDrive(const int speed, const int timeMillis)
{
  int left, right = 0;
  while(true)
  {
    int error = abs(nMotorEncoder(leftMotor)) - abs(nMotorEncoder(rightMotor));
  	error = abs(error);
  	int powerDiff = error*KP;
  	if(abs(nMotorEncoder(leftMotor)) < abs(nMotorEncoder(rightMotor)))
  	{
    	motor[leftMotor] = leftSpeed + powerDiff;
    	motor[rightMotor] = speed - powerDiff;
  	}
  	else
  	{
    	motor[leftMotor] = leftSpeed - powerDiff;
    	motor[rightMotor] = speed + powerDiff;
  	}
  	left = motor[leftMotor];
  	right = motor[rightMotor];
  	nxtDisplayString(1, "leftE = %d", nMotorEncoder(leftMotor));
  	nxtDisplayString(2, "rightE = %d", nMotorEncoder(rightMotor));
  	nxtDisplayString(3, "error = %d", error);
  	nxtDisplayString(4, "powerDiff = %d", powerDiff);
  	nxtDisplayString(5, "left = %d", left);
  	nxtDisplayString(6, "right = %d", right);
  	wait1Msec(100);
	}
}
