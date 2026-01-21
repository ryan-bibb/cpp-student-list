//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Ryan Bibb
//
//		Assignment:				Program # 11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					11/25/25
//
//
//		This file creates the node struct
//	
//		Other files required: 
//			1.	studentList.cpp
//			2.	student.h
//			3.	LList.h
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

template<typename TYPE>
struct Node
{
	Node<TYPE>* next;
	TYPE data;
	Node();
	Node(const TYPE& dat, Node<TYPE>* nex = nullotr);
};

template<typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

template<typename TYPE>
Node<TYPE>::Node(const TYPE& dat, Node<TYPE>* nex)
{
	data = dat;
	next = nex;
}

#endif