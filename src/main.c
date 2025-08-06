#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "globals.h"

/* These attributes need to
 * be initialized in Main.c
 * even if they are writed
 * on globals.h
 */
CURL *curl;
CURLcode response;

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("USAGE:\n");
        printf(" ./webREQ -get -g <url>\n");
        printf(" ./webREQ -post -p <url>\n");
        printf(" ./webREQ -all -a <url>\n");
        return 1;
    }

    const char *option = argv[1];
    const char *webEndpoint = argv[2];

    /* Initialize curl */
    curl_global_init(CURL_GLOBAL_ALL);
    /* CURL HANDLE */
    curl = curl_easy_init();

    /* I do this shit manual because
    * c hate strings in switch statements
    */
    if (strcmp(option, "-get") == 0 || strcmp(option, "-g") == 0) {
        getTypeReqs(webEndpoint);
    }
    else if (strcmp(option, "-post") == 0 || strcmp(option, "-p") == 0) {
        postTypeReqs(webEndpoint);
    }
    else if (strcmp(option, "-all") == 0 || strcmp(option, "-a") == 0) {
        getTypeReqs(webEndpoint);
        postTypeReqs(webEndpoint);
    }
    else {
        printf("Invalid option: %s\n", option);
        printf("USAGE:\n ./webREQ -get -g <url>\n ./webREQ -post -p <url>\n ./webREQ -all -a <url>\n");
        return 1;
    }


    curl_global_cleanup(); // Clean curl shits
    return 0;
}
