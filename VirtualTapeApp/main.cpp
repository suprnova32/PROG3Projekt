#include <cstdlib>
//#include "dllmain.h"
#include "AmazonSimpleStorageService.h"

using namespace std;

/*
 * 
 */


void testService(const std::string &name) 

{
    AmazonSimpleStorageService service;
    service.createBucket(name);
    service.putObject(name, "EinObjekt");
    
}

int main(int argc, char** argv) 

{
    testService("Teste2");
    return 0;
}

