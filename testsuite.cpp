#include "testsuite.h"
#include <iostream>
#include "LinkedListOfInts.h"
#include <vector>
#include "List.h"
#include "Node.h"
#include <exception>

using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

TestSuite::TestSuite()
{

}

void TestSuite::runTests()
{
    cout << "\n";
    testsWhenEmpty();
    testsWhenNonEmpty();
    cout << "All tests completed!" << "\n" << "\n";
}

void TestSuite::testsWhenEmpty()
{
    LinkedListOfInts* list = new LinkedListOfInts();
    LinkedListOfInts* list2 = new LinkedListOfInts();
    vector<int> myVector = list->toVector();
    int size = myVector.size();

    cout << "Test 1) An empty list of size 0 is created with constructor: ";
    if(size == 0)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 2) removeBack() returns false for an empty list: ";
    if(list->removeBack() == false)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 3) removeFront() returns false for an empty list: ";
    if(list->removeFront() == false)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 4) isEmpty() returns true for an empty list: ";
    if(list->isEmpty())
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 5) size() returns 0 for an empty list: ";
    if(list->size()==0)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 6) search(int) returns false for an empty list, given a randomInt: ";
    int randomInt = 40;
    if(list->search(randomInt) == false)
    {
       cout << "PASSED" << "\n";
    }
    else
    {
           cout << "FAILED" << "\n";
    }

    cout << "Test 7) addBack(int) adds a new element to an empty list which is considered to be at the back: ";
    list->addBack(10);
    myVector = list->toVector();
    size = myVector.size();
    int backVal = myVector.back();
    if(size == 1 && backVal == 10)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 8) addFront(int) adds a new element to an empty list which is considered to be at the front: ";
    list2->addFront(10);
    myVector = list2->toVector();
    size = myVector.size();
    int frontVal = myVector.front();
    if(size == 1 && frontVal == 10)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 9) removeBack() removes an element from the back of a list of size 1, resulting in an empty list: ";
    bool backRem = list->removeBack();
    myVector = list->toVector();
    size = myVector.size();
    if(size == 0)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 10) removeBack() returns true after being called on a non-empty list of size 1: ";
    if(backRem)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 11) removeFront() removes an element from the front of a list of size 1, resulting in an empty list: ";
    bool frontRem = list2->removeFront();
    myVector = list2->toVector();
    size = myVector.size();
    if(size == 0)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 12) removeFront() returns true after being called on a non-empty list of size 1: ";
    if(frontRem)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }
}

void TestSuite::testsWhenNonEmpty()
{
    LinkedListOfInts* list = new LinkedListOfInts();
    LinkedListOfInts* list2 = new LinkedListOfInts();

    list->addFront(5);
    list->addFront(4);
    list2->addFront(5);
    list2->addFront(4);
    vector<int> myVector;


    cout << "Test 13) size() returns correct value for a non-empty list: ";
    myVector = list->toVector();
    if(list->size()== myVector.size())
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 14) isEmpty() returns false for a non-empty list: ";
    if(list->isEmpty() == false)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 15) addBack(int) adds a new element to the back of a non-empty list: ";
    int size = myVector.size();
    list->addBack(6);
    myVector = list->toVector();
    int size2 = myVector.size();
    int backVal = myVector.back();
    if(size2 == (size+1) && backVal == 6)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 16) addFront(int) adds a new element to the front of a non-empty list: ";
    myVector = list2->toVector();
    size = myVector.size();
    list2->addFront(3);
    myVector = list2->toVector();
    size2 = myVector.size();
    int frontVal = myVector.front();
    if(size2 == (size+1) && frontVal == 3)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 17) search(int) returns false for a value not existing in a non-empty list: ";
    if(list->search(100) == false)
    {
       cout << "PASSED" << "\n";
    }
    else
    {
           cout << "FAILED" << "\n";
    }

    cout << "Test 18) search(int) returns true for a value existing in a non-empty list: ";
    if(list->search(5) == true)
    {
       cout << "PASSED" << "\n";
    }
    else
    {
           cout << "FAILED" << "\n";
    }

    cout << "Test 19) removeBack() removes an element from the back of a list of size exceeding 1: ";
    myVector = list->toVector();
    size = myVector.size();
    bool backRem = list->removeBack();
    myVector = list->toVector();
    size2 = myVector.size();
    if(size2 == (size-1))
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 20) removeBack() returns true after being called on a non-empty list of size exceeding 1: ";
    if(backRem)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 21) removeFront() removes an element from the front of a list of size exceeding 1: ";
    myVector = list2->toVector();
    size = myVector.size();
    bool frontRem = list2->removeFront();
    myVector = list2->toVector();
    size2 = myVector.size();
    if(size2 == (size-1))
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 22) removeFront() returns true after being called on a non-empty list of size exceeding 1: ";
    if(frontRem)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }

    cout << "Test 23) The destructor deletes all nodes in a non-empty list: ";
    delete list;
    delete list2;
    if(list3 == nullptr)
    {
        cout << "PASSED" << "\n";
    }
    else
    {
        cout << "FAILED" << "\n";
    }
    //anytime i try to access methods using list pointer, i get a seg fault. safe to say the list data is still floating somewhere in the heap since I can still access its info
    //using the toVector(); the destructor should have set the pointer to null after manually deleting the nodes, else it's not really 'deleted'. Also I get memory leaks from valgrind.
}


