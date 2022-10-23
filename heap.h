#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <iostream>
#include <vector>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());
  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();
  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);
  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;
  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();
  /// returns true if the heap is empty
  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;
    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
	//helper function for pop
	void pophelper(int node);
private:
  /// Add whatever helper functions and data members you need below
	PComparator comp;
	std::vector<T> heapvector;
 	int m;
};
// Add implementation of member functions here
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return heapvector.size();
}
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
	comp = c;
	this->m = m;
}
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
	T var = item;
	if(empty()){
		heapvector.push_back(item);
		return;
	}
	else{
		heapvector.push_back(item);
		int curr = heapvector.size()-1;
		while(comp(var, heapvector[(curr-1)/m])){
			T temp = item;
			heapvector[curr] = heapvector[(curr-1)/m];
			heapvector[(curr-1)/m] = temp;
			curr = (curr-1)/m;
		}
	}
	
}
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
		if(heapvector.empty()){
			return true;
		}
		else{
			return false;
		}
}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::logic_error("error");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return heapvector[0];
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
	  throw std::logic_error("error");
  }
	heapvector[0] = heapvector[heapvector.size()-1];
	heapvector.pop_back();
	pophelper(0);
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::pophelper(int node)
{
	//recursively running to put the value into correct position.
	int size = heapvector.size();
	if(node*m + 1 >= size){
		return;
	}
	else{
		T min = heapvector[node*m + 1];
		int minindex = node*m + 1;
		int index = node*m + 1;
		
		while(index <= node*m + m && index < size){
			if(comp(heapvector[index],min)){
				min = heapvector[index];
				minindex = index;
			}
			index ++;
		}
		if(comp(min, heapvector[node])){
			T temp = heapvector[node];
			heapvector[node] = min;
			heapvector[minindex] = temp;
			pophelper(minindex);
		}
		else{
			return;
		}
	}
}

#endif

