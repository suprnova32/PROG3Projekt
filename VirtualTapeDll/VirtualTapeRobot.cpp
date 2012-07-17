/* 
 * File:   VirtualTapeRobot.h
 * Author: eternus
 *
 * Created on June 28, 2012, 9:59 PM
 */

#include <scsi/scsi.h>

#include "VirtualTapeRobot.h"

ResultCode CVirtualTapeRobot::testUnitReady(const TestUnitReady *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::sendDiagnostic(const SendDiagnostic *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::initializeElementStatus(const InitializeElementStatus *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::initializeElementStatusWithRange(const InitializeElementStatusWithRange *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::inquire(const Inquire *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::requestSense(const RequestSense *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::read(const Read *cdb, void *data, int length)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeRobot::write(const Write *cdb, const void *data, int length)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeRobot::modeSense(const ModeSense *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::modeSelect(const ModeSelect *cdb) 

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::moveMedium(const MoveMedium *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::positionToElement(const PositionToElement *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::mediumRemoval(const MediumRemoval *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::readElementStatus(const ReadElementStatus *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::release(const Release *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::reserve(const Reserve *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeRobot::rewind(const Rewind *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeRobot::space(const Space *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeRobot::erase(const Erase *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeRobot::writeFilemark(const WriteFilemark *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeRobot::readBlockLimits(const ReadBlockLimits *cdb, void *data, int length)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

