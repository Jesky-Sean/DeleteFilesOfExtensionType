//"linked_list.cpp"
#include "linked_list.h"
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <string>


/// <summary>
/// create node and link, and add elements of data to the next node
/// </summary>
linked_list& linked_list::add_to_tail_node(element_t& el, std::vector<element_t>& vector_of_elements)
{
	size_t total_node_cnt = 0;

	if (head != nullptr) {
		tail->pNext_link = new node(el, vector_of_elements);
		tail = tail->pNext_link;
	}
	else {
		head = tail = new node(el, vector_of_elements);
	}

	return *this;
}



/// <summary>
/// print each node and its elem name.
/// </summary>
void linked_list::print_all_linked_list_node_data() const
{
	for (node* current = head; current; current = current->pNext_link)
	{
		for (auto& fs_iter : current->files_of_type)
		{
			std::cout << fs_iter << '\n';
		}
	}
}
/// <summary>
/// print the linked list node w/ correct elem. and data within it.
/// </summary>
void linked_list::print_all_linked_node_data(const element_t& elems) const
{
	for (node* current = head; current; current = current->pNext_link)
	{
		//check !empty()
		if (current->file_extension_type.string() == elems.string())
		{
			for (auto& fs_iter : current->files_of_type)
			{
				std::cout << fs_iter << '\n';
			}
		}
	}
}
//TODO: change these two programs above to log to a file in the dir. where the program is being run instead.


/// <summary>
/// collect, sort, and organize files (and their file extensions),
/// collected, then organize all the data into the linked list nodes of their type
/// </summary>
/// i dont like how this function looks or how it works, can and should be optimized.
linked_list& linked_list::orgainze_nodes(const std::vector<element_t>& collected_file_data, element_t& previous_exten)
{
	
	//std::vector<std::string>* p_types = new std::vector<std::string>; //old way to allocate memory
	std::unique_ptr<std::vector<std::string>> p_types(new std::vector<std::string>);	//new way to allocate memory .... ill take time, but i like it.

	p_types->reserve(collected_file_data.size());

	//iterate over all the files from the dir. provided by  the user
	for (const auto& current_filename : (collected_file_data))
	{
		if (current_filename.has_extension())
		{
			//collect all extensions from the files within the directory as iteration goes over them
			std::string path_str = current_filename.extension().string();
			p_types->push_back(path_str);
		}
	}
	//sort all the types collected - makes it so they are easy to remove duplicates.
	std::sort(p_types->begin(), p_types->end());

	std::vector<element_t> data;
	unsigned int counter = 0;

	for (auto& extn : *p_types) // go through a vector of extensions one by one
	{
		if (previous_exten != extn) //<--- chatgpt line
		{
			previous_exten = (*p_types)[counter];
			for (const auto& cfto : collected_file_data)
			{
				//remove duplicates.
				if ((*p_types)[counter] == cfto.extension().string())
				{
					data.push_back(cfto);
				}
			}
			//std::cout << previous_exten << '\t' << data->size() << '\n';
			//uncomment above to display the data within the nodes, eg. files found in each catagory.: 
			/*	".JPG"  1
				".PNG"  90
				".jpg"  96
				".mp4"  11
				".png"  2803
			*/
			add_to_tail_node(previous_exten, data);
			//data is used to transfer into the tail node, after that its cleard for the next nodes data, as the prev. entrys are now stored in the prev. node.
			data.clear();

		}
		counter += 1;
	}
	return *this;
}//this might have been more efficent using a map instead, but i like vectors, i like how they sound and look so eh.

// be careful, must be used after organize_nodes.
//worried this doesnt cover all conditions, so im thinking about how to make sure it covers cases like jpEg, and the like
linked_list& linked_list::delete_files_of_type_in_nodes()
{
	for (node* current = head; current; current = current->pNext_link) {
			for (auto& file_in_node : current->files_of_type) {
//TODO: add logging option to show what was deleted if required later on.
#if _WIN64
				DeleteFileA(file_in_node.string().c_str());
#elif _WIN32
				DeleteFileA(file_in_node.string().c_str());
#elif				
				fs::remove(file_in_node.string().c_str());
#endif
			}
	}
	return* this;
}

//for_testing_only, if this is active, and if the program reads corn from a file, it will terminate the program.
int kill_switch(element_t kill_condition) {
	if (kill_condition == ".CARROTS" || kill_condition == ".carrots")
		throw std::logic_error("reached testing kill point");
	else {
		//std::cout << "No corn discovered in these parts... yet!";
	}
	return 0;
}

