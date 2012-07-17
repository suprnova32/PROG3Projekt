/* 
 * File:   CVirtualTape.h
 * Author: eternus
 *
 * Created on June 28, 2012, 3:39 PM
 */

#ifndef CVIRTUALTAPE_H
#define	CVIRTUALTAPE_H

#include <scsi/scsi.h>

typedef int ResultCode;

struct TestUnitReady {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x00
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 3
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 5
    unsigned int control:8; // Shall be 0x00
};

struct SendDiagnostic {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x1D
    // Byte 1
    unsigned int lun:3; 
    unsigned int pageFormat:1; 
    unsigned int reserved1:1; // Shall be 0x00
    unsigned int selfTest:1; 
    unsigned int deviceOffline:1; 
    unsigned int unitOffline:1; 
    // Byte 2
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 3
    unsigned int paramListLengthByte0:8; 
    // Byte 4
    unsigned int paramListLengthByte1:8; 
    // Byte 4
    unsigned int control:8; 
};

struct InitializeElementStatus {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x07
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 3
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 5
    unsigned int control:8; // Shall be 0x00
};

struct InitializeElementStatusWithRange {
    // Byte 0
    unsigned int opcode:8; // Shall be 0xE7
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:4; // Shall be 0x00
    unsigned int range:1;
    // Byte 2
    unsigned int startElementByte0:8;
    // Byte 3
    unsigned int startElementByte1:8;
    // Byte 4
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 5
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 6
    unsigned int numElementByte0:8;
    // Byte 7
    unsigned int numElementByte1:8;
    // Byte 8
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 9
    unsigned int reserved5:8; // Shall be 0x00
};

struct Inquire {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x12
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:4; // Shall be 0x00
    unsigned int evpd:1;
    // Byte 2
    unsigned int pageCode:8;
    // Byte 3
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 4
    unsigned int allocationLength:8;
    // Byte 5
    unsigned int reserved3:8; // Shall be 0x00
};

struct RequestSense {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x03
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:4; // Shall be 0x00
    unsigned int evpd:1;
    // Byte 2
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 3
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4
    unsigned int allocationLength:8;
    // Byte 5
    unsigned int reserved4:8; // Shall be 0x00
};

struct Read {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x08
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:3; // Shall be 0x00
    unsigned int sili:1;
    unsigned int fixed:1;
    // Byte 2
    unsigned int startElementByte0:8;
    // Byte 3
    unsigned int startElementByte1:8;
    // Byte 4
    unsigned int startElementByte4:8;
    // Byte 5
    unsigned int control:8; // Shall be 0x00
};

struct Write {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x08
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:3; // Shall be 0x00
    unsigned int sili:1;
    unsigned int fixed:1;
    // Byte 2
    unsigned int startElementByte0:8;
    // Byte 3
    unsigned int startElementByte1:8;
    // Byte 4
    unsigned int startElementByte4:8;
    // Byte 5
    unsigned int control:8; // Shall be 0x00
};

struct ModeSense6 {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x1A
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:1; // Shall be 0x00
    unsigned int dbd:1; // Shall be 0x01
    unsigned int reserved2:3; // Shall be 0x00
    // Byte 2
    unsigned int pageControl:2;
    unsigned int pageCode:6;
    // Byte 3    
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4    
    unsigned int allocation:8;
    // Byte 5    
    unsigned int reserved4:8; // Shall be 0x00
};

struct ModeSense10 {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x1A
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:1; // Shall be 0x00
    unsigned int dbd:1; // Shall be 0x01
    unsigned int reserved2:3; // Shall be 0x00
    // Byte 2
    unsigned int pageControl:2;
    unsigned int pageCode:6;
    // Byte 3    
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4    
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 5    
    unsigned int reserved5:8; // Shall be 0x00
    // Byte 6    
    unsigned int reserved6:8; // Shall be 0x00
    // Byte 7    
    unsigned int allocationByte0:8;
    // Byte 8    
    unsigned int allocationByte1:8;
    // Byte 9    
    unsigned int reserved7:8; // Shall be 0x00
};

union ModeSense {
    ModeSense6 modeSense6;
    ModeSense10 modeSense10;
};

struct ModeSelect6 {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x15
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8;
    // Byte 3
    unsigned int reserved3:8;
    // Byte 4    
    unsigned int allocation:8;
    // Byte 5    
    unsigned int control:8; 
};

struct ModeSelect10 {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x55
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8;
    // Byte 3
    unsigned int reserved3:8;
    // Byte 4
    unsigned int reserved4:8;
    // Byte 5
    unsigned int reserved5:8;
    // Byte 6
    unsigned int reserved6:8;
    // Byte 7    
    unsigned int allocationByte0:8;
    // Byte 8    
    unsigned int allocationByte1:8;
    // Byte 9    
    unsigned int control:8; 
};

union ModeSelect {
    ModeSelect6 modeSelect6;
    ModeSelect10 modeSelect10;
};

struct MoveMedium {
    // Byte 0
    unsigned int opcode:8; // Shall be 0xA5
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int transportByte0:8;
    // Byte 3
    unsigned int transportByte1:8;
    // Byte 4
    unsigned int sourceByte0:8;
    // Byte 5
    unsigned int sourceByte1:8;
    // Byte 6
    unsigned int destinationByte0:8;
    // Byte 7
    unsigned int destinationByte1:8;
    // Byte 8
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 9
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 10
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 11
    unsigned int reserved5:8; // Shall be 0x00
};

struct PositionToElement {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x2B
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int transportByte0:8;
    // Byte 3
    unsigned int transportByte1:8;
    // Byte 4
    unsigned int destinationByte0:8;
    // Byte 5
    unsigned int destinationByte1:8;
    // Byte 6
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 7
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 8
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 9
    unsigned int reserved5:8; // Shall be 0x00
};

struct MediumRemoval {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x1E
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8;
    // Byte 3
    unsigned int reserved3:8;
    // Byte 4    
    unsigned int allocation:7;
    unsigned int prevent:1;
    // Byte 5    
    unsigned int control:8; 
};

struct ReadElementStatus {
    // Byte 0
    unsigned int opcode:8; // Shall be 0xB8
    // Byte 1
    unsigned int lun:3; 
    unsigned int volTag:1; 
    unsigned int typeCode:4; 
    // Byte 2
    unsigned int startElementByte0:8;
    // Byte 3
    unsigned int startElementByte1:8;
    // Byte 4
    unsigned int numElementByte0:8;
    // Byte 5
    unsigned int numElementByte1:8;
    // Byte 6
    unsigned int reserved1:7; // Shall be 0x00 
    unsigned int dvcid:1;
    // Byte 7
    unsigned int allocationByte0:8;
    // Byte 8    
    unsigned int allocationByte1:8;
    // Byte 9
    unsigned int allocationByte2:8;
    // Byte 10
    unsigned int reserved2:8; // Shall be 0x00 
    // Byte 11
    unsigned int reserved3:8; // Shall be 0x00 
};

struct Release {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x17
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 3
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 5
    unsigned int reserved5:8; // Shall be 0x00
};

struct Reserve {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x16
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 3
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 5
    unsigned int reserved5:8; // Shall be 0x00
};

struct Rewind {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x01
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:4; // Shall be 0x00
    unsigned int immediate:1; 
    // Byte 2
    unsigned int reserved2:8; // Shall be 0x00
    // Byte 3
    unsigned int reserved3:8; // Shall be 0x00
    // Byte 4
    unsigned int reserved4:8; // Shall be 0x00
    // Byte 5
    unsigned int reserved5:8; // Shall be 0x00
};

struct Space {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x11
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:2; // Shall be 0x00
    unsigned int code:3; 
    // Byte 2
    unsigned int countByte0:8;
    // Byte 3
    unsigned int countByte1:8;
    // Byte 4
    unsigned int countByte2:8;
    // Byte 5
    unsigned int control:8;
};

struct Erase {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x19
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:3; // Shall be 0x00
    unsigned int immediate:1; 
    unsigned int longg:1; 
    // Byte 2
    unsigned int reserved2:8;
    // Byte 3
    unsigned int reserved3:8;
    // Byte 4
    unsigned int reserved4:8;
    // Byte 5
    unsigned int control:8;
};

struct WriteFilemark {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x10
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:3; // Shall be 0x00
    unsigned int setmark:1; 
    unsigned int immediate:1; 
    // Byte 2
    unsigned int countByte0:8;
    // Byte 3
    unsigned int countByte1:8;
    // Byte 4
    unsigned int countByte2:8;
    // Byte 5
    unsigned int control:8;
};

struct ReadBlockLimits {
    // Byte 0
    unsigned int opcode:8; // Shall be 0x15
    // Byte 1
    unsigned int lun:3; 
    unsigned int reserved1:5; // Shall be 0x00
    // Byte 2
    unsigned int reserved2:8;
    // Byte 3
    unsigned int reserved3:8;
    // Byte 4
    unsigned int reserved4:8;
    // Byte 5
    unsigned int control:8;
};

class CVirtualTape {
public:
    virtual ResultCode testUnitReady(const TestUnitReady *cdb) = 0; 
    virtual ResultCode sendDiagnostic(const SendDiagnostic *cdb, void *data, int length) = 0; 
    virtual ResultCode initializeElementStatus(const InitializeElementStatus *cdb) = 0; 
    virtual ResultCode initializeElementStatusWithRange(const InitializeElementStatusWithRange *cdb) = 0; 
    virtual ResultCode inquire(const Inquire *cdb, void *data, int length) = 0; 
    virtual ResultCode requestSense(const RequestSense *cdb, void *data, int length) = 0; 
    virtual ResultCode read(const Read *cdb, void *data, int length) = 0; 
    virtual ResultCode write(const Write *cdb, const void *data, int length) = 0; 
    virtual ResultCode modeSense(const ModeSense *cdb, void *data, int length) = 0; 
    virtual ResultCode modeSelect(const ModeSelect *cdb) = 0; 
    virtual ResultCode moveMedium(const MoveMedium *cdb) = 0; 
    virtual ResultCode positionToElement(const PositionToElement *cdb) = 0;
    virtual ResultCode mediumRemoval(const MediumRemoval *cdb) = 0;
    virtual ResultCode readElementStatus(const ReadElementStatus *cdb, void *data, int length) = 0;
    virtual ResultCode release(const Release *cdb) = 0;
    virtual ResultCode reserve(const Reserve *cdb) = 0;
    virtual ResultCode rewind(const Rewind *cdb) = 0;
    virtual ResultCode space(const Space *cdb) = 0;
    virtual ResultCode erase(const Erase *cdb) = 0;
    virtual ResultCode writeFilemark(const WriteFilemark *cdb) = 0;
    virtual ResultCode readBlockLimits(const ReadBlockLimits *cdb, void *data, int length) = 0;
protected:
    int senseKey;
};
#endif	/* CVIRTUALTAPE_H */

