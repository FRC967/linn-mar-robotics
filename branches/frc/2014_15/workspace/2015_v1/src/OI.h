#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick xbox1, xbox2, board;
public:
	OI();

	//If a button is pressed down, a "tapped" function will return true only the first time it is called
	//After that, it will return false until the button is no longer pressed down, in which case it will reset
	float xbox1_y1();
	float xbox1_y2();
	float xbox1_x1();
	float xbox1_x2();
	float xbox1_rTVal();
	float xbox1_lTVal();
	bool xbox1_a();
	bool xbox1_b();
	bool xbox1_x();
	bool xbox1_y();
	bool xbox1_rB();
	bool xbox1_lB();
	bool xbox1_rT();
	bool xbox1_lT();
	bool xbox1_select();
	bool xbox1_start();
	bool xbox1_lClick();
	bool xbox1_rClick();
	bool xbox1_aTapped();
	bool xbox1_bTapped();
	bool xbox1_xTapped();
	bool xbox1_yTapped();
	bool xbox1_rBTapped();
	bool xbox1_lBTapped();
	bool xbox1_rTTapped();
	bool xbox1_lTTapped();
	bool xbox1_selectTapped();
	bool xbox1_startTapped();
	bool xbox1_lClickTapped();
	bool xbox1_rClickTapped();
	int xbox1_POV();
	bool xbox1_POVN();
	bool xbox1_POVNE();
	bool xbox1_POVE();
	bool xbox1_POVSE();
	bool xbox1_POVS();
	bool xbox1_POVSW();
	bool xbox1_POVW();
	bool xbox1_POVNW();
	bool xbox1_POVNTapped();
	bool xbox1_POVNETapped();
	bool xbox1_POVETapped();
	bool xbox1_POVSETapped();
	bool xbox1_POVSTapped();
	bool xbox1_POVSWTapped();
	bool xbox1_POVWTapped();
	bool xbox1_POVNWTapped();

	float xbox2_y1();
	float xbox2_y2();
	float xbox2_x1();
	float xbox2_x2();
	float xbox2_rTVal();
	float xbox2_lTVal();
	bool xbox2_a();
	bool xbox2_b();
	bool xbox2_x();
	bool xbox2_y();
	bool xbox2_rB();
	bool xbox2_lB();
	bool xbox2_rT();
	bool xbox2_lT();
	bool xbox2_select();
	bool xbox2_start();
	bool xbox2_lClick();
	bool xbox2_rClick();
	bool xbox2_aTapped();
	bool xbox2_bTapped();
	bool xbox2_xTapped();
	bool xbox2_yTapped();
	bool xbox2_rBTapped();
	bool xbox2_lBTapped();
	bool xbox2_rTTapped();
	bool xbox2_lTTapped();
	bool xbox2_selectTapped();
	bool xbox2_startTapped();
	bool xbox2_lClickTapped();
	bool xbox2_rClickTapped();
	int xbox2_POV();
	bool xbox2_POVN();
	bool xbox2_POVNE();
	bool xbox2_POVE();
	bool xbox2_POVSE();
	bool xbox2_POVS();
	bool xbox2_POVSW();
	bool xbox2_POVW();
	bool xbox2_POVNW();
	bool xbox2_POVNTapped();
	bool xbox2_POVNETapped();
	bool xbox2_POVETapped();
	bool xbox2_POVSETapped();
	bool xbox2_POVSTapped();
	bool xbox2_POVSWTapped();
	bool xbox2_POVWTapped();
	bool xbox2_POVNWTapped();

	bool board_1();
	bool board_2();
	bool board_3();
	bool board_4();
	bool board_5();
	bool board_bigRed();
	bool board_lilGreen();
	bool board_hiLoSwitch();
	bool board_up();
	bool board_down();
	bool board_in();
	bool board_out();
	bool board_1Tapped();
	bool board_2Tapped();
	bool board_3Tapped();
	bool board_4Tapped();
	bool board_5Tapped();
	bool board_bigRedTapped();
	bool board_lilGreenTapped();
	bool board_hiLoSwitchTapped();
	bool board_upTapped();
	bool board_downTapped();
	bool board_inTapped();
	bool board_outTapped();

	bool board_hiLoSwitchUnTapped();

private:
	bool tappedArrayXbox1[12]{false,false,false,false,false,false,false,false,false,false,false,false};
	bool tappedArrayXbox1POV[8]{false,false,false,false,false,false,false,false};
	bool tappedArrayXbox2[12]{false,false,false,false,false,false,false,false,false,false,false,false};
	bool tappedArrayXbox2POV[8]{false,false,false,false,false,false,false,false};
	bool tappedArrayBoard[12]{false,false,false,false,false,false,false,false,false,false,false,false};
	bool hiLoSwitchUnTapped;
};

#endif
