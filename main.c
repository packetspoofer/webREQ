#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
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

    /* REGEX SHITS */
    regex_t regex;
    int ret;

    // Regular expression pattern for basic URL validation:
    // ^(https?://)         -> URL must start with "http://""
    // ([a-zA-Z0-9.-]+)      -> Domain name with letters, digits, dots, or hyphens
    // (:[0-9]+)?           -> Optional port number
    // (/[a-zA-Z0-9./?=&%-]*)?$ -> Optional path and query parameters
    char *pattern = "^(http?://)([a-zA-Z0-9.-]+)(:[0-9]+)?(/[a-zA-Z0-9./?=&%-]*)?$";

    // Compile the regular expression with extended syntax
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        printf("Could not compile regex\n");
        return 1;
    }

    // Execute the regular expression on the URL string
    ret = regexec(&regex, webEndpoint, 0, NULL, 0);
    if (ret) {
        printf("Invalid URL\n");
        exit(1);
    }

    // Clean the compiled regular expression
    regfree(&regex);

    /* POST/PUT VALUE */
    char queryValue[85];
    printf("Insert the value (POST/PUT REQ): ");
    fgets(queryValue, sizeof(queryValue), stdin);
    queryValue[strcspn(queryValue, "\n")] = 0; // Remove the newline

    performAllRequests(webEndpoint,queryValue);
    curl_global_cleanup(); // Clean global stuffs
    return 0;
}
