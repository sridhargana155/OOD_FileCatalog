#ifndef DISPLAY_H
#define DISPLAY_H
/////////////////////////////////////////////////////////////////////////////
// Display.h - Displays the data already stored in the data store map      //
// ver 2.3                                                                 //
// ----------------------------------------------------------------------- //
// copyright ©  Sridhar Ganapathy                                          //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++ version 11, Visual Studio 2013                  //
// Platform:    Lenovo Z510, Core i7, Windows 8.1                          //
//									                                       //
// Author: Sridhar Ganapathy,CST,  Syracuse University		               //
//				SUID: 266711369, Email_id: sganapat@syr.edu                //
/////////////////////////////////////////////////////////////////////////////
/*
Module Operations :
==================
This file provides declarations for the methods defined in the Display.cpp file.
Below are the method name and functionalities of each method present in the Display Class,

display: This method displays the file names along with its path both 
resurvisely and non-recursively when a search is made based on the user input.

displayduplicateonly: This method displays the files for only the duplicates present in the directories.

displayfilesforusersearch: This method is called when the user gives input from the console.


Public Interface:
==============
void display(DataStore&);
void displayduplicateonly(DataStore&);
void filesearchfortext(std::vector<std::string>);
void displayfilesforusersearch(std::vector<std::string>);

Required Files:
===============
DataStore.h, Display.cpp


Build Command:
==============
cl /EHa /DTEST_DISPLAY Display.cpp

Maintenance History:
====================
ver 2.3: 09 Feb 15
Created Test stubs and commented meaningful informations for each methods
* ver 2.2 : 06 Feb 15
*Started integrating this module with the remaining modules. Cleared are the link errors.
Removed the unwanted header files that caused link error
* ver 2.1 :
* moved the functions from the Filemanager and created a new method in the Display package
* ver 2.0 : 04 Feb 15
* - made a few small changes to display the files and path stored in the map
with the help of Professor's code
* ver 1.0 : 23 Jan 15
* - first release

*/
#include"../DataStore/DataStore.h"
class Display
{
public:
	void display(DataStore&);
	void displayduplicateonly(DataStore&);
	void filesearchfortext(std::vector<std::string>);
	void displayfilesforusersearch(std::vector<std::string>);
};

#endif