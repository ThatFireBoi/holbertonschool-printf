# Proyect _printf()

## Description
 
 This function is called _printf and is designed to produce formatted output according to the given format string. It's a custom implementation of the printf function in C. It supports various format specifiers for different data types like characters, strings, integers, and binary.

The supported format specifiers are:

    %c: Character specifier. It expects an int argument that represents the character to be printed.

    %s: String specifier. It expects a char * argument containing the string to be printed.

    %d, %i: Integer specifiers. They expect an int argument that will be printed as a signed decimal number.

    %%: Percent specifier. It is used to print a literal percent symbol ("%").

If an unknown format specifier is encountered, it will be printed as %r.

## Flowchart


![My_First_Board](https://github.com/ThatFireBoi/holbertonschool-printf/assets/127802407/f9422cde-69ce-4dc0-8255-64958618644c)


## Usage

To use this _printf function, you should include the "main.h" header in your program and call _printf with the desired format string and the corresponding arguments. The function will produce the formatted output based on the format specifiers and their respective handler functions defined in the formatHandlers array.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)

## Authors:
Jose G. Nieves Milete |
Gabriel Castro
