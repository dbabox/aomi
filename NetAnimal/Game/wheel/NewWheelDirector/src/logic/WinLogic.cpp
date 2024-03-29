
#include "NewWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;



WinLogic::WinLogic(my_context ctx):LogicAdv(ctx)
{
	ORZ_LOG_NORMAL_MESSAGE("State In: WinLogic!");
	
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_WIN_ENABLE, WheelEvents::PROCESS_WIN_DISABLE));
}

WinLogic::~WinLogic(void)
{
	ORZ_LOG_NORMAL_MESSAGE("State Out: WinLogic!");
	
}

sc::result WinLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();

	return transit<PlayLogic>();	
}


