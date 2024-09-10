#pragma once


#include "../Events/Event.h"
#include <functional>

namespace GOG {
	
template<typename EventType>
using EventHandler = std::function<void(const EventType& e)>;

class IEventHandlerWrapper
{
	
public:
	void Exec(const Event& e) {
		Call(e);
	}

	virtual EventType GetEventType() const = 0;
	
private:
	virtual bool Call(const Event& e) = 0;
};

template<typename EventType>
class EventHandlerWrapper : public : IEventHandler{
	
public:
	explicit EventHandlerWrapper(const EventHandler<EventType> event_handler) : m_event_handler(e_handler) {}
		
	EventType GetEventType() const override {
		return m_event_handler.target_type();
	}

private:
	bool Call(const Event& e) override {
		if (e.GetEventType() == EventType::GetStaticType()) {
			m_event_handler(static_cast<const EventType&>(e));
			return true;
		}
		return false;
	}
	
private:
	EventHandler<EventType> m_event_handler;
};




}


