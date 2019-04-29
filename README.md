## Table of contents
* [Description](#description)
* [Requirements](#requirements)
* [Setup](#setup)
* [Usage](#usage)

## Description
This project allows to process simple regular expressions. An output from the analysis is a collection of group matches. For greedy regular expressions
a determenistic finite automata is used (match groups algorithm based on the article https://www.labs.hpe.com/techreports/2012/HPL-2012-41R1.pdf).
For lazy regular expressions a nondetermenistic finite automata performs the task.
	
## Requirements
* programming language compiler: C++11
* build utils: Cmake

## Setup
To setup the project, use the followings commands (all dependencies are downloaded by Cmake):
```
$ cd <project_dir>
$ git clone https://github.com/krystianAndrzejewski/regular_expression
$ cd regular_expression
cmake -H. -Bbuild -G <generator_name:"Visual Studio 14 2015 Win64">
```

## Usage
An example of the project usage is defined in main.cpp. A regular expression has a special syntax (is practically coherent with other regExp implementation) and can be assembled from the operators 
(all operators produces a regular expression that can be combined with other regular expression):
* <ascii_character> - a basic operator that is defined as a translation (input character must match the value of the operarator),
* [<ascii_character>-<ascii_character><ascii_character>(...)] - a multi-basic operator that is represented by one or more ascii character that must match the operator (dash operator takes two neighboring ascii characters and allows to get all characters from created range between the characters),
* [^<ascii_character>-<ascii_character><ascii_character>(...)] - a multi-basic operator that is represented by one or more ascii character that cannot match the operator (dash operator takes two neighboring ascii characters and forbids to get all characters from created range between the characters),
* ( <regular_expression> ) - a group operator that allows to combine other operators,
* <regular_expression>* - 0 or more greedy repeation of the regular expression,
* <regular_expression>*? - 0 or more lazy repeation of the regular expression,
* <regular_expression>+ - 1 or more greedy repeation of the regular expression,
* <regular_expression>+? - 1 or more lazy repeation of the regular expression,
* <regular_expression>? - 0 or 1 presence of the regular expression,
* \<regular_expression>|\<regular_expression> - alternative operator that allow to defines two regular expresion and one of them must matched with a input.
<p>Escaped characters for a basic operator are \\, \(, \), \+, \*, \|, \[, \+ and for a mult-basic operator are \\, \]. </p>
<p>Errors during processing either a grammar definition or a text to compilation are reported by exception or returned values. </p>


