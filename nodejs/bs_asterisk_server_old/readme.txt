Run daemon.
------------------------------------------------------------------------

node bs_asterisk_server.js



Calling asterisk server for submitting caller info.
------------------------------------------------------------------------

http://localhost:[HTTP PORT]/ingoing

Postdata:

	- sourcenumber 		= [SOURCE NUMBER]
	- destinationnumber = [DESTINATION NNUMBER]
	- caller_data		= [JSON DATA ABOUT THE CALLER]
	
	
	
Calling asterisk server for registering a client.
------------------------------------------------------------------------

http://localhost:[HTTP PORT]/register

Postdata:

	- private_key		= [SECRET PRIVATE KEY]
	- ip				= [CLIENT IP]
	- numbers			= [JSON ARRAY CONTAINS PHONE NUMBERS OF THE CLIENT]
	

