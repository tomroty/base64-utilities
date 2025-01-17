# base64-utilities

A simple command-line tool for encoding and decoding Base64 strings.

## Installation

```bash
git clone https://github.com/tomroty/base64-utilities.git
cd base64-utilities
make
```

## Usage

The program supports the following commands:

- Encode a string to Base64:
```bash
./base64_encoder -e "Hello, World!"
```

- Decode a Base64 string:
```bash
./base64_encoder -d "SGVsbG8sIFdvcmxkIQ=="
```

- Show help:
```bash
./base64_encoder -h
```

## Building from Source

Requirements:
- GCC compiler
- Make

Simply run `make` in the project directory to build the executable.

