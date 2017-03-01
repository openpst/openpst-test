<?php

require_once('console.php');

class ArgumentParser
{

	const STATE_PARSED = 0;

	const STATE_DIRTY = 1;

	/** @var array */
	protected $arguments = array();
	
	/** @var array */
	protected $parsedArguments = array();

	/** @var int */
	protected $state = self::STATE_DIRTY;

	/** @var Console */
	protected $cli;

	/**
	* Constructor
	*
	* @param Console|null $cli
	* @param array $arguments
	*/
	public function __construct(Console $cli = null, array $arguments = array())
	{
		if (is_null($cli)) {
			$this->cli = new Console();
		} else {
			$this->cli = $cli;
		}

		if (count($arguments)) {
			foreach ($arguments as $arg) {
				if (!$arg instanceof Argument) {				
					throw \InvalidArgumentException('ArgumentParser constructor must contain an array of Argument if provided');
				}
				$this->arguments[] = $arg;
			}			
		}

		// add in default "help"
		$this->addArgument('help', 'h', Argument::ARG_TYPE_NO_VALUE, 'Displays help', false, Argument::ARG_OPTIONAL);

		if (count($this->arguments)) {
			$this->parse();
		}
	}

	/**
	 * addArgument
	 * 
	 * Add an argument to be parsed 
	 */
	public function addArgument($name, $shortName, $type, $help = null, $default = null, $requirements = Argument::ARG_OPTIONAL)
	{
		if ($this->hasArgument($name)) {
			throw new \Exception(sprintf('Argument with name %s is already defined', $name));
		} else if ($this->hasArgumentByShortname($shortName)) {
			throw new \Exception(sprintf('Argument with short name %s is already defined', $shortName));
		}

		$this->setState(static::STATE_DIRTY);

		$this->arguments[] = new Argument($name, $shortName, $type, $help, $default, $requirements);

		return $this;
	}

	/**
	 * hasArgument
	 * 
	 * Check if an argument exists by its name
	 */
	public function hasArgument($name)
	{
		foreach ($this->arguments as $arg) {
			if ($arg->getName() == $name) {
				return true;
			}
		}
		return false;
	}

	/**
	 * hasArgumentByShortName
	 * 
	 * Check if an argument exists by its short name
	 *
	 * @param string $name
	 *
	 * @return bool
	 */
	public function hasArgumentByShortName($name)
	{
		foreach ($this->arguments as $arg) {
			if ($arg->getShortName() == $name) {
				return true;
			}
		}
		return false;
	}

	/**
	 * getArgument
	 * 
	 *  Get an argument by name
	 *
	 * @param string $name
	 *
	 * @throws \Exception when argument does not exist
	 * @return mixed
	 */
	public function getArgument($name)
	{
		foreach ($this->arguments as $arg) {
			if ($arg->getName() == $name) {
				return $arg;
			}
		}

		throw new \Exception(sprintf('Argument `%s` does not exist', $name));
	}

	/**
	 * getArgument
	 * 
	 *  Get an argument by name
	 *
	 * @param string $name
	 *
	 * @throws \Exception when argument does not exist
	 * @return Argument
	 */
	public function getArgumentByShortName($name)
	{
		foreach ($this->arguments as $arg) {
			if ($arg->getShortName() == $name) {
				return $arg;
			}
		}

		throw new \Exception(sprintf('Argument short name `%s` does not exist', $name));
	}

	/**
	 * getShortName
	 * 
	 *  Get an arguments short name by full name
	 *
	 * @param string $name
	 *
	 * @return string
	 */
	public function getShortName($name)
	{
		if (!$this->hasArgument($name)) {
			return false;
		}
		return $this->getArgument($name)->getShortName();
	}

	/**
	 * getValue
	 * 
	 *  Get an arguments value by full name
	 *
	 * @param string $name
	 *
	 * @return mixed
	 */
	public function getValue($name)
	{
		if (!$this->hasArgument($name)) {
			return false;
		}

		return $this->getArgument($name)->getValue();
	}

	/**
	 * getValueByShortname
	 * 
	 *  Get an arguments value by short name
	 *
	 * @param string $shortName
	 *
	 * @return mixed
	 */
	public function getValueByShortname($shortName)
	{
		if (!$this->hasArgumentByShortName($shortName)) {
			return false;
		}

		return $this->getArgumentByShortName($shortName)->getValue();
	}

	/**
	 * parse
	 * 
	 * Parses the passed arguments from the command line with the specified arguments
	 * set. Called after arguments have been set 
	 *
	 * @return array - Array of parsed arguments
	 */
	public function parse()
	{
		global $argv, $argc;

		if ($this->isDirty() && count($this->arguments)) {
			$shortopts = null;
			$longopts = array();

			foreach ($this->arguments as $arg) {
				if ($arg->getType() != Argument::ARG_TYPE_BOOL) {
					if ($arg->getRequirements() == Argument::ARG_OPTIONAL) {
						$shortopts .= $arg->getShortName() . '::';
						$longopts[] = $arg->getName() . '::';
					} else if ($arg->getRequirements() == Argument::ARG_REQUIRED) {
						$shortopts .= $arg->getShortName() . ':';
						$longopts[] = $arg->getName() . ':';
					} else {
						$shortopts .= $arg->getShortName();
						$longopts[] = $arg->getName();
					}
				} else {
					$shortopts .= $arg->getShortName();
					$longopts[] = $arg->getName();
				}
			}

			$opts = getopt($shortopts, $longopts);
			$parsedOpts = array();

			foreach ($this->arguments as $arg) {
				$valueFound = false;
				if (isset($opts[$arg->getName()])) {
					if ($arg->getType() == Argument::ARG_TYPE_BOOL) {
						$arg->setValue(true);
					} else {
						$arg->setValue($opts[$arg->getName()]);
					}
					$valueFound = true;
				} else if (isset($opts[$arg->getShortName()])) {
					if ($arg->getType() == Argument::ARG_TYPE_BOOL) {
						$arg->setValue(true);
					} else {
						$arg->setValue($opts[$arg->getShortName()]);
					}
					$valueFound = true;
				}

				if (!$valueFound && $arg->getRequirements() == Argument::ARG_REQUIRED && !$arg->getDefault()) {
					$this->cli->writeLine(PHP_EOL . 'Error: Invalid or missing arguments' . PHP_EOL);
					$this->usage();
				}
				
				if ($arg->getType() == Argument::ARG_TYPE_INT) {
					$parsedOpts[$arg->getName()] = (int) $arg->getValue();
				} else if ($arg->getType() == Argument::ARG_TYPE_DATETIME) {
					if ($arg->getValue()) {
						try {
							if (is_numeric($arg->getValue())) {
								// assume timestamp
								$parsedOpts[$arg->getName()] = new \DateTime();
								$parsedOpts[$arg->getName()]->setTimestamp($arg->getValue());							
							} else {
								$parsedOpts[$arg->getName()] = new \DateTime($arg->getValue());
							}						
						} catch (\Exception $e) {
							$this->cli->writeLine(PHP_EOL . 'Error: Option %s must be a valid date string' . PHP_EOL);
							$this->usage();
						}
					} else {
						$parsedOpts[$arg->getName()] = null;
					}
				} else {
					$parsedOpts[$arg->getName()] = $arg->getValue();
				}
				
				$arg->setValue($parsedOpts[$arg->getName()]);
			}
			
			$this->parsedArguments = $parsedOpts;
		}

		$this->setState(static::STATE_PARSED);

		if ($this->hasArgumentByShortName('h')) {
			if ($this->getValue('help')) {
				$this->usage();
			}
		}

		return $this->parsedArguments;
	}

	/**
	* usage
	* Displays argument usage and terminates the program
	*/
	public function usage()
	{
		foreach ($this->getHelp() as $line) {
			$this->cli->writeLine($line);
		}
		die();
	}

	/**
	* getHelp
	* Gets help text as an array of lines
	* 
	* @return array
	*/
	public function getHelp()
	{
		$ret = array();

		$ret[] = 'Program Usage:';
		$ret[] = null;
		$ret[] = "\t" . 'php <script> <options>';
		$ret[] = null;
		$ret[] = 'Program Options:';
		$ret[] = null;
		foreach ($this->arguments as $arg) {
			$default = $arg->getDefault();
			if ($default === false) {
				$default = 'False';
			} else if ($default === true) {
				$default = 'True';
			}
			if ($arg->getName() == 'help') {
				$ret[] = "\t" . sprintf('--%s [-%s] | %s', 
					$arg->getName(), 
					$arg->getShortName(), 
					$arg->getHelp()
				);
			} else {
				$ret[] = "\t" . sprintf('--%s [-%s] | %s - %s Default: %s', 
					$arg->getName(), 
					$arg->getShortName(), 
					$arg->getHelp(), 
					$arg->getRequirements() == Argument::ARG_REQUIRED ? 'REQUIRED' : 'OPTIONAL',
					$default
				);				
				$ret[] = "\t\t" . sprintf('Example: php script.php -%s%s', $arg->getShortName(), $arg->getType() == Argument::ARG_TYPE_BOOL ? '' : '<VALUE>');
				$ret[] = "\t\t" . sprintf('Example: php script.php --%s%s', $arg->getName(), $arg->getType() == Argument::ARG_TYPE_BOOL ? '' : '=<VALUE>');
				$ret[] = '';
			}
			
		}
		
		return $ret;
	}

	/**
	* getConsole
	*
	* @return Console
	*/
	public function getConsole()
	{
		return $this->cli;
	}

	/**
	* isDirty
	*
	* @return bool
	*/
	private function isDirty()
	{
		return $this->state == static::STATE_DIRTY;
	}

	/**
	* setState
	*
	* @param int $state - one of STATE_ constants
	*
	* @return ArgumentParser
	*/
	private function setState($state)
	{
		$this->state = $state;
		return $this;
	}

}

/**
* Argument - Represents a single argument
*/
class Argument
{
	const ARG_REQUIRED 			= 0x01;
	const ARG_OPTIONAL 			= 0x02;

	const ARG_TYPE_INT 			= 1;
	const ARG_TYPE_FLOAT 		= 2;
	const ARG_TYPE_STRING 		= 3;
	const ARG_TYPE_BOOL			= 4;
	const ARG_TYPE_NO_VALUE		= self::ARG_TYPE_BOOL;
	const ARG_TYPE_DATETIME		= 5;

	protected $longName;

	protected $shortName;

	protected $help;

	protected $default;

	protected $requirements;

	public function __construct($name, $shortName, $type = self::ARG_STRING, $help = null, $default = null, $requirements = self::ARG_OPTIONAL)
	{
		$this->name 		 = $name;
		$this->shortName 	 = $shortName;
		$this->help 		 = $help;
		$this->default 		 = $default;
		$this->type  		 = $type;
		$this->requirements  = $requirements;
	}

	public function getName() 
	{
		return $this->name;
	}

	public function setName($name) 
	{
		$this->name = $name;
		return $this;
	}

	/**
	 * @return mixed
	 */
	public function getShortName()
	{
		return $this->shortName;
	}

	/**
	 * @param mixed $shortName
	 */
	public function setShortName($shortName)
	{
		$this->shortName = $shortName;
		return $this;
	}

	/**
	 * @return null
	 */
	public function getHelp()
	{
		return $this->help;
	}

	/**
	 * @param null $help
	 */
	public function setHelp($help)
	{
		$this->help = $help;
		return $this;
	}

	/**
	 * @return null
	 */
	public function getDefault()
	{
		return $this->default;
	}

	/**
	 * @param null $default
	 */
	public function setDefault($default)
	{
		$this->default = $default;
		return $this;
	}

	/**
	 * @return int
	 */
	public function getRequirements()
	{
		return $this->requirements;
	}

	/**
	 * @param int $requirements
	 */
	public function setRequirements($requirements)
	{
		$this->requirements = $requirements;
		return $this;
	}

	/**
	 * @return mixed
	 */
	public function getType()
	{
		return $this->type;
	}

	/**
	 * @param mixed $type
	 */
	public function setType($type)
	{
		$this->type = $type;
	}

	public function getValue()
	{
		return isset($this->value) ? $this->value : $this->getDefault();
	}

	public function setValue($value)
	{
		$this->value = $value;
		return $this;
	}
	
}