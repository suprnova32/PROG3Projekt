/* 
 * File:   VirtualTapeDrive.h
 * Author: eternus
 *
 * Created on June 28, 2012, 9:57 PM
 */

#include "VirtualTapeDrive.h"

ResultCode CVirtualTapeDrive::testUnitReady(const TestUnitReady *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::sendDiagnostic(const SendDiagnostic *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::initializeElementStatus(const InitializeElementStatus *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeDrive::initializeElementStatusWithRange(const InitializeElementStatusWithRange *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeDrive::inquire(const Inquire *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::requestSense(const RequestSense *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::read(const Read *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::write(const Write *cdb, const void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::modeSense(const ModeSense *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::modeSelect(const ModeSelect *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::moveMedium(const MoveMedium *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeDrive::positionToElement(const PositionToElement *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeDrive::mediumRemoval(const MediumRemoval *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::readElementStatus(const ReadElementStatus *cdb, void *data, int length)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeDrive::release(const Release *cdb)

{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeDrive::reserve(const Reserve *cdb)


{
    senseKey = ILLEGAL_REQUEST;
    return CHECK_CONDITION;
}

ResultCode CVirtualTapeDrive::rewind(const Rewind *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::space(const Space *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::erase(const Erase *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::writeFilemark(const WriteFilemark *cdb)

{
    senseKey = NO_SENSE;
    return GOOD;
}

ResultCode CVirtualTapeDrive::readBlockLimits(const ReadBlockLimits *cdb, void *data, int length)

{
    senseKey = NO_SENSE;
    return GOOD;
}


