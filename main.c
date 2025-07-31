#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "globals.h"

/* This attribute need to be
 * initialized in Main.c even
 * if they are global
 */
CURL *curl;
CURLcode response;

int main(void) {

    /* Initialize curl */
    curl_global_init(CURL_GLOBAL_ALL);
    /* CURL HANDLE */
    curl = curl_easy_init();

    /* INSERT THE ENDPOINT */
    char webEndpoint[254];
    printf("Insert the URL (http gangy): ");
    fgets(webEndpoint, sizeof(webEndpoint), stdin);
    webEndpoint[strcspn(webEndpoint, "\n")] = 0; // Remove the newline

    /* POST/PUT VALUE */
    char queryValue[85];
    printf("Insert the value (POST/PUT REQ): ");
    fgets(queryValue, sizeof(queryValue), stdin);
    queryValue[strcspn(queryValue, "\n")] = 0; // Remove the newline

    performAllRequests(webEndpoint,queryValue);
    curl_global_cleanup(); // Clean global stuffs
    return 0;
}
