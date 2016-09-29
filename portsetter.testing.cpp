#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/******************************
 
Tanner Frandsen
CS 3370-001
Sep 13 2016
Professor Wagstaff

******************************/


/***************** Function Prototypes *************/
//purpose: Checks to see if the file exists
//Peram 1: char * name = name of the file you are looking for
//Throw: None
//Returns: bool true if the file exists
bool testObjectExists(const char * name);



//purpose: Test the various programs
//Peram 1: None
//Throw: None
//Returns: 0 if succuessful, non-zero if failure
int main(int argc, char * args[]) {
    int negativeTestsCount = 0;
    int positiveTestsCount = 0;
    int testFailures = 0;
    int statusCode = int();
    string outputFileName = " >> InformationFiles/testResults_";
    string setEnvLang = "export LANGUAGE=";
    if (argc > 1)
    {
        setEnvLang.append(args[1]);
        setEnvLang.append(" && ");
        outputFileName.append(args[1]);
        outputFileName.append(".txt");
    }
    else {
        setEnvLang.append("en && ");
        outputFileName.append("en.txt");
    }
    
    
    
    
    vector<string> positiveTests;
    vector<string> negativeTests;

    if (!testObjectExists("./portsetter.cpp.o")) {
        cout << "Error reading testing object, Please see the README" << endl;
        return 1;
    }


//*************************************** Positive Test File ************************************//
    fstream testFile;
	string path = "InformationFiles/test_positive.txt";
	
    testFile.open(path);
    if (testFile.rdstate() != 0) {
        cout << "Error opening " << path << endl;
        return 1;
    }
    
	while(!testFile.eof())
	{
	    getline(testFile, path);
		positiveTests.push_back(path.c_str());
	}
	testFile.close();
	
	
	//*************************************** Negative Test File ************************************//
	 testFile;
	 path = "InformationFiles/test_negative.txt";
	
    testFile.open(path);
    if (testFile.rdstate() != 0) {
        cout << "Error opening " << path << endl;
        return 1;
    }
    
	while(!testFile.eof())
	{
	    getline(testFile, path);
		negativeTests.push_back(path.c_str());
		
	}
	testFile.close();

	
    
    cout << "--------------------- Testing ---------------------" << endl;
    for (int i= 0; i < positiveTests.size(); ++i)  {
        //append together the desired test string and fire the test.
        
        positiveTests[i].insert(0,setEnvLang);
	    positiveTests[i].append(outputFileName);
	    statusCode = system(positiveTests[i].c_str()) / 256;
    
        positiveTestsCount++;
        if (statusCode != 0) {
            testFailures++;
            cout << "Test failed inappropriately on test: " << positiveTests.at(i) << "  returned: " << statusCode << endl;
        }
    }
    

    for (int i = 0; i < negativeTests.size(); ++i) {
        //append together the desired test string and fire the test. 
        
        
        negativeTests[i].insert(0,setEnvLang);
	    negativeTests[i].append(outputFileName);
	    statusCode = system(negativeTests[i].c_str()) / 256;

        negativeTestsCount++;
        if (statusCode == 0) {
            testFailures++;
            cout << "Test passed inappropriately on test: " << negativeTests.at(i) << "  returned: " << statusCode << endl;
        }
    }

    
    cout << "--------------------- Test Results ---------------------" << endl;
    cout << "Executed Positive Tests: " << positiveTestsCount << endl;
    cout << "Executed Negative Tests: " << negativeTestsCount <<  endl;
    cout << "Total Executed Tests:    " << negativeTestsCount + positiveTestsCount <<  endl;
    cout << "Total Failed Tests       " << testFailures << endl;
    cout << "--------------------- End Test Results ---------------------" << endl;
    
    return 0;
}


//purpose: Checks to see if the file exists
//Peram 1: char * name = name of the file you are looking for
//Throw: None
//Returns: bool true if the file exists
bool testObjectExists(const char * name) {
    ifstream file;
    file.open(name);
    return file.good();
}

