#define START_RED     "Red"
#define START_BLUE    "Blue"
#define START_INSIDE  "Inside"
#define START_OUTSIDE "Outside"
#define PARK_BACK     "Back"
#define PARK_FRONT    "Front"
string startColor;
string startPosition;
bool startPause = false;
string robotPark;
string bBallPark;

void getUserInput()
{
  //disableDiagnosticsDisplay();
  nxtDisplayCenteredTextLine(0, "Red or Blue?");
  nxtDisplayCenteredTextLine(7, "Red Blue");
  while(true)
  {
    if(nNxtButtonPressed == 2)
    {
      startColor = START_RED;
      nxtDisplayCenteredTextLine(0, "Red");
      break;
    }
    else if(nNxtButtonPressed == 1)
    {
      startColor = START_BLUE;
      nxtDisplayCenteredTextLine(0, "Blue");
      break;
    }
  }
  PlaySound(soundBlip);
  wait1Msec(1000);
  nxtDisplayCenteredTextLine(1, "Inside or Outside?");
  nxtDisplayCenteredTextLine(7, "Inside Outside");
  while(true)
  {
    if(nNxtButtonPressed == 2)
    {
      startPosition = START_INSIDE;
      nxtDisplayCenteredTextLine(1, "Inside");
      break;
    }
    else if(nNxtButtonPressed == 1)
    {
      startPosition = START_OUTSIDE;
      nxtDisplayCenteredTextLine(1, "Outside");
      break;
    }
  }
  PlaySound(soundBlip);
  wait1Msec(1000);
  nxtDisplayCenteredTextLine(2, "Wait 5 Seconds?");
  nxtDisplayCenteredTextLine(7, "Yes No");
  while(true)
  {
    if(nNxtButtonPressed == 2)
    {
      startPause = true;
      nxtDisplayCenteredTextLine(2, "5s Wait: Yes");
      break;
    }
    else if(nNxtButtonPressed == 1)
    {
      startPause = false;
      nxtDisplayCenteredTextLine(2, "5s Wait: No");
      break;
    }
  }
  nxtDisplayTextLine(7, "");
  PlaySound(soundBlip);


  nxtDisplayCenteredTextLine(7, "* Tally ho! *");
}

task main()
{
	getUserInput();
}
