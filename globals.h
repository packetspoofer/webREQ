/*
 * THIS HEADER IS INDED FOR MAKE
 * ACCESSIBLE CERTAIN ELEMENTS IN ALL
 * C FILES
 */
#ifndef GLBOALS_H
#define GLOBALS_H

#include <curl/curl.h>

/*
 * Declare *curl and response varirables
 * global (Accessible from any file)
 * */
extern CURL *curl;
extern CURLcode response;

/*
 * We set performsAllRequests method
 * available in all files
*/
void performAllRequests(char *webDomain, char *inputValue);

#endif
