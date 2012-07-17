/* 
 * File:   VirtualTapeDrive.h
 * Author: eternus
 *
 * Created on June 28, 2012, 9:57 PM
 */

#include "VirtualTape.h"

#ifndef VIRTUALTAPEDRIVE_H
#define	VIRTUALTAPEDRIVE_H

class CVirtualTapeDrive: public CVirtualTape {
public:
    virtual ResultCode testUnitReady(const TestUnitReady *cdb); 
    virtual ResultCode sendDiagnostic(const SendDiagnostic *cdb, void *data, int length); 
    virtual ResultCode initializeElementStatus(const InitializeElementStatus *cdb); 
    virtual ResultCode initializeElementStatusWithRange(const InitializeElementStatusWithRange *cdb); 
    virtual ResultCode inquire(const Inquire *cdb, void *data, int length); 
    virtual ResultCode requestSense(const RequestSense *cdb, void *data, int length); 
    virtual ResultCode read(const Read *cdb, void *data, int length); 
    virtual ResultCode write(const Write *cdb, const void *data, int length); 
    virtual ResultCode modeSense(const ModeSense *cdb, void *data, int length); 
    virtual ResultCode modeSelect(const ModeSelect *cdb); 
    virtual ResultCode moveMedium(const MoveMedium *cdb); 
    virtual ResultCode positionToElement(const PositionToElement *cdb);
    virtual ResultCode mediumRemoval(const MediumRemoval *cdb);
    virtual ResultCode readElementStatus(const ReadElementStatus *cdb, void *data, int length);
    virtual ResultCode release(const Release *cdb);
    virtual ResultCode reserve(const Reserve *cdb);
    virtual ResultCode rewind(const Rewind *cdb);
    virtual ResultCode space(const Space *cdb);
    virtual ResultCode erase(const Erase *cdb);
    virtual ResultCode writeFilemark(const WriteFilemark *cdb);
    virtual ResultCode readBlockLimits(const ReadBlockLimits *cdb, void *data, int length);
};

#endif	/* VIRTUALTAPEDRIVE_H */

