
#ifndef AMAZONSIMPLESTORAGESERVICE_H
#define	AMAZONSIMPLESTORAGESERVICE_H
#include <string>

class AmazonS3SoapBindingProxy;

class AmazonSimpleStorageService {
public:
    AmazonSimpleStorageService();
    AmazonSimpleStorageService(const AmazonSimpleStorageService& orig);
    virtual ~AmazonSimpleStorageService();
    void createBucket(const std::string &name);
    void putObject(const std::string &bucket, const std::string &name);
private:
    AmazonS3SoapBindingProxy *m_service; 
    static void initializeService();
    static bool m_initialized;
    static std::string m_key;
    static std::string m_value;
};

#endif	/* AMAZONSIMPLESTORAGESERVICE_H */

