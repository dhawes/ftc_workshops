#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     intakeMotor,   tmotorTetrix, openLoop, encoder)

task main()
{
	while(true)
	{
		//While the gyro reads less than 35 degrees (350 counts)
	  // Does reading the sensor this way work outside of virtual worlds?
	  // With the HiTechnic drivers you get degrees/sec which you need to integrate
		while(SensorValue[gyro] < 900)
		{
			//Quickly turn to the right
			motor[rightMotor] =	-75;
			motor[leftMotor]  =  75;
		}

		while(SensorValue[gyro] > 0)
		{
			//Quickly turn to the right
			motor[rightMotor] =	75;
			motor[leftMotor]  = -75;
		}
	}
}
