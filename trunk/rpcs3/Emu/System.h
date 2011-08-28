#pragma once

#include "Gui/MemoryViewer.h"
#include "Emu/Cell/CPU.h"
#include "Utilites/Array.h"

class Emulator
{
	enum Status
	{
		Runned,
		Paused,
		Stoped,
	};

	enum Mode
	{
		DisAsm,
		Interpreter,
	};

	uint m_status;
	uint m_mode;

	MemoryViewerPanel* m_memory_viewer;
	ArrayF<CPUThread> m_cpu_threads;

public:
	bool IsSlef;

	Emulator();

	virtual void SetSelf(wxString self_patch);
	virtual void SetElf(wxString elf_patch);

	virtual void Run();
	virtual void Pause();
	virtual void Resume();
	virtual void Stop();

	ArrayF<CPUThread>& GetCPU()
	{
		return m_cpu_threads;
	}

	CPUThread& GetPPU()
	{
		return m_cpu_threads.Get(0);
	}

	CPUThread& GetSPU(const u8 core)
	{
		if(core >= m_cpu_threads.GetCount())
		{
			ConLog.Error("Get SPU error: unknown number! (%d)", core);
			return m_cpu_threads.Get(0);
		}

		return m_cpu_threads.Get(core);
	}

	virtual bool IsRunned() const { return m_status == Runned; }
	virtual bool IsPaused() const { return m_status == Paused; }
	virtual bool IsStoped() const { return m_status == Stoped; }
};

extern Emulator Emu;