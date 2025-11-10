## Question: Explain the difference between text mode and binary mode while opening a file in C. Provide scenarios where each is preferable and the possible issues if the wrong mode is chosen.

### Answer
When opening files in C using `fopen()`, you can specify different modes that affect how the file content is interpreted and handled by the system.

Text Mode (`"r"`, `"w"`, `"a"`, etc.)
- The system may perform automatic character translations
- The system handles new line anf EOF

Binary Mode (`"rb"`, `"wb"`, `"ab"`, etc.)
- Data is read/written exactly as stored in the file
- Every byte is preserved without modification
- Consistent behavior across different operating systems
- Must be specified with 'b' suffix
- Images, executables, databases, compressed files, encrypted data, network protocols