#pragma once

#include <queue>

template <typename T>
class MovingAverageFilter
{
public:
	/*
	 * @brief Create a new instance of the Moving average filter.
	 * Member variables will be initialized as 
	 * 
	 * MaximumElemets = maxElements_init
	 * sum			 = zero
	 * 
	 * @param maxElements_init Maximum number that Q can store. 
	 */
	MovingAverageFilter(const size_t maxElements_init) : 
		MaximumElemets(maxElements_init)
		, sum(0)
	{}
	
	/*
	 * @brief filter operating function
	 *
	 * @param input input of the filtering
	 * @return filtered data
	 */
	T filter(const T& input)
	{
		if (q.size() > MaximumElemets - 1)
		{
			T frontData = q.front();
			sum = sum - frontData + input;
			q.pop();
		}
		else
		{
			sum += input;
		}
		q.push(input);

		T numOfElements = static_cast<T>(q.size());

		return sum / numOfElements;
	}

	/*
	 * @brief Reset the filter object
	 */
	void reset()
	{
		while (!q.empty())
		{
			q.pop();
		}
		sum = 0;
	}

private:
	// Queue for storing data
	std::queue<T> q;

	//Maximum number that Q can store.
	size_t MaximumElemets;

	// Sum of all the elements of queue
	T sum;
};