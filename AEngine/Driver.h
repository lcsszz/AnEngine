#pragma once
#ifndef __DRIVER_H__
#define __DRIVER_H__

#include"onwind.h"
#include"BaseBehaviour.h"

namespace AEngine
{
	class Driver :public NonCopyable
	{
		bool m_initialized;

		Driver() = default;
		~Driver() = default;

	public:

		static Driver* GetInstance();

		void Initialize(HWND hwnd, HINSTANCE hInstance, int screenw, int screenh);
		void Release();

		void BeginBehaviour(Game::BaseBehaviour* behaviour);
		void EndBehaviour();
	};
}

#endif