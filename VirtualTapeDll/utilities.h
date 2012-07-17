/* 
 * File:   utilities.h
 * Author: eternus
 *
 * Created on July 12, 2012, 5:53 PM
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

std::string base64_encodestring(const char* text, int len);
const char* xml_datetime(time_t now);
char* aws_signature(const char* key, ...);



#endif	/* UTILITIES_H */

