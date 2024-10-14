//"fsHelper.cpp"
#include "fsHelper.h"
#include <iostream>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;
typedef fs::path element_t;
#include <cmath>

/// @brief collect all filenames and their paths from the Source location provided by the user to use within the rest of the program.
/// @param const fs::path == element_t, directory location to search for filenames, and the data associated with their use within the program
/// @return const inline vector<element_t>
/// multi-variable [directory(s) with files to copy] function overload

const std::vector<element_t> collect_relivant_files(const std::vector<element_t>& directory, const std::vector<element_t>& extns_to_delete)
{
	std::unique_ptr<std::vector<element_t>> vfiles(new std::vector<element_t>);
	vfiles->reserve(500'000);
	try {
		for (auto dir_iter : directory) {
			for (const fs::directory_entry& dir : fs::recursive_directory_iterator{ dir_iter , fs::directory_options::skip_permission_denied })
			{
				const element_t& file_path = dir;
				const element_t* file_path_p = &file_path;

				if (!fs::is_directory(*file_path_p))
				{
					if (file_path_p->has_extension())
					{	//check these are files are of the type we need to delete later on, as to not store every file of every type as we go.
						for (auto& i : extns_to_delete) {
							if (file_path_p->extension() == i) { //significant reduction in ram (110%) just by changing this to look for specific ext. types instead of during organization of nodes.
								vfiles->push_back(*file_path_p);
								//std::cout << "File:\t" << *file_path_p << '\n';
							}
						}
					}
				}
			}
		}
	}
	catch (std::filesystem::filesystem_error& err) {
		//std::cout << "Filesys error" << "\n" << err.what() << std::endl;
	}
	return *vfiles; //this is. mistake, its not cleaned up (now fixed though), if the vector was stack allocated it woulbe but by using new, im responsible if i use new, to use delete |||||| this should be deleted by RAII (Resource aq. is initialization.. what a bad name) anyways, it should be deleted at the end of scope so no leaks should be happening.
}
/// @brief create a directorys from the extensions of the files collected from earlier.
/// @param const element_t base_save_location -  destination location; where to save folders, and files.
/// @param const vector<element_t>* extensions - a vector of pointers to a vector of extension types collected from the files

/* 
	* This functionality will store the logged info. from this computer (computer's name, information on the files, etc.) to the location where the program is running for later analysis or proof later is/if required.
	* The data will be locked with a password provided by the user and will be hardcoded in this program, this program will delete itself then after, using pgp/gpg decryption tools on the file will yeld the data.
	* that would be some cool tooling i think.
	* program runs > program stores system info, file deleted info, etc. > program deletes itself (store itself on a page maybe, then delete from memory, while running process from a page idk yet) > only thing left (if requested by user beforehand, is a log of what was deleted, encrypted so only they will know) 


void create_directory_from_extension_type(const element_t base_save_location, const element_t curr_extension)
{
	fs::create_directory((base_save_location.string()) + curr_extension.string().erase(0, 1));
}
*/