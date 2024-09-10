#pragma once
#include <string>


namespace GOG {


	enum class EventType {
		None = 0,
		WindowClose
	};

	class Event {
	public:
		virtual const EventType GetEventType() const = 0;

	public:
		bool Handled{ false };
	};

}