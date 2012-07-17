#include <soapAmazonS3SoapBindingProxy.h>
#include <AmazonS3SoapBinding.nsmap>
#include <fstream>

#include "AmazonSimpleStorageService.h"
#include "utilities.h"

bool AmazonSimpleStorageService::m_initialized;
std::string AmazonSimpleStorageService::m_key;
std::string AmazonSimpleStorageService::m_value;

AmazonSimpleStorageService::AmazonSimpleStorageService()

{
    initializeService();

    m_service = new AmazonS3SoapBindingProxy;
    m_service->soap_stream_fault(std::cout);
    
    soap_ssl_client_context(m_service->soap,
           SOAP_SSL_NO_AUTHENTICATION,
           NULL,
           NULL,
           NULL,
           NULL,
           NULL);

    /* Wenn Sie im Hochschulnetz arbeiten...
        client.proxy_host="proxy.hft-stuttgart.de"; // proxy hostname
        client.proxy_port=80;
        client.proxy_userid=NULL;  // user pass if proxy
        client.proxy_passwd=NULL;  // requires authentication
        client.proxy_http_version="1.1"; // http version
    */
}

AmazonSimpleStorageService::AmazonSimpleStorageService(const AmazonSimpleStorageService& orig) 

{
    initializeService();
}

AmazonSimpleStorageService::~AmazonSimpleStorageService() 

{
    delete m_service;
}

void AmazonSimpleStorageService::initializeService() 

{
    if ( m_initialized ) {
        return;
    }
    
    m_initialized = true;
    // Hier müssen Sie Ihre eigenen Daten eintragen.
    //std::ifstream input("/mnt/Peter Heusch/Teaching/PRO3/AmazonS3/AmazonS3.data");
    m_key = "AKIAJZ2GYUUHM7NGJ2MA";
    m_value = "knjzWY0laqR0nOLleyyQT3wUYVeuE0RLB2+sDcOh";
    //input.close();
    soap_ssl_init();
}

void AmazonSimpleStorageService::createBucket(const std::string& name) 

{
    time_t now = time(NULL);
    
    _ns1__CreateBucket request;
    _ns1__CreateBucketResponse response;
    
    request.AWSAccessKeyId = strdup(m_key.c_str());
    request.Bucket=strdup(name.c_str());
    request.Signature=aws_signature(
            m_value.c_str(),
            "AmazonS3",
            "CreateBucket",
            xml_datetime(now),
            NULL);;
    request.Timestamp=&now;

    int answer = m_service->CreateBucket(&request, &response);
    printf("CreateBucket returned: %d\n", answer);
    if ( answer != SOAP_OK ) {
        m_service->soap_print_fault(stderr);
    }
    free(request.Bucket);
}

void AmazonSimpleStorageService::putObject(const std::string& bucket, const std::string& name) 

{
    time_t now = time(NULL);
    std::string data("Dies ist ein S3-Test");
    while ( data.length() < 2048 ) {
        data = data + data;
    }
    _ns1__PutObjectInline request;
    _ns1__PutObjectInlineResponse response;

    xsd__base64Binary image;
    image.soap_default(m_service->soap);
    image.__ptr = (unsigned char *)strdup(data.c_str());
    image.__size = strlen((char *)(image.__ptr));

    request.AWSAccessKeyId = strdup(m_key.c_str());
    request.Bucket=strdup(bucket.c_str());
    request.Signature=aws_signature(
            m_value.c_str(),
            "AmazonS3",
            "PutObjectInline",
            xml_datetime(now),
            NULL);;
    request.Timestamp=&now;
    request.Key = strdup(name.c_str());
    request.ContentLength = data.length();
    request.Data = image;
    request.soap = m_service->soap;
    
    int answer = m_service->PutObjectInline(&request, &response);
    printf("PutObject returned: %d\n", answer);
    if ( answer != SOAP_OK ) {
        m_service->soap_print_fault(stderr);
    }
    free(request.Bucket);
    free(request.Key);
}