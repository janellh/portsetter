This Program will set the listening port on the current working system.
Portsetter is language independent will change languages based on locale.
To run the testing app ensure the portsetter is compiled and the object file exists.
run the testing command. If no perams are passed the tests will be run in english.
optional perams possible are a two char language code to test the program in that language.
ie portsetter.cpp.o es runs the tests in spanish because of the es. results will be stored 
in results_[LC] file.

If your language is not supported add it using the following steps

*********************************** ADD LANGUAGES **********************************
To add a language to the program create three text files within the information files folder
name the files the following

    portsetter.messages_[LC].txt
    portsetter.about_[LC].txt
    portsetter.usage_[LC].txt

[LC]  should be filled with the language code.  for example "portsetter.messages_en.txt"
where en = english.