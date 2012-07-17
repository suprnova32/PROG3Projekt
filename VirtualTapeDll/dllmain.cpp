#include <stdio.h>
#include <string.h>
#include <stdarg.h>


#include "dllmain.h"

#include "VirtualTapeDrive.h"
#include <string>

#include "VirtualTapeRobot.h"
#include "AmazonSimpleStorageService.h"

void testService(const char *name) 

{
    CVirtualTapeDrive vtd;
    CVirtualTapeRobot vtr;
    AmazonSimpleStorageService service;
    service.createBucket(std::string(name));
    service.putObject(std::string(name), "EinObjekt");
    
}

