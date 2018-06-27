#ifndef H_EVENT
#define H_EVENT

#include "event.hpp"

#include <map>
#include <cstdint>
#include <functional>

using namespace std;

template <class T>

class Event
{
	using map_of_events_t = map<uint32_t, function<void(T &args)>>;

private:

	uint32_t seed;
	map_of_events_t subscriptions;

public:

	Event()
	{

		this->seed = 0;
	}

	uint32_t add(function<void(T &args)> handler)
	{

		uint32_t subscription_memo = this->seed++;
		subscriptions[subscription_memo] = handler;

		return subscription_memo;
	}

	void remove(uint32_t subscription){

		subscriptions.erase(subscription);
	}

	void fire(T arg)
	{

		for (auto const& x : subscriptions) x.second(arg);
	}
};

#endif
