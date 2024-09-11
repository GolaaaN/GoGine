#include "EventManager.h"

void GOG::EventManager::Subscribe(const EventType& e, const std::unique_ptr<IEventHandlerWrapper> handler)
{
	auto subscribers = m_subscribers.find(e);
    if (subscribers != m_subscribers.end()) {
        auto& handlers = subscribers->second;
        for (auto& it : handlers) {
            if (it->GetEventType() == handler->GetEventType()) {
                return;
            }
        }
        handlers.emplace_back(std::move(handler));
    }
    else {
        m_subscribers[e].emplace_back(std::move(handler));
    }
}

void GOG::EventManager::UnSubscribe(const EventType& e)
{
}

void GOG::EventManager::TriggerEvent(const Event& e)
{
    for (auto& handler : m_subscribers[e.GetEventType()]) {
        handler->Exec(e);
    }
}

void GOG::EventManager::QueueEvent(std::unique_ptr<Event> e)
{
    m_events_queue.emplace_back(std::move(e));
}

void GOG::EventManager::DispatchEvents()
{
    for (auto eventIt = m_events_queue.begin(); eventIt != m_events_queue.end();) {
        if (!eventIt->get()->Handled) {
            TriggerEvent(*eventIt->get());
            eventIt = m_events_queue.erase(eventIt);
        }
        else {
            ++eventIt;
        }
    }
}
