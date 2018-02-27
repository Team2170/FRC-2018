
// Select left or right switch based on field data
#ifndef DRIVETOSWITCH_H
#define DRIVETOSWITCH_H


#include "ScoreSwitchLeft.h"
#include "ScoreSwitchRight.h"
#include "../Robot.h"

#include "Commands/ConditionalCommand.h"

class DriveToSwitchScore : public frc::ConditionalCommand {
public:
	DriveToSwitchScore();

protected:
virtual bool Condition();
};

#endif
