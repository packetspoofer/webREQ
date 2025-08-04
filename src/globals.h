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

/* Enum used for returning the
 * (string type) request outcome
 */
typedef enum {
    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_ACCEPTED = 202,
    HTTP_NO_CONTENT = 204,

    HTTP_MOVED_PERMANENTLY = 301,
    HTTP_FOUND = 302,
    HTTP_NOT_MODIFIED = 304,

    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_FORBIDDEN = 403,
    HTTP_NOT_FOUND = 404,
    HTTP_METHOD_NOT_ALLOWED = 405,

    HTTP_INTERNAL_SERVER_ERROR = 500,
    HTTP_NOT_IMPLEMENTED = 501,
    HTTP_BAD_GATEWAY = 502,
    HTTP_SERVICE_UNAVAILABLE = 503
} HttpStatusCode;

/*
 * We set httpResponseToString method
 * available in all C files
 */

const char* httpResponseToString(HttpStatusCode code);

/*
 * We set performsAllRequests method
 * available in all C files
 */
void performAllRequests(char *webDomain);

#endif
