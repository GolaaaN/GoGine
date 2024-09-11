#pragma once
#include "Event.h"


namespace GOG {

	class WindowCloseEvent : public Event {

		const EventType GetEventType() const override {
			return GOG::EventType::WindowClose;
		}

		const const char* GetEventName() const override {
			return "WindowClose event";
		}
	};
}