#pragma once
#include "Event.h"


namespace GOG {

	class WindowCloseEvent : public Event {
		const EventType GetEventType() const override {
			return GOG::EventType::WindowClose;
		}
	};
}