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
First, setup the config.txt file, by adding:
- ICAO Code of default aerodrome
- You API key that you can retrieve here: https://www.checkwxapi.com/

Don't leave any empty spaces after the 2 lines.

Example:
    ELLX
    6edcd2cb0exxxxxfb3d3c71845
    -- No spaces after tokens --

2 options to execute the program:
- ```metar``` it will display the default aerodrome from config.txt file
- ```metar LFST``` will display the airport LFST.

## Copyright
Published under GNU General Public License.
