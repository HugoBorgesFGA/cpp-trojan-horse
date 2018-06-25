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

private:

	uint32_t seed;
	map<uint32_t, function<void(T &owner)>> subscriptions;

public:

	Event()
	{

		this->seed = 0;
	}

	uint32_t add(function<void(T &owner)> handler)
	{

		uint32_t subscription_memo = this->seed++;
		subscriptions[subscription_memo] = handler;

		return subscription_memo;
	}

	void fire(T arg)
	{

		for (auto const& x : subscriptions) x.second(arg);
	}
};

#endif
