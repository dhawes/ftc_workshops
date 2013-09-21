//////////////////////////////////////////////////////////////////////////////////////////////
//
//                          Shell example for Implementing a State Machine
//
// State machines are a very common program architecture. This program provides a basic
// 'shell' or 'template' as a starting point for implementation.
//
// Among other things, it illustrates two useful concepts for a state machine:
//
// 1. Use an "enum" definition to keep track of your differnt states. As opposed to using
//    numeric values. It's far easier to add/change states to the machine without having
//    to go back and change the program -- the 'case' values will auto adjust as you
//    add/subtract states.
//
// 2. Ensure there is a "default" clause in the 'switch on state' block so that you can
//    trap usage of invalid values for the state machine.
//
//////////////////////////////////////////////////////////////////////////////////////////////


typedef enum
{
  stateInitialization,
  stateForward,
  stateReverse,
  stateShuttingDown
} TStates;

TStates nCurrState;


task main()
{
  //
  // One-time startup code
  //
  nCurrState = stateInitialization;

  //
  // COntinuous loop for state machine
  //
  while (true)
  {
    switch (nCurrState)
    {
    case stateInitialization:
      /* Insert program specific code here */
      break;

    case stateForward:
      /* Insert program specific code here */
      break;

    case stateReverse:
      /* Insert program specific code here */
      break;

    case stateShuttingDown:
      /* Insert program specific code here */
      break;

    default:
      // Should never get here. Play warning message and restart
     PlaySound(soundLowBuzz);
     nCurrState = stateInitialization;
     break;
    }
  }
}
