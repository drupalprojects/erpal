<?php

namespace WebSocket\Application;

error_reporting(E_ALL);

require(__DIR__ . '/nicokaiser-php-websocket/server/lib/SplClassLoader.php');

$classLoader = new \SplClassLoader('WebSocket', __DIR__ . '/nicokaiser-php-websocket/server/lib');
$classLoader->register();


class ErpalAsteriskTestApplication extends Application
{
    private $clients	= array();
	private $starttime	= 0;
	
	public function __construct() {
		$this->starttime	= time();
	}
	
    public function onConnect($client)
    {
        $this->clients[] = $client;
    }
	
    public function onDisconnect($client)
    {
        $key = array_search($client, $this->clients);
        if ($key) {
            unset($this->clients[$key]);
        }
    }
	
	public function onTick() {
		if( time()>$this->starttime+3 ) {
			$data	= file_get_contents( "last_call.htm" );
			foreach( $this->clients as $sendto ) {
				$sendto->send( $data );
			}
			$this->starttime	= time()*2;
		}
	}
	
    public function onData($data, $client)
    {
        /*foreach ($this->clients as $sendto) {
            $sendto->send($data);
        }*/
    }
}

$server = new \WebSocket\Server('localhost', 3081);
$server->registerApplication('erpal_asterisk', \WebSocket\Application\ErpalAsteriskTestApplication::getInstance());
$server->run();
