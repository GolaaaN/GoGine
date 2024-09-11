#pragma once
#include <vector>
#include <memory>
#include "../Events/Event.h"
#include <unordered_map>
#include "EventHandler.h"

namespace GOG {
	class EventManager
	{
	public:
		void Subscribe(const EventType &e, const std::unique_ptr<IEventHandlerWrapper> handler);
		void UnSubscribe(const EventType& e);
		void TriggerEvent(const Event& e);
		void QueueEvent(std::unique_ptr<Event> e);
		void DispatchEvents();

	private:
		std::vector<std::unique_ptr<Event>> m_events_queue;
		std::unordered_map<EventType, std::vector<std::unique_ptr<IEventHandlerWrapper>>> m_subscribers;
	};
}

