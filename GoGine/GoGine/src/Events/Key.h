#pragma once
#include "Event.h"
#include <sstream>

namespace GOG {
	class KeyEvent : public Event {

	public:

		KeyEvent(uint32_t key_code_) : m_key_code(key_code_) {}

		virtual const EventType GetEventType() const {
			return GOG::EventType::KeyEvent;
		}

		virtual const char* GetEventName() const {
			return "KeyEvent event";
		}


	protected:
		uint32_t m_key_code;
	};


	class KeyPressed : public KeyEvent {
	public:

		KeyPressed(uint32_t key_code_) : KeyEvent(key_code_) {}

		virtual const EventType GetEventType() const {
			return GOG::EventType::KeyPressed;
		}

		virtual const char* GetEventName() const {
			
			std::stringstream s;
			s << "key pressed event: " << m_key_code;

			return s.str().data();
		}
	};
}
