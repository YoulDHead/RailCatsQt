#ifndef railcats_queue
#define railcats_queue

#include <string>
#include <vector>
#include <iostream>

#define 	RailCats_MESSAGE_NOP 	1

static const int StateChanged=1;

class RailCats_Queue_Element{
	public:
		RailCats_Queue_Element();
		int SetData(std::vector<char> Data);
		bool GetData(std::vector<char> & Data);
		bool SetID(int ID);		
		int ElementID; //RailCats_MESSAGE_
		int ElementLength;// Length of data
		std::vector<char> ElementData; //Data		
		time_t TimeStamp;
};


class RailCats_Queue{

	public:
		RailCats_Queue();
		~RailCats_Queue();

		bool Push_Element(RailCats_Queue_Element NewElement);
		bool Push_Element_HI(RailCats_Queue_Element NewElement);

		bool Pop_Element(RailCats_Queue_Element & TempElement);
		int CleanUp(int ElementMaxAge);

	private: 

		std::vector<RailCats_Queue_Element> Elements;		

};

#endif
