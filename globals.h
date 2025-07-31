/*
 * THIS HEADER IS INDED FOR MAKE
 * ACCESSIBLE CERTAIN ELEMENTS IN ALL
 * C FILES
 */

#ifndef GLBOALS_H
#define GLOBALS_H

/*
 * Declare *curl and response varirables
 * global (Accessible from any C file)
 */
#include <curl/curl.h>
extern CURL *curl;
extern CURLcode response;

/*
 * We set performsAllRequests method
 * available in all C files
*/
void performAllRequests(char *webDomain, char *inputValue);

#endif
