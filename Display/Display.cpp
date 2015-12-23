/////////////////////////////////////////////////////////////////////////////
// Display.cpp - Displays the data already stored in the data store map    //
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
#include"Display.h"
#include<map>

//-------------------------------------------------<Displays the filenames and path from directories and its sub directories>--------------------------------------------------------------------------------------------------------

void Display::display(DataStore& ds)
{
	cout << "The output is: \n\n";
	for (ds.itr = ds.store.begin(); ds.itr != ds.store.end(); ++ds.itr)
	{
		std::cout << "FileName: \t" << ds.itr->first << "\n";
		for (ds.litr = ds.itr->second.begin(); ds.litr != ds.itr->second.end(); ds.litr++)
			std::cout << "Path: \t" << **(ds.litr) << "\n";
	}
}

//-------------------------------------------------<Displays only the duplicate filenames and path from the directories and its sub directories>--------------------------------------------------------------------------------------------------------

void Display::displayduplicateonly(DataStore& ds)
{
	cout << "Only the duplicate files along with its path present in both current directory and its sub-directories are displayed below: \n\n";
	for (ds.itr = ds.store.begin(); ds.itr != ds.store.end(); ++(ds.itr))
	{
		int listchecker = 0;
		for (ds.litr = ds.itr->second.begin(); ds.litr != ds.itr->second.end(); (ds.litr)++)
		{
			listchecker++;
		}
		if (listchecker > 1)
		{
			std::cout << "FileName: \t" << ds.itr->first << "\n";
			for (ds.litr = ds.itr->second.begin(); ds.litr != ds.itr->second.end(); (ds.litr)++)
				std::cout << "Path: \t" << **(ds.litr) << "\n";
		}
	}
	cout << "\n";
}

//-------------------------------------------------<Searches the filenames and paths for the matching text from the command line arguments already given>--------------------------------------------------------------------------------------------------------


void Display::filesearchfortext(std::vector<std::string> tmp)
{
	for (auto t1 : tmp)
	{
		cout << t1;
		if (t1.find(".") != string::npos)
			cout << " ==> ";
		else
			cout << "\n";
	}
}

//-------------------------------------------------<Searches the filenames and paths for the matching text from the console when the end user is giving>--------------------------------------------------------------------------------------------------------


void Display::displayfilesforusersearch(std::vector<std::string> tmp)
{
	for (auto t1 : tmp)
	{
		cout << t1;
		if (t1.find(".") != string::npos)
			cout << " ==> ";
		else
			cout << "\n";
	}
}

//------------------------------------------------<Test Stub>---------------------------------------------------------------------------------

#ifdef TEST_DISPLAY
int main()
{
	DataStore ds;
	ds.save("Filename.h", "./TestCheck");
	Display disp;
	disp.display(ds);
	disp.displayduplicateonly(ds);
	std::vector<std::string> test_vector;
	test_vector.push_back("Filename.h");
	test_vector.push_back("Path1");
	test_vector.push_back("Filename1.h");
	test_vector.push_back("Path2");
	disp.displayfilesforusersearch(test_vector);
	disp.filesearchfortext(test_vector);
}
#endif