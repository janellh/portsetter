#include <iostream>
#include <vector>
#include <fstream>
#include <string> 


using namespace std;

/******************************
Tanner Frandsen
CS 3370-001
Sep 22 2016
Professor Wagstaff
******************************/

 /********************************************************Function Prototypes ********************************************************/
 
//purpose: Print utility usage information
//Peram 1: const string langCode = "en" language code for the language file you want to open
//Throw: None
//Returns: void
void printUsage(const string langCode = "en");

//purpose: Print information about utility
//Peram 1: const string langCode = "en" language code for the language file you want to open
//Throw: None
//Returns: void
void printAbout(const string langCode = "en");

//purpose: Validates port number recieved it indeed a number and converts valid string to int.
//Peram 1: string: portNumber desitred port number to convert
//Throw: int bad string or invalid port number
//Returns: int converted from string
int validPortNumber(string portNumber);

//purpose: check the env and get the language local
//Peram 1: none
//Throw: none
//Returns: string that symbolized the 2 char language code
string getEnvLanguage();



int main(int argc, char * args[]) {

	const string VERSION_NUM = "0.3.0a";
	char * portNumber = char();
	vector <string> messages;
	string langCode = string();
	string path = "InformationFiles/portsetter.messages_";
	fstream messagesFile;
	
	//	To make the cout statements more readable use enum as vector refferences
	enum {	
		VERSION, 
		LANG_NOT_FOUND,
		E_BAD_ENV_PORT,
		E_BAD_ARG,
		E_INVALID_NUM_ARG,
		E_BAD_PORT,
		E_ENG_NOT_FOUND,
		LISTENING_ON_PORT
	};
	
	//get language and init the program
	langCode = getEnvLanguage();
	
	path.append(langCode);
	path.append(".txt");
	
	//open appropriate vector folder
	messagesFile.open(path);
	
	if (messagesFile.rdstate() != 0) {
		//error reading language messages defualt to english
		cout << langCode << " translation file not found, Default to English" << endl;
		messagesFile.open("InformationFiles/portsetter.messages_en.txt");
		if (messagesFile.rdstate() != 0) {
			cout << "Error Reading English Messages." << endl;
			return 1;
		}
	}
	
	// pushback messages into vector
	while (!messagesFile.eof()) {
		 getline(messagesFile, path);
		 messages.push_back(path);
	}
	
	// close file
	messagesFile.close();
	
	//------------------------------------------------------------- 0 ARG --------------------------------------------------------------------------------//
	if (argc == 1) { //no perams passed
		printUsage(langCode);
		return 0;
	}
	
	//------------------------------------------------------------- 1 ARG --------------------------------------------------------------------------------//
	if (argc == 2) {	//asking for help
		if (string(args[1]) == "-v" ||string(args[1]) == "--version" ) {
			cout << endl << messages[VERSION] << " "<< VERSION_NUM << endl;
			return 0;
		}
		if (string(args[1]) == "-!" ||string(args[1]) == "--about" ) {
			printAbout(langCode);
			return 0;
		}
		if (string(args[1]) == "-h" || string(args[1]) == "--help" || string(args[1]) == "-?") {
			printUsage(langCode);
			return 0;
		}
		if (string(args[1]) == "-p" || string(args[1]) == "--port" ) {
			cout << messages[E_BAD_PORT] << endl;
			printUsage(langCode);
			return 3;
		}
		cout << messages[E_BAD_ARG] << endl;
		printUsage(langCode);
		return 1;
	}
	
	//------------------------------------------------------------- 3 ARG --------------------------------------------------------------------------------//
	if (argc == 3) { //trying to use utility
		if ((string(args[1]) == "-p" || string(args[1]) == "--port")) {
			try {	//if error thrown catch and exit with invalid port number
					cout << messages[LISTENING_ON_PORT] <<" "<< validPortNumber(args[2]) << endl;
					return 0;
				}
			catch (...) {
				if(string(args[2]) == "-e") {
					portNumber = getenv("PORT");
					try {
						cout << messages[LISTENING_ON_PORT] <<" "<< validPortNumber(portNumber) << endl;
						return 0;
					}
					catch (...){
						cout << messages[E_BAD_ENV_PORT] << endl;
						printUsage(langCode);
						return 1;
					}
				}
				cout << messages[E_BAD_PORT] << endl;
				printUsage(langCode);
				return 3;
			}
		}
	}
	//------------------------------------------------------------- 4 ARG --------------------------------------------------------------------------------//
	if (argc == 4) { 
		// if here they are trying to set the port to user defined enviorment port
		if ((string(args[1]) == "-p" || string(args[1]) == "--port")) {
			if (string(args[2]) == "-e" ){
				try {
					cout << messages[LISTENING_ON_PORT] << " " << validPortNumber(portNumber) << endl; //try to get number
					return 0;
				}
				catch (...) { //error occured in validating port number
					cout << messages[E_BAD_ENV_PORT] << " " << args[3] << endl;
					printUsage(langCode);
					return 1;
				}
			}
		cout << messages[E_INVALID_NUM_ARG]	 << endl;
		printUsage(langCode);
		return 2;
		}
	}		
			
	else //argc > 4
	cout << messages[E_INVALID_NUM_ARG] << endl;
	printUsage(langCode);
	return 2;
}


//purpose: Print utility usage information
//Peram 1: const string langCode = "en" language code for the language file you want to open
//Throw: None
//Returns: void
void printUsage(const string langCode) {
	
	fstream aboutFile;
	string line = "InformationFiles/portsetter.usage_";
	
	line.append(langCode);	//get the language
	line.append(".txt");
	
	
	aboutFile.open(line);
	
	
	if (aboutFile.rdstate() != 0) {
		
		cout << langCode << " file not found, defualt to English." << endl;
		aboutFile.open("InformationFiles/portsetter.usage_en.txt");
		if (aboutFile.rdstate() != 0 ) {
			cout << "Error: English file not found." << endl;
			return;
		}
	}
	while(!aboutFile.eof()) {
		getline(aboutFile, line);
		cout << line << endl;
	}
	aboutFile.close();
}


//purpose: Print information about utility
//Peram 1: const string langCode = "en" language code for the language file you want to open
//Throw: None
//Returns: void
void printAbout(const string langCode) {
	
	fstream usageFile;
	string line = "InformationFiles/portsetter.about_";
	
	line.append(langCode);	//get the language
	line.append(".txt");
	
	
	usageFile.open(line);
	
	
	if (usageFile.rdstate() != 0) {
		
		cout << langCode << " file not found, defualt to English." << endl;
		usageFile.open("InformationFiles/portsetter.about_en.txt");
		if (usageFile.rdstate() != 0 ) {
			cout << "Error: English file not found." << endl;
			return;
		}
	}
	while (!usageFile.eof())
	{
		getline(usageFile, line);
		cout << line << endl;
	}
	usageFile.close();
}


//purpose: Validates port number recieved it indeed a number and converts valid string to int.
//Peram 1: string: portNumber desitred port number to convert
//Throw: int bad string or invalid port number
//Returns: int converted from string
int validPortNumber(string portNumber) {
	const int MAX_PORT_NUM = 65535;
	const int MIN_PORT_NUM = 1;
	int port;
	
	for (int i = 0; i < portNumber.length(); ++i) {	
		//first check to see if is totally number
		if (!isdigit(portNumber[i])) throw i;
	}
	
	port = stoi(portNumber);
	if (port > MAX_PORT_NUM || port < MIN_PORT_NUM ) throw port;

	return port;
}


//purpose: check the env and get the language local
//Peram 1: none
//Throw: none
//Returns: string that symbolized the 2 char language code
string getEnvLanguage() {
	char * language = char();
	string s_language = string();

	vector <string> localeBank;
	localeBank.push_back("LANGUAGE");
	localeBank.push_back("LC_ALL");
	localeBank.push_back("LC_MESSAGES");
	localeBank.push_back("LANG");
	
	for (int i = 0; i < localeBank.size(); i++) {
		language = getenv(localeBank[i].c_str());
		
		if (language != nullptr && string(language) != "" && string(language) != "C"  && string(language) != "C.UTF-8" ) {
			s_language = string(language);
			
			if (s_language.length() >= 2) return  s_language.substr(0,2);
		}
	}	
		
	//no language found Default to english
	return "en";
}