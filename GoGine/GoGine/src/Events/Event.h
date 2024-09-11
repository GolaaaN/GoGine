#pragma once
#include <string>


namespace GOG {


	enum class EventType {
		None = 0,
		WindowClose,
		KeyEvent, KeyPressed, KeyRealesed
	};

	class Event {
	public:
		virtual const EventType GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;

	public:
		bool Handled{ false };
	};

}