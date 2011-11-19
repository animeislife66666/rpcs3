#pragma once
#include "Thread.h"

class SPUThread : public CPUThread
{
public:
	s32 GPR[128]; //General-Purpose Register
	u64 cycle;

public:
	SPUThread(const u8 core);
	~SPUThread();

	virtual wxString RegsToString()
	{
		wxString ret = CPUThread::RegsToString();
		for(uint i=0; i<128; ++i) ret += wxString::Format("GPR[%d] = 0x%x\n", i, GPR[i]);
		return ret;
	}

public:
	virtual void _InitStack(); 
	virtual u64 GetFreeStackSize() const;

protected:
	virtual void DoReset();
	virtual void DoRun();
	virtual void DoPause();
	virtual void DoResume();
	virtual void DoStop();
	virtual void DoSysResume();

private:
	virtual void DoCode(const s32 code);
};