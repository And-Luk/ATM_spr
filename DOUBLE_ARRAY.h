//#include"stdafx.h"

#if !defined  (_DOUBLE_ARRAY_)
#define        _DOUBLE_ARRAY_

#include"Header.h"

class DOUBLE_ARRAY
//static class DOUBLE_ARRAY
{
public:
	DOUBLE_ARRAY();
   virtual ~DOUBLE_ARRAY();
	bool PUSH_DOUBLE_ARRAY(string SEARCH, string INSERT);
	

    string* PTR;
    deque<string*> DOB_END_QUE_ARR;      // ξοπεδελενθε 2 β DOUBLE_ARRAY.h

	//ARR_DOUB POP_DOUBLE_ARRAY();
	//ARR_DOUB operator = (DOUBLE_ARRAY);
private:
	//ARR_DOUB AR_DOUB;
	//static deque<ARR_DOUB> DOBLE_END_QUE_ARR; // ξοπεδελενθε β DOUBLE_ARRAY.h
	
protected:
	//static deque<ARR_DOUB> DOBLE_END_QUE_ARR; // ξοπεδελενθε 1 β DOUBLE_ARRAY.h
	//static deque<string*> DOB_END_QUE_ARR;      // ξοπεδελενθε 2 β DOUBLE_ARRAY.h
	//string* PTR;                                // ξοπεδελΈν β DOUBLE_ARRAY.h
};

#endif




