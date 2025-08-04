#include <curl/curl.h>
#include <string.h>
#include "globals.h"

/* Parse the http response to string (ex: 200 = "OK")
 * Enum is declared on globals.h
 */
const char* httpResponseToString(HttpStatusCode code) {
    switch (code) {
        case HTTP_OK: return "OK";
        case HTTP_CREATED: return "CREATED";
        case HTTP_ACCEPTED: return "ACCEPTED";
        case HTTP_NO_CONTENT: return "NO CONTENT";

        case HTTP_MOVED_PERMANENTLY: return "MOVED PERMANENTLY";
        case HTTP_FOUND: return "FOUND";
        case HTTP_NOT_MODIFIED: return "NOT MODIFIED";

        case HTTP_BAD_REQUEST: return "BAD REQUEST";
        case HTTP_UNAUTHORIZED: return "UNAUTHORIZED";
        case HTTP_FORBIDDEN: return "FORBIDDEN";
        case HTTP_NOT_FOUND: return "NOT FOUND";
        case HTTP_METHOD_NOT_ALLOWED: return "METHOD NOT ALLOWED";

        case HTTP_INTERNAL_SERVER_ERROR: return "INTERNAL SERVER ERROR";
        case HTTP_NOT_IMPLEMENTED: return "NOT IMPLEMENTED";
        case HTTP_BAD_GATEWAY: return "BAD GATEWAY";
        case HTTP_SERVICE_UNAVAILABLE: return "SERVICE UNAVAILABLE";

        default: return "UNKNOW STATUS";
    }
}

/* Do all the requests to a specified endpoint */
void performAllRequests(char *webDomain) {

    long response_code;

    if (curl) {

        /* OPTIONS REQUEST */
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "OPTIONS");
        response = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "OPTIONS:", response_code, httpResponseToString(response_code));

        /* HEAD REQUEST */
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        response = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "HEAD:", response_code, httpResponseToString(response_code));

        /* GET REQUEST */
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        response = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "GET:", response_code, httpResponseToString(response_code));

        /* POST REQUEST */
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_MIMEPOST, "");
        response = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "POST:", response_code, httpResponseToString(response_code));

        /* PUT REQUEST */
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        response = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "PUT:", response_code, httpResponseToString(response_code));
    }

}
