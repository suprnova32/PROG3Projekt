#include <string>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

#include "utilities.h"

std::string base64_encodestring(const char* text, int len) 

{
    EVP_ENCODE_CTX ectx;
    int size = len*2;
    size = size > 64 ? size : 64;
    unsigned char* out = (unsigned char*)malloc( size );
    int outlen = 0;
    int tlen = 0;

    EVP_EncodeInit(&ectx);
    EVP_EncodeUpdate(&ectx,
            out,
            &outlen,
            (const unsigned char*)text,
            len
            );
    tlen += outlen;
    EVP_EncodeFinal( &ectx, out+tlen, &outlen );
    tlen += outlen;

    std::string str((char*)out, tlen );
    free( out );
    return str;
}

const char* xml_datetime(time_t now) 

{

  const int MAX=25;
  static char output[MAX+1];

  strftime( output, MAX+1, "%Y-%m-%dT%H:%M:%S.000Z", gmtime( &now ) );

  return output;
}

char* aws_signature(const char* key, ...) 

{
  unsigned int i, len;
  char *data;
  const char **list = &key;

  static char hmac[EVP_MAX_MD_SIZE];

  for (i = 1, len = 0; *(list+i) != NULL; ++i) {
    len += strlen( *(list+i) );
  }

  data = (char*)malloc(sizeof(char) * (len+1));

  if (data) {
    for ( i = 1, len = 0 ; *(list+i) != NULL ; ++i ) {
      strncpy( data+len, *(list+i), strlen(*(list+i)) );
      len += strlen(*(list+i));
    }
    data[len]='\0';

    HMAC( EVP_sha1(),
          key,  strlen(key),
          (unsigned char*)data, strlen(data),
          (unsigned char*) hmac, &len
        );
    free(data);
  }

  std::string b64data=base64_encodestring(hmac, len);

  strcpy(hmac,b64data.c_str());

  return hmac;
};

