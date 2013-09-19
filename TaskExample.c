#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     intakeMotor,   tmotorTetrix, openLoop, encoder)

bool intakeOn = false;

task runIntake()
{
	intakeOn = true;
	while(intakeOn)
	{
	  motor[intakeMotor] = 100;
	  wait1Msec(1000);
	}
	motor[intakeMotor] = 0;
}

task report()
{
	while(true)
	{
		eraseDisplay();
		nxtDisplayString(1, "right = %d", motor[rightMotor]);
		nxtDisplayString(2, "left = %d", motor[leftMotor]);
		wait1Msec(100);
	}
}

task main()
{
	StartTask(runIntake);
	StartTask(report);
	int iterations = 0;
	while(true)
	{
		// no reading, turn in place
		motor[rightMotor] = 20;
		motor[leftMotor] = 20;

		wait1Msec(2000);

		motor[rightMotor] = -20;
		motor[leftMotor] = -20;

		wait1Msec(2000);
		iterations++;
		if(iterations >= 3)
		{
			intakeOn = false;
		}
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}
