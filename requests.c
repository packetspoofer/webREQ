#include <curl/curl.h>
#include "globals.h"

/* IGNORE HTML BODY (Powered by gpt) */
size_t discard_response(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

void performAllRequests(char *webDomain, char *inputValue) {

    long response_code;

    if (curl) {

        /*
         * OPTIONS REQUEST
         */

        // Set parameters
        curl_easy_setopt(curl, CURLOPT_URL, webDomain);
        curl_easy_setopt(curl, CURLUPART_OPTIONS, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_response);
        // Perform the get request
        response = curl_easy_perform(curl);
        // Print the response of the request
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("%s %ld\n", "OPTIONS:", response_code);
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
        printf("%s %ld\n", "HEAD:", response_code);
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
        printf("%s %ld\n", "GET:", response_code);
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
        printf("%s %ld\n", "POST:", response_code);



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
        printf("%s %ld\n", "PUT:", response_code);



        curl_easy_cleanup(curl); // Clean stuffs
    }

}
