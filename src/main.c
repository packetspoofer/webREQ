#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "globals.h"

/* These attributes need to
 * be initialized in Main.c
 * even if they are global
 */
CURL *curl;
CURLcode response;

int main(void) {

    /* Initialize curl */
    curl_global_init(CURL_GLOBAL_ALL);
    /* CURL HANDLE */
    curl = curl_easy_init();

    /* GET THE ENDPOINT */
    char webEndpoint[254];
    printf("Insert the URL (http gangy): ");
    fgets(webEndpoint, sizeof(webEndpoint), stdin);
    webEndpoint[strcspn(webEndpoint, "\n")] = 0; // Remove the newline

    // TODO  Do the check of URL

    performAllRequests(webEndpoint);

    curl_global_cleanup(); // Clean global stuffs
    return 0;
}
