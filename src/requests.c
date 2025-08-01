#include <curl/curl.h>
#include "globals.h"

/* IGNORE HTML BODY (Powered by gpt) */
size_t discard_response(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

/* PARSE THE HTTP RESPONSE TO STRING (ex: 200 = "OK")*/
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

void performAllRequests(char *webDomain, char *inputValue) {

    long response_code;

    if (curl) {

        /*
         * OPTSTNS REQUEST
         */

        // Set parameters
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLUPART_OPTIONS, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_response);
        // Perform the get request
        response = curl_easy_perform(curl);
        // Print the response of the request
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "OPTIONS:", response_code, httpResponseToString(response_code));
        // Reset the params and stuffs
        curl_easy_reset(curl);




        /*
         * HEAD REQUEST
         */

        // Set parameters
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_response);
        // Perform the get request
        response = curl_easy_perform(curl);
        // Print the response of the request
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "HEAD:", response_code, httpResponseToString(response_code));

        // Reset the params and stuffs
        curl_easy_reset(curl);



        /*
         * GET REQUEST
         */

        // Set parameters
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_response);
        // Perform the get request
        response = curl_easy_perform(curl);
        // Print the response of the request
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "GET:", response_code, httpResponseToString(response_code));


        // Reset the params and stuffs
        curl_easy_reset(curl);


        /*
         * POST REQUEST
         */

        // Set parameters
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, inputValue);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_response);
        // Perform the get request
        response = curl_easy_perform(curl);
        // Print the response of the request
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "POST:", response_code, httpResponseToString(response_code));



        /*
         * PUT REQUEST
         */

        // Set parameters
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLOPT_PUT, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, inputValue);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_response);
        // Perform the get request
        response = curl_easy_perform(curl);
        // Print the response of the request
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld %s\n", "PUT:", response_code, httpResponseToString(response_code));


        curl_easy_cleanup(curl); // Clean stuffs
    }

}
