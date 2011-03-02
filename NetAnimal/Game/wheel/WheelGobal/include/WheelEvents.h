#ifndef __Orz_Wheel_WheelEvents_h__
#define __Orz_Wheel_WheelEvents_h__

#include "WheelGobalConfig.h"
namespace Orz
{

	DEF_EVENT_BEGIN_WITH_EXPORT(_OrzWheelGobalExport, WheelEvents)
	DEF_EVENT(CLICK_BUTTON)
	DEF_EVENT(ASK_TIME)
	DEF_EVENT(SET_TIME)
	DEF_EVENT(HOW_WINNER)
	DEF_EVENT(FIND_SC)
	DEF_EVENT(ASK_STATE)
	DEF_EVENT(COME_IN_MENU)
	DEF_EVENT(DATA_MENU)
	DEF_EVENT(GO_OUT_MENU)
	DEF_EVENT(SET_MODE)
	DEF_EVENT(COME_IN_SETUP)
	DEF_EVENT(TO_SETUP)
	DEF_EVENT(RESET_GAME)
	DEF_EVENT(HARDWARE_RETURN)
	DEF_EVENT(KEY_F4)
	DEF_EVENT(KEY_F5)
	DEF_EVENT(KEY_F6)

	
	DEF_EVENT(PROCESS_LOGO_ENABLE)
	DEF_EVENT(PROCESS_LOGO_DISABLE)

	
	DEF_EVENT(PROCESS_READY_ENABLE)
	DEF_EVENT(PROCESS_READY_DISABLE)

	
	DEF_EVENT(PROCESS_START_ENABLE)
	DEF_EVENT(PROCESS_START_DISABLE)

	DEF_EVENT(PROCESS_PRORUN_ENABLE)
	DEF_EVENT(PROCESS_PRORUN_DISABLE)

	
	DEF_EVENT(PROCESS_RUN_ENABLE)
	DEF_EVENT(PROCESS_RUN_DISABLE)


	DEF_EVENT(PROCESS_WIN_ENABLE)
	DEF_EVENT(PROCESS_WIN_DISABLE)
	
	DEF_EVENT(PROCESS_PLAY_ENABLE)
	DEF_EVENT(PROCESS_PLAY_DISABLE)
	

	DEF_EVENT(PROCESS_END_ENABLE)
	DEF_EVENT(PROCESS_END_DISABLE)
	
	DEF_EVENT_END(WheelEvents)

	enum WheelEventChannels
	{
		CHANNEL_INTERNAL = 0,
		CHANNEL_PROCESS = 1
		
	};
}
#endif