#include "StateMachine.h"
#include "Hash.hpp"
using namespace std;
using namespace AnEngine::Utility;

namespace AnEngine::Game
{
	template<typename _Ty>
	function<bool(_Ty, _Ty)> Cmp[StateMachine::Condition::Count] =
	{
		[](_Ty a, _Ty b) { return a == b; },
		[](_Ty a, _Ty b) { return a != b; },
		[](_Ty a, _Ty b) { return a < b; },
		[](_Ty a, _Ty b) { return a <= b; },
		[](_Ty a, _Ty b) { return a > b; },
		[](_Ty a, _Ty b) { return a >= b; },
	};

	void StateMachine::Update()
	{
	}

	int StateMachine::GetStateIndex(const std::wstring& name)
	{

		return -1;
	}

	int StateMachine::GetStateIndex(std::wstring&& name)
	{

		return -1;
	}

	void StateMachine::AddIntParam(wstring&& name, int initValue)
	{
		if (m_str2Hash.find(name) != m_str2Hash.end())
		{
			throw exception();
		}
		uint64_t h = m_str2Hash[name] = m_str2Hash.size();
		m_intParam[h] = initValue;
	}

	void StateMachine::AddFloatParam(wstring&& name, float initValue)
	{
		if (m_str2Hash.find(name) != m_str2Hash.end())
		{
			throw exception();
		}
		uint64_t h = m_str2Hash[name] = m_str2Hash.size();
		m_intParam[h] = initValue;
	}

	void StateMachine::AddBoolParam(wstring&& name, bool initValue)
	{
		if (m_str2Hash.find(name) != m_str2Hash.end())
		{
			throw exception();
		}
		uint64_t h = m_str2Hash[name] = m_str2Hash.size();
		m_intParam[h] = initValue;
	}

	void StateMachine::AddTrigerParam(wstring&& name)
	{
		if (m_str2Hash.find(name) != m_str2Hash.end())
		{
			throw exception();
		}
		uint64_t h = m_str2Hash[name] = m_str2Hash.size();
		m_intParam[h] = false;
	}

	int StateMachine::CreateNewState(std::wstring && name, const std::function<void()>& func)
	{
		int index = m_stateName.size();
		std::hash<std::wstring> h;
		uint64_t ha = h(name);
		m_stateName.emplace_back(name);
		m_states.emplace_back(State(ha, func));
		return index;
	}

	int StateMachine::CreateNewState(std::wstring && name, std::function<void()>&& func)
	{
		int index = m_stateName.size();
		std::hash<std::wstring> h;
		uint64_t ha = h(name);
		m_stateName.emplace_back(name);
		m_states.emplace_back(State(ha, func));
		return index;
	}

	void StateMachine::AddStateChangeCondition(uint32_t from, uint32_t to, std::wstring name, uint32_t newValue, Condition cond)
	{
	}

	void StateMachine::AddStateChangeCondition(uint32_t from, uint32_t to, std::wstring name, float newValue, Condition cond)
	{
	}

	void StateMachine::AddStateChangeCondition(uint32_t from, uint32_t to, std::wstring name, bool newValue, Condition cond)
	{
	}

	void StateMachine::AddStateChangeCondition(uint32_t from, uint32_t to, std::wstring trggerName)
	{
	}

	void StateMachine::SetInt(std::wstring&& name, int value)
	{
		m_intParam[m_str2Hash[name]] = value;
	}

	void StateMachine::SetBool(std::wstring&& name, bool value)
	{
		m_intParam[m_str2Hash[name]] = value;
	}

	void StateMachine::SetFloat(std::wstring&& name, float value)
	{
		m_intParam[m_str2Hash[name]] = value;
	}

	void StateMachine::SetTrigger(std::wstring&& name)
	{
		m_intParam[m_str2Hash[name]] = true;
	}

	void StateMachine::SetCurrentState(int index)
	{
		if (index < 0 || index >= m_states.size())
		{
			throw exception();
		}
		m_curState = index;
	}
}