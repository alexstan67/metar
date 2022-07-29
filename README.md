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
metar uses environment variables to work.
Please create the 2 followings:

- METAR_DEFAULT=<ICAO Code of default aerodrome>
- METAR_API_CHECKWX=<Your API key that you can retrieve here: https://www.checkwxapi.com/>

Example:
export METAR_DEFAULT=ELLX
export METAR_API_CHECKWX=6edcd2cb0e6xxxxxxxxxxxxxxx

2 options to execute the program:
- ```metar``` it will display the default aerodrome from config.txt file
- ```metar LFST``` will display the airport LFST.

If Makefile doesn't execute, modify the rights:
sudo chmod 776 Makefile

## Copyright
Published under GNU General Public License.
