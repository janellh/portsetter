# **CS 3370 Portsetter**
==========================
This Program will set the listening port on the current working system.
Portsetter is language independent should change languages based on locale.



##**Run the program:**
type the command -> portsetter.cpp.o _[flags]_  
    where _[flags]_ are the options you want to run
    
    
###**Potential Flags**
-h   | --help    | -? ->  info about how to use the program **default** <br />
-p # | --port #       ->  sets the listening port to #<br />
-v   | --version      ->  prints the current version of the program.<br />
-!   | --about        ->  info about the program.<br /><br />
-p -e _[PORT]_        ->  _[PORT]_ is not listed and sets to default env port.<br />
--port -e _[PORT]_    ->  _[PORT]_ is not listed and sets to default env port.<br />
-p -e [MYPORT]        -> [MYPORT] is the enviorment port number.<br />
--port -e [MYPORT]    -> [MYPORT] is the enviorment port number.<br />
-p --enviroment _[PORT]_        ->  _[PORT]_ is not listed and sets to default env port.<br />
--port --enviroment _[PORT]_    ->  _[PORT]_ is not listed and sets to default env port.<br />
-p --enviroment [MYPORT]        -> [MYPORT] is the enviorment port number.<br />
--port --enviroment [MYPORT]    -> [MYPORT] is the enviorment port number.<br />

Running program anywhere the name would need to be added to the Alias list. 


###**How to add a Language**
- create the followng three text files within the information files folder.<br />
- portsetter.messages_[LC].txt<br />
- portsetter.about_[LC].txt<br />
- portsetter.usage_[LC].txt<br />



##**Run the testing program:**
--------------------------
To run the testing app ensure the portsetter.cpp.o file exists.
type the command -> portsetter.testing.cpp.o _[flags]_  
    where _[flags]_ are the options you want to run 

the testing program will start by setting the local of the "test enviorment"
to the value passed as flag 1 to test various languages.
Following the initalizaion the program will run all tests within the txt files
test_positive.txt
test_negative.txt



###**Potential Flags**
en      ->  tests the program in english **default**
_[LC]_    -> test the program in specified language

following the test programs completion the portsetter output will be store in,
results_[LC] file.



###**Adding a test**
Determine the expected result of the given test.
If the test should return 0 place the case in test_positive.txt
else place the test in test_negative.txt



note [LC]  should be filled with the language code.  
ie for example "portsetter.messages_en.txt"
where en = english.
