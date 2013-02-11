<?php
	/**
	 *	Copyright (c) 2009-2013 MORPOL Softwareentwicklung
	 *	
	 *	This script provides a class MORPOL_CommandLineParser that let's you parse a given input string according to the given rules
	 *	For a list of available rules please take a look at the constants defined below. Each constant has it's own character that may be given to ::buildFlags to get the integer that ::parse accepts.
	 *	Additionally you can add default values for each argument.
	 *	If you have any questions, bug reports or feature requests please contact cl-parser@morpol.de
	 *	
	 *	@author Thiemo Müller
	 *	@changed 2013/01/24
	 */
	
	
	//namespace MORPOL\Tools {
		
		/**
		 *	Class for parsing command-line-like syntaxes defined using parsing flags
		 */
		class MORPOL_CommandLineParser {
			
			// Parsing flags										// Sign	Description
			const PF_ARGUMENTS_PLUS						= 0x0001;	// +	An argument may be named using the + sign: <command> +<name> <value...>
			const PF_ARGUMENTS_MINUS					= 0x0002;	// -	An argument may be named using the - sign: <command> -<name> <value...>
			const PF_ARGUMENTS_PLUS_MINUS_ED			= 0x0004;	// +/-	Arguments may be enabled/disabled using -/+: <command> -<disabled> +<enabled>
			const PF_ARGUMENTS_PLUS_MINUS_E				= 0x0008;	// +/+	Arguments may only be enabled using -/+ (interchangeably): <command> -<enabled> +<enabled>
			const PF_ARGUMENTS_EQUAL					= 0x0010;	// =	An argument may be named usign the = sign: <command> <name>=<value>
			const PF_ARGUMENTS_DOUBLE_QUOTES			= 0x0020;	// "	An argument may be defined using quotes: "bla bla" (Single argument) != bla bla (Two arguments)
			const PF_ARGUMENTS_DOUBLE_QUOTES_CONCAT		= 0x0040;	// "+	Double-quoted strings without a space between will be concatenated: "bla"" " bla"" (Two arguments) != "bla"" " bla"" (Four arguments)
			const PF_ARGUMENTS_DOUBLE_QUOTES_CONCAT_ALL	= 0x0080;	// "++	Double-quoted strings without a space between will be concatenated even if the surrounding characters are not quoted: "bla"bla"bla" (Single  argument) != "bla"bla"bla" (Three arguments) (Please note: <argument>="<value"> will always work!)
			const PF_ARGUMENTS_DOUBLE_QUOTES_ESCAPE		= 0x0100;	// "\	Arguments delimited by quotes may be escaped: "bla\"" "bla\"" (Two arguments) != "bla"" "bla"" (Four arguments)
			const PF_ARGUMENTS_ANY_NAME					= 0x0200;	// .	Arguments may have any name
			const PF_ARGUMENTS_UNNAMED					= 0x0400;	// ?	Arguments may have no name at all (identified by index then)
			const PF_ARGUMENTS_REDEFINITIONS_JOIN		= 0x0800;	// |	If an argument was defined multiple times, their values will be joined. Works only if the arguments value-count was set to unlimited or the argument wasn't declared at all.
			const PF_ARGUMENTS_PLAIN_NAME				= 0x1000;	// p	Names don't need a strict character to be defined (like +, - or =), but are given as plain arguments: <command> <name> <value...>
			
			/**
			 *	The actual parsing function.
			 *
			 *	For examples please see the test-file at tests/base/tools/helpers.php
			 *
			 *	@param sArguments The input to be parsed
			 *	@param iFlags Any combination of the ::PF_* flags
			 *	@param aArgumentDefinitions An array of associative arrays of valid argument names giving their default value or an empty array for no default value, may be extended if PF_ARGUMENTS_ANY_NAME was set. The index within the original array gives the number of values expected, -1 means unlimited.
			 *  @param bDetailed Whether or not the result shall include the arguments only or more details like the position where they were found and their given default, if any
			 *	@param sDoubleQuoteEscaper The sign to escape double quotes within quoted strings
			 *	@param sMultipleEqualDivider If the ::PF_ARGUMENTS_EQUAL flag is set and a argument shall have multiple values, each value must be separated with this sign. Set to null to disable multiple value arguments for this type
			 *	@param sUnnamedIndex At which index unnamed arguments shall be saved. Defaults to an empty string.
			 *	@return An associative array containig the values for the arguments that were parsed
			 */
			public static function parse( $sArguments, $iFlags=0, $aArgumentDefinitions=Array(), $bDetailed=FALSE, $sDoubleQuoteEscaper='\\', $sMultipleEqualDivider='|', $sUnnamedIndex='' ) {
				
				$aArgC		= Array();
				$aArguments	= Array();
				foreach( $aArgumentDefinitions as $iArgC=>$aDefaults )
					foreach( $aDefaults as $sArg=>$aDefault ) {
						$aArgC[$sArg]	= $iArgC;
						//if( count($aDefault) )
							$aArguments[$sArg]	= Array(
								'default'			=> $aDefault,
								'values'			=> array(),
								'start'				=> -1,
								'end'				=> -1,
							);
					}
				
				/*
				 *	Step 1:	Split the given string to a list of arguments
				 *			The result will be an array containing of subarrays as array( sArgument, iStartPosition, iEndPosition )
				 */
				$c			= strlen( $sArguments );
				$i			= 0;
				$iBegin		= 0;
				$aBase		= Array();
				$sStack		= "";
				$bE			= $iFlags&self::PF_ARGUMENTS_EQUAL;
				$bDQ		= $iFlags&self::PF_ARGUMENTS_DOUBLE_QUOTES;
				$bDQE		= $iFlags&self::PF_ARGUMENTS_DOUBLE_QUOTES_ESCAPE;
				$bDQC		= $iFlags&self::PF_ARGUMENTS_DOUBLE_QUOTES_CONCAT;
				$bDQCA		= $iFlags&self::PF_ARGUMENTS_DOUBLE_QUOTES_CONCAT_ALL;
				while( $i<$c ) {
					$sChr1	= $sArguments[$i];
					if( $sChr1==" " || $sChr1=="\t" ) {
						if( $iBegin<$i || $sStack )
							$aBase[]	= Array( $sStack . substr( $sArguments, $iBegin, $i-$iBegin ), $iBegin, $i );
						$sStack	= "";
						$iBegin	= $i+1;
					}
					elseif( $sChr1=='"' && $bDQ ) {
						if( $iBegin<$i || $sStack ) {
							if( $bDQCA || ($bE && $sArguments[$i-1]=="=") )
								$sStack		.= substr( $sArguments, $iBegin, $i-$iBegin );
							else {
								$aBase[]	= Array( $sStack . substr( $sArguments, $iBegin, $i-$iBegin ), $iBegin, $i );
								$sStack		= "";
							}
						}
						$iArgBegin	= $iBegin;
						$iBegin		= ++$i;
						$sArgument	= "";
						while( $i<$c ) {
							while( $i<$c && $sArguments[$i]!='"' )
								$i++;
							$bAdd	= !$bDQE;
							if( !$bAdd ) {
								$n			= $i-1;
								while( $n>=0 && $sArguments[$n]==$sDoubleQuoteEscaper )
									$n--;
								if( ($i-$n)%2 )
									$bAdd	= true;
							}
							if( $bAdd ) {
								$sArgument	.= substr( $sArguments, $iBegin, $i-$iBegin );
								if( !$bDQC || $i+2>=$c || $sArguments[$i+1]!='"' )
									break;
								$iBegin	= ++$i + 1;
							}
							$i++;
						}
						if( $bDQE )
							$sArgument	= str_replace( Array('\\\\','\\"'), Array('\\','"'), $sArgument );
						if( $bDQCA )
							$sStack		.= $sArgument;
						else {
							$aBase[]	= Array( $sStack . $sArgument, $iArgBegin, $i );
							$sStack		= "";
						}
						$iBegin		= $i+1;
					}
					$i++;
				}
				if( $iBegin<$i || $sStack )
					$aBase[]	= Array( $sStack . substr( $sArguments, $iBegin, $i-$iBegin ), $iBegin, $i );
				
				/*
				 *	Step 2:	Use the given arguments and relate them, i.e. add name=>value pairing
				 *			The result will be an array of subarrays as array( sArgumentName, aValues, bEnabled, bEnabledAsString, iArgumentStart, iArgumentEnd )
				 */
				$bAN		= $iFlags&self::PF_ARGUMENTS_ANY_NAME;
				$bRJ		= $iFlags&self::PF_ARGUMENTS_REDEFINITIONS_JOIN;
				$bU			= $iFlags&self::PF_ARGUMENTS_UNNAMED;
				$bP			= $iFlags&self::PF_ARGUMENTS_PLUS;
				$bM			= $iFlags&self::PF_ARGUMENTS_MINUS;
				$bPMED		= $iFlags&self::PF_ARGUMENTS_PLUS_MINUS_ED;
				$bPME		= $iFlags&self::PF_ARGUMENTS_PLUS_MINUS_E;
				$bPN		= $iFlags&self::PF_ARGUMENTS_PLAIN_NAME;
				if( ($bPMED || $bPME) && !$bP && !$bM )
					$bP = $bM = true;
				$bNoArgs	= false;
				$sNoArg		= '0';
				$iArgStart	= 0;
				$iArgEnd	= 0;
				$sName		= null;
				$aValues	= Array();
				$aStack		= Array();
				foreach( $aBase as $n=>$aArgument ) {
					$sArgument	= $aArgument[ 0 ];
					// Equal sign has priority
					if( $bE && ($i=strpos($sArgument,'='))!==false ) {
						$aStack[]		= Array( $sName, $aValues, $bNoArgs, $sNoArg, $iArgStart, $iArgEnd );
						
						$aValues		= Array();
						$iArgStart		= $aArgument[ 1 ];
						$iArgEnd		= $aArgument[ 2 ];
						$sName			= substr( $sArgument, 0, $i++ );
						if( $sMultipleEqualDivider!==null )
							$aValues		= explode( $sMultipleEqualDivider, substr( $sArgument, $i ) );
						else
							$aValues		= Array( substr( $sArgument, $i ) );
						
						$o				= 0;
						for( $c=0; $c<count($aValues); $c++ ) {
							$sValue			= $aValues[$c];
							$aValues[ $c ]	= Array( 'value'=>$sValue, 'start'=>$i+$o, 'end'=>$i+$o+strlen($sValue) );
							$o				+= strlen($sValue) + strlen($sMultipleEqualDivider);
						}
					}
					elseif( ($sArgument[0]=='+' && $bP) || ($sArgument[0]=='-' && $bM) ) {
						$aStack[]		= Array( $sName, $aValues, $bNoArgs, $sNoArg, $iArgStart, $iArgEnd );
						
						$aValues		= Array();
						$sName			= substr($sArgument,1);
						$iArgStart		= $aArgument[ 1 ];
						$iArgEnd		= $aArgument[ 2 ];
						$bNoArgs		= $bPMED || $bPME;
						if( $bNoArgs )
							$sNoArg			= $bPME || $sArgument[0]=='+' ? '1' : '0';
					}
					elseif( $bPN && isset($aArgC[$sArgument]) ) {
						$aStack[]		= Array( $sName, $aValues, $bNoArgs, $sNoArg, $iArgStart, $iArgEnd );
						
						$aValues		= Array();
						$sName			= $sArgument;
						$iArgStart		= $aArgument[ 1 ];
						$iArgEnd		= $aArgument[ 2 ];
					}
					else {
						$aValues[]		= Array( 'value'=>$sArgument, 'start'=>$aArgument[ 1 ], 'end'=>$aArgument[ 2 ] );
						
						$iArgEnd		= $aArgument[ 2 ];
					}
				}
				$aStack[]		= Array( $sName, $aValues, $bNoArgs, $sNoArg, $iArgStart, $iArgEnd );
				
				$aUnknown		= Array();
				
				/*
				 *	Step 3:	Join together all arguments to the final associative array. I.e. multiply defined arguments will be joined or ignored
				 *			The result is the requested array, still detailed
				 */
				foreach( $aStack as $aDef ) {
					list($sPrevName,$aPrevValues,$bPrevNoArgs,$sPrevNoArg,$iArgStart,$iArgEnd)	= $aDef;
					
					if( isset($aArguments[$sPrevName]) && !count($aArguments[$sPrevName]['values']) ) {
						$aArguments[$sPrevName]['start']	= $iArgStart;
						$aArguments[$sPrevName]['end']		= $iArgEnd;
					}
					
					if( $sPrevName!==null ) {
						$bMay	= isset($aArgC[$sPrevName]);
						if( $bMay ) {
							$bMay	= $aArgC[$sPrevName]==-1;
							if( $bMay ) {
								if( isset($aArguments[$sPrevName]) && $bRJ ) {
									$aPrevValues	= array_merge( $aArguments[$sPrevName]['values'] , $aPrevValues );
								}
							}
							else {
								$bMay	= $aArgC[$sPrevName]==count($aPrevValues);
								if( !$bMay && count($aPrevValues)>$aArgC[$sPrevName] && $bU ) {
									while( count($aPrevValues)>$aArgC[$sPrevName] ) {
										if( !isset($aArguments[$sUnnamedIndex]) )
											$aArguments[$sUnnamedIndex]	= Array( 'values'=>Array() );
										
										$aArguments[$sUnnamedIndex]['values']	= array_merge( $aArguments[$sUnnamedIndex]['values'], Array( array_pop( $aPrevValues ) ) );
									}
									$bMay	= true;
								}
							}
						}
						else {
							$bMay	= $bAN;
							if( $bMay ) {
								$aArguments[$sPrevName]	= Array( 'values'=>$aPrevValues, 'start'=>$iArgStart, 'end'=>$iArgEnd );
							}
							else {
								$aUnknown[]	= Array( 'name'=>$sPrevName, 'values'=>$aPrevValues, 'start'=>$iArgStart, 'end'=>$iArgEnd );
							}
							/*else {
								$bMay	= $bRJ && isset($aArguments[$sPrevName]);
								if( $bMay )
									$aPrevValues	= array_merge( $aArguments[$sPrevName]['values'], $aPrevValues );
							}*/
						}
						if( $bMay ) {
							if( !count($aPrevValues) && $bPrevNoArgs )
								$aPrevValues	= Array( Array('value'=>$sPrevNoArg,'start'=>$iArgEnd,'end'=>$iArgEnd),'start'=>$iArgEnd,'end'=>$iArgEnd );
							$aArguments[$sPrevName]['values']	= $aPrevValues;
						}
					}
					elseif( count($aPrevValues) && $bU ) {
						if( !isset($aArguments[$sUnnamedIndex]) )
							$aArguments[$sUnnamedIndex]	= Array( 'values'=>Array() );
						
						$aArguments[$sUnnamedIndex]['values']	= array_merge( $aArguments[$sPrevName]['values'], $aPrevValues );
					}
					else {
						$aUnknown[]	= Array( 'name'=>$sPrevName, 'values'=>$aPrevValues, 'start'=>$iArgStart, 'end'=>$iArgEnd );
					}
				}
				
				//file_put_contents( dirname(__FILE__).'/debug.txt', print_r( Array( 'base'=>$aBase, 'stack'=>$aStack, 'arguments'=>$aArguments, 'unknown'=>$aUnknown ), 1 ) );
				
				if( $bDetailed ) {
					return Array(
						'unknown'	=> $aUnknown,
						'arguments'	=> $aArguments,
					);
				}
				
				/*
				 *	Step 4:	Optionally flatten the array to include the final values only
				 *			The result is an array as array( key=>value_or_default )
				 */
				$aResult	= Array();
				foreach( $aArguments as $sName=>$aArgument ) {
					$aResult[ $sName ]	= Array();
					
					if( count($aArgument['values']) ) {
						foreach( $aArgument['values'] as $aValue )
							$aResult[ $sName ][]	= $aValue['value'];
					}
					else if( isset($aArgument['default']) ) {
						$aResult[ $sName ]	= $aArgument['default'];
					}
					
				}
				
				return $aResult;
				
			}
			
			/**
			 *	Build flags from string array
			 *
			 *	@param s... Any of: + - +/- +/+ = " "+ "++ "\ . ? | p to be added as flags
			 *	@return An integer describing the given flags
			 */
			public static function buildFlags() {
				$iFlags	= 0;
				$aFlags	= func_get_args();
				
				foreach( $aFlags as $sFlag ) {
					switch( $sFlag ) {
						case '+':
							$iFlags	|= self::PF_ARGUMENTS_PLUS;
							break;
						case '-':
							$iFlags	|= self::PF_ARGUMENTS_MINUS;
							break;
						case '+/-':
							$iFlags	|= self::PF_ARGUMENTS_PLUS_MINUS_ED;
							break;
						case '+/+':
							$iFlags	|= self::PF_ARGUMENTS_PLUS_MINUS_E;
							break;
						case '=':
							$iFlags	|= self::PF_ARGUMENTS_EQUAL;
							break;
						case '"':
							$iFlags	|= self::PF_ARGUMENTS_DOUBLE_QUOTES;
							break;
						case '"+':
							$iFlags	|= self::PF_ARGUMENTS_DOUBLE_QUOTES_CONCAT;
							break;
						case '"++':
							$iFlags	|= self::PF_ARGUMENTS_DOUBLE_QUOTES_CONCAT_ALL;
							break;
						case '"\\':
							$iFlags	|= self::PF_ARGUMENTS_DOUBLE_QUOTES_ESCAPE;
							break;
						case '.':
							$iFlags	|= self::PF_ARGUMENTS_ANY_NAME;
							break;
						case '?':
							$iFlags	|= self::PF_ARGUMENTS_UNNAMED;
							break;
						case '|':
							$iFlags	|= self::PF_ARGUMENTS_REDEFINITIONS_JOIN;
							break;
						case 'p':
							$iFlags	|= self::PF_ARGUMENTS_PLAIN_NAME;
							break;
					}
				}
				
				return $iFlags;
			}
			
		}
		
	//}
	
?>