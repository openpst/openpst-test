<?php
############################################################################

class Console
{

	/** @var resource */
	protected $stdout;

	/** @var resource */
	protected $stdin;

	/**
	* Constructor
	*/
	public function __construct($in = 'php://stdin', $out = 'php://stdout')
	{
		$this->stdout 	= fopen($out, 'w');
		$this->stdin 	= fopen($in, 'r');
	}

	/**
	* Destructor
	*/
	public function __destruct()
	{
		if (is_resource($this->stdin)) {
			fclose($this->stdin);
		}

		if (is_resource($this->stdout)) {
			fclose($this->stdout);
		}
	}

	/**
	* write - Write to output stream without a terminating line character.
	*
	* @param string $msg
	* @param additional string format arguments
	*/
	public function write($msg)
	{
		fwrite($this->stdout, vsprintf($msg, array_slice(func_get_args(), 1)));
	}

	/**
	* writeLine - Write to output stream with a terminating lnie character.
	*
	* @param string $msg Formatted string, pass additional arguments to replace
	*/
	public function writeLine($msg)
	{
		fwrite($this->stdout, vsprintf($msg, array_slice(func_get_args(), 1)).PHP_EOL);		
	}

	/**
	* getUserInput
	*
	* @param string $prompt a message to display to the user. Formatted string, pass additional arguments to replace
	*
	* @return bool
	*/
	public function getUserInput($prompt) 
	{
		if (function_exists('readline')) {			
			$data = readline(vsprintf($prompt, array_slice(func_get_args(), 1)));
		} else {
			$this->write(vsprintf($prompt, array_slice(func_get_args(), 1)));
			$data = trim(fgets($this->stdin));
		}
		return $data;
	}

	/**
	* confirm
	*
	* @param string $prompt a message to display to the user
	*
	* @return bool
	*/
	public function confirm($msg) {
		$userResponse = strtolower(trim($this->getUserInput(vsprintf($msg, array_slice(func_get_args(), 1)))));

		if (!$userResponse || !in_array($userResponse, array('y','n'))) {
			$this->writeLine('Confirm with Y or N');
			return $this->confirm($msg);
		}

		return $userResponse == 'y' ? true : false;
	}

}