# metar - Raw METAR data request

**metar** retrieves **MET**eorolical **A**erodrome **R**eport* (METAR) which
contain information about current weather conditions of specified weather
observation stations.

## Requirements
libcurl - the multiprotocol file transfer library.

## Installing

### Linux
Running ```make``` should suffice. What it
does is basically

    gcc main.c -o metar -lcurl

You can copy the executable to ```/usr/local```.

## Manual
Before compiling, modify line 23 & 24 in main.c to setup:

- ICAO Code of default aerodrome
- You API key that you can retrieve here: https://www.checkwxapi.com/

Example:
const char DEFAULT_ICAO[] = "LFAT";
const char API_KEY[] = "6edcd2cb0e6xxxxxxxxxxxxxxx";

2 options to execute the program:
- ```metar``` it will display the default aerodrome from config.txt file
- ```metar LFST``` will display the airport LFST.

If Makefile doesn't execute, modify the rights:
sudo chmod 776 Makefile

## Copyright
Published under GNU General Public License.
