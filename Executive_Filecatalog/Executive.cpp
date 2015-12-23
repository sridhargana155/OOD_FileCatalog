/////////////////////////////////////////////////////////////////////////////
// Executive.cpp - Displays the data already stored in the data store map  //
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
#include "../FileMgr/FileMgr.h"
#include "../DataStore/DataStore.h"
#include <iostream>
#include"../Display/Display.h"
#include<vector>
#include<string>
#ifdef TEST_EXECUTIVE

//------------------------------<Controls the main flow execution in this application>-------------------------------------------------------

int main(int argc, char* argv[])
{

	if (argc == 1) // when nothing is given as command line input
	{
		std::string dir = FileSystem::Directory::getCurrentDirectory();
		std::vector<std::string> currentdirfiles = FileSystem::Directory::getFiles(dir, "*.*");
		cout << "There are " << currentdirfiles.size() << " files in 1 directory";
	}
	else if (argc == 2) // when only path is given as command line argument
	{
		DataStore ds;
		Display disp;
		FileMgr fm(argv[1], ds);
		cout << "The files present in the given directory alone are \n";
		std::vector<std::string> currentdirfiles = FileSystem::Directory::getFiles(argv[1], "*.*");
		for (auto f1 : currentdirfiles)
		 cout<< f1<<"\n";
		fm.addPattern("*.*");
		fm.searchnonrecursive();
		while (1)
		{
			string userpattern, usertext;
			cout << "\nEnter the pattern  in the format: .<pattern> (Eg: .h ) that you want to search from the existing data stored \n Or Simply type Exit to Sign Out to the next requirement\n";
			cin >> userpattern;
			if (userpattern == "exit" || userpattern == "Exit" || userpattern == "EXIT")
				break;
			cout << "Enter the searchtext you want to search from the existing data stored \n Or Simply type Exit to Sign Out to the next requirement\n";
			cin >> usertext;
			if (usertext == "exit" || usertext == "Exit" || usertext == "EXIT")
				break;
			std::vector<std::string> tmpforfilename;
			tmpforfilename = ds.userfilenamesforsearchtext(usertext, userpattern);
			disp.displayfilesforusersearch(tmpforfilename);
		}
	}
	else // when the all the requirement options are given as command line arguments
	{
		DataStore ds;
		Display disp;
		FileMgr fm(argv[1], ds);
		int checkerforpath = 0, checkerforpattern = 0, checkerforswitches = 0;
		std::vector<std::string> CopyArgumentsintoVector;
		CopyArgumentsintoVector.assign(argv + 1, argv + argc);
		for (auto tr : CopyArgumentsintoVector) // checking for the patterns in the command line argument with find()
		{
			if ((tr.find("../") != string::npos) || (tr.find("./") != string::npos) || (tr.find("\\") != string::npos))
			{
				checkerforpath++;
			}
		}
		for (auto tr : CopyArgumentsintoVector)
		{
			if ((tr.find("*.") != string::npos))
			{
				checkerforpattern++;
				fm.addPattern(tr);
				fm.searchnonrecursive();
			}
		}
		if (checkerforpattern == 0)
		{
			fm.addPattern("*.*");
		}
		else if (checkerforpattern>0)
		{
			int fors = 0;
			for (auto tr1 : CopyArgumentsintoVector)
			{
				if ((tr1.find("/s") != string::npos))
				{
					fors++;
				}
			}
			if (fors==0)
			disp.display(ds);
		}
		int s = 0; // checker for the presnece of s
		for (auto tr1 : CopyArgumentsintoVector)
		{
			int l = 0;
			if ((tr1.find("/s") != string::npos))
			{
				s++; // incrementing s if present
				for (auto tr1 : CopyArgumentsintoVector)
				{
					if (tr1.find("/d") != string::npos)
					{
						l++;
					}
				}
				if (l != 0) // when both /s and /d are present
				{
					fm.search();
					disp.displayduplicateonly(ds);
				}
				else // when only /s is present
				{
					fm.search();
					disp.display(ds);
				}
			}
			
			if ((tr1.find("/f") != string::npos)) // when /f is present
			{
				std::vector<std::string> tmp;
				int x = (tr1.find("/f") != string::npos) + 1;
				string textstring;
				textstring = tr1.substr(x);
				tmp = ds.searchtext(textstring);
				disp.filesearchfortext(tmp);
			}
		}
		for (auto tr1 : CopyArgumentsintoVector)
		{
			if ((tr1.find("/d") != string::npos) && s==0)
			{
				cout << "There are no duplicates in the current directory\n";
			}

		}
		// requirement 8 for repeatedly asking input from the end user through console
		while (1)
		{
			string userpattern, usertext;
			cout << "Enter the pattern in the format: .<pattern> (Eg: .h ) that you want to search from the existing data stored \n Or Simply type Exit to Sign Out to the next requirement\n\n";
			cin >> userpattern;
			if (userpattern == "exit" || userpattern == "Exit" || userpattern == "EXIT")
				break;
			cout << "Enter the searchtext you want to search from the existing data stored \n Or Simply type Exit to Sign Out to the next requirement\n\n";
			cin >> usertext;
			if (usertext == "exit" || usertext == "Exit" || usertext == "EXIT")
				break;
			std::vector<std::string> tmpforfilename;
			tmpforfilename = ds.userfilenamesforsearchtext(usertext, userpattern);
			disp.displayfilesforusersearch(tmpforfilename);
		}
	}
	return 0;
}
#endif