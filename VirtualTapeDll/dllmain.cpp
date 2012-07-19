#include <stdio.h>
#include <string.h>
#include <stdarg.h>


#include "dllmain.h"

#include "VirtualTapeDrive.h"
#include <string>
#include <iostream>

#include "VirtualTapeRobot.h"
#include "AmazonSimpleStorageService.h"

void testService(const std::string name) 

{
    CVirtualTapeDrive vtd;
    CVirtualTapeRobot vtr;
    AmazonSimpleStorageService service;
    service.createBucket(name);
    service.putObject(name, "EinObjekt");
    
}

int main(int argc, char** argv){
    testService("NewBucket");
    return 0;
}

