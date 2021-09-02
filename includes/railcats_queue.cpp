#include "railcats_queue.h"
#include "time.h"

RailCats_Queue_Element::RailCats_Queue_Element(){
	ElementLength=0;
	TimeStamp=time(NULL);
	
};

int RailCats_Queue_Element::SetData(std::vector<char> Data){

	ElementLength=Data.size();
	ElementData=Data;

	return 0;

};

bool RailCats_Queue_Element::GetData(std::vector<char> & Data){

	Data=ElementData;

	return 0;

};

bool RailCats_Queue_Element::SetID(int ID){

	ElementID=ID;
	return true;
};


// Push new element to end of queue
bool RailCats_Queue::Push_Element(RailCats_Queue_Element NewElement){

	Elements.push_back(NewElement);	
	return true;

};

// Push new high priority element to the start of queue
bool RailCats_Queue::Push_Element_HI(RailCats_Queue_Element NewElement){

	Elements.insert(Elements.begin(),NewElement);	
	return true;

};

// Pop element from the beginig of a queue
bool RailCats_Queue::Pop_Element(RailCats_Queue_Element & TempElement){

	RailCats_Queue_Element MyElement;


	if(0!=Elements.size()){


		TempElement=Elements.at(0);
		Elements.erase(Elements.begin());
		return true;
	}
	return false;

};

int RailCats_Queue::CleanUp(int ElementMaxAge){


	time_t CurrentTimeStamp=time(NULL);
	int DeletedElementsCounter=0;

	for (int i=0;i<Elements.size();i++){

		std::cout<<"CurrentTimeStamp="<<CurrentTimeStamp<<" Elements.at(i).TimeStamp="<<Elements.at(i).TimeStamp<<" MaxAge="<<ElementMaxAge<<std::endl;

		if(CurrentTimeStamp-Elements.at(i).TimeStamp>ElementMaxAge){
		// erase element
			Elements.erase(Elements.begin()+i);
			DeletedElementsCounter++;
		}

	}

    return true;
};


RailCats_Queue::RailCats_Queue(){};
RailCats_Queue::~RailCats_Queue(){};







