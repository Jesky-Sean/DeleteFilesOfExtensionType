# DeleteFileType WIP - deleting files of type (WIN64, LinuxOS - cross-platform safe) setup for deleting all media of <extension type(s)> off a computers drives to remove blackmail images or the like. (window is hidden from the user when program is running, stealth mode!!!!!)
review (i dont have peers right now still):
https://chatgpt.com/share/3c4a32fd-812e-41f7-a796-3e5fc9c4ce2b

whats cool is this was from the DeleteProgram Branch of FileTypeOrganization program and i learned how to move a branch, and use one and move it to its own repo eventually. was rather fun to do and learn (honestly hated  it, each second i hated)

by uncommenting you understand the risks. 

before compiling, uncomment the delete function, this function WILL DELETE FILES OF THE TYPE YOU DETERMINED! BE CAREFUL, WINDOW IS HIDDEN WHEN RUN BY USER!!!! STILL VISABLE IN TASK MANAGER.

line 85 |    llist->delete_files_of_type(path_to_delete_from, i);

this version - branch of my linked list is optimized for deleting nodes of  <type> fast. (toxic env. are no fun to stay in)
i hope this is used in a way that alligns with the spirit of why it was created and not to harm anyone, but help someone.

a program that delete files of specific types, setup to delete files of a type(s) specific to multimedia(not all, research your target system to know whats used first) made to delete images secretly. 
---

not yet tested on LinuxOS, kali, tested on windows (x64, x86):
but stupid inputs == stupid results, unttil i can place proper validation checks. (i almost always expect people will try and break it anyways, so i do that last. 
anyways, finished patching, will work on both OS's now: 

for LinuxOS - To compile code, go to directory of this programs files, open the command prompt to that location and run this command:

    clang++ main.cpp linked_list.cpp fsHelper.cpp -std=c++17 -lstdc++fs -o FileTypeDeleter.out
    or using gcc, g++.  
    [gcc/g++] main.cpp linked_list.cpp fsHelper.cpp -std=c++17 -lstdc++fs -o FileTypeD...

for windows - open in VS code double click on the .sln file, build program, then run form command line.

to run:

    [from compiled directory]./FTDeleter.out <source (directory location to copy from)>  


   ---
currently these options need to be changed in the code directly until final version of code is completed. (fixing bugs, fixing formatting, adding/removing a few things here and there first)



*how it works:*
---
[+] Each extension type is a node within a singly linked list. 

[+] Inside each node, from the directory deleting from, are all the files of that extension type and their location/path 

[+] Every extension type with that value (.mp3, .png, .jpeg, .jpg, etc.) will be deleted, 

---

more examples/explaining how it works:

---
whats cools is, the nature of nodes and sorting makes this all happen naturally. if the nodes are in order, then being copied over to its correct destination is as easy as reaching a node of that type. 
 
  go through vector of file paths, if -as it finds mp3 files:
  ![HowItWorks_](https://github.com/user-attachments/assets/b52dec5b-93eb-475f-b7c3-58d124f9bff7)

    [directory path]/.../.../***.mp4 > delete all files from system that are in this mp3 node
    [directory path]/.../.../***.tiff > delete all files from system that are in this mp3 node
    [directory path]/.../.../***.zip
    [directory path]/.../.../***.mp3 > delete all files from system that are in this mp3 node
    [directory path]/.../.../***.png > delete all files from system that are in this node
    [directory path]/.../.../***.tiff >delete all files from system that are in this mp3 node
    [directory path]/.../.../***.mp3 > delete all files from system that are in this mp3 node
    [directory path]/.../.../***.mp3 > delete all files from system that are in this mp3 node


collect the collection of extension namess to put into a node each of their own [Head Node] -...-> [mp3]->[mp4]->[m4a]-...->[Tail Node]


for each node in the linked list we visit, we delete files of that nodes extension type,

now we can delete from each node one by one (or multithread it if you really need speed... but you dont its fine as it is... u know... C++..) by accessing the node and reading the data within it.

do this for each file extension type (node) until all nodes have been visited.. and deleted of those types of files. 
---

i hope one of these helps explain it. depending on who you are one should at least be helpful. 

