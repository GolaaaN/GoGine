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


	private:
		std::vector<std::unique_ptr<Event>> m_events_queue;
		std::unordered_map<EventType, std::vector<std::unique_ptr<IEventHandlerWrapper>>> m_subscribers;
	};
}

