/*
 * Author:	Alexandre Stanescot
 * Purpose: Display a raw metar given an airport ICAO code (Exemple: "ELLX")
 * Date:	15/05/2022
 * Version:	1.1
 * Compile:	gcc main.c -o metar -lcurl
 * Run:		./metar or ./metar ELLX
 */

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

// Defines
#define LINE_MAX_LENGTH 50

// Prototypes
size_t got_data(char *buffer, size_t itemsize, size_t nitems, void* ignorethis);
void getMetar(const char icao[], const char api_key[]);

// Constants
const char DEFAULT_ICAO[] = "WADD";
const char API_KEY[] = "6edcd2xxxxxxxxxxxxxxxxx45";

// Functions
int main(int argc, char *argv[])
{
	// We check if argument was given, by default ELLX
	char icao[5];
	
	if(argc == 2)
	{
		strcpy(icao, argv[1]);
	}
	else
	{
		strcpy(icao, DEFAULT_ICAO);
	}

	getMetar(DEFAULT_ICAO, API_KEY);

	return EXIT_SUCCESS;
}

void getMetar(const char icao[], const char api_key[])
{
	// CURL Function
	CURL *curl;
	CURLcode result;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	if(!curl)
	{
		fprintf(stderr, "init failure\n");
	}

	// set options ans headers
	char full_url[38] = {0};
	char* url = "https://api.checkwx.com/bot/metar/";
	strcat(full_url, url);
	strcat(full_url, icao);
	curl_easy_setopt(curl, CURLOPT_URL, full_url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);

	char full_api[] = "";
	strcat(full_api, "x-api-key: ");
	strcat(full_api, API_KEY);

	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, full_api);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers); 

	// Perform out section	
	result = curl_easy_perform(curl);
	if(result != CURLE_OK)
	{
		fprintf(stderr, "Download problem: %s\n", curl_easy_strerror(result));
	}
	else
	{
		printf("\n");
	}

	curl_easy_cleanup(curl);
}

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void* ignorethis)
{
	size_t bytes = itemsize * nitems;
	printf("%s\n", buffer);
	
	return bytes;
}
