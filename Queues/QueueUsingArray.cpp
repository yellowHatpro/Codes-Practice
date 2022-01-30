#include <iostream>
using namespace std;

//There are 2 types of Queues : Static and Dynamic 
//Static Queue

template <typename T>
class QueueUsingArray{
	T *data;
	int nextIndex; //will initiate with 0 later
	int firstIndex;//will initiate with -1 later
	int size;
	int capacity; //capacity of the queue
public:
	QueueUsingArray(int s){
		data = new T[s]; //new array of type T of size s
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size==0;
	}

	void enqueue(T element){
		if (size==capacity)
		{
			cout<<"Queue is full!!"<<endl;
		}
		else{
			if (firstIndex==-1) firstIndex=0;
			data[nextIndex] = element;
			nextIndex = (nextIndex +1) % capacity;
			size++;
		}
	}

	T front(){
		if (isEmpty())
		{
			cout<<"Queue is empty!!"<<endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue(){
		if (isEmpty())
		{
			cout<<"Queue is empty!!"<<endl;
			return 0;
		}
		size--;
		T ans = data[firstIndex];
		firstIndex =(firstIndex+1) % capacity;
		//If first index reaches end of the array then it will become zero and continue to add elements.
		return ans;
	}
};

//Dynamic Array <3

template <typename T>
class Queue{
	T* data;
	int nextIndex;//Will initialize with 0
	int firstIndex;//will initialize with -1
	int size;
	int capacity;

public:
	Queue(int s){
		data = new T[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size==0;
	}

	void enqueue(T element){
		if (size==capacity){
			//here we will expand queue past its capacity , same as its implemented with vectors
			T *newData = new T[2*capacity];
			int j=0;
			for (int i = firstIndex; i < capacity; i++)// if firstIndex !=0
			{
				newData[j] = data[i];
				j++;
			}
			for(int i=0;i<firstIndex;i++)//this , coz there could have been elements before first elements (we know na first element need not to be at 0 index :)) 
			{
				newData[j] = data[i];
				j++;
			}
			delete data;
			data = newData;
			firstIndex = 0;
			nextIndex = capacity;
			capacity *=2;
		}

		if (firstIndex==-1) firstIndex = 0;
		data[nextIndex] = element;
		nextIndex = (nextIndex+1) % capacity;
		size++;
	}

	T front(){
		if (isEmpty())
		{
			cout << "Query is Empty!!"<<endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue(){
		if (isEmpty())
		{
			cout<<"Queue is empty!!"<<endl;
			return 0;
		}
		size--;
		T ans = data[firstIndex];
		firstIndex = (firstIndex +1) % capacity; 
		return ans;
	}
};

int main(){
	
}