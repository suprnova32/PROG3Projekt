/* soapAmazonS3SoapBindingObject.h
   Generated by gSOAP 2.8.9 from AmazonS3.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapAmazonS3SoapBindingObject_H
#define soapAmazonS3SoapBindingObject_H
#include "soapH.h"

/******************************************************************************\
 *                                                                            *
 * Service Object                                                             *
 *                                                                            *
\******************************************************************************/

class AmazonS3SoapBindingService : public soap
{    public:
	AmazonS3SoapBindingService()
	{ static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "http://s3.amazonaws.com/doc/2006-03-01/", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};

	this->namespaces = namespaces; };
	virtual ~AmazonS3SoapBindingService() { };
	/// Bind service to port (returns master socket or SOAP_INVALID_SOCKET)
	virtual	SOAP_SOCKET bind(const char *host, int port, int backlog) { return soap_bind(this, host, port, backlog); };
	/// Accept next request (returns socket or SOAP_INVALID_SOCKET)
	virtual	SOAP_SOCKET accept() { return soap_accept(this); };
#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
	/// Then accept SSL handshake, when SSL is used
	virtual	int ssl_accept() { return soap_ssl_accept(this); };
#endif
	/// Serve this request (returns error code or SOAP_OK)
	virtual	int serve() { return soap_serve(this); };
};

/******************************************************************************\
 *                                                                            *
 * Service Operations (you should define these globally)                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 __ns1__CreateBucket(struct soap*, _ns1__CreateBucket *ns1__CreateBucket, _ns1__CreateBucketResponse *ns1__CreateBucketResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__DeleteBucket(struct soap*, _ns1__DeleteBucket *ns1__DeleteBucket, _ns1__DeleteBucketResponse *ns1__DeleteBucketResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetObjectAccessControlPolicy(struct soap*, _ns1__GetObjectAccessControlPolicy *ns1__GetObjectAccessControlPolicy, _ns1__GetObjectAccessControlPolicyResponse *ns1__GetObjectAccessControlPolicyResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetBucketAccessControlPolicy(struct soap*, _ns1__GetBucketAccessControlPolicy *ns1__GetBucketAccessControlPolicy, _ns1__GetBucketAccessControlPolicyResponse *ns1__GetBucketAccessControlPolicyResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__SetObjectAccessControlPolicy(struct soap*, _ns1__SetObjectAccessControlPolicy *ns1__SetObjectAccessControlPolicy, _ns1__SetObjectAccessControlPolicyResponse *ns1__SetObjectAccessControlPolicyResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__SetBucketAccessControlPolicy(struct soap*, _ns1__SetBucketAccessControlPolicy *ns1__SetBucketAccessControlPolicy, _ns1__SetBucketAccessControlPolicyResponse *ns1__SetBucketAccessControlPolicyResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetObject(struct soap*, _ns1__GetObject *ns1__GetObject, _ns1__GetObjectResponse *ns1__GetObjectResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetObjectExtended(struct soap*, _ns1__GetObjectExtended *ns1__GetObjectExtended, _ns1__GetObjectExtendedResponse *ns1__GetObjectExtendedResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__PutObject(struct soap*, _ns1__PutObject *ns1__PutObject, _ns1__PutObjectResponse *ns1__PutObjectResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__PutObjectInline(struct soap*, _ns1__PutObjectInline *ns1__PutObjectInline, _ns1__PutObjectInlineResponse *ns1__PutObjectInlineResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__DeleteObject(struct soap*, _ns1__DeleteObject *ns1__DeleteObject, _ns1__DeleteObjectResponse *ns1__DeleteObjectResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__ListBucket(struct soap*, _ns1__ListBucket *ns1__ListBucket, _ns1__ListBucketResponse *ns1__ListBucketResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__ListAllMyBuckets(struct soap*, _ns1__ListAllMyBuckets *ns1__ListAllMyBuckets, _ns1__ListAllMyBucketsResponse *ns1__ListAllMyBucketsResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__SetBucketLoggingStatus(struct soap*, _ns1__SetBucketLoggingStatus *ns1__SetBucketLoggingStatus, _ns1__SetBucketLoggingStatusResponse *ns1__SetBucketLoggingStatusResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetBucketLoggingStatus(struct soap*, _ns1__GetBucketLoggingStatus *ns1__GetBucketLoggingStatus, _ns1__GetBucketLoggingStatusResponse *ns1__GetBucketLoggingStatusResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__CopyObject(struct soap*, _ns1__CopyObject *ns1__CopyObject, _ns1__CopyObjectResponse *ns1__CopyObjectResponse);

#endif
